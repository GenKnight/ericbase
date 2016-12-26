#include "MyApplication.h"
#include <assert.h>
#include <fstream>
#include <QMessageBox>
//#include <QThread>
#include <QtCore>
#include <common/SpendTime.h>
#include "dataserver/SearchIndex.h"

using namespace itstation;

MyApplication::MyApplication(int argc,char *argv[], bool cast_mode)
	: QApplication(argc, argv), cast_mode_(cast_mode), has_load_min_(false)
	, is_init_(false), temp_file_(NULL), data_file_(NULL)
{ 
	wgt_ = new QWidget(); 
	if (!cast_mode) { data_file_ = new DataFile(); }

	tick_tcp_server_ = new TickTcpServer(3334);
}

MyApplication::~MyApplication() 
{ 
	delete wgt_; 
	if (NULL != data_file_) { delete data_file_; }
	if (temp_file_ != NULL) { fclose(temp_file_); }
	delete tick_tcp_server_;
}

void MyApplication::CalcProductId(Symbol* sym)
{
	std::string prefix = sym->instrument;
	prefix = prefix.substr(0, 3);
	switch (sym->exchange)
	{
	case EXCHANGE_SSE:
		if (prefix == "600" || prefix == "601" || prefix == "603")
		{
			sym->product = PRODUCT_STOCK;
		}
		else if (prefix == "000")
		{
			sym->product = PRODUCT_INDEX;
		}
		else
		{
			sym->product = PRODUCT_OTHER;
		}
		break;
	case EXCHANGE_SZE:
		if (prefix == "000" || prefix == "001" || prefix == "002" || prefix == "300")
		{
			sym->product = PRODUCT_STOCK;
		}
		else if (prefix == "399")
		{
			sym->product = PRODUCT_INDEX;
		}
		else
		{
			sym->product = PRODUCT_OTHER;
		}
		break;
	default:
		sym->product = PRODUCT_OTHER;
		break;
	}
}

void MyApplication::ThdProc()
{
	if (cast_mode_ || !has_load_min_) { return; }

	if (is_init_)
	{
		data_file_->DoAfterMarket();
	}
}

void MyApplication::SlotDoAfterMarket()
{
	QtConcurrent::run(this, &MyApplication::ThdProc);
}

bool MyApplication::winEventFilter(MSG *message, long *result)
{
	switch(message->message)  
	{  
	case My_Msg_StkData:  
		{
			LONG lPara = message->lParam;
			RCV_DATA *	pHeader = (RCV_DATA *)message->lParam;
			SimpleDateTime now(time(NULL));
			switch(message->wParam)
			{
			case RCV_REPORT:
				{
					if (pHeader->m_nPacketNum <= 0) { return true; }
					//emit SignalInfo(tr("收到TICK  %1").arg(pHeader->m_nPacketNum));

					int nBufSize = pHeader->m_pReport[0].m_cbSize;
					PBYTE pBaseBuf = (PBYTE)&pHeader->m_pReport[0];
					for(int i=0; i<pHeader->m_nPacketNum; i++)
					{
						RCV_REPORT_STRUCTEx & buf = *(PRCV_REPORT_STRUCTEx)(pBaseBuf + nBufSize*i );
						//StockTick& tick = tmp_data[i];
						
						Symbol sym;
						if (buf.m_wMarket == SH_MARKET_EX) {
							sym.exchange = EXCHANGE_SSE;
						}
						else if (buf.m_wMarket == SZ_MARKET_EX) {
							sym.exchange = EXCHANGE_SZE;
						}
						else {
							return true;
						}
						memcpy(sym.instrument, buf.m_szLabel, sizeof(InstrumentIdType));
						strcpy(sym.szName, buf.m_szName);
						
						CalcProductId(&sym);
						if (sym.product == PRODUCT_OTHER /*|| buf.m_fNewPrice < 0.001*/) { continue; }	//这里通过newprice拦截掉了停牌股票
						if (sym.product == PRODUCT_STOCK)
						{
							StockTick tick;
							tick.date_time = SimpleDateTime(buf.m_time);
							/*
							if( strcmp(buf.m_szLabel , "600890")==0)
 							{
								static int lastsec(0);
								if(tick.date_time.time.sec - lastsec>=0 && tick.date_time.time.sec - lastsec<=2)
								{
									SignalInfo(tr("%0").arg(tick.date_time.Str().c_str()));
									long a=1;
								}
								lastsec = tick.date_time.time.sec;
							}*/
							//非当天的数据
							if (tick.date_time.date != now.date) 
							{ 
								return true;
							}

							tick.symbol = sym;
							tick.type = COMM_TICK_DATA;
							tick.identify = COMM_IDENTIFY;
							tick.last_price = buf.m_fNewPrice;
							tick.volume = buf.m_fVolume;
							tick.amount = buf.m_fAmount;
							//tick.avg_price = buf.m_fAmount / (buf.m_fVolume * 100);
							tick.pre_close = buf.m_fLastClose;
							tick.today_open = buf.m_fOpen;
							tick.today_high = buf.m_fHigh;
							tick.today_low = buf.m_fLow;
							for (int j=0; j<3; ++j)
							{
								tick.buy_price[j] = ToMovePoint(buf.m_fBuyPrice[j], buf.m_fNewPrice, DOT_DOT_ONE_POINT);
								tick.sell_price[j] = ToMovePoint(buf.m_fSellPrice[j], buf.m_fNewPrice, DOT_DOT_ONE_POINT);
								tick.buy_volume[j] = buf.m_fBuyVolume[j];
								tick.sell_volume[j] = buf.m_fSellVolume[j];
							}
							tick.buy_price[3] = ToMovePoint(buf.m_fBuyPrice4, buf.m_fNewPrice, DOT_DOT_ONE_POINT);
							tick.sell_price[3] = ToMovePoint(buf.m_fSellPrice4, buf.m_fNewPrice, DOT_DOT_ONE_POINT);
							tick.buy_volume[3] = buf.m_fBuyVolume4;
							tick.sell_volume[3] = buf.m_fSellVolume4;
							tick.buy_price[4] = ToMovePoint(buf.m_fBuyPrice5, buf.m_fNewPrice, DOT_DOT_ONE_POINT);
							tick.sell_price[4] = ToMovePoint(buf.m_fSellPrice5, buf.m_fNewPrice, DOT_DOT_ONE_POINT);
							tick.buy_volume[4] = buf.m_fBuyVolume5;
							tick.sell_volume[4] = buf.m_fSellVolume5;

							if (is_init_) {
								tick_tcp_server_->SendTick(sym, (char*)&tick, sizeof(StockTick));
								if(strcmp(sym.instrument,"601211")==0)
								{
									SignalInfo(tr("%0").arg(tick.date_time.Str().c_str()));
								}
							}
						}
						else if (sym.product == PRODUCT_INDEX)
						{
							StockTick tick;
							memset(&tick,0,sizeof(tick));
							tick.date_time = SimpleDateTime(buf.m_time);
							//非当天的数据,或者盘前
							if (tick.date_time.date != now.date || tick.date_time.time < SimpleTime(9, 30, 0)) { 
								return true; 
							}
							tick.symbol = sym;
							tick.type = COMM_TICK_DATA;
							tick.identify = COMM_IDENTIFY;
							tick.last_price = buf.m_fNewPrice;
							tick.volume = buf.m_fVolume;
							tick.amount = buf.m_fAmount;
							//tick.avg_price = buf.m_fAmount / (buf.m_fVolume * 100);
							tick.pre_close = buf.m_fLastClose;
							tick.today_open = buf.m_fOpen;
							tick.today_high = buf.m_fHigh;
							tick.today_low = buf.m_fLow;
							//TODO:计算指数的张数和跌数

							if (is_init_) {
								tick_tcp_server_->SendTick(sym, (char*)&tick, sizeof(tick));
							}
						}
					}
				}
				break;

			case RCV_PANKOU:
				{
					tagMy_PankouType *panHeader=(tagMy_PankouType *)message->lParam;
					Symbol sym;
					if (panHeader->m_wMarket == SH_MARKET_EX) {
						sym.exchange = EXCHANGE_SSE;
					}
					else if (panHeader->m_wMarket == SZ_MARKET_EX) {
						sym.exchange = EXCHANGE_SZE;
					}
					else {
						return true;
					}
					memcpy(sym.instrument, panHeader->m_szLabel, sizeof(InstrumentIdType));
					CalcProductId(&sym);
					if (sym.product == PRODUCT_OTHER) { return true; }
					emit SignalInfo(tr("补充分笔：%1").arg(sym.instrument));
					has_load_min_ = true;

					Timer spnd_time;
					spnd_time.Start();

					float open_price = 0;
					for(unsigned int i=0;i<panHeader->m_nCount;++i)
					{
						tagRCV_PANKOU_STRUCTEx & buf=*(tagRCV_PANKOU_STRUCTEx *)(panHeader->m_Data + i );
						if (i == 0) { open_price = buf.m_fNewPrice; }
						//StockTick& tick = tmp_data[i];

						if (sym.product == PRODUCT_STOCK)
						{
							StockTick tick;
							tick.type = COMM_TICK_DATA;
							tick.identify = COMM_IDENTIFY;
							tick.symbol = sym;

							tick.date_time = SimpleDateTime(buf.m_time);
							tick.last_price = buf.m_fNewPrice;
							tick.volume = buf.m_fVolume;
							tick.amount = buf.m_fAmount;
							//tick.avg_price = buf.m_fAvgPrice;
							//TODO:昨收
							tick.today_open = open_price;
							tick.today_high = buf.m_fHigh;
							tick.today_low = buf.m_fLow;
							for (int j=0; j<PRICE_LEVEL_NUM; ++j)
							{
								tick.buy_price[j] = ToMovePoint(buf.m_fBuyPrice[j], buf.m_fNewPrice, DOT_DOT_ONE_POINT);
								tick.sell_price[j] = ToMovePoint(buf.m_fSellPrice[j], buf.m_fNewPrice, DOT_DOT_ONE_POINT);
								tick.buy_volume[j] = buf.m_fBuyVolume[j];
								tick.sell_volume[j] = buf.m_fSellVolume[j];
							}
							if (cast_mode_) { 
								if (is_init_) {
									tick_tcp_server_->SendTick(sym, (char*)&tick, sizeof(tick));
									//common::Thread::Sleep(1000);
								}
							}
							else if (is_init_)
							{
								data_file_->PushTick(&tick);
							}
						} 
						else if (sym.product == PRODUCT_INDEX)
						{
							StockTick tick;
							memset(&tick,0,sizeof(tick));
							tick.type = COMM_TICK_DATA;
							tick.identify = COMM_IDENTIFY;
							tick.symbol = sym;

							tick.date_time = SimpleDateTime(buf.m_time);
							tick.last_price = buf.m_fNewPrice;
							tick.volume = buf.m_fVolume;
							tick.amount = buf.m_fAmount;
							//tick.avg_price = buf.m_fAvgPrice;
							//TODO:昨收
							tick.today_open = open_price;
							tick.today_high = buf.m_fHigh;
							tick.today_low = buf.m_fLow;
							//TODO:计算指数的张数和跌数
							if (cast_mode_) { 
								if (is_init_) {
									tick_tcp_server_->SendTick(sym, (char*)&tick, sizeof(tick));
									//common::Thread::Sleep(1000);
								}
							}
							else if (is_init_) { 
								data_file_->PushTick(&tick);
							}
						}
					}

					spnd_time.Stop();
					emit SignalInfo(tr("用时：%1").arg(spnd_time.Seconds()));
				}
				break;  

			case RCV_FILEDATA:
				switch(pHeader->m_wDataType)
				{
				case FILE_HISTORY_EX:
					RCV_HISTORY_STRUCTEx * pDay = pHeader->m_pDay;
					for(int i=0; i<pHeader->m_nPacketNum ; ++i)
					{
						if(pDay[i].m_head.m_dwHeadTag == EKE_HEAD_TAG)
						{
							if (NULL != temp_file_) { 
								fclose(temp_file_);
								temp_file_ = NULL;
							}
							Symbol sym;
							if (pDay[i].m_head.m_wMarket == SH_MARKET_EX) {
								sym.exchange = EXCHANGE_SSE;
							}
							else if (pDay[i].m_head.m_wMarket == SZ_MARKET_EX) {
								sym.exchange = EXCHANGE_SZE;
							}
							else {
								emit SignalInfo(tr("补充日线收到未知市场类型"));
								continue;
							}
							memcpy(sym.instrument,pDay[i].m_head.m_szLabel, sizeof(InstrumentIdType));
							CalcProductId(&sym);
							if (sym.product == PRODUCT_OTHER) { continue; }
							emit SignalInfo(tr("补充日线：%1").arg(sym.instrument));
							
							std::string day_path_ = Global::GetInstance()->fnd_home + "/data/Day/";
							
							if (sym.product == PRODUCT_STOCK) {
								day_path_ += "STOCK/";
							}
							else {
								day_path_ += "INDEX/";
							}
							day_path_ += std::string(sym.instrument) + ".data";
							if ((temp_file_ = fopen(day_path_.c_str(), "ab+")) == NULL)
							{
								emit SignalInfo(tr("补充日线错误：打开文件失败"));
								continue;
							}

							fseek(temp_file_, 0, SEEK_END);
							if (ftell(temp_file_) >= sizeof(Kline))
							{
								fseek(temp_file_, -sizeof(Kline), SEEK_END);
								Kline kline;
								fread(&kline, sizeof(Kline), 1, temp_file_);
								last_date_ = kline.b_time.date;
								fseek(temp_file_, 0, SEEK_END);
							}
							else
							{
								last_date_ = SimpleDate();
							}
						}
						else
						{
							if (NULL != temp_file_)
							{
								Kline kline;
								kline.b_time = SimpleDateTime(pDay[i].m_time);
								if (kline.b_time.date <= last_date_) { continue; }
								kline.b_time.time = SimpleTime(9, 30, 0);
								kline.e_time = kline.b_time;
								kline.e_time.time = SimpleTime(15, 0, 0);
								kline.open = pDay[i].m_fOpen;
								kline.high = pDay[i].m_fHigh;
								kline.low = pDay[i].m_fLow;
								kline.close = pDay[i].m_fClose;
								kline.volume = pDay[i].m_fVolume;

								fwrite(&kline, sizeof(Kline), 1, temp_file_);
							}
						}
					}
					break;
				}
			}
		}
		break;  

	default:  
		break;  
	}  

	return QApplication::winEventFilter(message,result);
}

void MyApplication::Init()
{
	if (is_init_) {
		return;
	}

	if (!cast_mode_)
	{
		std::string err;
		if (!data_file_->Init(err))
		{
			QMessageBox::critical(NULL, tr("初始化失败"), tr("%1").arg(err.c_str()));
			exit(-1);
		}
	}

	string err;
	if (!tick_tcp_server_->StartUp(err))
	{
		emit SignalInfo(tr("TcpServer初始化失败:%1").arg(err.c_str()));
		QMessageBox::critical(NULL, tr("初始化失败"), tr("TcpServer初始化失败:%1").arg(err.c_str()));
		exit(-1);
	}

	//itstation::common::Thread::Sleep(10000);
	WId wid = wgt_->winId();
	int ok = stk_drv_.Stock_Init(wid,My_Msg_StkData,RCV_WORK_SENDMSG);	// 数据共享引用
	stk_drv_.GetStockDrvInfo(RI_SUPPORTEXTHQ,NULL);	//设置 Szn Label6 Receive	
	stk_drv_.GetStockDrvInfo(RI_PanKouSUPPORT,NULL);
	stk_drv_.GetStockDrvInfo(RI_DATAExtSUPPORT2,NULL);

#if 0
	sym_db_ = new SymbolExTable(DBTableFactory::GetInstance()->GetEnv(), "StockCodeTable.db");
	if (!sym_db_->OpenDb())
	{
		delete temp_day_kline_db_;
		temp_day_kline_db_ = NULL;
		emit SignalInfo(tr("打开行情代码表失败"));
	}
#endif
	
	is_init_ = true;
}

void MyApplication::ShowInfo(const QString& str)
{
	emit SignalInfo(str);
}

//void MyApplication::InitMid(std::string& err)
//{
//	mid_hdl_ = new midware::MyMidHdl();
//	mid_point_ = midware::MidPointFactory::CreateInstance("StockDataServer")->GetPoint("DataCast");
//	assert(mid_point_->Connect("127.0.0.1", 2921, mid_hdl_));
//	mid_point_->JoinEx();
//}

char MyApplication::ToMovePoint(float price, float base_p, MovePointType p_type) {
	if (price > 1000000 || price < -1000000 || (price > -0.000001 && price < 0.000001))
	{
		return NAN_PRICE_UNIT;
	}
	float num = (price - base_p) > 0 ? (price - base_p + 0.001) : (price - base_p - 0.001);
	switch (p_type) {
	case DOT_DOT_ONE_POINT:
		return int(num / 0.01);
		break;
	case DOT_DOT_TWO_POINT:
		return int(num / 0.02);
		break;
	case DOT_DOT_FIVE_POINT:
		return int(num / 0.05);
		break;
	case DOT_ONE_POINT:
		return int(num / 0.1);
		break;
	case DOT_TWO_POINT:
		return int(num / 0.2);
		break; 
	case DOT_FIVE_POINT:
		return int(num / 0.5);
		break;
	case ONE_POINT:
		return int(num);
		break;
	case TWO_POINT:
		return int(num / 2);
		break;
	default:
		return int(num / 5);
	}
} 

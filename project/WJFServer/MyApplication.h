#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include "dataserver/TickTcpServer.h"
#include <string>
#include <QWidget>
#include <QDebug>
#include "STKDRV.h"
#include "Stockdrv.h"
#include "dataserver/DataServerStruct.h"
#include <QApplication>
#include <QString>
#include "DataFile.h"

using namespace itstation;

#define	 My_Msg_StkData		WM_APP + 1
//typedef common::BklyDB<std::string, SymbolEx> SymbolExTable;

class MyApplication : public QApplication
{
	Q_OBJECT

public:
	MyApplication(int argc,char *argv[], bool cast_mode = false);
	~MyApplication();

	void Init();

	void ShowInfo(const QString& str);

	//DataDb* GetDataDb() { return data_db_; }

public slots:
	void SlotDoAfterMarket();

protected:
	bool winEventFilter(MSG *message, long *result);

private:
	char ToMovePoint(float price, float base_p, MovePointType p_type);
	void CalcProductId(Symbol* sym);

	void ThdProc();

signals:
	void SignalInfo(QString str);

private:
	QWidget* wgt_;
	CSTKDRV stk_drv_;

	bool cast_mode_;
	bool has_load_min_;

	//DataDb* data_db_;
	//KlineTable* temp_day_kline_db_;
	//SymbolExTable* sym_db_;
	DataFile* data_file_;
	bool is_init_;
	FILE* temp_file_;

	TickTcpServer* tick_tcp_server_;
	SimpleDate last_date_;
	//FILE* pf_;
	//bool new_sym_;
	//std::string code_;
	//std::string exch_;
	//float pre_vol;
};

#endif // MYAPPLICATION_H

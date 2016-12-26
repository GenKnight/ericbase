
#pragma once

#ifndef _APP_COMM_INTERFACE_DEF_
#define _APP_COMM_INTERFACE_DEF_

#include <string>
#include <stdio.h>
#include <string.h>
#pragma pack(push,1)     /*指定1字节对齐*/

//错误码定义
#define	PROCESS_SUCCESS				  0	    //处理成功
#define	REQUEST_PACKAGE_ILLEGAL		  1		//请求数据异常
#define	OPERATE_DB_FAILED			  2		//数据库操作失败
#define	USRID_EXISTED				  3		//登录账号已经存在
#define	USRID_NOT_EXISTED			  4		//未注册的手机号
#define	WRONG_PASSWD				  5		//登录密码错误
#define	MAC_ADDRESS_CHANGE			  6		//mac地址变化
#define CMD_NOT_SUPPORTED			  7		//不支持请求
#define	INFO_NOT_EXIST				  8		//无相关信息
#define	NOT_LOGIN_YET				  9		//未登录
#define	ME_ORDER_NOTOVER			 10		//还有融资订单未处理
#define	ME_UP_LIMIT					 11		//超过融资上限
#define	ME_CASH_USEUP				 12		//暂无资金可融资
#define	ME_ORDER_INVALID			 13		//融资订单无效
#define	ME_PAY_LESS					 14		//实际支付金额小于应该支付金额
#define	RISK_CTRL_NOT_PASS			 15		//风控检查未通过
#define	BUY_FORBIDDEN				 16		//没有买入权限
#define	SELL_FORBIDDEN				 17		//没有卖出权限
#define	WARRANT_RATIO_NOT_PASS		 18		//担保比率不符合要求
#define	SEC_MV_NOT_PASS				 19		//证券市值不符合要求
#define	BELONGTO_BLACK_LIST			 20		//黑名单证券代码
#define	MD_SERVER_HALT				 21		//实时行情服务终止
#define	GET_ASSET_FAILED			 22		//获取资产失败
#define ASSET_NOT_ENOUGH			 23		//资产不足
#define	SLEF_SELECTION_EXISTED		 24		//自选股已存在
#define SLEF_SELECTION_NOT_EXISTED	 25		//自选股不存在
#define	SLEF_OVER_MAX_CASH   		 26		//额度超过最大最
#define	ME_ORDER_FINISH_PZTY	     27		//体验配资未完结
#define	ME_ORDER_NOPOWER_PZTY	     28		//没有体验配资资格
#define	PUSH_MONEY_FAILED	         29		//入金失败
#define	DRAW_MONEY_NOT_ENOUGH	     30		//可提余额不足
#define	DRAW_MONEY_FAILED	         31		//出金失败
#define	WARRAN_TRATE_MIN	         32		//担保比例低于0.6，请充值后再尝试展期
#define	LEFT_MONEY_NOT_ENOUGH	     33		//余额不足支付利息
#define	USED_MONEY_NOT_ENOUGH	     34		//可用资金不足支付利息
#define ERR_TABLE_BASE_DATE			 35		//基准日期表配置错误
#define NOT_TRADING_TIME			 36		//非交易时间
#define NOT_SUPPORT_ENTRUST			 37		//当前时间点不支持的委托
#define	ENTRUST_CANCEL_FORBIDDEN	 38		//没有撤单权限
#define	ENTRUST_INVALID				 39		//委托无效
#define	CONDITION_ORDER_INVALID		 40		//条件单已经失效
#define	PUSH_MONEY_NO_PRIVILEGE		 41		//无入金权限
#define	DURING_PZTY_NO_PRIVILEGE	 42		//体验期间，不开放入金权限
#define	ADD_INFO_EXISTED	         43		//添加记录已存在
#define	ORDER_CANNOT_CANCEL	         44		//该单不可撤单
#define	FUND_ACCOUNT_CANNOT_FIND	 45		//找不到资金账户
#define	INSTRUMENT_INFO_CANNOT_FIND	 46		//找不到合约参数
#define	RISKRULE_INFO_CANNOT_FIND	 47		//找不到风控规则
#define	MARGIN_RATIO_NOT_PASS		 48		//保证金比率不符合要求
#define	QUANTITY_USE_NOT_ENOUGH		 49		//可平数量不足
#define	USER_LOGIN_NO_PRIVILEGE		 50		//该用户没有登入权限
#define	ADMIN_CANNOT_DELETE			 51		//管理员不可以删除
#define	SYSROLE_CANNOT_ADD			 52		//系统角色不可以添加
#define	SYSROLE_CANNOT_MODIFY		 53		//系统角色不可以修改
#define	SYSROLE_CANNOT_DELETE		 54		//系统角色不可以删除
#define	USER_NO_ENTRUST_PRIVILEGE    55		//用户没有委托权限
#define	INST_IS_NOT_LEGAL		     56		//指令不合法
#define	PZACC_CANNOT_CHANGE_FUND	 57		//已分配资金的子帐不可更改资金账户
#define	EXIST_SAME_RISKCTRL_ITEM	 58		//已存在相同的风控指标
#define	SUBENTRUST_NO_CANCEL		 59		//指令相关的委托不符合撤单条件
#define	PRODUCT_NO_DEFAULT_ACC		 60		//产品没有默认子账户
#define	INST_TRADER_EXISTING		 61		//指令已有交易员
#define	GET_STOCK_MAXNUM_BUY_FAIL	 62		//获取股票最大可买数量失败
#define	DURING_SETTLEMENT_NO_OP		 63		//盘后结算期间不允许此操作
#define	PRODUCT_FUNDACC_EXISTED		 64		//产品下已存在同类资金账户
#define	USER_MACHINE_EXISTED		 65		//该用户在本机已登录


#define STOCK_SECURITY_TYPE          "1"    //股票
#define FUTURE_SECURITY_TYPE         "2"    //期货

#define ENTRUST_INST_APPROVING       '1'   //审批中
#define ENTRUST_INST_EXECTUING       '2'   //执行中
#define ENTRUST_INST_ORDERED_CANCEL  '3'   //已报待撤
#define ENTRUST_INST_PARTDONE_CANCEL '4'   //部成待撤
#define ENTRUST_INST_PART_CANCELED   '5'   //部撤
#define ENTRUST_INST_CANCELED        '6'   //已撤
#define ENTRUST_INST_DONE            '8'   //完成
#define ENTRUST_INST_FAILED          '9'   //废单
#define ENTRUST_INST_CANCEL_SENDED   'a'   //撤单已发
#define ENTRUST_INST_RISK_PASSED     'p'   //风控通过
#define ENTRUST_INST_RISK_REJECT     'r'   //风控驳回
#define ENTRUST_INST_APPROVE_REJECT  'd'   //审批驳回


#define ENTRUST_NOT_ORDERED          '0'   //未报
#define ENTRUST_TOBE_ORDERED         '1'   //待报
#define ENTRUST_ORDERED              '2'   //已报
#define ENTRUST_ORDERED_CANCEL       '3'   //已报待撤
#define ENTRUST_PARTDONE_CANCEL      '4'   //部成待撤
#define ENTRUST_PART_CANCELED        '5'   //部撤
#define ENTRUST_CANCELED             '6'   //已撤
#define ENTRUST_PART_DONE            '7'   //部成
#define ENTRUST_DONE                 '8'   //完成
#define ENTRUST_FAILED               '9'   //废单
#define ENTRUST_CANCEL_SENDED        'a'   //撤单已发


#ifndef _WIN32
typedef unsigned char       BYTE;
#endif

//接口协议定义
//通用数据部分头
typedef struct tagResponseHead
{
	int success;		         //0-成功
	int requestid;		         //类别
	int num;			         //数量
}RESPONSE_HEAD,MULTI_MSGS_HEAD;

//1、注册请求【datatype=1】
typedef struct tagRegister
{
	char mobile[16];
	char password[64];
	char remote_ip[16];
	char macAddress[48];
	char invitenum[32];		//邀请会员号
	char fund_flag;         //'0':绑定所有 '1':股票 '3':期货

	char reserve[128];		//预留
}APP_REGISTER;

//2、登录请求【datatype=2】
typedef struct tagLogin
{
	int requestid;	//1--初次登录 2--验证登录 3--前置机登录

	char mobile[16];
	char password[64];
	char remote_ip[16];
	char macAddress[48];

	char reserve[128];		//预留
}APP_LOGIN;

//3、密码请求【datatype=3】
typedef struct tagModifyPasswd
{
	int requestid;	//1--重置密码 2--找回密码

	char mobile[16];
	char old_password[64]; //1--enable
	char new_password[64];
	char macAddress[48];   //2--enable
	char remote_ip[16];
	char reserve[128];		//预留
}APP_MODIFY_PASSWD;

typedef struct tagMemberIdRep
{
	int success;		//0-成功
	int member_id;		//会员id
}APP_MEMBER_ID_REP;

//-------------------------------------------------------
//4、获取用户信息【datatype=4】
typedef struct tagUsrInfo
{
	/*请求信息id定义
	0--基础信息 1--保证金余额、可抵余额[废弃] 2--代金券 3--请求资产 4--取消资产请求 
	5--请求仓位 6--取消仓位请求 7--自选股请求 8--合约请求 9--委托查询 10--资金流水 
	11--获取交易默认值 12--获取我的信息 13--获取资产表现 14--出入金流水 15--邮箱信息 
	16--支付信息 17--挂单查询 18--成交查询 19--结算单查询 20--条件单 21--仓位明细
	22--保证金利率 23--手续费率*/
	int requestid;			

	int member_id;
	char mobile[16];

	int email_limit;
	int email_offset;

	char reserve[128];		//预留
}APP_USR_INFO;

//请求用户信息返回结构定义：0--基础信息 
typedef struct tagUsrInfo00
{
	int success;	//0-成功
	int requestid;	//0--基础信息

	bool first_experience_flag;	//初次体验标志
	char invitation_code[32];	//邀请码

	char reserve[512];		//预留
}USRINFO0;

//请求用户信息返回结构定义：1--保证金余额、可抵余额（废弃）
typedef struct tagUsrInfo01
{
	int success;	//0-成功
	int requestid;	//1--保证金余额、可抵余额

	double margin_remainder;	//保证金余额
	double offset_remainder;	//可抵余额
}USRINFO1;

//代金券定义
typedef struct taPayCoupon
{	
	char   pay_coupon[13];      //代金券编号
	double coupon_value;		//代金券金额
	char expire_date[30];       //到期日期
}PAY_COUPON;

//资产定义
typedef struct tagAsset
{	
	double dSetoff;			//可抵金额
	double dMargin;			//保证金
	double dAsset;			//总资产
	double dNetAsset;		//净资产
	double dDebt;			//负债
	double dMakretValue;	//总市值
	double dCash;			//现金
	double dblDrawableCash;	//可提现金额 dAvaiableQuota
	double dWarrantRate;	//担保比率
	double dAvaiableCash;	//可用金额（用于买股票等）
}USR_ASSET;

//请求用户【资产】信息返回结构定义（仅股票）：
typedef struct tagUsrInfo03
{
	int success;		//0-成功
	int requestid;		//3--请求资产

	USR_ASSET asset;	//资产信息
}USRINFO3;

typedef struct tagAssetEx
{	
	double dSetoff;			//可抵金额
	double dMargin;			//保证金
	double dAsset;			//总资产
	double dNetAsset;		//净资产
	double dDebt;			//负债
	double dMakretValue;	//股票总市值
	double dCash;			//资金余额
	double dblDrawableCash;	//可取金额
	double dWarrantRate;	//担保比率
	double dAvaiableCash;	//资金可用

	double dMaxMarketValue1;	//最大股票市值
	double dMaxMarketValue2;	//最大期货市值 【废弃!】

	double dWarningLine;	    //预警线
	double dCloseLine;      	//平仓线
	double dRiskDegree;         //风险度

	double dMarketValue300;		//创业板市值
}USR_ASSET_EX;

typedef USR_ASSET_EX STOCK_ASSET;

//请求用户【资产】信息返回结构定义（仅期货）：
typedef struct tagFutureAsset
{
	double dDynamicRight;	    //动态权益
	double dAvaiableSum;	    //可用资金
	double dPreCreditSum;	    //上次信用额度	    0
	double dPreMortgageSum;	    //上次质押金额  	0
	double dMortgageSum;	    //质押金额		0
	double dWithdrawSum;	    //出金
	double dDepositSum;		    //入金
	double dStaticRight;	    //静态权益	
	double dCloseProfit;	    //平仓盈亏 
	double dPositionProfit;	    //持仓盈亏
	double dCash;			    //现金
	double dPreReserve;		    //上次结算准备金
	double dRoyalty;		    //权利金		    0
	double dDeliveryMargin;	    //交割保证金	    0
	double dFrozenRoyalty;	    //冻结权利金	    0
	double dCredit;			    //信用金额		0
	double dFallbackCash;	    //保底资金		0
	double dblDrawableCash;	    //可取资金 dPayableCash
	double dCommission;		    //手续费
	double dMargin;			    //占用保证金
	double dFrozenMargin;	    //冻结保证金
	double dFrozenCommission;	//冻结手续费

	//配资产生
	double dNetAsset;		    //净资产
	double dDebt;			    //负债
	double dMarginDebt;		    //借款保证金（配资保证金）
	double dSetoff;			    //可抵金额
	double dWarrantRate;	    //担保比率
	double dDrawable;		    //配资可取金额
	double dMarketValue;		//期货总市值
	double dMaxMarketValue;		//最大期货市值


}FUTURE_ASSET;

typedef struct tagIFUsrInfo03
{
	int success;		//0-成功
	int requestid;		//3--请求资产

	FUTURE_ASSET asset;	//资产信息
}IFUSRINF03;

typedef struct tagCommonAsset
{
	double dblMarketValue;		//证券总市值
	double dblAsset;			//总资产/动态权益
	
	double dblContractMargin;	//合约占用保证金
	double dblFrozenMargin;		//合约冻结保证金

	double dblAvailableCash;	//可用资金
	double dblDebt;				//总负债
	double dblNetAsset;			//净资产
	double dblMargin;			//保证金（借款保证金）
	double dblSetOff;			//可抵金额
	double dblGuaranteeRate;	//信用担保比例
	double dblDrawableCash;		//可取金额

}COMMON_ASSET;

//证券总资产
typedef struct tagSecurityAsset
{
	STOCK_ASSET  stock_asset;	//股票资产
	FUTURE_ASSET future_asset;	//期货资产

	//可以继续扩充
	COMMON_ASSET common_asset;	//共同资产【股票资产 和 期货资产】
}SEC_ASSET;

typedef struct tagUsrInfo04
{
	int success;		//0-成功
	int requestid;		//4--取消资产请求
}USRINFO4;

typedef struct tagPosition
{	
	char SecurityCode[32];		//证券代码
	double quantity;			//证券总数量
	double quantity_can_use;	//证券可卖数量
	double real_open_amount;	//今买数量
	double real_off_amount;		//今卖数量
	double cost_balance;		//成本金额
	double keep_cost_price;		//成本价
	char cond_status;           //条件单标志 '0'无 '1'有

	bool operator < (const tagPosition &CompareTo) const
	{
		return cost_balance>CompareTo.cost_balance;
	}

	bool operator > (const tagPosition &CompareTo) const
	{
		return cost_balance<CompareTo.cost_balance;
	}

}SECURITY_POSITION;

//证券仓位定义
typedef struct tagPositionSec
{	
	char position_type;         //仓位类型 1、3
	char issue_cd[32];			//证券代码
	char security_type[8];
	char currency_cd[3];
	char ls;                    //买卖方向 'L':买 'S':卖
	double quantity;			//剩余数量
	double quantity_can_use;	//可用数量
	double real_open_amount;	//今开数量
	double real_off_amount;		//今平数量
	double cost_balance;		//成本金额
	double keep_cost_price;		//成本价
	int Position;               //总仓位=quantity
	int OpenVolume;             //开仓量
	int CloseVolume;			//平仓量
	double OpenAmount;			//开仓金额
	double CloseAmount;			//平仓金额
	double PositionCost;        //持仓成本
	double OpenCost;            //开仓成本
	int TodayPosition;          //今日持仓

	char cond_status;           //条件单标志 '0'无 '1'有

	bool operator < (const tagPositionSec &CompareTo) const
	{
		return cost_balance>CompareTo.cost_balance;
	}

	bool operator > (const tagPositionSec &CompareTo) const
	{
		return cost_balance<CompareTo.cost_balance;
	}

}SECURITY_POSITION_SEC;

typedef struct tagUsrInfo06
{
	int success;		//0-成功
	int requestid;		//6--取消仓位请求
}USRINFO6;

//证券仓位定义
typedef struct tagSelection
{	
	char symbol[16];		//证券代码
}SECURITY_SELECTION;

//账户合约定义
typedef struct tagDebt
{	
	long long    debt_id;          //合约号
	char   debt_type[20];          //合约类型
	char   contract_date[30];      //合约日期 YYYY-MM-DD
	double initial_leverage;       //杠杆
	int    initial_term;           //初始期限
	double contract_value;         //融资合约金额
	char   maturity_date[30];      //到期日
	double total_interest_and_fee; //费用
	double paid_principal;         //还款金额
	char   last_maturity_date[30]; //展期前到期日
	int    renewal_times;          //展期次数
	char   debt_status;            //合约状态

	char   initial_cycle;          //期限单位
	double to_pay_cash;            //微信支付金额
}SECUTIRY_DEBT;

//股票委托
typedef struct tagSTEntrustInfo
{
	int    entrust_id;             //委托号
	char   pz_account[30];		   //子账账号
	char   position_type;          //仓位类型
	char   issue_cd[30];           //系统代码
	char   trans_code[20];
	char   direction;
	char   offset_flag;
	char   hedge_flag;
	char   entrust_date[30];       //委托日期时间
	char   entrust_prop[20];       //委托属性
	double entrust_price;          //委托价格
	double entrust_quantity;       //委托数量
	double frozen_value;
	double frozen_fee;
	char   currency_cd[3];
	double trade_price;
	double trade_quantity;
	char   entrust_way;
	char   entrust_status;         //状态
	char   cancel_info[20];		   //信息
	double withdraw_amount;		   //撤单数量
	char   fund_account[30];
	char   original_entrust_id[30];
	char   OrderRef[13];
}ST_ENTRUST_INFO;

//期货挂单委托
typedef struct tagIFOrderInfo
{	
	int    entrust_id;             //委托号
	char   position_type;          //仓位类型
	char   issue_cd[30];           //系统代码
	char   trans_code[20];         //业务类型 FU_B_OPEN/FU_S_OPEN/FU_B_OFF/FU_S_OFF
	char   direction;              //买卖方向 B/S
	char   offset_flag;			   //开平 0/1
	char   hedge_flag;             //套利
	char   entrust_date[30];       //委托日期时间
	char   entrust_prop[20];       //委托属性 F1：市价 F2：限价 
	double entrust_price;          //委托价格
	double entrust_quantity;       //委托数量
	double frozen_value;
	double frozen_fee;
	char   currency_cd[3];
	double trade_price;
	double trade_quantity;
	char   entrust_way;
	char   entrust_status;         //状态
	char   cancel_info[20];
	double withdraw_amount;
	char   ExchangeID[9];          //撤单id
	char   OrderSysID[21];         //撤单id

	char   entrust_type;           //委托单类型 '0':普通单 '1':条件单 (暂时不用)
}IF_ORDER_INFO;

//期货挂单委托查询[前置机]
typedef struct tagIFPcOrderInfo
{	
	char mobile[16];

	char   issue_cd[30];           //系统代码
	char   OrderRef[13];
	char   OrderPriceType;
	char   direction;              //买卖方向 B/S
	char   offset_flag;			   //开平 0/1
	char   hedge_flag;             //套利
	double entrust_price;          //委托价格
	double entrust_quantity;       //委托数量 同:VolumeTotalOriginal
	char   TimeCondition;
	char   GTDDate[9];
	char   VolumeCondition;
	int    MinVolume;
	char   ContingentCondition;
	double StopPrice;
	char   ForceCloseReason;
	int    IsAutoSuspend;
	char   BusinessUnit[21];
	int    RequestID;
	char   OrderLocalID[13]; 
	char   ExchangeID[9]; 
	char   ParticipantID[11];
	char   ClientID[11];
	char   ExchangeInstID[31];
	char   TraderID[21];
	int    InstallID;
	char   OrderSubmitStatus;
	int    NotifySequence;
	char   TradingDay[9];
	int    SettlementID;
	char   OrderSysID[21];
	char   OrderSource;
	char   OrderStatus;
	char   OrderType;
	int    VolumeTraded;
	int    VolumeTotal;
	char   InsertDate[9];
	char   InsertTime[9];
	char   ActiveTime[9];
	char   SuspendTime[9];
	char   UpdateTime[9];
	char   CancelTime[9];
	char   ActiveTraderID[21];
	char   ClearingPartID[11];
	int    SequenceNo;
	char   UserProductInfo[11];
	char   StatusMsg[81];
	int    UserForceClose;
	char   ActiveUserID[16];
	int    BrokerOrderSeq;
	char   RelativeOrderSysID[21];
	int    ZCETotalTradedVolume;
	int    IsSwapOrder; 
}IF_PC_ORDER_INFO;

//资金流水定义
typedef struct tagFundsFlow
{	
	int    journal_id;             //流水号
	char   position_type;          //仓位类型
	char   issue_cd[30];           //系统代码
	char   trans_code[20];         //业务类型 buy/sell
	char   trans_date[30];         //成交日期
	double trans_price2;           //成交价格
	double trans_quantity;         //成交数量
	double trans_value;            //发生金额
}FUNDS_FLOW;

typedef struct tagUsrInfo11
{
	int success;		         //0-成功
	int requestid;		         //11-获取默认交易信息

	char is_auto_renewal;        //默认是否展期 '0':不展期 '1':展期
	char fast_trade_b_option;    //买类型 '0':未设置 '1':按百分比 '2':按数量
	double default_buy_percent;  //默认买百分比
	int default_buy_amount;      //默认买数量
	char fast_trade_s_option;    //卖类型 '0':未设置 '1':按百分比 '2':按数量
	double default_sell_percent; //默认卖百分比
	int default_sell_amount;     //默认卖数量
}USRINF11;

typedef struct tagUsrInfo12
{
	int success;		         //0-成功
	int requestid;		         //12-获取我的信息

	char member_nickname[40];	 //昵称
	char birthday[30];           //生日 YYYY-MM-DD
	char height[20];	         //身高
	char education[20];		     //学历
	char occupation[20];		 //行业
	char company[20];			 //公司
	char region[20];		     //地区
	char emotional_state[20];	 //感情状态
	char label[80];			     //标签
	char email[40];			     //邮箱
	char identity_card[18];	     //卡号
	char verified_date_id[30];	 //绑定日期
	char member_name[40];  
	char registered_date[30];    //2015-08-04
	char contact_address[80];
	char member_status;
}USRINF12;

typedef struct tagSettleContent
{
	int success;		         //0-成功
	int requestid;		         //12-获取我的信息

	///结算编号
	int	SettlementID;

	///消息正文
	int data_len;
	//char* Content;

}SETTLE_CONTENT;

//资产表现查询定义
typedef struct tagDailyInfo
{	
	char   asofdate[30];           //日期
	double nav;                    //净值
}DAILY_INFO;

//资产表现信息返回结构定义：
typedef struct tagUsrInfo13
{
	char   success;		           //0-成功
	int    requestid;		       //13-请求自选

	char   registered_date[30];   //开始日期 YYYY-MM-DD
	double recent_nav;            //最近净值
	double recent_drawdown;       //最近回撤

	int num;	                  //资产表现数量
	//+num个DAILY_INFO
}USRINF13;

//邮箱信息定义
typedef struct tagEmailInfo
{	
	int    seq_id;              //邮件号
	int    member_id;           //会员号
	char   send_time[30];       //发送日期
	char   main_data[512];      //邮件内容
	char   mail_status;         //状态

}EMAIL_INFO;

//支付信息定义
typedef struct tagEbatongInfo
{	
	char   customer_id[64];         
	char   card_no[64];             //卡号
	char   bank_code[18];           //银行号
	char   verified_date[30];       //认证日期
	char   status;
	char   real_name[64];
	char   cert_no[64];
	char   cert_type[2];
}EBATONG_INFO;

//股票成交回报
typedef struct tagSTRecordInfo
{
	int    trade_id;				//成交号
	char   pz_account[30];			//子账账号
	char   position_type;			//仓位类型
	char   issue_cd[30];			//系统代码
	char   trans_code[20];
	char   direction;
	char   offset_flag;
	char   hedge_flag;
	char   currency_cd[3];
	char   trade_date[30]; 
	double trade_price;				//委托价格
	double trade_quantity;			//委托数量
	double trade_value;
	char   real_type;
	char   real_status;				//状态
	int	   entrust_id;
	char   fund_account[30];
	char   original_trade_id[30];
	char   original_entrust_id[30];
	char   OrderRef[13];
}ST_RECORD_INFO;

//期货成交查询
typedef struct tagIFTradeInfo
{	
	int    trade_id;               //成交号
	char   position_type;          //仓位类型
	char   issue_cd[30];           //系统代码
	char   trans_code[20];         //业务类型 FU_B_OPEN/FU_S_OPEN/FU_B_OFF/FU_S_OFF
	char   direction;              //买卖方向 B/S
	char   offset_flag;			   //开平 0/1
	char   hedge_flag;             //套利
	char   currency_cd[3];
	char   trade_date[30];         //成交日期时间
	double trade_price;            //成交价格
	double trade_quantity;         //成交数量
	double trade_value;
	char   real_type;
	char   real_status;
	int    entrust_id;
}IF_TRADE_INFO;

//期货成交查询[前置机]
typedef struct tagIFPcTradeInfo
{	
	char mobile[16];

	char   issue_cd[30];           //系统代码
	char   OrderRef[13];
	char   ExchangeID[9];
	char   TradeID[21];
	char   direction;              //买卖方向 B/S
	char   OrderSysID[21];
	char   ParticipantID[11];
	char   ClientID[11];
	char   TradingRole;
	char   ExchangeInstID[31];
	char   offset_flag;			   //开平 0/1
	char   hedge_flag;             //套利
	double trade_price;            //成交价格
	double trade_quantity;         //成交数量
	char   TradeDate[9];
	char   TradeTime[9];
	char   TradeType;
	char   PriceSource;
	char   TraderID[21];
	char   OrderLocalID[13];
	char   ClearingPartID[11];
	char   BusinessUnit[21];
	int    SequenceNo;
	char   TradingDay[9];
	int    SettlementID;
	int    BrokerOrderSeq;
	char   TradeSource;
}IF_PC_TRADE_INFO;

//期货条件单查询
typedef struct tagIFStopPnlInfo
{	
	int    cond_entrust_id;		   //条件单号
	int    with_entrust_id;        //对应委托号
	char   pz_account[30];
	char   position_type;          //仓位类型
	char   issue_cd[30];           //系统代码
	char   direction;              //买卖方向 B/S
	double entrust_quantity;       //委托数量
	char   base_price_type[20];
	double base_price;
	int    stop_loss_spread;
	double stop_loss_price;
	int    stop_profit_spread;
	double stop_profit_price;
	char   trigger_price_type[20];
	char   off_price_type[20];
	char   effective_type[20];
	char   cond_entrust_status;
	int    entrust_id;
}IF_STOP_PNL_INFO;

//股票仓位查询[前置机]
typedef struct tagSTPcPositionInfo
{	
	char position_type;         //仓位类型 1、3
	char issue_cd[32];			//证券代码
	char security_type[8];
	char currency_cd[3];
	char ls;                    //买卖方向 'L':买 'S':卖
	double quantity;			//剩余数量
	double quantity_can_use;	//可用数量
	double real_open_amount;	//今开数量
	double real_off_amount;		//今平数量
	double cost_balance;		//成本金额
	double keep_cost_price;		//成本价
	int Position;               //总仓位=quantity
	int OpenVolume;             //开仓量
	int CloseVolume;			//平仓量
	double OpenAmount;			//开仓金额
	double CloseAmount;			//平仓金额
	double PositionCost;        //持仓成本
	double OpenCost;            //开仓成本
	int TodayPosition;          //今日持仓
}ST_PC_POSITION_INFO;

//期货仓位查询[前置机]
typedef struct tagIFPcPositionDetailInfo
{	
	char mobile[16];

	char   issue_cd[30];           //系统代码
	char   hedge_flag;
	char   direction;              //买卖方向 B/S
	char   open_date[30];          //2015-09-28 13:57:44
	char   TradeID[21];
	double quantity;
	double trans_price2;
	char   TradingDay[9];
	int    SettlementID;
	char   TradeType;
	char   ExchangeID[9];
	double CloseProfitByDate;
	double CloseProfitByTrade;
	double PositionProfitByDate;
	double PositionProfitByTrade;
	double Margin;
	double ExchMargin;
	double MarginRateByMoney;
	double MarginRateByVolume;
	double LastSettlementPrice;
	double SettlementPrice;
	int    CloseVolume;
	double CloseAmount;
}IF_PC_POSITION_DETAIL_INFO;

typedef struct tagMEFuMarginRate
{ 
	char instrument_id[30];		
	char investor_range;       
	char hedge_flag;        
	double long_margin_ratio_by_money;		
	double long_margin_ratio_by_volume;
	double short_margin_ratio_by_money;
	double short_margin_ratio_by_volume;
	int is_relative;
}ME_FU_MARGIN_RATE;

typedef struct tagMEFuCommissionRate
{
	char instrument_id[30];		
	char investor_range;              
	double open_ratio_by_money;		
	double open_ratio_by_volume;
	double close_ratio_by_money;
	double close_ratio_by_volume;
	double close_today_ratio_by_money;
	double close_today_ratio_by_volume;
}ME_FU_COMMISSION_RATE;
//-------------------------------------------------------------------------------------------------

//5、获取基础信息（和账户无关）【datatype=5】
typedef struct tagBaseInfo
{
	/*请求信息id 1--配资套餐参数  2--证券列表  3--单个证券信息 4--账户排名
	*/
	int requestid;			 
	char issue_cd[16];		//系统代码 requestid=3时有效

	char reserve[128];		//预留
}APP_BASE_INFO;

typedef struct tagMEPackage
{
	int sequence_no;            
	char cycle_type[20];		//周期
	int cycle_value_from;       //值起
	int cycle_value_to;         //值止
	int leverage;				//杠杆
	int amount_value_from;		//值起
	int amount_value_to;		//值止
	int amount_increasing;		//递增金额
	char charging_mode[20];		//计费方式
	double charging_rate;		//计费标准
	char charging_unit[20];		//计费单位
	char charging_method[20];	//扣费方式
	char first_experience_flag; //新手体验标志 0:非新手 1:新手
}ME_PACKAGE;

typedef struct tagSecMaster
{
	char issue_cd[16];				//系统代码
	char symbol[16];				//挂牌代码
	char security_short_name[16];	//证券简称
	char exchange_cd[8];			//交易所
	char security_type[8];			//证券类型
	char market[20];				//市场
}SEC_MASTER;

typedef struct tagMasterFu
{
	char issue_cd[30];				//系统代码
	char symbol[30];				//挂牌代码
	char exchange_cd[8];			//交易所
	char issue_name[20];			//期货简称
	char currency_cd[3];			//货币类型
	char country_cd[2];				//货币类型
	char security_type[8];			//期货类型
	char fu_product_id[30];
	char fu_product_class;
	int delivery_year;
	int delivery_month;
	int max_market_order_volume;
	int min_market_order_volume;
	int max_limit_order_volume;
	int min_limit_order_volume;
	int volume_multiple;			//合约乘数
	double price_tick;
	char create_date[8];
	char open_date[30];
	char expire_date[30];
	char start_deliv_date[30];
	char end_deliv_date[30];
	char inst_life_phase;
	int is_trading;
	char ctp_position_type;
	char position_date_type;
	double long_margin_ratio;
	double short_margin_ratio;
	char max_margin_side_algorithm;
	char underlying_instr_id[30];
	double strike_price;
	char options_type;
	double underlying_multiple;
	char combination_type;
}MASTER_FU;

typedef struct tagAccountRoe
{
	char mobile[16];
	char member_nickname[40];	 //昵称
	double roe;                  //净资产收益率
}ACCOUNT_ROE;
//-------------------------------------------------------

//6、申请配资请求【datatype=6】
typedef struct tagMERequest
{
	int member_id;

	char mobile[16];
	char pzaccount[32];				//融资账号
//	char password[64];				//登录密码
	bool first_experience_flag;		//初次体验标志
	double initial_margin;			//初始占用保证金
	int initial_leverage;			//杠杆比例
	double lending_rate;			//利率
	double contract_value;			//配资额度
	int term;						//期限
	double total_interest_and_fee;	//利息
	double stock_rate;				//股票融资占比 如：1.0 --100%股票（股票：期货的比例。不开通期货默认为100：0，开通期货默认为30：70。）

	char initial_cycle;             //期限单位

	char reserve[128];		//预留
}APP_ME_REQUEST;

//-------------------------------------------------------
//7、配资订单生成【datatype=7】
typedef struct tagMEOrder
{
	int member_id;

	char mobile[16];
	char pzaccount[32];		//融资账号
	long long order_num;	//配资订单号
	double pay_sum;			//需要支付的总额    微信支付
	double pay_actural;		//使用账户支付的额度 可抵金额

	char ticket_num[13];	//使用代金券编号
	double ticket_use_sum;	//代金券实际使用金额

	char reserve[128];		//预留
}APP_ME_ORDER;

//-------------------------------------------------------
//8、配资订单（包含单纯充值）【datatype=8】
typedef struct tagMEPay
{
	int member_id;

	char mobile[16];
	char pzaccount[32];				//融资账号
	long long order_num;			//order_num>0 -- 配资订单号；
	bool order_valid;				//配资订单（true--订单生效；false--订单作废）
	double actural_pay_sum;			//配资订单实际支付金额

	char reserve[128];		//预留
}APP_ME_PAY;

//配资请求统一回报【datatype=6 7 8】
typedef struct tagMERequestReply
{
	int success;			//0-成功

	long long order_num;	//配资订单号
}APP_ME_REQUEST_REPLY;

//12、自选股 datatype=12
typedef struct tagSelfSelection
{
	int requestid;                  //1.添加 2.删除

    int member_id;
	char mobile[16];
	char symbol[16];				//证券代码

	char reserve[128];			    //预留 
}APP_SELF_SELECTION;

//13、减配 datatype=13
typedef struct tagReducePosition
{
    int member_id;

	char       mobile[16];
	long long    debt_id;           //合约号
	double     reduceCash;          //减配金额

	char reserve[128];			    //预留 
}APP_REDUCE_POSITION;

//14、展期 datatype=14
typedef struct tagDelayDay
{
    int member_id;

	char       mobile[16];
	long long    debt_id;           //合约号

	char reserve[128];			    //预留 
}APP_DELAY_DAY;
//-------------------------------------------------------

//15、入金【datatype=15】
typedef struct tagPushMoney
{
    int member_id;

	char mobile[16];
	char password[64];				//登录密码
	char pzaccount[32];				//账号
	double operate_amount;			//入金金额
	char ticket_num[13];	        //使用代金券编号
	double ticket_use_sum;	        //代金券实际使用金额
	double pay_cash;                //现金支付额度
	double stock_future_proportion;	//股票:1 期货:0

	char reserve[128];			//预留
}APP_PUSH_MONEY;

//16、入金确认【datatype=16】
typedef struct tagPushMoneyPay
{
    int member_id;

	char mobile[16];
	char pzaccount[32];				//融资账号
	long long order_num;			//order_num>0 -- 订单号；
	bool order_valid;				//订单（true--订单生效；false--订单作废）
	double actural_pay_sum;			//订单实际支付金额

	char reserve[128];		//预留
}APP_PUSH_MONEY_PAY;

//入金请求返回数据结构定义【datatype=15 16】
typedef struct tagPUSHRequestReply
{
	int success;			    //0-成功

	long long order_num;		//入金订单号
}APP_PUSH_REQUEST_REPLY;

//17、出金【datatype=17】
typedef struct tagDrawMoney
{
    int member_id;

	char mobile[16];
	char password[64];				//登录密码
//	bool bOperateSuccess;			//出金是否成功
	double operate_amount;			//出金金额
    double stock_future_proportion;	//股票:1 期货:0

	char reserve[128];			//预留
}APP_DRAW_MONEY;

//18、用户退出【datatype=18】
typedef struct tagUserExit
{
	int requestid;                    //1.正常退出 2.超时退出

    int member_id;
	char mobile[16];

	char reserve[128];			//预留
}APP_USER_EXIT;

//19、配资订单撤销【datatype=19】
typedef struct tagMEPayCancle
{
    int member_id;

	char mobile[16];
	long long order_num;				//order_num>0 -- 配资订单号；

	char reserve[128];		//预留
}APP_ME_PAY_CANCLE;

//20、配资订单查询【datatype=20】
typedef struct tagMEPayFind
{
    int member_id;

	char mobile[16];
	long long order_num;				//order_num>0 -- 配资订单号；

	char reserve[128];		//预留
}APP_ME_PAY_FIND;

typedef struct tagMEFindRequest
{
	int success;			        //0-成功

    long long order_num;			//order_num>0 -- 配资订单号；
    double dcash;                   //资金余额
	double initial_margin;			//初始占用保证金
	int initial_leverage;			//杠杆比例
	char initial_cycle;             //期限单位
	int initial_term;				//期限
	double lending_rate;			//利率
    double contract_value;			//配资额度
	double total_interest_and_fee;	//利息
    double paid_margin_from_asset;  //可抵金额使用
    double used_coupon;             //代金券
    double paid_cash;               //微信支付
	char debt_status;               //合约状态
	char debt_type[20];             //合约类型
}ME_FIND_REQUEST;

//21、账户条件变量【datatype=21】
typedef struct tagMEAccountSet
{
	int requestid;			     //请求 1--默认是否展期 2--默认买卖量

	int member_id;

	char mobile[16];
	char is_auto_renewal;        //默认是否展期 '0':不展期 '1':展期

	char fast_trade_b_option;    //买类型 '0':未设置 '1':按百分比 '2':按数量
	double default_buy_percent;  //默认买百分比
	int default_buy_amount;      //默认买数量
	char fast_trade_s_option;    //卖类型 '0':未设置 '1':按百分比 '2':按数量
	double default_sell_percent; //默认卖百分比
    int default_sell_amount;     //默认卖数量
    
	char reserve[128];		//预留
}APP_ME_ACCOUNT_SET;

//22、我的设置【datatype=22】
typedef struct tagMemberInfoSet
{
    int member_id;
	char mobile[16];
	char key[32];
	char values[512];

	char reserve[128];		//预留
}APP_MEMBER_INFO_SET;

//23、指定股票持仓【datatype=23】
typedef struct tagSinglePosition
{
    int member_id;
	char mobile[16];
    char SecurityCode[32];	//证券代码

	char reserve[128];		//预留
}APP_SINGLE_POSITION;

typedef struct tagMESinglePositionRequest
{
	int success;			        //0-成功
	SECURITY_POSITION field;
}ME_SINGLE_POSITION_REQUEST;

//24、邮箱设置【datatype=24】
typedef struct tagMailSet
{
	int requestid;			//请求 1--设置状态 2--回复是否有未读邮件

    int member_id;
	char mobile[16];
	char seq_id[512];	    //邮件号 1:12:33

	char reserve[128];		//预留
}APP_MAIL_SET;

typedef struct tagMEMailStatusResponse
{
	int success;			//0-成功
	int requestid;          //1设置状态 -2--回复是否有未读邮件
	char mail_status;       //'0'--有未读 '1'--无未读
}ME_MAIL_STATUS_RESPONSE;

//25、资产表现查询【datatype=25】
typedef struct tagMEShareRef
{
    int member_id;
	char mobile[16];

	char reserve[128];		//预留
}APP_ME_SHARE_REF;

//资产表现查询定义
typedef struct tagDailyShareInfo
{	
	char   asofdate[30];           //日期
	double nav;                    //净值
}DAILY_SHARE_INFO;

//资产表现信息返回结构定义：
typedef struct tagUsrShareResponse
{
	char   success;		           //0-成功

	char   registered_date[30];   //开始日期 YYYY-MM-DD
	double recent_nav;            //最近净值
	double recent_drawdown;       //最近回撤
	char member_nickname[40];	  //昵称

	int num;	                  //资产表现数量
	//+num个DAILY_SHARE_INFO
}APP_SHARE_RESPONSE;

//26、支付信息设置【datatype=26】
typedef struct tagEbatongSet
{
	int requestid;			//请求 1--add 2--delete

	int member_id;
	char mobile[16];
	char customer_id[64];   
	char real_name[64];
	char cert_no[64];
	char cert_type[2];  
	char card_no[64];             //卡号
	char bank_code[18];           //银行号

	char reserve[128];		//预留
}APP_EBATONG_SET;

//┍───────┯───────────┯─────────┑
//│页面委托属性  ┃沪市				  │深市              │
//├───────┼───────────┼─────────┥
//│限价          │S1：限价委托		  │S1：限价委托      │
//├───────┼───────────┼─────────┥
//│市价		  │SS3：五档即成转限价	  │SZ2：对方最优价格 │
//┖───────┸───────────┴─────────┙

//监控接口定义 ME<-->Monitor-------------------------------------------------------------------------
//报警信息结构定义【datatype=60001】
typedef struct tagAlarm
{
	int nAlarmType;			//报警类型 1-子账户担保比例 2-负债 3-单个股票市值 4-创业板市值 5-资金账户担保比例
	int nAlarmLevel;		//报警级别 0：红牌报警（最严重） 1：预警1级 2：预警2级 3：预警3级（最轻） -1：无级别

	char account[32];		//账号

	double dblThreshhold;	//报警阀值
	double dblAlarmValue;	//触发报警的当前值
	int nAlarmDate;			//报警日期 YYYYMMDD
	int nAlarmTime;			//报警时间 HHMMSS
}ME_ALARM;

//报警解除信息结构定义【datatype=60002】
typedef struct tagAlarmCancel
{
	int nAlarmType;			//报警类型 1-子账户担保比例 2-负债 3-单个股票市值 4-创业板市值 5-资金账户担保比例

	char account[32];		//账号

	int nAlarmDate;			//报警日期 YYYYMMDD
	int nAlarmTime;			//报警时间 HHMMSS
}ME_ALARM_CANCEL;

typedef struct tagAssetMonitor
{	
	double dSetoff;			//可抵金额
	double dMargin;			//保证金
	double dAsset;			//总资产
	double dNetAsset;		//净资产
	double dDebt;			//负债
	double dMakretValue;	//总市值
	double dCash;			//现金
	double dblDrawableCash;	//可提现金额
	double dWarrantRate;	//担保比率
	double dAvaiableCash;	//可用金额（用于买股票等）

	double dMaxMarketValue1;	//最大股票市值
	double dMaxMarketValue2;	//最大期货市值【废弃!】

	double dWarningLine;	    //预警线
	double dCloseLine;      	//平仓线
	double dRiskDegree;         //风险度
}USR_ASSET_MON;

//监控终端资产结构定义【datatype=60003】
typedef struct tagMonitorAsset
{
	char account[32];		//账号

	USR_ASSET_MON asset_mon;
}MON_ASSET;

//请求帐户信息结构定义 【datatype=60004】
typedef struct tagMonitorRequest
{
	/*1:仓位 2.合约 3.资金流水 4.子账当日交易 5.子账历史交易 
	6.子账当日委托 7.子账历史委托 8.子账当日条件单 9.子账资产
	10.子帐合计资产*/
	int requestid;			

	char account[32];		//账号
	char start_date[30];    //开始日期 2015-03-19 00:00:00
	char end_date[30];      //结束日期 9999-12-31 23:59:59 默认
}MON_REQUEST;

//监控终端证券仓位结构定义
typedef struct tagMonitorSecurityInfo
{	
	char account[32];		    //+账号
	char position_type;         //+仓位类型 1、3
	char issue_cd[32];			//证券代码
	char ls;                    //+买卖方向 'L':买 'S':卖
	double quantity;			//证券总数量
	double quantity_can_use;	//证券可卖数量
	double real_open_amount;	//今买数量
	double real_off_amount;		//今卖数量
	double cost_balance;		//成本金额
	double keep_cost_price;		//成本价
	double last_price;			//最新价

	char HedgeFlag;             //+投保
	double UseMargin;           //+占用保证金
	double PositionCost;        //+持仓成本
	double OpenCost;            //+开仓成本
	int TodayPosition;          //+今日持仓
}MON_SECUTIRY_INFO;

//监控终端账户合约定义
typedef struct tagDebtEx
{	
	char account[32];		       //+账号
	long long    debt_id;          //合约号
	char   debt_type[20];          //合约类型
	char   contract_date[30];      //合约日期 YYYY-MM-DD
	double initial_leverage;       //杠杆
	
	double contract_value;         //融资合约金额
	char   maturity_date[30];      //到期日
	double total_interest_and_fee; //费用
	double paid_principal;         //还款金额
	char   last_maturity_date[30]; //展期前到期日
	int    renewal_times;          //展期次数
	char   debt_status;            //合约状态

	double initial_margin;         //保证金
	double lending_rate;           //利率
	char   fund_account[30];       //配资账户
	int    initial_term;           //初始期限

	double stock_future_proportion;//股票:1 期货:0
}SECUTIRY_DEBT_EX;

//监控终端账户资金流水定义
typedef struct tagJournalEx
{	
	char account[32];		       //+账号
	int    journal_id;             //流水号
	char   position_type;          //仓位类型
	char   issue_cd[30];           //系统代码
	char   trans_code[20];         //业务类型 CASH_IN/CASH_OUT/PZ_FEE/buy/sell
	char   trans_date[30];         //成交日期
	double trans_price2;           //成交价格
	double trans_quantity;         //成交数量
	double trans_value;            //发生金额
	double commission;             //佣金
	double stamp_duty;             //印花税
	double transfer_fee;           //过户费
	double settlement_fee;         //结算费
	char   original_journal_id[30];//原始流水号
}SECUTIRY_JOURNAL_EX;

typedef struct tagIFTradingRecordInfo
{	
	char account[32];		       //+账号
	int    trade_id;               //成交号
	char   position_type;          //仓位类型
	char   issue_cd[30];           //系统代码
	char   trans_code[20];         //业务类型 FU_B_OPEN/FU_S_OPEN/FU_B_OFF/FU_S_OFF
	char   direction;              //+买卖方向 B/S
	char   offset_flag;			   //+开平 0/1
	char   hedge_flag;             //+套利
	char   currency_cd[3];		   //+
	char   trade_date[30];         //成交日期时间
	double trade_price;            //成交价格
	double trade_quantity;         //成交数量
	double trade_value;
	char   real_type;              //+
	char   real_status;
	int    entrust_id;
}TRADING_RECORD_INFO;

//监控终端子账委托单定义
typedef struct tagTradingEntrustInfo
{	
	int    entrust_id;             //委托号
	char   position_type;          //仓位类型
	char   issue_cd[30];           //系统代码
	char   trans_code[20];         //业务类型 buy/sell
	char   entrust_date[30];       //委托日期时间
	char   entrust_prop[20];       //委托属性
	double entrust_price;          //委托价格
	double entrust_quantity;       //委托数量
	double trade_price;            //成交价格
	double trade_quantity;         //成交数量
	char   entrust_status;         //状态
}TRADING_ENTRUST_INFO;

//监控终端子账条件单定义
typedef struct tagTradingCondEntrustInfo
{	
	int    cond_entrust_id;        //委托号
	char   position_type;          //仓位类型
	char   issue_cd[30];           //系统代码
	char   trans_code[20];         //业务类型 buy/sell
	char   entrust_date[30];       //条件委托日期时间
	char   entrust_prop[20];       //条件委托属性
	double trigger_price;          //触发价格
	double entrust_price;          //委托价格
	double entrust_quantity;       //委托数量
	char   cond_entrust_status;    //状态
}TRADING_COND_ENTRUST_INFO;

typedef struct tagMonitorAssetEx
{
	char account[32];		//账号

	double dSetoff;			//可抵金额
	double dMargin;			//保证金
	double dAsset;			//总资产
	double dNetAsset;		//净资产
	double dDebt;			//负债
	double dMakretValue;	//总市值
	double dCash;			//现金
	double dblDrawableCash;	//可提现金额
	double dWarrantRate;	//担保比率
	double dAvaiableCash;	//可用金额（用于买股票等）

	double dMaxMarketValue1;	//最大股票市值
	double dMaxMarketValue2;	//最大期货市值【废弃!】

	double dWarningLine;	    //预警线
	double dCloseLine;      	//平仓线
	double dRiskDegree;         //风险度
}USR_MONITOR_ASSET_EX;

typedef struct tagMonitorIFAsset
{
	char account[32];		//账号

	FUTURE_ASSET field;
}USR_MONITOR_IF_ASSET;

//COMMON_ASSET

//子帐合计资产
typedef struct tagMonitorCommonAsset
{
	char account[32];		//账号

	COMMON_ASSET field;
}USR_MONITOR_COMMON_ASSET;

//监控终端黑名单请求结构定义 【datatype=60005】
typedef struct tagBlackListRequest
{
	int requestid;              //操作类型1.find_current 2.find_his 3.add 4.remove 

	char issue_cd[30];		    //证券代码
    char add_date[30];          //开始日期 2015-03-19 12:40:03
	char remove_date[30];    	//结束日期 9999-12-31 23:59:59 默认
    unsigned char reason[20];   //原因   linux 20
    char last_update_user[20];  //操作员 
}MON_BLACK_LIST_REQUEST;

typedef struct tagCurrentBlackList
{	
	char issue_cd[30];		    //证券代码
	char sec_blacklist_type[20];
	char add_date[30];          //开始日期 2015-03-19 12:40:03
	char remove_date[30];    	//结束日期 9999-12-31 23:59:59 默认
	unsigned char reason[40];   //原因   linux 20*2
}CURRENT_BLACK_LIST;

typedef struct tagHisBlackList
{	
	char issue_cd[30];		    //证券代码
	char sec_blacklist_type[20];
	char bl_set_type[20];       //操作方向 add/remove
	char bl_set_date[30];       //add/remove日期 2015-03-19 12:40:03
	unsigned char reason[40];   //原因   linux 20*2
	char last_update_time[30];  //操作时间
	char last_update_user[20];  //操作员 
}HIS_BLACK_LIST;

//配资套餐【datatype=60006】
typedef struct tagPzSetMealRequest
{
	int requestid;              //操作类型1.find 2.add 3.update 4.delete 

	int sequence_no;            
	char cycle_type[20];		//周期
	int cycle_value_from;       //值起
	int cycle_value_to;         //值止
	int leverage;				//杠杆
	int amount_value_from;		//值起
	int amount_value_to;		//值止
	int amount_increasing;		//递增金额
	char charging_mode[20];		//计费方式
	double charging_rate;		//计费标准
	char charging_unit[20];		//计费单位
	char charging_method[20];	//扣费方式
	char first_experience_flag; //新手体验标志 0:非新手 1:新手
	char last_update_user[20];  //操作员 
}MON_PZ_SET_MEAL_REQUEST;

typedef struct tagSetMealInfo
{	
	int sequence_no;            
	char cycle_type[20];		//周期
	int cycle_value_from;       //值起
	int cycle_value_to;         //值止
	int leverage;				//杠杆
	int amount_value_from;		//值起
	int amount_value_to;		//值止
	int amount_increasing;		//递增金额
	char charging_mode[20];		//计费方式
	double charging_rate;		//计费标准
	char charging_unit[20];		//计费单位
	char charging_method[20];	//扣费方式
	char first_experience_flag; //新手体验标志 0:非新手 1:新手
	char status;                //状态
	char last_update_user[20];  //操作员 
}SET_MEAL_INFO;

//获取股票信息（和账户无关）【datatype=60007】
typedef struct tagStockRequest
{
	int requestid;			//请求信息id 1--证券列表 2--删除 3--修改 4--新增

	char issue_cd[30];				         //证券编号
	char symbol[22];				         //证券代码
	char security_eng_short_name[40];		 //证券名称
	char security_eng_long_name[120];		 //证券名称
	unsigned char security_short_name[30];	         //证券名称
	unsigned char security_long_name[80];	         //证券名称
	char exchange_cd[7];			         //交易所
	char currency_cd[3];			         //货币
	char country_cd[2];			             //国家
	char security_type[8];			         //证券类型
	char market[20];				         //市场
	double issue_size;			             //发行数量
	double issue_price;			             //价格
	double face_value;			             //面值
	char face_value_currency_cd[3];			 //计量货币
	char issue_date[30];                     //发行日 YYYY-MM-DD
	char listing_date[30];                   //上市日 YYYY-MM-DD
	char initial_listing_date[30];           //首发上市日 YYYY-MM-DD
	char delisting_date[30];                 //摘牌日期 YYYY-MM-DD
	char last_corporate_action_code[20];     //最近公司行为
	char last_corporate_action_date[30];     //最近公司行为日期 YYYY-MM-DD
	char reserve[128];		//预留
}APP_STOCK_REQUEST;


typedef struct tagMonitorStockInfo
{
	char issue_cd[30];				         //证券编号
	char symbol[22];				         //证券代码
	char security_eng_short_name[40];		 //证券名称
	char security_eng_long_name[120];		 //证券名称
	unsigned char security_short_name[60];	         //证券名称 linux 30*2
	unsigned char security_long_name[160];	         //证券名称 linux 80*2
	char exchange_cd[7];			         //交易所
	char currency_cd[3];			         //货币
	char country_cd[2];			             //国家
	char security_type[8];			         //证券类型
	char market[20];				         //市场
	double issue_size;			             //发行数量
	double issue_price;			             //价格
	double face_value;			             //面值
	char face_value_currency_cd[3];			 //计量货币
	char issue_date[30];                     //发行日 YYYY-MM-DD
	char listing_date[30];                   //上市日 YYYY-MM-DD
	char initial_listing_date[30];           //首发上市日 YYYY-MM-DD
	char delisting_date[30];                 //摘牌日期 YYYY-MM-DD
	char last_corporate_action_code[20];     //最近公司行为
	char last_corporate_action_date[30];     //最近公司行为日期 YYYY-MM-DD
}MONITOR_STOCK_INFO;

//获取账户信息【datatype=60008】
typedef struct tagPzaccountRequest
{
	int requestid;			  //请求信息id 1--账户信息 2--账户冻结 3--账户解冻 4--账户平仓 5--账户修改 6--账户解冻2

    char account[32];		  //账号
	char commission_type[20]; //费率(5--账户修改)
	double pz_credit_line;
	char reserve[128];		  //预留
}APP_PZACCOUNT_REQUEST;


typedef struct tagMonitorPzaccountInfo
{
	int member_id;
	char pz_account[30];		       //账户
	char pz_account_group[30];		   //账户组
	char pz_account_type[20];	       //账户类型
	char pz_open_date[30];             //YYYY-MM-DD
	int pz_account_level;			   
	double pz_credit_line;			   
	char pz_account_status;            //账户状态
	char commission_type[20];	       //费率
	unsigned char pz_account_name[80]; //linux 40*2
}MONITOR_PZACCOUNT_INFO;

//创建用户【datatype=60009】
typedef struct tagUserRegister
{
    int requestid;	//1-用户注册 2-修改密码 3-修改用户信息 4-用户登录 5-用户登出 6-获取用户信息 7-删除用户 8-查询在线用户 9-强制登出 10-解除锁定

	char user_id[20];
    unsigned char user_name[50];
	char password[16];
    char newpassword[16];
	char user_role_cd[20];
	char user_phone[20];
	char user_email[50];
	char login_ip[20];
	char user_status[20]; //+

	char reserve[128];		//预留
}MON_USER_REGISTER;

typedef struct tagMonitorUserInfo
{
	char user_id[20];
    unsigned char user_name[100]; //linux 50*2
    char user_role_cd[20];
	char user_phone[20];
	char user_email[50];
	char user_status[20]; //+
}MONITOR_USER_INFO;

typedef struct tagMonitorCurUserInfo
{
	char user_id[20];
	unsigned char user_name[100]; //linux 50*2
	char user_role_cd[20];
	char user_phone[20];
	char user_email[50];
	char login_time[30];
	char login_ip[20];
}MONITOR_CUR_USER_INFO;

typedef struct tagMonUserLoginRep
{
	int success;			//0-成功
	int requestid;          //4-用户登录 9-强制登出
	char user_id[20];
}MON_USER_LOGIN_REP;
//数据字典和券商信息【datatype=60010】
typedef struct tagPzCodeRequest
{
	int requestid;			//请求信息id 1--code 2--broker 3--counter 4--broker_server 5--broker

	char reserve[128];		//预留
}APP_PZCODE_REQUEST;

typedef struct tagMonitorPzCodeInfo
{
	char code[20];		    //编码
	char code_type[20];		//编码类型
	unsigned char code_name[80];	    //编码名称 linux 40*2
	int display_order;      //账户状态
}MONITOR_PZCODE_INFO;

typedef struct tagMonitorBrokerInfo
{
	char broker_id[20];		            
	unsigned char broker_name[80];	    //linux 40*2
	char broker_status;
	unsigned char comments[160];	    //linux 80*2
}MONITOR_BROKER_INFO;

typedef struct tagMonitorCounterInfo
{
	char counter_cd[20];		            
	unsigned char counter_name[80];	       //linux 40*2
	unsigned char counter_developer[80];   //linux 40*2
	char counter_status;
	unsigned char comments[160];	       //linux 80*2
}MONITOR_COUNTER_INFO;

typedef struct tagMonBrokerServerInfo
{
	char broker_id[20];						//经纪公司账号
	char counter_cd[20];			        //柜台
	unsigned char server_farm_name[80];		//linux 40*2	
	char trade_ip1[30];		     
	char trade_ip2[30];			 
	char trade_ip3[30];			
	char market_ip1[30];		
	char market_ip2[30];		
	char market_ip3[30];		
	char broker_server_status;		
	unsigned char comments[160];			//linux 80*2
	char default_flag;
}MON_BROKER_SERVER_INFO;

//经济商操作【datatype=60011】
typedef struct tagBrokerOpRequest
{
	int requestid;			//请求信息id 1--add 2--update 3--delete

	char broker_id[20];		            
	unsigned char broker_name[40];
	char broker_status;
	unsigned char comments[80];

	char reserve[128];		//预留
}BROKER_OP_REQUEST;

//经济商服务操作【datatype=60012】
typedef struct tagBrokerServerOpRequest
{
	int requestid;			//请求信息id 1--add 2--update 3--delete

	char broker_id[20];						//经纪公司账号
	char counter_cd[20];			        //柜台
	unsigned char server_farm_name[40];
	char trade_ip1[30];		     
	char trade_ip2[30];			 
	char trade_ip3[30];			
	char market_ip1[30];		
	char market_ip2[30];		
	char market_ip3[30];		
	char broker_server_status;		
	unsigned char comments[80];
	char default_flag;

	char reserve[128];		//预留
}BROKER_SERVER_OP_REQUEST;

//账组【datatype=60013】
typedef struct tagAccountGroup
{
	int requestid;	//1-新增账组 2-修改账组 3-删除账组 4-账组信息 5-账组信息2

	char pz_account_group[30];
	unsigned char pz_account_group_name[40];
	char pz_account_group_type[20];
	char pz_account_group_status;
	char last_update_user[20];

	char reserve[128];		//预留
}APP_ACCOUNT_GROUP;

typedef struct tagMonitorGroupInfo
{
	char pz_account_group[30];
	unsigned char pz_account_group_name[80];  //40*2
	char pz_account_group_type[20];
	char pz_account_group_status;
	char last_update_user[20];
}MONITOR_GROUP_INFO;

//会员信息【datatype=60014】
typedef struct tagMemberRequest
{
	int requestid;			//请求信息id 1--获取会员信息 2--会员信息修改

	int member_id;          //会员id

	char mobile_phone[11];         
	unsigned char member_name[40];
	char email[40];
	unsigned char occupation[20];
	char last_update_user[20];

	char reserve[128];		//预留
}APP_MEMBER_REQUEST;

typedef struct tagMonitorMemberInfo
{
	int member_id;                 //会员id
	char mobile_phone[11];         
	unsigned char member_name[80];          //40*2
	unsigned char member_nickname[80];      //40*2
	char registered_date[30];      //日期 YYYY-MM-DD
	char identity_card[18];
	char verified_date_id[30];     //日期 YYYY-MM-DD
	char email[40];
	char verified_date_e[30];      //日期 YYYY-MM-DD
	char gender[20];
	char birthday[30];
	char education[20];
	char region[20];
	unsigned char occupation[40];           //linux 20*2
	unsigned char contact_address[160];     //linux 80*2
	char member_status;

}MONITOR_MEMBER_INFO;

//指定账组信息【datatype=60015】
typedef struct tagGroupRequest
{
	char dGroup[32];		//帐组
	int requestid;			//请求信息id 1--资产 2--持仓(仅返回) 3--账组资金流水

	char start_date[30];    //开始日期 2015-03-19 12:40:03
	char end_date[30];      //结束日期 9999-12-31 23:59:59 默认
	char reserve[128];		//预留
}APP_GROUP_REQUEST;

//帐组资产信息
typedef struct tagMonitorGroupAssetEx
{
	char dGroup[32];		//帐组

	double dSetoff;			//可抵金额
	double dMargin;			//保证金
	double dAsset;			//总资产
	double dNetAsset;		//净资产
	double dDebt;			//负债
	double dMakretValue;	//总市值
	double dCash;			//现金
	double dblDrawableCash;	//可提现金额
	double dAvaiableCash;	//可用金额（用于买股票等）

	double dDebtToday;      //今借出资金
	int    dAccoutNum;      //子账户数目
    int    dAccoutNumToday; //今开户数目
}USR_MONITOR_GROUP_ASSET_EX;

//帐组仓位信息
typedef struct tagGroupInfo
{	
	char SecurityCode[32];		//证券代码

	double quantity;			//证券总数量
	double quantity_can_use;	//证券可卖数量
	double real_open_amount;	//今买数量
	double real_off_amount;		//今卖数量


	double last_price;			//最新价
}MON_GROUP_INFO;

//账组资金流水
typedef struct tagJournalGroup
{	
    char pz_account[32];		    //账户
	SECUTIRY_JOURNAL_EX sp;         //子帐结构
}SECUTIRY_JOURNAL_GROUP;

//创建角色【datatype=60016】
typedef struct tagUserRole
{
    int requestid;	//1-获取角色 2-新增角色 3-修改角色 4-删除角色
	char user_role_cd[20];
	unsigned char code_name[20];
    unsigned char user_role_desc[80];
	char is_sys_role;
	char management_terminal;
	char trade_terminal;
	int user_role_class;

	char reserve[128];		//预留
}APP_USER_ROLE;

typedef struct tagMonitorUserRoleInfo
{
	char user_role_cd[20];
    unsigned char code_name[40];        //linux 20*2
    unsigned char user_role_desc[160];  //linux 80*2
	char is_sys_role;
	char management_terminal;
	char trade_terminal;
	int user_role_class;

}MONITOR_USER_ROLE_INFO;

//资金账户【datatype=60017】
typedef struct tagFundAccount
{
	/*1-获取 2-新增 3-修改基础信息 4-删除[未用] 
	5-获取2 6-分配资金 7-新增[一对一] 8-分配资金[一对一]*/
	int requestid;	

	char fund_account[30];                //investor_id.broker_id
	char investor_id[20];                 //fund_account 原
	char broker_id[20];
	char fund_password[16];
	char fund_account_type[20];			  //资产类别 '1':股票 '3':期货
	unsigned char fund_name[40];
	char counter_cd[20];                  //柜台
	char open_date[30];                   //开户日期
	char investment_type[20];             //投资类型 主动管理/配资
	char risk_control_type[20];			  //风控类型 事前风控/Y型风控
	char fund_account_status;             //账户状态
	unsigned char comments[80];			  //备注
	char last_update_user[20];			  //6
										  //fund_pz_amount_t
	double cash;                          //调整资产6
	char currency_cd[3];				  //币种6
	double min_amount_remain;			  //最少保留资产6
	double amount_can_use;                //获取资金账户可调整资产

	char asofdate[30];                    //fund_asset_adjust
	double initial_net_asset_value;
	char structured_flag;
	double priority_amount;
	double posterior_amount;

	char product_id[30];                  //product_fund_account

	char reserve[128];		  //预留
}APP_FUND_ACCOUNT;

typedef struct tagMonitorFundAccountInfo
{
	char fund_account[30];              //investor_id.broker_id
	char investor_id[20];               //fund_account 原
	char broker_id[20];
	char fund_password[16];
	char fund_account_type[20];
    unsigned char fund_name[80];        //linux 40*2
	char counter_cd[20];
	char open_date[30];
	char investment_type[20];
	char risk_control_type[20];
	char fund_account_status;
    unsigned char comments[160];        //linux 80*2
	char last_update_user[20];

	double cash;                        //fund_pz_amount_t
	char currency_cd[3];                //币种
	double min_amount_remain;
	double amount_can_use;              //获取资金账户可调整资产

	char asofdate[30];                  //fund_asset_adjust
	double initial_net_asset_value;
	char structured_flag;
	double priority_amount;
	double posterior_amount;

	char product_id[30];                //product_fund_account
}MONITOR_FUND_ACCOUNT_INFO;

//指定资金账户信息【datatype=60018】
typedef struct tagFundAccountRequest
{
	/*请求信息id 1--合约汇总 2--合约明细 [1/2无效]
	3--资产 4--持仓 5--当日成交 6--历史成交 7--资金流水
	8--委托*/
	int requestid;			    

	char fund_account[32];		//资金账户

	int start_date;
	int end_date;
	char reserve[128];		//预留
}APP_FUND_ACCOUNT_REQUEST;

//资金账户合约汇总
typedef struct tagMonFundAccDebtTotal
{
	char fund_account[32];	//资金账户

    char currency_cd[3];    //币种
	double dCashTotal;		//资金总额
	int    dDebtNum;		//合约数量
	double dHasQuota;		//已配额度(负债)
	double interest_fee;    //费用
	double dCanQuate;		//可配额度
	char near_max_date[30]; //最近到期日期 2015-03-19 12:40:03
	char far_max_date[30];  //最远到期日期 9999-12-31 23:59:59 默认

}USR_MON_FUND_ACC_DEBT_TOTAL;

//资金账户合约明细
typedef struct tagFundAccountDebt
{	
	SECUTIRY_DEBT_EX sp;            //子帐结构
}SECUTIRY_FUND_ACCOUNT_DEBT;

//股票资产记录
typedef struct tagMonitorFundInfo {
	char brokerId[16];			        //经纪公司账号
	char accountId[16];					//资金账号
	double asset;						//总资产
	double marketValue;					//股票市值
	double balance;						//资金余额
	double available;					//可用资金
	double withdraw;					//可取资金
	double todayBuyAmount;				//当日买入金额									 
	double todaySellAmount;				//当日卖出金额					
	char currency_cd[3];			    //币值类型， 1-人民币CNY 2-美元USD 3-港币HKD
}USR_MONITOR_FUND_INFO;

//期货资产记录
typedef struct tagMonIFFundInfo
{
	char BrokerID[11];
	char InvestorID[13];

	double dStaticRight;				//静态权益
	double dCloseProfit;				//平仓盈亏 
	double dPositionProfit;				//持仓盈亏
	double dDynamicRight;				//动态权益
	double dMargin;						//占用保证金
	double dFrozenMargin;				//冻结保证金
	double dFrozenCommission;			//冻结手续费
	double dCommission;					//手续费
	double dPreReserve;					//上次结算准备金
	double dWithdrawSum;				//出金
	double dDepositSum;					//入金
	double dFallbackCash;				//保底资金
	double dblDrawableCash;				//可取资金
	double dAvaiableSum;				//可用资金
}USR_MON_IFFUND_INFO;

//股票仓位记录
typedef struct tagMonitorFundPosition
{
	char brokerId[16];			        //经纪公司账号
	char accountId[16];					//资金账号
	int exchangeId;						//交易所代码 1:上交所 2:深交所
	char symbol[16];					//证券代码
	int volume;							//持仓数量
	int availableVolume;				//可用数量
	int yesterdayVolume;				//昨仓
	double costPrice;					//成本价格
	double lastPrice;					//最新价
	double marketValue;					//证券市值
	double floatProfit;					//浮动盈亏
}USR_MONITOR_FUND_POSITION;

//期货仓位记录
typedef struct tagMonIFFundPosition
{
	char BrokerID[11];
	char InvestorID[13];
	char issue_cd[32];			//证券代码
	char ls;                    //+买卖方向 '2':买 '3':卖
	double quantity;			//证券总数量
	double quantity_can_use;	//证券可卖数量(Nothing)
	double real_open_amount;	//今买数量
	double real_off_amount;		//今卖数量
	double last_price;			//最新价

	char HedgeFlag;             //+投保
	double UseMargin;           //+占用保证金
	double PositionCost;        //+持仓成本
	double OpenCost;            //+开仓成本
	int TodayPosition;          //+今日持仓
	double PositionProfit;		//++持仓盈亏
}USR_MON_IF_FUND_POSITION;

//股票交易记录
typedef struct tagMonitorFundTrade
{
	char BrokerID[11];
	char InvestorID[13];
	char OrderRef[13];
	char TradeDate[30];		//成交日期，格式：20150205
	char TradeTime[30];		//成交时间，格式：10:12:12
	char symbol[16];		//证券代码
	int direction;			//1:买 2:卖
	int volume;				//成交数量
	double price;			//成交价格
	double amount;			//成交金额
	char orderId[30];		//交易所返回的委托编号
	int exchangeId;			//交易所代码 1:上交所 2:深交所
	char tradeId[30];		//成交号
	char Position[30];		//成交位置
}USR_MONITOR_FUND_TRADE;

//期货交易记录
typedef struct tagMonIFFundTrade
{
	char BrokerID[11];
	char InvestorID[13];
	char position_type;     //仓位类型
	char InstrumentID[31];	//合约代码
	char ExchangeID[9];     //交易所代码
	char TradeID[21];		//成交号 
	char OrderRef[13];		//下单号
	char OrderSysID[21];	//交易所返回的委托编号
	char Direction;			//方向：'0'-买入 '1'-卖出
	char OffsetFlag;        //开平标志 '0'-开仓 '!0'-平仓
	char HedgeFlag;			//投机套保标志
	char TradeDate[9];      //成交日期
	char TradeTime[9];		//成交时间
	double price;			//成交价格
	int volume;			    //成交数量
}USR_MON_IFFUND_TRADE;

//股票资金流水
typedef struct tagMonitorFundJournal
{
	char BrokerID[11];
	char InvestorID[13];
	double ChangeAmount;					//变动金额
	double reserveValue;					//余额 
	char holderId[30];						//股东账号
	int exchangeId;							//交易所代码 1:上交所 2:深交所
	char symbol[16];						//证券代码
	int direction;							//方向：1-买入 2-卖出
	int tradeVolume;						//成交数量
	double tradePrice;						//成交价格
	char tradeId[30];						//成交号
	char flowId[20];						//流水号
	char abstractType[12];					//摘要类别
	char orderId[30];						//交易所返回的委托编号
	char currency_cd[3];					//币值类型 1-人民币CNY 2-美元USD 3-港币HKD
	char TradeDate[30];						//成交日期，格式：20150205
	char TradeTime[30];						//成交时间，格式：10:12:12
	double tradeValue;						//成交金额
	double commission;						//佣金
	double transferFee;						//过户费
	double stampTax;						//印花税
	double otherFee;						//其他费用
	unsigned char business_abstract[64];	//业务摘要   linux 32*2
}USR_MONITOR_FUND_JOURNAL;

//股票委托单
typedef struct tagMonitorFundOrder
{
	char BrokerID[11];
	char InvestorID[13];
	char OrderRef[13];		//报单引用
	char SessionId[30];		//会话编号
	char symbol[16];		//证券代码
	int exchangeId;			//交易所代码 1:上交所 2:深交所
	int direction;			//方向：1-买入 2-卖出
	int priceType;			//报价方式
	double price;			//委托价格
	int volume;				//委托数量
	int orderWay;			//委托方式
	int businessId;			//业务类型
	int AcceptedVolume;		//接受数量
	int FrozenVolume;		//冻结数量
	double FrozenAmount;	//冻结金额
	int TradeVolume;		//交易数量
	char orderId[30];		//交易所返回的委托编号
	char InsertDate[30];	//委托日期，格式：20150205
	char InsertTime[30];	//委托时间，格式：10:12:12
	int status;				//委托状态
}USR_MONITOR_FUND_ORDER;

//期货委托单
typedef struct tagMonIFFundOrder
{
	char	InstrumentID[31];			//合约代码
	char	OrderRef[13];				//报单引用
	char    OrderPriceType;				//报单价格条件+
	char    Direction;                  //买卖方向
	char    CombOffsetFlag[5];			//组合开平标志
	char    CombHedgeFlag[5];           //组合投机套保标志
	double  LimitPrice;                 //价格
	int     VolumeTotalOriginal;        //数量
	char    TimeCondition;				//有效期类型
	char    GTDDate[9];					//GTD日期
	char    VolumeCondition;			//成交量类型
	int     MinVolume;					//最小成交量
	char    ContingentCondition;		//触发条件
	double  StopPrice;					//止损价
	char    ForceCloseReason;			//强平原因
	int     IsAutoSuspend;				//自动挂起标志
	char    BusinessUnit[21];			//业务单元
	char    OrderSubmitStatus;			//报单提交状态
	char    OrderStatus;				//报单状态
	int		RequestID;					//请求编号	
	char	OrderLocalID[13];			//本地报单编号	
	char	ExchangeID[9];				//交易所代码	
	char	ParticipantID[11];			//会员代码	
	char	ClientID[11];				//客户代码	
	char	ExchangeInstID[31];			//合约在交易所的代码	
	char	TraderID[21];				//交易所交易员代码	
	int		InstallID;					//安装编号	
	int		NotifySequence;				//报单提示序号	
	char	TradingDay[9];				//交易日	
	int		SettlementID;				//结算编号	
	char	OrderSysID[21];				//报单编号	
	char	OrderSource;				//报单来源	
	char	OrderType;					//报单类型	
	int		VolumeTraded;				//今成交数量	
	int		VolumeTotal;				//剩余数量	
	char	InsertDate[9];				//报单日期	
	char	InsertTime[9];				//委托时间	
	char	ActiveTime[9];				//激活时间	
	char	SuspendTime[9];				//挂起时间	
	char	UpdateTime[9];				//最后修改时间	
	char	CancelTime[9];				//撤销时间	
	char	ActiveTraderID[21];			//最后修改交易所交易员代码	
	char	ClearingPartID[11];			//结算会员编号
	int		SequenceNo;					//序号	
	char	StatusMsg[81];				//状态信息	
	int		UserForceClose;				//用户强评标志	
	char	ActiveUserID[16];			//操作用户代码	
	int		BrokerOrderSeq;				//经纪公司报单编号	
	char	RelativeOrderSysID[21];		//相关报单	
	int		ZCETotalTradedVolume;		//郑商所成交数量
	int		IsSwapOrder;				//互换单标志
	char	UserProductInfo[11];		//+来源
}USR_MON_IFFUND_ORDER;

//资金表现信息【datatype=60019】
typedef struct tagFundReportRequest
{
	int requestid;			    //请求信息id 1--表现

	char fund_account[32];		//资金账户
	char start_date[30];        //开始日期 1900-01-01
	char end_date[30];          //结束日期 9999-12-31

	char reserve[128];		    //预留
}APP_FUND_REPORT_REQUEST;

typedef struct tagMonitorFundReport
{
	char fund_account[32];	//资金账户
	char asofdate[30];      //最近到期日期 2015-03-19
	char currency_cd[3];	//币值类型 1-人民币CNY 2-美元USD 3-港币HKD
	double cash;			//+
	double cash_can_use;	//+
	double market_value;			
	double total_assets_value;
	double other_assets_value; //+
	double total_liabilities_value;		
	double net_assets_value;			
	double margin_debt_count;			
	double margin_debt_amout;	
	double new_margin_debt_count;			
	double new_margin_debt_amout;			
	double interest_income;	
	double delta_commission_income;			
	double margin_amount;			
	double new_margin_amount;			
	double nav;	
	double warning_line;			
	double close_line;	
	double risk_degree;			
}USR_MONITOR_FUND_REPORT;

//获取所有功能模块【datatype=60020】
typedef struct tagUiModuleRequest
{
	int requestid;			//请求信息id 1--获取所有功能模块

	char reserve[128];		//预留
}APP_UI_MODULE_REQUEST;
	
typedef struct tagMonitorUiModuleInfo
{
	char ui_module_cd[8];
    unsigned char code_name[60];        //linux 30*2
    unsigned char description[112];     //linux 56*2
}MONITOR_UI_MODULE_INFO;

//功能模块【datatype=60021】
typedef struct tagRoleUiModule
{
	int requestid;	//1-获取 2-添加 3-删除 4-根据用户ID获取功能模块 5-获取2 
	char user_id[20];
	char user_role_cd[20];
	char ui_module_cd[8];

	char reserve[128];		//预留
}APP_ROLE_UI_MODULE;

typedef struct tagMonitorRoleUiModuleInfo
{
	char user_role_cd[20];
	char ui_module_cd[8];
}MONITOR_ROLE_UI_MODULE_INFO;

//用户账户设置【datatype=60022】
typedef struct tagUserPzModule
{
	int requestid;	//1-指定获取 2-添加 3-删除 4-全量获取
	char user_id[20];
	char pz_account[30];
	char pz_account_type[20];

	char reserve[128];		//预留
}APP_USER_PZ;

typedef struct tagMonitorUserPzInfo
{
	char user_id[20];
	char pz_account[30];
	char pz_account_type[20];
}MONITOR_USER_PZ_INFO;

//用户资金账户设置【datatype=60023】
typedef struct tagUserFundAcc
{
	int requestid;	//1-获取 2-添加 3-删除 4-获取2
	char user_id[20];
	char fund_account[30];
	char account_type[20];

	char reserve[128];		//预留
}APP_USER_FUND_ACC;

typedef struct tagMonitorUserFundInfo
{
	char user_id[20];
	char fund_account[30];
	char account_type[20];
}MONITOR_USER_FUND_INFO;

//账户风控参数【datatype=60024】
typedef struct tagRiskRuleItem
{
	int requestid;	//1-获取所有参数列表 2-获取风控规则列表 3-新增风控规则 4-删除

	char rc_rule[20];
	unsigned char description[48];
	unsigned char comments[255];
    char last_update_user[20];

	char reserve[128];		//预留
}APP_RISK_RULE_ITEM;

typedef struct tagMonitorRiskControlInfo
{
	char item_code[20];
	char item_type[20];
	int item_class;
	unsigned char description[96];        //linux 48*2
	unsigned char comments[510];          //linux 255*2
}MONITOR_RISK_CONTROL_INFO;

typedef struct tagMonitorRcRuleInfo
{
	char rc_rule[20];
	unsigned char description[96];        //linux 48*2
	unsigned char comments[510];          //linux 255*2
    char last_update_user[20];
}MONITOR_RC_RULE_INFO;

//指定规则下合规参数设置【datatype=60025】
typedef struct tagRcRuleItem
{
	int requestid;	//1-获取 2-修改

	char rc_rule[20];
	char item_code[20];
	char const_code[30];
	char constant_value[38];
	char alert_level1[38];
	char alert_level2[38];
	char alert_level3[38];
	char item_status;
	int priority;

	char reserve[128];		//预留
}APP_RC_RULE_ITEM;

typedef struct tagMonitorRcRuleItemInfo
{
	char rc_rule[20];

	char item_code[20];
	char const_code[30];
	char constant_value[38];
	char alert_level1[38];
	char alert_level2[38];
	char alert_level3[38];
	char item_status;
	int priority;
}MONITOR_RC_RULE_ITEM_INFO;

//关联账组和风控规则【datatype=60026】
typedef struct tagRcGroupRule
{
    int requestid;	//1-关联账组和风控规则(add/update) 2-获取账组关联规则

	char pz_account_group[30];
	char rc_rule[20];

	char reserve[128];		//预留
}APP_RC_GROUP_RULE;

typedef struct tagMonitorRcGroupRuleInfo
{
    char pz_account_group[30];
	char rc_rule[20];
}MONITOR_RC_GROUP_RULE_INFO;

//资金账户风控参数【datatype=60027】
typedef struct tagFundRiskRuleItem
{
	int requestid;	//1-获取所有参数列表 2-获取风控规则列表 3-新增风控规则 4-删除

	char f_rc_rule[20];
	unsigned char description[48];
	unsigned char comments[255];
	char last_update_user[20];

	char reserve[128];		//预留
}APP_FUND_RISK_RULE_ITEM;

typedef struct tagMonFundRiskControlInfo
{
	char item_code[20];
	char item_type[20];
	int item_class;
	unsigned char description[96];        //linux 48*2
	unsigned char comments[510];          //linux 255*2
}MON_FUND_RISK_CONTROL_INFO;

typedef struct tagMonFundRcRuleInfo
{
	char f_rc_rule[20];
	unsigned char description[96];        //linux 48*2
	unsigned char comments[510];          //linux 255*2
	char last_update_user[20];
}MON_FUND_RC_RULE_INFO;

//指定规则下合规参数设置【datatype=60028】
typedef struct tagFundRcRuleItem
{
	int requestid;	//1-获取 2-修改

	char f_rc_rule[20];
	char item_code[20];
	char const_code[30];
	char constant_value[38];
	char alert_level1[38];
	char alert_level2[38];
	char alert_level3[38];
	char item_status;
	int priority;

	char reserve[128];		//预留
}APP_FUND_RC_RULE_ITEM;

typedef struct tagMonFundRcRuleItemInfo
{
	char f_rc_rule[20];

	char item_code[20];
	char const_code[30];
	char constant_value[38];
	char alert_level1[38];
	char alert_level2[38];
	char alert_level3[38];
	char item_status;
	int priority;
}MON_FUND_RC_RULE_ITEM_INFO;

//关联账组和风控规则【datatype=60029】
typedef struct tagFundRcGroupRule
{
	int requestid;	//1-关联账组和风控规则(add/update) 2-获取账组关联规则

	char fund_account_group[30];
	char f_rc_rule[20];

	char reserve[128];		//预留
}APP_FUND_RC_GROUP_RULE;

typedef struct tagMonFundRcGroupRuleInfo
{
	char fund_account_group[30];
	char f_rc_rule[20];
}MON_FUND_RC_GROUP_RULE_INFO;

//获取子账合规预警【datatype=60030】
typedef struct tagRcAlertJournalRequest
{
	int requestid;		     //1--子账合规预警信息

	char start_date[30];    //开始日期 2015-03-19 12:40:03
	char end_date[30];      //结束日期 9999-12-31 23:59:59 默认
	char reserve[128];		//预留
}APP_RC_ALERT_JOURNAL_REQUEST;

//子账合规预警信息
typedef struct tagRcAlertJournalInfo
{	
	int sequence_no;		
	char pz_account[30];
	char item_code[20];
	char const_code[30];
	char alert_date[30];    //日期 2015-03-19 12:40:03
	char alert_level[38];
	char alert_level_value[38];
    char actual_value[38];
}MON_RC_ALERT_JOURNAL_INFO;

//获取证券除权信息（和账户无关）【datatype=60031】
typedef struct tagXDRightRequest
{
	int requestid;			//请求信息id 1--新增证券除权 2--修改 3--删除 4--获取 
							//5--获取未处理 6--获取时间段 7获取指定股票时间段

	char issue_cd[30];				             //证券编号
	char ex_dividend_date[30];                   //除权除息日 YYYY-MM-DD	6/7 begin_date
	char declaration_date[30];                   //公告日期 YYYY-MM-DD	6/7 end_date
	char record_date[30];                        //股权登记日 YYYY-MM-DD
	char stk_div_flag;                           //'0' false '1' true
	char div_flag;
	char reverse_stk_flag;
	char allot_flag;
	double stock_splits_per10;			         //红股
	double reverse_stock_splits_per10;			 //缩股
	char xr_listing_date[30];                    //送转股上市日 YYYY-MM-DD
	double div_cash_per10_pre_tax;			     //红利（含税）
	double div_cash_per10_after_tax;			 //红利（税后）
	char currency_cd[3];				         //分红货币
	char payment_date[30];                       //派息日 YYYY-MM-DD
	double allotment_per10;			             //配股
	double allotment_price;			             //配股价
	double total_allotment_amount;			     //实际配股数
	char allotment_listing_date[30];             //获配股份上市日 YYYY-MM-DD
	unsigned char comments[20];                  //备注说明
	char stk_div_status;                           
	char stk_listing_status;
	char div_status;
	char reverse_stk_status;
	char allot_status;
	char xd_status;                              //状态

	char reserve[128];		//预留
}APP_XDRIGHT_REQUEST;

typedef struct tagMonitorXDRightInfo
{
	char issue_cd[30];				             //证券编号
	char ex_dividend_date[30];                   //除权除息日 YYYY-MM-DD
	char declaration_date[30];                   //公告日期 YYYY-MM-DD
	char record_date[30];                        //股权登记日 YYYY-MM-DD
	char stk_div_flag;                           //'0' false '1' true
	char div_flag;
	char reverse_stk_flag;
	char allot_flag;
	double stock_splits_per10;			         //红股
	double reverse_stock_splits_per10;			 //缩股
	char xr_listing_date[30];                    //送转股上市日 YYYY-MM-DD
	double div_cash_per10_pre_tax;			     //红利（含税）
	double div_cash_per10_after_tax;			 //红利（税后）
	char currency_cd[3];				         //分红货币
	char payment_date[30];                       //派息日 YYYY-MM-DD
	double allotment_per10;			             //配股
	double allotment_price;			             //配股价
	double total_allotment_amount;			     //实际配股数
	char allotment_listing_date[30];             //获配股份上市日 YYYY-MM-DD
	unsigned char comments[40];                           //备注说明 linux 20*2
	char stk_div_status;                           
	char stk_listing_status;
	char div_status;
	char reverse_stk_status;
	char allot_status;
	char xd_status;                              //状态
}MONITOR_XDRIGHT_INFO;

//获取子帐和资金账户委托、成交【datatype=60032】
typedef struct tagMonitorReconcileReq
{
	int requestid;			//1:子帐委托 2.资金账户委托 3.子帐成交 4.资金账户成交

	char reserve[128];		//预留
}MON_RECONCILE_REQUEST;

//监控终端委托单定义
typedef struct tagReconcileEntrustInfo
{	
	int    entrust_id;             //委托号
	char   account[30];            //子帐、资金账户
	char   position_type;          //仓位类型
	char   issue_cd[30];           //系统代码
	char   trans_code[20];         //业务类型 buy/sell
	char   direction;              //买卖方向
	char   entrust_date[30];       //委托日期时间
	char   entrust_prop[20];       //委托属性
	double entrust_price;          //委托价格
	double entrust_quantity;       //委托数量
	char   currency_cd[3];         //币种
	double trade_price;            //成交价格
	double trade_quantity;         //成交数量
	char   entrust_way;            //委托方式
	char   entrust_status;         //状态
	unsigned char cancle_info[40]; //linux 20*2
	double withdraw_amount;        
	char   original_entrust[30];   //原始委托号/OrderRef
	char   reconcile_flag;

	char   fund_account[30];       //资金账户【子帐有效】

	char   offset_flag;            //开平标志 '0'-开 '1'-平 '3'-平今+
	char   hedge_flag;			   //投保 '1'+
}RECONCILE_ENTRUST_INFO;

//监控终端交易定义
typedef struct tagReconcileRecordInfo
{	
	int    trade_id;               //成交号
	char   account[30];            //子帐、资金账户
	char   position_type;          //仓位类型
	char   issue_cd[30];           //系统代码
	char   trans_code[20];         //业务类型 buy/sell
	char   direction;              //买卖方向
	char   currency_cd[3];         //币种
	char   trade_date[30];         //成交日期时间
	double trade_price;            //成交价格
	double trade_quantity;         //成交数量
	double trade_value;            //成交金额
	char   real_type;
	char   real_status;            //状态
	int    entrust_id;             //委托号、资金账户委托号
	char   original_trade_id[30];
	char   original_entrust_id[30];//原始委托号
	char   reconcile_flag;

    char   fund_account[30];       //资金账户【子帐有效】

	char   offset_flag;            //开平标志 '0'-开 '1'-平 '3'-平今+
	char   hedge_flag;			   //投保 '1'+
}RECONCILE_RECORD_INFO;

//获取子帐委托修改【datatype=60033】
typedef struct tagMonitorEntrustOpReq
{
	int requestid;			//1.子帐委托新增 2.修改

	int    entrust_id;             //委托号
	char   account[30];            //子帐、资金账户
	char   position_type;          //仓位类型
	char   issue_cd[30];           //系统代码
	char   trans_code[20];         //业务类型 buy/sell
	char   direction;              //买卖方向
	char   entrust_date[30];       //委托日期时间
	char   entrust_prop[20];       //委托属性
	double entrust_price;          //委托价格
	double entrust_quantity;       //委托数量
	char   currency_cd[3];         //币种
	double trade_price;            //成交价格
	double trade_quantity;         //成交数量
	char   entrust_way;            //委托方式
	char   entrust_status;         //状态
	unsigned char cancle_info[20];
	double withdraw_amount;        
	char   original_entrust[30];   //原始委托号
	char   reconcile_flag;
	char   fund_account[30];       //资金账户【子帐有效】
	char   offset_flag;            //开平标志 '0'-开 '1'-平 '3'-平今+
	char   hedge_flag;			   //投保 '1'+

	char reserve[128];		//预留
}MON_ENTRUST_OP_REQUEST;

//获取子帐成交修改【datatype=60034】
typedef struct tagMonitorRecordOpReq
{
	int requestid;			//1.子帐成交新增 2.修改

	int    trade_id;               //成交号
	char   account[30];            //子帐、资金账户
	char   position_type;          //仓位类型
	char   issue_cd[30];           //系统代码
	char   trans_code[20];         //业务类型 buy/sell
	char   direction;              //买卖方向
	char   currency_cd[3];         //币种
	char   trade_date[30];         //成交日期时间
	double trade_price;            //成交价格
	double trade_quantity;         //成交数量
	double trade_value;            //成交金额
	char   real_type;
	char   real_status;            //状态
	int    entrust_id;             //委托号、资金账户委托号
	char   original_trade_id[30];
	char   original_entrust_id[30];//原始委托号
	char   reconcile_flag;
	char   fund_account[30];       //资金账户【子帐有效】
	char   offset_flag;            //开平标志 '0'-开 '1'-平 '3'-平今+
	char   hedge_flag;			   //投保 '1'+

	char reserve[128];		//预留
}MON_RECORD_OP_REQUEST;

//产品信息【datatype=60035】
typedef struct tagProductInfoReq
{
	/*请求信息id 1-获取 2-add 3-update[状态和说明] 4-delete[未用] 5-获取2
	6-资产调整 7-add[一对一]*/
	int requestid;			    

	char product_id[30];		//product_id
	char asofdate[30];          //日期 1900-01-01
	//pz_jy_fuanda.product_account                           
	char product_type[20];		//海正:'AM'，众期网:'IND'
	char product_symbol[30];
	unsigned char product_name[40];
	char open_date[30];
	char product_status;
	unsigned char comments[80];
	//pz_jy_fuanda.product_asset_adjust
	char currency_cd[3];
	double initial_net_asset_value;
	char structured_flag;
	double priority_amount;
	double priority_interest_rate;
	char priority_dated_date[30];
	double posterior_amount;
	double pp_proportion;
	double adjust_cash;
	
	char reserve[128];		    //预留
}APP_PRODUCT_INFO_REQ;

typedef struct tagMonProductInfoRep
{
	char product_id[30];		//product_id
	char asofdate[30];          //日期 1900-01-01
	char product_type[20];
	char product_symbol[30];
	unsigned char product_name[80];  //linux 40*2
	char open_date[30];
	char product_status;
	unsigned char comments[160];     //linux 80*2
	char currency_cd[3];
	double initial_net_asset_value;
	char structured_flag;
	double priority_amount;
	double priority_interest_rate;
	char priority_dated_date[30];
	double posterior_amount;
	double pp_proportion;	
	double usable_cash;				//+可分配资金
}USR_MON_PRODUCT_INFO_REP;

//子帐联系信息【datatype=60036】
typedef struct tagPzConnectAccountReq
{
	int requestid;			    //请求信息id 1--获取子帐资金账户 2--获取子帐产品
	//char product_id[30];		//product_id

	char reserve[128];		    //预留
}APP_PZ_CONNECT_ACCOUNT_REQ;

typedef struct tagMonFundAccountRep
{
	char pz_account[30];
	char position_type;
	char fund_account[30];		
}USR_MON_FUND_ACCOUNT_REP;

typedef struct tagMonProductAccountRep
{
	char product_id[30];
	char pz_account[30];	
}USR_MON_PRODUCT_ACCOUNT_REP;

//期货合约【datatype=60037】
typedef struct tagFutureRequest
{
	int requestid;			//请求信息id 1.期货合约 2.保证金率 3.费率 

	char reserve[128];		//预留
}APP_FUTURE_REQUEST;

typedef struct tagMonitorFutureInfo
{
	char issue_cd[30];				         //证券编号
	char symbol[30];				         //证券代码
	char exchange_cd[8];			         //交易所
	unsigned char issue_name[80];	         //证券名称 linux 20*2
	char currency_cd[3];			         //货币
	char country_cd[2];			             //国家
	char security_type[8];			         //证券类型
	char fu_product_id[30];				     
	char fu_product_class;				
	int delivery_year;			             
	int delivery_month;			             
	int max_market_order_volume;			 
	int min_market_order_volume;			 
	int max_limit_order_volume;			     
	int min_limit_order_volume;			     
	int volume_multiple;			         
	double price_tick;			             
	char create_date[8];			 
	char open_date[30];                  
	char expire_date[30];                
	char start_deliv_date[30];           
	char end_deliv_date[30];      
	//char inst_life_phase;
	//int is_trading;
	//char ctp_position_type;
	//char position_date_type;
	//double long_margin_ratio;
	//double short_margin_ratio;
	//char max_margin_side_algorithm;
	//char underlying_instr_id[30];
	//double strike_price;
	//char options_type;
	//double underlying_multiple;
	//char combination_type;
	//char strike_mode;
}MONITOR_FUTURE_INFO;

typedef struct tagMonFuMarginRate
{ 
	char instrument_id[30];	
	char asofdate[30];	
	char investor_range;
	char broker_id[20];
	char investor_id[30];     
	char hedge_flag;        
	double long_margin_ratio_by_money;		
	double long_margin_ratio_by_volume;
	double short_margin_ratio_by_money;
	double short_margin_ratio_by_volume;
	int is_relative;
}MON_FU_MARGIN_RATE;

typedef struct tagMonFuCommissionRate
{
	char instrument_id[30];
	char asofdate[30];		
	char investor_range;  
	char broker_id[20];
	char investor_id[30];            
	double open_ratio_by_money;		
	double open_ratio_by_volume;
	double close_ratio_by_money;
	double close_ratio_by_volume;
	double close_today_ratio_by_money;
	double close_today_ratio_by_volume;
}MON_FU_COMMISSION_RATE;

//监控子帐请求【datatype=60038】
typedef struct tagMonPzAccountReq
{
	int requestid;			//请求信息id 1--add 2--find 3--update 4--海证子帐注册

	char product_id[30];    //find用

	int member_id;          //update用
	char pz_account[30];	//update用

	char mobile[16];
	char password[64];
	unsigned char pz_account_name[40];  //子帐名称
	char pz_account_type[20];  //子帐类型
	char pz_open_date[30];     //开户日期 2015-09-08
	double pz_credit_line;     //信用额度
	char pz_account_status;    //子帐状态
	int  fund_num;
	char fund_account_type1;   //股票:'1' 期货:'3'
	char fund_accout1[30];
	char fund_account_type2;
	char fund_accout2[30];
	char fund_account_type3;
    char fund_accout3[30];		//预留资金账户

	char reserve[128];			//预留
}MONITOR_PZACCOUNT_REQ;

typedef struct tagMonProductPzAccReply
{
	int member_id;
	char pz_account[30];
	char mobile_phone[16];
	char login_password[64];
	unsigned char member_name[80];	     //linux 40*2
	char identity_card[18];
	char email[40];
	unsigned char comments[160];         //linux 80*2
	unsigned char pz_account_name[80];   //+子帐名称 linux 40*2
	char pz_account_type[20];            //子帐类型
	char pz_open_date[30];               //开户日期 2015-09-08
	char commission_type[20];            
	double pz_credit_line;               //信用额度
	char pz_account_status;              //子帐状态
	int  fund_num;
	char fund_account_type1;			 //股票:'1' 期货:'3'
	char fund_accout1[30];
	char fund_account_type2;
	char fund_accout2[30];
	char fund_account_type3;
    char fund_accout3[30];  //预留资金账户

}MON_PRODUCT_PZ_ACC_REPLY;

//联系人信息【datatype=60039】
typedef struct tagContactReq
{
	int requestid;			    //请求信息id 1-产品联系人 2-产品联系人更新 3-资金账户联系人 4-资金账户联系人更新

	char account[30];		    //product_id/fund_account

	int contact_num;            //1~4
	unsigned char contact_name[20];
	char contact_phone[20];
	char contact_mobile[11];
	unsigned char contack_desc[40];

	char reserve[128];		    //预留
}MON_CONTACT_REQ;

typedef struct tagContactRep
{
	char account[30];		//product_id/fund_account

	unsigned char contact1_name[40]; //linux 20*2
	char contact1_phone[20];
	char contact1_mobile[11];
	unsigned char contack1_desc[80]; //linux 40*2
	unsigned char contact2_name[40];
	char contact2_phone[20];
	char contact2_mobile[11];
	unsigned char contack2_desc[80];
	unsigned char contact3_name[40];
	char contact3_phone[20];
	char contact3_mobile[11];
	unsigned char contack3_desc[80];
	unsigned char contact4_name[40];
	char contact4_phone[20];
	char contact4_mobile[11];
	unsigned char contack4_desc[80];	
}USR_MON_CONTACT_REP;

//子帐资产分配【datatype=60040】
typedef struct tagMonAccAssetAdjustReq
{
	/*请求信息id 1--获取指定产品下子帐信息 2-子帐资产分配 */
	int requestid;			    

	char product_id[30];    //获取指定产品下子帐信息

	char fund_account[30];
	char pz_account[30];
	char position_type;          //仓位类型
	double adjust_cash;             
	double initial_net_asset_value;
	char structured_flag;
	double priority_amount;
	double posterior_amount;
	double pp_proportion;
	char last_update_user[20];			  

	char reserve[128];		    //预留
}MON_ACC_ASSET_ADJUST_REQ;

typedef struct tagMonProdAccInfoRep
{
	char fund_account[30];
	char pz_account[30];
	char asofdate[30];                   
	double initial_net_asset_value;
	char structured_flag;
	double priority_amount;
	double posterior_amount;
}USR_MON_PROD_ACC_INFO_REP;

//风控参数分类【datatype=60041】
typedef struct tagRiskCtrlDef
{
	int requestid;	//1-获取所有参数列表 2-获取风控子类

	char reserve[128];		//预留
}MON_RISK_CTRL_DEF;

typedef struct tagRiskCtrlDefInfo
{
	char item_category[20];
	unsigned char category_name[80];      //linux 40*2
	char pb_class_flag;
	char product_class_flag;
	char fund_class_flag;
	char sub_class_flag;
	char tr_flag;
	char in_flag;
	char cl_flag;
	unsigned char in_strategy[160];        //linux 80*2
	unsigned char description[160];        //linux 80*2
}MON_RISK_CTRL_DEF_INFO;

typedef struct tagRiskCtrlSubItem
{
	char item_category[20];
	char sub_item_code[20];
	char position_type;
	unsigned char description[160];        //linux 80*2
	char option1[20];
	char option2[20];
	char option3[20];
	char option4[20];
}MON_RISK_CTRL_SUB_ITEM;

//风控请求结构定义 【datatype=60042】
typedef struct tagRiskCtrlRuleReq
{
	/*操作类型1.find 2.add 3.rule_cur 4.rule_his 5.all_rule_cur 6.all_rule_his
	7.启用 8.暂停 9.update*/
	int requestid; 

	/* 1:黑白名单 2:个股持仓比例控制 3:个股成交量控制 4:净值比例
	5:反向交易控制 6:合约到期日 7:分档仓位限制 8:同类资产比例控制*/
	int  item_type;             
	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL
	char account_id[30];		//泛指product_id/fund_account/pz_account，"0"为全局 
	
	char start_date[30];        //开始日期 2015-03-19 12:40:03
	char end_date[30];    	    //结束日期 9999-12-31 23:59:59 默认
	unsigned char comments[80]; //原因   linux 80
	char rc_rule_status;        //启停状态 '1'未启用，'2'启用，'3'暂停，'4'停用 
	char set_type[20];          //操作方向 ADD/USE/BLOCK/STOP
	char last_update_user[20];  //操作员 
}MON_RISK_CTRL_RULE_REQ;

typedef struct tagBlackWhiteList
{	
	int rc_sequence_no;
	char item_code[20];
	char account_id[30];
	char position_type;
	char issue_cd[30];		    //证券代码
	char rc_sec_bw_list_type[20];
	char add_date[30];          //开始日期 2015-03-19 12:40:03
	char remove_date[30];    	//结束日期
	unsigned char reason[40];   //原因   linux 20*2
	char status;                //'0'启用 '1'暂停
}BLACK_WHITE_LIST;

typedef struct tagStockTradeList
{	
	int rc_sequence_no;
	char item_code[20];
	char account_id[30];
	char position_type;
	char comparison_direction;  //'G'大于 'L'小于
	double threshold_level1;
	char action_level1[20];     //FORBIDDEN ALERT2 ALERT3
	double threshold_level2;
	char action_level2[20];
	double threshold_level3;
	char action_level3[20];
	char status;                //'0'启用 '1'暂停
}STOCK_TRADE_LIST;

typedef struct tagNavRList
{	
	int rc_sequence_no;
	char item_code[20];
	char account_id[30];
	char position_type;
	char comparison_direction;  //'G'大于 'L'小于
	double threshold_level1;
	char action_level1[20];     //FORBIDDEN ALERT2 ALERT3
	double threshold_level2;
	char action_level2[20];
	double threshold_level3;
	char action_level3[20];
	char status;                //'0'启用 '1'暂停
}NAV_R_LIST;

typedef struct tagReversTradeList
{	
	int rc_sequence_no;
	char item_code[20];
	char account_id[30];
	char position_type;
	char add_date[30];          //开始日期 2015-03-19 12:40:03
	char remove_date[30];    	//结束日期
	char status;                //'0'启用 '1'暂停
}REVERS_TRADE_LIST;

typedef struct tagFuMaturityList
{	
	char issue_cd[30];
	char expire_date[30];       //到期日 2015-03-19
	char end_deliv_date[30];    //最后交割日
}FU_MATURITY_LIST;

typedef struct tagNavPosCtrlList
{	
	int rc_sequence_no;
	char item_code[20];
	char sub_item_code[20];
	char account_id[30];
	char position_type;
	double from_nav_ex;
	double to_nav_in;
	char comparison_direction;  //'G'大于 'L'小于
	double threshold_level1;
	char action_level1[20];     //FORBIDDEN ALERT2 ALERT3
	double threshold_level2;
	char action_level2[20];
	double threshold_level3;
	char action_level3[20];
	char status;                //'0'启用 '1'暂停
}NAV_POS_CTRL_LIST;

typedef struct tagAssetClassList
{	
	int rc_sequence_no;
	char item_code[20];
	char sub_item_code[20];
	char account_id[30];
	char position_type;
	char comparison_direction;  //'G'大于 'L'小于
	double threshold_level1;
	char action_level1[20];     //FORBIDDEN ALERT2 ALERT3
	double threshold_level2;
	char action_level2[20];
	double threshold_level3;
	char action_level3[20];
	char status;                //'0'启用 '1'暂停
}ASSET_CLASS_LIST;

typedef struct tagRuleCurList
{	
	int rc_sequence_no;
	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL
	char account_id[30];		//泛指product_id/fund_account/pz_account，"0"为全局 
	char start_date[30];        //开始日期 2015-03-19 12:40:03
	char end_date[30];    	    //结束日期
	unsigned char comments[160];//原因   linux 160
	char rc_rule_status;        //启停状态 1未启用，2启用，3暂停，4停用 
}RULE_CUR_LIST;

typedef struct tagRuleHisList
{	
	int sequence_no;
	int rc_sequence_no;
	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL
	char account_id[30];		//泛指product_id/fund_account/pz_account，"0"为全局 
	char set_type[20];          //操作方向 ADD/USE/BLOCK/STOP
	unsigned char comments[160];//原因   linux 160
}RULE_HIS_LIST;

//风控黑白名单请求结构定义 【datatype=60043】
typedef struct tagBNWRequest
{
	int requestid;              //操作类型1.save

	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL
	char account_id[30];		//泛指product_id/fund_account/pz_account，"0"为全局 

	char op;                    //'0':不操作 '1':添加 '2':移除
	char black_white_flag;      //'0':black '1':white
	char item_code[20];
	char position_type;
	char issue_cd[30];		    //证券代码
	char rc_sec_bw_list_type[20];
	char add_date[30];          //开始日期 2015-03-19 12:40:03
	char remove_date[30];    	//结束日期 9999-12-31 23:59:59 默认
	unsigned char reason[20];   //原因   linux 20
	char status;                //'0'启用 '1'暂停
	char last_update_user[20];  //操作员 
}MON_BNW_REQUEST;

//风控个股持仓比例/成交量请求结构定义 【datatype=60044】
typedef struct tagStockTradeRequest
{
	int requestid;              //操作类型1.save

	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL
	char account_id[30];		//泛指product_id/fund_account/pz_account，"0"为全局 

	char item_code[20];
	char position_type;
	char comparison_direction;  //'G'大于 'L'小于
	double threshold_level1;
	char action_level1[20];     //FORBIDDEN ALERT2 ALERT3
	double threshold_level2;
	char action_level2[20];
	double threshold_level3;
	char action_level3[20];
	char status;                //'0'启用 '1'暂停
	char last_update_user[20];  //操作员 
}STOCK_TRADE_REQUEST;

//风控净值比例请求结构定义 【datatype=60045】
typedef struct tagNavRRequest
{
	int requestid;              //操作类型1.save

	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL
	char account_id[30];		//泛指product_id/fund_account/pz_account，"0"为全局 

	char item_code[20];
	char position_type;
	char comparison_direction;  //'G'大于 'L'小于
	double threshold_level1;
	char action_level1[20];     //FORBIDDEN ALERT2 ALERT3
	double threshold_level2;
	char action_level2[20];
	double threshold_level3;
	char action_level3[20];
	char status;                //'0'启用 '1'暂停
	char last_update_user[20];  //操作员 
}NAV_R_REQUEST;

//反向交易控制请求结构定义 【datatype=60046】
typedef struct tagReversTradeRequest
{
	int requestid;              //操作类型1.save 2.delete主表一并删除

	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL

	char account_id[30];		//泛指product_id/fund_account/pz_account，"0"为全局 
	char item_code[20];
	char position_type;
	char add_date[30];          //开始日期 2015-03-19 12:40:03
	char remove_date[30];    	//结束日期 9999-12-31 23:59:59 默认
	char status;                //'0'启用 '1'暂停
	char last_update_user[20];  //操作员 
}REVERS_TRADE_REQUEST;

//到期合约控制请求结构定义 【datatype=60047】
typedef struct tagFuMaturityRequest
{
	int requestid;              //操作类型1.save

	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL

	char account_id[30];		//泛指product_id/fund_account/pz_account，"0"为全局 
	char item_code[20];
	char position_type;
	char start_date[30];        //开始日期 2015-03-19 12:40:03
	char end_date[30];    	    //结束日期 9999-12-31 23:59:59 默认
	char status;                //'0'启用 '1'暂停
	char last_update_user[20];  //操作员 
}FU_MATURITY_REQUEST;

//分档仓位限制请求结构定义 【datatype=60048】
typedef struct tagNavPosCtrlRequest
{
	int requestid;                  //操作类型1.save 2.delete

	//int  record_num;            

	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL
	char account_id[30];		//泛指product_id/fund_account/pz_account，"0"为全局 

	char item_code[20];
	char sub_item_code[20];
	char position_type;         //'0'全量 '1'股票 '3'期货
	double from_nav_ex;
	double to_nav_in;
	char comparison_direction;  //'G'大于 'L'小于
	double threshold_level1;
	char action_level1[20];     //FORBIDDEN ALERT2 ALERT3
	double threshold_level2;
	char action_level2[20];
	double threshold_level3;
	char action_level3[20];
	char status;                //'0'启用 '1'暂停
	char last_update_user[20];  //操作员 
}NAV_POS_CTRL_REQUEST;

//同类资产限制请求结构定义 【datatype=60049】
typedef struct tagAssetClassRequest
{
	int  requestid;             //操作类型1.save 2.delete

	//int  record_num;            

	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL
	char account_id[30];		//泛指product_id/fund_account/pz_account，"0"为全局 

	char item_code[20];
	char sub_item_code[20];
	char position_type;         //'0'全量 '1'股票 '3'期货
	char comparison_direction;  //'G'大于 'L'小于
	double threshold_level1;
	char action_level1[20];     //FORBIDDEN ALERT2 ALERT3
	double threshold_level2;
	char action_level2[20];
	double threshold_level3;
	char action_level3[20];
	char status;                //'0'启用 '1'暂停
	char last_update_user[20];  //操作员 
}ASSET_CLASS_REQUEST;

//指令风控信息请求结构定义 【datatype=60050】
typedef struct tagInstJrnalReq
{
	int requestid;             //1.in_check 2.tr_check 3.指令信息

	int entrust_inst_id;       //2使用
	int limit;                 //获取条数
	int offset;				   //第几条开始 1~
}INST_JRNAL_REQ;

typedef struct tagMonInCheckInfo
{
	int  sequence_no;
	char item_code[20];
	char sub_item_code[20];
	char account_id[30];			//泛指product_id/fund_account/pz_account，"0"为全局 
	char class_type[20];			//PB/PRODUCT/FUND/SUB
	char issue_cd[30];
	double check_value;
	double threshold_level;
	char action_level[20];			//FORBIDDEN ALERT2 ALERT3
	unsigned char other_info[160];	//linux 80*2

	int totalNum;
}MON_IN_CHECK_INFO;

typedef struct tagMonTrCheckInfo
{
	int  sequence_no;
	int  entrust_inst_id;			//指令编号	
	char item_code[20];
	char sub_item_code[20];
	char pz_account[30];
	char position_type;
	char issue_cd[30];
	char fund_account[30];
	char product_id[30];
	double check_value;
	double threshold_level;
	char action_level[20];			//FORBIDDEN ALERT2 ALERT3
	unsigned char other_info[160];	//linux 80*2
}MON_TR_CHECK_INFO;	

typedef struct tagMonInstInfo
{
	int	   entrust_inst_id;				//指令编号	

	char   pz_account[30];				//子账账号
	char   position_type;				//'1'股票 '3'期货
	char   issue_cd[30];				//合约代码
	char   product_id[30];
	char   work_flow_type[20];          //工作流
	char   from_user_id[20];			//指令来源
	char   order_type[20];				//交易类型：普通交易/算法交易 
	char   quote_type[20];				//报价方式：
	double single_over_price;			//单笔超价（%）
	//以下为算法交易独有-----
	char   single_quantity[20];			//单笔基准量
	double single_quantity_p;			//基准量比例
	double order_interval;				//下单间隔
	double withdraw_interval;			//撤单间隔
	int    over_price_order_amt;		//超价启用笔数
	double volatility_range;			//波动区间
	int    singe_min_volume;			//单笔最小量
	int    singe_max_volume;			//单笔最大量
	int    effective_time;				//有效时间
	int    max_entrust_num;				//最大委托次数
	//------
	char   trans_code[20];			    //BUY/SELL/FU_B_OPEN/FU_S_OPEN/FU_B_OFF/FU_S_OFF
	char   direction;					//方向：'B'-买 'S'-卖
	char   offset_flag;                 //'0'-开 '1'-平 '3'-平今
	char   hedge_flag;				    //'1' 
	char   entrust_prop[20];			//委托属性 限价、市价等 
	double entrust_inst_price;			//指令价格
	double entrust_inst_quantity;		//指令数量
	char   cond_entrust_type[20];		//条件单类型
	char   inst_start_date[30];			//指令开始时间
	char   currency_cd[3];				//货币类型 'CNY'人民币 'USD'美元 'HKD'港币

	double frozen_value;
	double frozen_fee;
	char   approve_user_id[20];
	char   trade_user_id[20];			//trade_user_id
	char   inst_end_date[30];
	double withdraw_amount;
	double trade_quantity;
	double frozen_quantity;
	char   entrust_inst_status;
	unsigned char cancel_info[160];		//linux 80*2
	char   entrust_inst_ref[40];
}MON_INST_INFO;

//用户和产品关系请求结构定义 【datatype=60051】
typedef struct tagUserProductReq
{
	/*操作类型1.save 2.find[key:user_id] 3.delete[key:user_id]
	4.find[key:product_id] 5.delete[key:product_id] 6.find
	*/
	int requestid;                     

	char user_id[20];
	char product_id[30];
	char account_type[20];		
	char last_update_user[20];  //操作员 
}USER_PRODUCT_REQ;

typedef struct tagUserProductRep
{
	char user_id[20];
	char product_id[30];
	char account_type[20];		
	char last_update_user[20];  //操作员 
}USER_PRODUCT_REP;

//产品信息请求结构定义 【datatype=60052】
typedef struct tagProductIdInfoReq
{
	/*请求信息id 1--资产 */
	int requestid;			    

	char product_id[30];		//产品id
}PRODUCT_ID_INFO_REQ;

typedef struct tagProductAssetsInfo
{
	double dDynamicRight;		//总资产
	double dMargin;			    //占用保证金
	double dFrozenMargin;	    //冻结保证金
	double dblDrawableCash;	    //可取资金
	double dAvaiableSum;	    //可用资金
	double market_value;		//证券总市值
	double dHasQuota;		    //负债
	double Nav;					//净值
	double Nav_A;				//A基金 净值
	double Nav_B;				//B基金 净值
}PRODUCT_ASSETS_INFO;

typedef struct tagMonProductIdAssets
{
	int success;				//0-成功
	int requestid;				//1-资产
	char product_id[30];		//产品id

	PRODUCT_ASSETS_INFO field;  //产品资产
}MON_PRODUCT_ID_ASSETS;

//子帐和用户关系请求结构定义 【datatype=60053】
typedef struct tagSubAccUserReq
{
	int requestid;				//操作类型1.save 2.find 3.delete

	char pz_account[30];		//子账账号
	char work_flow_type[20];	//"TR_1ROLE"/"TR_3ROLE" 
	char user_id[20];
}SUBACC_USER_REQ;

typedef struct tagSubAccUserRep
{
	char pz_account[30];		//子账账号
	char work_flow_type[20];	//"TR_1ROLE"/"TR_3ROLE" 
	char user_id[20];
}SUBACC_USER_REP;

//产品子帐和用户关系请求结构定义 【datatype=60054】
typedef struct tagPdSubAccUserReq
{
	int requestid;				//操作类型1.save 2.find 3.delete

	char product_id[30];		//产品id
	char work_flow_type[20];	//"TR_1ROLE"/"TR_3ROLE"
	char user_id[20];
	char user_role_cd[20];
}PD_SUBACC_USER_REQ;

typedef struct tagPdSubAccUserRep
{
	char product_id[30];		//产品id
	char work_flow_type[20];	//"TR_1ROLE"/"TR_3ROLE" 
	char user_id[20];
	char user_role_cd[20];
}PD_SUBACC_USER_REP;

//产品替他权益请求结构定义 【datatype=60055】
typedef struct tagProductEquityReq
{
	/*请求信息id 1--add 2--modify 3--delete 4--find*/
	int requestid;			    

	char product_id[30];		//产品id
	char asofdate[30];			//查询日期
	unsigned char equity_name[40];
	double equity_value;
	char last_update_user[20];  //操作员 

	char flag;                  //'0':默认子帐 '1':盈亏
}PRODUCT_EQUITY_REQ;

typedef struct tagProductEquityInfo
{
	char product_id[30];			//产品id
	char asofdate[30];
	unsigned char equity_name[80];	//权益名称 linux 40*2
	double equity_value;			//权益值
	char last_update_user[20];		//操作员 
}PRODUCT_EQUITY_INFO;

//到期日基准日请求结构定义 【datatype=60056】
typedef struct tagBaseDateReq
{
	int requestid;				//操作类型 1.find
}BASE_DATE_REQ;

typedef struct tagBaseDateRep
{
	char base_date_cd[20];
	char asofdate[30]; 
	char action_status;
	char last_date[30];
	char next_date[30];
}BASE_DATE_REP;

//期货合约行情请求结构定义 【datatype=60057】
typedef struct tagMarketDataFutureReq
{
	int requestid;				//操作类型 1.find

	char asofdate[30]; 
}MARKET_DATA_FUTURE_REQ;

//交易限制结构体定义  【datatype = 60058】
typedef struct tagTradeLimitReq
{
	int requestid; //1、find 2、update

	int abn_trans_no;
	char security_type[8];
	char exchange_cd[8];
	char abn_trans_item_cd[20];
	int threshold_level;
	char last_update_user[20];
}TRADE_LIMIT_REQ;

typedef struct tagTradeLimitRep
{
	char exchange_cd[8];
	int abn_trans_no;
	char security_type[8];
	char abn_trans_item_cd[20];
	int abn_trans_item_const;
	int abn_trans_item_spare1;
	double abn_trans_item_spare2;
	char description[128];
	int threshold_level;

}TRADE_LIMIT_REP;

typedef struct tagMarketDataFutureRep
{
	char issue_cd[30];
	char asofdate[30]; 
	char data_source[20];
	double pre_settlement_price;
	double pre_close_price;
	double pre_open_interest;
	double open_price;
	double highest_price;
	double lowest_price;
	int volume;
	double turnover;
	double open_interest;
	double close_price;
	double settlement_price;
	double upper_limit_price;
	double lower_limit_price;
	double pre_delta;
	double curr_delta;
	double average_price;
	char action_day[30];
	double net_change1;
	double net_change2;
	double oi_change;
	double deliv_settlement_price;
	double daily_return1;
	double daily_return2;
	char trade_status;
	char suspension;
}MARKET_DATA_FUTURE_REP;

//心跳消息(Datatype：999)
typedef struct tagMonitorHeartInfo
{
	int serverType;		//1：交易，2：行情，3：资管，4：Web
	int date;			//如：20150408
	int time;			//如：134550
}MONITOR_HEART_INFO;

//用户心跳消息
typedef struct tagUserLoginInfo
{
	char username[20];
	char loginIP[20];
}USER_LOGIN_INFO;
//--------------------------------------------------------------------------------------
//MD<-->资管 

//---------------------------------------------------------------------------------
//10、交易下单--买入【datatype=10】/卖出【datatype=11】
typedef struct tagStockTrade
{
	int member_id;
	char mobile[16];				
	int direction;					//方向：1-买入 2-卖出 3-请求最大可买数量
	char symbol[16];				//证券代码
	double quantity;				//数量
	int mode;						//下单模式：
									//1-限价委托
									//2-市价【深对手方最优价格委托】
									//3-市价【深本方最优价格委托】
									//4-市价【深即时成交剩余撤销委托】
									//5-市价【沪深最优五档并撤销委托】
									//6-市价【深全额成交或撤销委托】
									//7-市价【沪最优五档并转限价委托】
									//
									//
									//当日条件单：100-卖出止损【最新价低于触发价格卖出（转化为市价委托）】
									//长期条件单：101-卖出止损【最新价低于触发价格卖出（转化为市价委托）】
	double price;					//报价（市价委托时，APP提供涨停价）
	double condition_price;			//触发价格
	char UserProductInfo[11];		//+来源
//前置机新增
	char OrderRef[13];              //报单引用
}APP_BUY_SALE;

//交易下单返回结构定义 买入【datatype=10】/卖出【datatype=11】
typedef struct tagEntrustReply
{
	int success;

	APP_BUY_SALE field;	//备注：请求股票最大可买数量时,quantity最大可买数量
}APP_ENTRUST_REPLY;

//50、请求撤单数据结构定义【datatype=50】
typedef struct tagStockCancel
{
	int member_id;
	int EntrustID;					//下单号
	char mobile[16];
	int direction;					//方向：1-撤单（买入） 2-撤单（卖出） 3-撤单（条件单1） 4-一键平仓
	char symbol[16];				//合约号
}STOCK_CANCEL;

//返回结构定义【datatype=50】
typedef struct tagStockCancelReply
{
	int success;	//0-成功
	int nEntrustID;
}STOCK_CANCEL_REPLY;

//----------------------------------------------------------------------
//ME-->TS
//委托【datatype=201】 撤单【datatype=204】 交易员撤单【datatype=206】 
typedef struct tagEntrust
{
	int EntrustID;					//下单号
	char mobile[16];				//子帐pz_account
	int direction;					//方向：1-买入 2-卖出
	char symbol[16];				//证券代码
	double quantity;				//数量
	int mode;						//下单模式：
									//1-限价委托
									//2-市价【深对手方最优价格委托】
									//3-市价【深本方最优价格委托】
									//4-市价【深即时成交剩余撤销委托】
									//5-市价【沪深最优五档并撤销委托】
									//6-市价【深全额成交或撤销委托】
									//7-市价【沪最优五档并转限价委托】
	double price;					//报价（限价委托时有效）
}ME_ENTRUST;

//---------------------------------------------------------------------------
//--- public定义 ---

typedef struct tagSecPositionEx
{
	std::string position_type;
	std::string security_type;

	SECURITY_POSITION sp;
	double dNewestPrice;		//最新价
	double settled_quantity;	//上次结算准备金 +期货 2015/08/12
}SECURITY_POSITION_EX;

typedef struct tagMarginDebt
{
	double contract_value;
	double paid_principal;
	double initial_leverage;
	double margin;

	double accrued_interest;	//+应付利息 20150323
}ST_MARGIN_DEBT;


typedef struct tagMarginDebtTimer
{
	std::string account;	//账号

	long long llDebtID;		//合约号
	int maturity_date;		//合约到期日期 YYYYMMDD
	double contract_value;	//最初借钱合约金额
	double paid_principal;	//已经支付本金金额
	double lending_rate;	//利率
	int initial_term;		//展期期限（天数）
	bool bAutoExtend;		//自动展期标志

	double initial_leverage;
	double margin;
	double accrued_interest;	//+应付利息 20150323	

	std::string debt_type;	//PZTY-体验套餐 PZ-日/月套餐
	int contract_date;
	char initial_cycle;		//D-日套餐 M-月套餐
}MARGIN_DEBT_TIMER;

//证券仓位定义
typedef struct tagPositionTimer
{	
	char SecurityCode[32];		//证券代码

	std::string position_type;
	std::string security_type;

	double quantity;			//证券总数量
	double quantity_can_use;	//证券可卖数量
	double real_open_amount;	//今买数量
	double real_off_amount;		//今卖数量
	double cost_balance;		//成本金额
	double keep_cost_price;		//成本价

	long long debt_id;
}SECURITY_POSITION_TIMER;

typedef struct tagConditionBuy
{
	APP_BUY_SALE field;

	std::string header_session;
	std::string header_usrid;
	int nOrderID;
}CONDITION_BUY;

//资金账户监控指标定义【datatype=60501】
typedef struct tagFundMon
{
	char account[32];		//资金账户

	double dblAsset;		//总资产
	double dblNetAsset;		//净资产
	double dblMarketValue;	//证券市值
	double dblDebt;			//负债
	double dblMargin3rd;	//第三方资产（第三方保证金）
	double dblProfit;		//浮动盈亏
	double dblPreAlertLine;	//预警线
	double dblCoverLine;	//平仓线
	double dblRiskDegree;	//风险度
}FUND_MON;

// 风控模块盘中预警结构体定义
// 资管 -- 管理终端【datatype=60502】 MULTI_MSGS_HEAD中requestid=1
// 资管 --  CTP前置【datatype=70003】 MULTI_MSGS_HEAD中requestid=1
typedef struct tagAlarmIn
{
	int nAlarmDate;						//报警日期 YYYYMMDD
	int nAlarmTime;						//报警时间 HHMMSS	
	
	int nRiskCtrlType;					//风控类型 
											// 1-黑白名单
											// 2-持仓股本
											// 3-成交量
											// 4-净值
											// 5- 位限制
											// 6-反向交易
											// 7-到期合约
											// 8-资产比例

	char class_type[20];				// 0 / PRODUCT / FUND / SUB
	char item_code[20];					//风控子类型
	char sub_item_code[20];				//风控指标

	int nAlarmLevel;					//预警级别 
											// -1：红色预警（最严重） -2：橙色预警(ALERT2) -3：黄色预警(ALERT3) -4：白色预警(ALERT4-最轻） 0：无级别

	char account[30];					//账号
	char issue_cd[30];					//证券代码

	double dblParamThreshhold;			//参数设置的报警阀值
	double dblAlarmValue;				//触发报警的当前值
	char other_info[160];				//CTPFRONT有用
	unsigned char unother_info[160];	//ADMIN有用
}ALARM_IN;

#pragma pack (pop)      /*还原默认字节对齐*/

#endif

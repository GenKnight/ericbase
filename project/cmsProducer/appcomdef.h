
#pragma once

#ifndef _APP_COMM_INTERFACE_DEF_
#define _APP_COMM_INTERFACE_DEF_

#include <string>
#include <stdio.h>
#include <string.h>
#pragma pack(push,1)     /*ָ��1�ֽڶ���*/

//�����붨��
#define	PROCESS_SUCCESS				  0	    //����ɹ�
#define	REQUEST_PACKAGE_ILLEGAL		  1		//���������쳣
#define	OPERATE_DB_FAILED			  2		//���ݿ����ʧ��
#define	USRID_EXISTED				  3		//��¼�˺��Ѿ�����
#define	USRID_NOT_EXISTED			  4		//δע����ֻ���
#define	WRONG_PASSWD				  5		//��¼�������
#define	MAC_ADDRESS_CHANGE			  6		//mac��ַ�仯
#define CMD_NOT_SUPPORTED			  7		//��֧������
#define	INFO_NOT_EXIST				  8		//�������Ϣ
#define	NOT_LOGIN_YET				  9		//δ��¼
#define	ME_ORDER_NOTOVER			 10		//�������ʶ���δ����
#define	ME_UP_LIMIT					 11		//������������
#define	ME_CASH_USEUP				 12		//�����ʽ������
#define	ME_ORDER_INVALID			 13		//���ʶ�����Ч
#define	ME_PAY_LESS					 14		//ʵ��֧�����С��Ӧ��֧�����
#define	RISK_CTRL_NOT_PASS			 15		//��ؼ��δͨ��
#define	BUY_FORBIDDEN				 16		//û������Ȩ��
#define	SELL_FORBIDDEN				 17		//û������Ȩ��
#define	WARRANT_RATIO_NOT_PASS		 18		//�������ʲ�����Ҫ��
#define	SEC_MV_NOT_PASS				 19		//֤ȯ��ֵ������Ҫ��
#define	BELONGTO_BLACK_LIST			 20		//������֤ȯ����
#define	MD_SERVER_HALT				 21		//ʵʱ���������ֹ
#define	GET_ASSET_FAILED			 22		//��ȡ�ʲ�ʧ��
#define ASSET_NOT_ENOUGH			 23		//�ʲ�����
#define	SLEF_SELECTION_EXISTED		 24		//��ѡ���Ѵ���
#define SLEF_SELECTION_NOT_EXISTED	 25		//��ѡ�ɲ�����
#define	SLEF_OVER_MAX_CASH   		 26		//��ȳ��������
#define	ME_ORDER_FINISH_PZTY	     27		//��������δ���
#define	ME_ORDER_NOPOWER_PZTY	     28		//û�����������ʸ�
#define	PUSH_MONEY_FAILED	         29		//���ʧ��
#define	DRAW_MONEY_NOT_ENOUGH	     30		//��������
#define	DRAW_MONEY_FAILED	         31		//����ʧ��
#define	WARRAN_TRATE_MIN	         32		//������������0.6�����ֵ���ٳ���չ��
#define	LEFT_MONEY_NOT_ENOUGH	     33		//����֧����Ϣ
#define	USED_MONEY_NOT_ENOUGH	     34		//�����ʽ���֧����Ϣ
#define ERR_TABLE_BASE_DATE			 35		//��׼���ڱ����ô���
#define NOT_TRADING_TIME			 36		//�ǽ���ʱ��
#define NOT_SUPPORT_ENTRUST			 37		//��ǰʱ��㲻֧�ֵ�ί��
#define	ENTRUST_CANCEL_FORBIDDEN	 38		//û�г���Ȩ��
#define	ENTRUST_INVALID				 39		//ί����Ч
#define	CONDITION_ORDER_INVALID		 40		//�������Ѿ�ʧЧ
#define	PUSH_MONEY_NO_PRIVILEGE		 41		//�����Ȩ��
#define	DURING_PZTY_NO_PRIVILEGE	 42		//�����ڼ䣬���������Ȩ��
#define	ADD_INFO_EXISTED	         43		//��Ӽ�¼�Ѵ���
#define	ORDER_CANNOT_CANCEL	         44		//�õ����ɳ���
#define	FUND_ACCOUNT_CANNOT_FIND	 45		//�Ҳ����ʽ��˻�
#define	INSTRUMENT_INFO_CANNOT_FIND	 46		//�Ҳ�����Լ����
#define	RISKRULE_INFO_CANNOT_FIND	 47		//�Ҳ�����ع���
#define	MARGIN_RATIO_NOT_PASS		 48		//��֤����ʲ�����Ҫ��
#define	QUANTITY_USE_NOT_ENOUGH		 49		//��ƽ��������
#define	USER_LOGIN_NO_PRIVILEGE		 50		//���û�û�е���Ȩ��
#define	ADMIN_CANNOT_DELETE			 51		//����Ա������ɾ��
#define	SYSROLE_CANNOT_ADD			 52		//ϵͳ��ɫ���������
#define	SYSROLE_CANNOT_MODIFY		 53		//ϵͳ��ɫ�������޸�
#define	SYSROLE_CANNOT_DELETE		 54		//ϵͳ��ɫ������ɾ��
#define	USER_NO_ENTRUST_PRIVILEGE    55		//�û�û��ί��Ȩ��
#define	INST_IS_NOT_LEGAL		     56		//ָ��Ϸ�
#define	PZACC_CANNOT_CHANGE_FUND	 57		//�ѷ����ʽ�����ʲ��ɸ����ʽ��˻�
#define	EXIST_SAME_RISKCTRL_ITEM	 58		//�Ѵ�����ͬ�ķ��ָ��
#define	SUBENTRUST_NO_CANCEL		 59		//ָ����ص�ί�в����ϳ�������
#define	PRODUCT_NO_DEFAULT_ACC		 60		//��Ʒû��Ĭ�����˻�
#define	INST_TRADER_EXISTING		 61		//ָ�����н���Ա
#define	GET_STOCK_MAXNUM_BUY_FAIL	 62		//��ȡ��Ʊ����������ʧ��
#define	DURING_SETTLEMENT_NO_OP		 63		//�̺�����ڼ䲻����˲���
#define	PRODUCT_FUNDACC_EXISTED		 64		//��Ʒ���Ѵ���ͬ���ʽ��˻�
#define	USER_MACHINE_EXISTED		 65		//���û��ڱ����ѵ�¼


#define STOCK_SECURITY_TYPE          "1"    //��Ʊ
#define FUTURE_SECURITY_TYPE         "2"    //�ڻ�

#define ENTRUST_INST_APPROVING       '1'   //������
#define ENTRUST_INST_EXECTUING       '2'   //ִ����
#define ENTRUST_INST_ORDERED_CANCEL  '3'   //�ѱ�����
#define ENTRUST_INST_PARTDONE_CANCEL '4'   //���ɴ���
#define ENTRUST_INST_PART_CANCELED   '5'   //����
#define ENTRUST_INST_CANCELED        '6'   //�ѳ�
#define ENTRUST_INST_DONE            '8'   //���
#define ENTRUST_INST_FAILED          '9'   //�ϵ�
#define ENTRUST_INST_CANCEL_SENDED   'a'   //�����ѷ�
#define ENTRUST_INST_RISK_PASSED     'p'   //���ͨ��
#define ENTRUST_INST_RISK_REJECT     'r'   //��ز���
#define ENTRUST_INST_APPROVE_REJECT  'd'   //��������


#define ENTRUST_NOT_ORDERED          '0'   //δ��
#define ENTRUST_TOBE_ORDERED         '1'   //����
#define ENTRUST_ORDERED              '2'   //�ѱ�
#define ENTRUST_ORDERED_CANCEL       '3'   //�ѱ�����
#define ENTRUST_PARTDONE_CANCEL      '4'   //���ɴ���
#define ENTRUST_PART_CANCELED        '5'   //����
#define ENTRUST_CANCELED             '6'   //�ѳ�
#define ENTRUST_PART_DONE            '7'   //����
#define ENTRUST_DONE                 '8'   //���
#define ENTRUST_FAILED               '9'   //�ϵ�
#define ENTRUST_CANCEL_SENDED        'a'   //�����ѷ�


#ifndef _WIN32
typedef unsigned char       BYTE;
#endif

//�ӿ�Э�鶨��
//ͨ�����ݲ���ͷ
typedef struct tagResponseHead
{
	int success;		         //0-�ɹ�
	int requestid;		         //���
	int num;			         //����
}RESPONSE_HEAD,MULTI_MSGS_HEAD;

//1��ע������datatype=1��
typedef struct tagRegister
{
	char mobile[16];
	char password[64];
	char remote_ip[16];
	char macAddress[48];
	char invitenum[32];		//�����Ա��
	char fund_flag;         //'0':������ '1':��Ʊ '3':�ڻ�

	char reserve[128];		//Ԥ��
}APP_REGISTER;

//2����¼����datatype=2��
typedef struct tagLogin
{
	int requestid;	//1--���ε�¼ 2--��֤��¼ 3--ǰ�û���¼

	char mobile[16];
	char password[64];
	char remote_ip[16];
	char macAddress[48];

	char reserve[128];		//Ԥ��
}APP_LOGIN;

//3����������datatype=3��
typedef struct tagModifyPasswd
{
	int requestid;	//1--�������� 2--�һ�����

	char mobile[16];
	char old_password[64]; //1--enable
	char new_password[64];
	char macAddress[48];   //2--enable
	char remote_ip[16];
	char reserve[128];		//Ԥ��
}APP_MODIFY_PASSWD;

typedef struct tagMemberIdRep
{
	int success;		//0-�ɹ�
	int member_id;		//��Աid
}APP_MEMBER_ID_REP;

//-------------------------------------------------------
//4����ȡ�û���Ϣ��datatype=4��
typedef struct tagUsrInfo
{
	/*������Ϣid����
	0--������Ϣ 1--��֤�����ɵ����[����] 2--����ȯ 3--�����ʲ� 4--ȡ���ʲ����� 
	5--�����λ 6--ȡ����λ���� 7--��ѡ������ 8--��Լ���� 9--ί�в�ѯ 10--�ʽ���ˮ 
	11--��ȡ����Ĭ��ֵ 12--��ȡ�ҵ���Ϣ 13--��ȡ�ʲ����� 14--�������ˮ 15--������Ϣ 
	16--֧����Ϣ 17--�ҵ���ѯ 18--�ɽ���ѯ 19--���㵥��ѯ 20--������ 21--��λ��ϸ
	22--��֤������ 23--��������*/
	int requestid;			

	int member_id;
	char mobile[16];

	int email_limit;
	int email_offset;

	char reserve[128];		//Ԥ��
}APP_USR_INFO;

//�����û���Ϣ���ؽṹ���壺0--������Ϣ 
typedef struct tagUsrInfo00
{
	int success;	//0-�ɹ�
	int requestid;	//0--������Ϣ

	bool first_experience_flag;	//���������־
	char invitation_code[32];	//������

	char reserve[512];		//Ԥ��
}USRINFO0;

//�����û���Ϣ���ؽṹ���壺1--��֤�����ɵ���������
typedef struct tagUsrInfo01
{
	int success;	//0-�ɹ�
	int requestid;	//1--��֤�����ɵ����

	double margin_remainder;	//��֤�����
	double offset_remainder;	//�ɵ����
}USRINFO1;

//����ȯ����
typedef struct taPayCoupon
{	
	char   pay_coupon[13];      //����ȯ���
	double coupon_value;		//����ȯ���
	char expire_date[30];       //��������
}PAY_COUPON;

//�ʲ�����
typedef struct tagAsset
{	
	double dSetoff;			//�ɵֽ��
	double dMargin;			//��֤��
	double dAsset;			//���ʲ�
	double dNetAsset;		//���ʲ�
	double dDebt;			//��ծ
	double dMakretValue;	//����ֵ
	double dCash;			//�ֽ�
	double dblDrawableCash;	//�����ֽ�� dAvaiableQuota
	double dWarrantRate;	//��������
	double dAvaiableCash;	//���ý��������Ʊ�ȣ�
}USR_ASSET;

//�����û����ʲ�����Ϣ���ؽṹ���壨����Ʊ����
typedef struct tagUsrInfo03
{
	int success;		//0-�ɹ�
	int requestid;		//3--�����ʲ�

	USR_ASSET asset;	//�ʲ���Ϣ
}USRINFO3;

typedef struct tagAssetEx
{	
	double dSetoff;			//�ɵֽ��
	double dMargin;			//��֤��
	double dAsset;			//���ʲ�
	double dNetAsset;		//���ʲ�
	double dDebt;			//��ծ
	double dMakretValue;	//��Ʊ����ֵ
	double dCash;			//�ʽ����
	double dblDrawableCash;	//��ȡ���
	double dWarrantRate;	//��������
	double dAvaiableCash;	//�ʽ����

	double dMaxMarketValue1;	//����Ʊ��ֵ
	double dMaxMarketValue2;	//����ڻ���ֵ ������!��

	double dWarningLine;	    //Ԥ����
	double dCloseLine;      	//ƽ����
	double dRiskDegree;         //���ն�

	double dMarketValue300;		//��ҵ����ֵ
}USR_ASSET_EX;

typedef USR_ASSET_EX STOCK_ASSET;

//�����û����ʲ�����Ϣ���ؽṹ���壨���ڻ�����
typedef struct tagFutureAsset
{
	double dDynamicRight;	    //��̬Ȩ��
	double dAvaiableSum;	    //�����ʽ�
	double dPreCreditSum;	    //�ϴ����ö��	    0
	double dPreMortgageSum;	    //�ϴ���Ѻ���  	0
	double dMortgageSum;	    //��Ѻ���		0
	double dWithdrawSum;	    //����
	double dDepositSum;		    //���
	double dStaticRight;	    //��̬Ȩ��	
	double dCloseProfit;	    //ƽ��ӯ�� 
	double dPositionProfit;	    //�ֲ�ӯ��
	double dCash;			    //�ֽ�
	double dPreReserve;		    //�ϴν���׼����
	double dRoyalty;		    //Ȩ����		    0
	double dDeliveryMargin;	    //���֤��	    0
	double dFrozenRoyalty;	    //����Ȩ����	    0
	double dCredit;			    //���ý��		0
	double dFallbackCash;	    //�����ʽ�		0
	double dblDrawableCash;	    //��ȡ�ʽ� dPayableCash
	double dCommission;		    //������
	double dMargin;			    //ռ�ñ�֤��
	double dFrozenMargin;	    //���ᱣ֤��
	double dFrozenCommission;	//����������

	//���ʲ���
	double dNetAsset;		    //���ʲ�
	double dDebt;			    //��ծ
	double dMarginDebt;		    //��֤�����ʱ�֤��
	double dSetoff;			    //�ɵֽ��
	double dWarrantRate;	    //��������
	double dDrawable;		    //���ʿ�ȡ���
	double dMarketValue;		//�ڻ�����ֵ
	double dMaxMarketValue;		//����ڻ���ֵ


}FUTURE_ASSET;

typedef struct tagIFUsrInfo03
{
	int success;		//0-�ɹ�
	int requestid;		//3--�����ʲ�

	FUTURE_ASSET asset;	//�ʲ���Ϣ
}IFUSRINF03;

typedef struct tagCommonAsset
{
	double dblMarketValue;		//֤ȯ����ֵ
	double dblAsset;			//���ʲ�/��̬Ȩ��
	
	double dblContractMargin;	//��Լռ�ñ�֤��
	double dblFrozenMargin;		//��Լ���ᱣ֤��

	double dblAvailableCash;	//�����ʽ�
	double dblDebt;				//�ܸ�ծ
	double dblNetAsset;			//���ʲ�
	double dblMargin;			//��֤�𣨽�֤��
	double dblSetOff;			//�ɵֽ��
	double dblGuaranteeRate;	//���õ�������
	double dblDrawableCash;		//��ȡ���

}COMMON_ASSET;

//֤ȯ���ʲ�
typedef struct tagSecurityAsset
{
	STOCK_ASSET  stock_asset;	//��Ʊ�ʲ�
	FUTURE_ASSET future_asset;	//�ڻ��ʲ�

	//���Լ�������
	COMMON_ASSET common_asset;	//��ͬ�ʲ�����Ʊ�ʲ� �� �ڻ��ʲ���
}SEC_ASSET;

typedef struct tagUsrInfo04
{
	int success;		//0-�ɹ�
	int requestid;		//4--ȡ���ʲ�����
}USRINFO4;

typedef struct tagPosition
{	
	char SecurityCode[32];		//֤ȯ����
	double quantity;			//֤ȯ������
	double quantity_can_use;	//֤ȯ��������
	double real_open_amount;	//��������
	double real_off_amount;		//��������
	double cost_balance;		//�ɱ����
	double keep_cost_price;		//�ɱ���
	char cond_status;           //��������־ '0'�� '1'��

	bool operator < (const tagPosition &CompareTo) const
	{
		return cost_balance>CompareTo.cost_balance;
	}

	bool operator > (const tagPosition &CompareTo) const
	{
		return cost_balance<CompareTo.cost_balance;
	}

}SECURITY_POSITION;

//֤ȯ��λ����
typedef struct tagPositionSec
{	
	char position_type;         //��λ���� 1��3
	char issue_cd[32];			//֤ȯ����
	char security_type[8];
	char currency_cd[3];
	char ls;                    //�������� 'L':�� 'S':��
	double quantity;			//ʣ������
	double quantity_can_use;	//��������
	double real_open_amount;	//������
	double real_off_amount;		//��ƽ����
	double cost_balance;		//�ɱ����
	double keep_cost_price;		//�ɱ���
	int Position;               //�ܲ�λ=quantity
	int OpenVolume;             //������
	int CloseVolume;			//ƽ����
	double OpenAmount;			//���ֽ��
	double CloseAmount;			//ƽ�ֽ��
	double PositionCost;        //�ֲֳɱ�
	double OpenCost;            //���ֳɱ�
	int TodayPosition;          //���ճֲ�

	char cond_status;           //��������־ '0'�� '1'��

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
	int success;		//0-�ɹ�
	int requestid;		//6--ȡ����λ����
}USRINFO6;

//֤ȯ��λ����
typedef struct tagSelection
{	
	char symbol[16];		//֤ȯ����
}SECURITY_SELECTION;

//�˻���Լ����
typedef struct tagDebt
{	
	long long    debt_id;          //��Լ��
	char   debt_type[20];          //��Լ����
	char   contract_date[30];      //��Լ���� YYYY-MM-DD
	double initial_leverage;       //�ܸ�
	int    initial_term;           //��ʼ����
	double contract_value;         //���ʺ�Լ���
	char   maturity_date[30];      //������
	double total_interest_and_fee; //����
	double paid_principal;         //������
	char   last_maturity_date[30]; //չ��ǰ������
	int    renewal_times;          //չ�ڴ���
	char   debt_status;            //��Լ״̬

	char   initial_cycle;          //���޵�λ
	double to_pay_cash;            //΢��֧�����
}SECUTIRY_DEBT;

//��Ʊί��
typedef struct tagSTEntrustInfo
{
	int    entrust_id;             //ί�к�
	char   pz_account[30];		   //�����˺�
	char   position_type;          //��λ����
	char   issue_cd[30];           //ϵͳ����
	char   trans_code[20];
	char   direction;
	char   offset_flag;
	char   hedge_flag;
	char   entrust_date[30];       //ί������ʱ��
	char   entrust_prop[20];       //ί������
	double entrust_price;          //ί�м۸�
	double entrust_quantity;       //ί������
	double frozen_value;
	double frozen_fee;
	char   currency_cd[3];
	double trade_price;
	double trade_quantity;
	char   entrust_way;
	char   entrust_status;         //״̬
	char   cancel_info[20];		   //��Ϣ
	double withdraw_amount;		   //��������
	char   fund_account[30];
	char   original_entrust_id[30];
	char   OrderRef[13];
}ST_ENTRUST_INFO;

//�ڻ��ҵ�ί��
typedef struct tagIFOrderInfo
{	
	int    entrust_id;             //ί�к�
	char   position_type;          //��λ����
	char   issue_cd[30];           //ϵͳ����
	char   trans_code[20];         //ҵ������ FU_B_OPEN/FU_S_OPEN/FU_B_OFF/FU_S_OFF
	char   direction;              //�������� B/S
	char   offset_flag;			   //��ƽ 0/1
	char   hedge_flag;             //����
	char   entrust_date[30];       //ί������ʱ��
	char   entrust_prop[20];       //ί������ F1���м� F2���޼� 
	double entrust_price;          //ί�м۸�
	double entrust_quantity;       //ί������
	double frozen_value;
	double frozen_fee;
	char   currency_cd[3];
	double trade_price;
	double trade_quantity;
	char   entrust_way;
	char   entrust_status;         //״̬
	char   cancel_info[20];
	double withdraw_amount;
	char   ExchangeID[9];          //����id
	char   OrderSysID[21];         //����id

	char   entrust_type;           //ί�е����� '0':��ͨ�� '1':������ (��ʱ����)
}IF_ORDER_INFO;

//�ڻ��ҵ�ί�в�ѯ[ǰ�û�]
typedef struct tagIFPcOrderInfo
{	
	char mobile[16];

	char   issue_cd[30];           //ϵͳ����
	char   OrderRef[13];
	char   OrderPriceType;
	char   direction;              //�������� B/S
	char   offset_flag;			   //��ƽ 0/1
	char   hedge_flag;             //����
	double entrust_price;          //ί�м۸�
	double entrust_quantity;       //ί������ ͬ:VolumeTotalOriginal
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

//�ʽ���ˮ����
typedef struct tagFundsFlow
{	
	int    journal_id;             //��ˮ��
	char   position_type;          //��λ����
	char   issue_cd[30];           //ϵͳ����
	char   trans_code[20];         //ҵ������ buy/sell
	char   trans_date[30];         //�ɽ�����
	double trans_price2;           //�ɽ��۸�
	double trans_quantity;         //�ɽ�����
	double trans_value;            //�������
}FUNDS_FLOW;

typedef struct tagUsrInfo11
{
	int success;		         //0-�ɹ�
	int requestid;		         //11-��ȡĬ�Ͻ�����Ϣ

	char is_auto_renewal;        //Ĭ���Ƿ�չ�� '0':��չ�� '1':չ��
	char fast_trade_b_option;    //������ '0':δ���� '1':���ٷֱ� '2':������
	double default_buy_percent;  //Ĭ����ٷֱ�
	int default_buy_amount;      //Ĭ��������
	char fast_trade_s_option;    //������ '0':δ���� '1':���ٷֱ� '2':������
	double default_sell_percent; //Ĭ�����ٷֱ�
	int default_sell_amount;     //Ĭ��������
}USRINF11;

typedef struct tagUsrInfo12
{
	int success;		         //0-�ɹ�
	int requestid;		         //12-��ȡ�ҵ���Ϣ

	char member_nickname[40];	 //�ǳ�
	char birthday[30];           //���� YYYY-MM-DD
	char height[20];	         //���
	char education[20];		     //ѧ��
	char occupation[20];		 //��ҵ
	char company[20];			 //��˾
	char region[20];		     //����
	char emotional_state[20];	 //����״̬
	char label[80];			     //��ǩ
	char email[40];			     //����
	char identity_card[18];	     //����
	char verified_date_id[30];	 //������
	char member_name[40];  
	char registered_date[30];    //2015-08-04
	char contact_address[80];
	char member_status;
}USRINF12;

typedef struct tagSettleContent
{
	int success;		         //0-�ɹ�
	int requestid;		         //12-��ȡ�ҵ���Ϣ

	///������
	int	SettlementID;

	///��Ϣ����
	int data_len;
	//char* Content;

}SETTLE_CONTENT;

//�ʲ����ֲ�ѯ����
typedef struct tagDailyInfo
{	
	char   asofdate[30];           //����
	double nav;                    //��ֵ
}DAILY_INFO;

//�ʲ�������Ϣ���ؽṹ���壺
typedef struct tagUsrInfo13
{
	char   success;		           //0-�ɹ�
	int    requestid;		       //13-������ѡ

	char   registered_date[30];   //��ʼ���� YYYY-MM-DD
	double recent_nav;            //�����ֵ
	double recent_drawdown;       //����س�

	int num;	                  //�ʲ���������
	//+num��DAILY_INFO
}USRINF13;

//������Ϣ����
typedef struct tagEmailInfo
{	
	int    seq_id;              //�ʼ���
	int    member_id;           //��Ա��
	char   send_time[30];       //��������
	char   main_data[512];      //�ʼ�����
	char   mail_status;         //״̬

}EMAIL_INFO;

//֧����Ϣ����
typedef struct tagEbatongInfo
{	
	char   customer_id[64];         
	char   card_no[64];             //����
	char   bank_code[18];           //���к�
	char   verified_date[30];       //��֤����
	char   status;
	char   real_name[64];
	char   cert_no[64];
	char   cert_type[2];
}EBATONG_INFO;

//��Ʊ�ɽ��ر�
typedef struct tagSTRecordInfo
{
	int    trade_id;				//�ɽ���
	char   pz_account[30];			//�����˺�
	char   position_type;			//��λ����
	char   issue_cd[30];			//ϵͳ����
	char   trans_code[20];
	char   direction;
	char   offset_flag;
	char   hedge_flag;
	char   currency_cd[3];
	char   trade_date[30]; 
	double trade_price;				//ί�м۸�
	double trade_quantity;			//ί������
	double trade_value;
	char   real_type;
	char   real_status;				//״̬
	int	   entrust_id;
	char   fund_account[30];
	char   original_trade_id[30];
	char   original_entrust_id[30];
	char   OrderRef[13];
}ST_RECORD_INFO;

//�ڻ��ɽ���ѯ
typedef struct tagIFTradeInfo
{	
	int    trade_id;               //�ɽ���
	char   position_type;          //��λ����
	char   issue_cd[30];           //ϵͳ����
	char   trans_code[20];         //ҵ������ FU_B_OPEN/FU_S_OPEN/FU_B_OFF/FU_S_OFF
	char   direction;              //�������� B/S
	char   offset_flag;			   //��ƽ 0/1
	char   hedge_flag;             //����
	char   currency_cd[3];
	char   trade_date[30];         //�ɽ�����ʱ��
	double trade_price;            //�ɽ��۸�
	double trade_quantity;         //�ɽ�����
	double trade_value;
	char   real_type;
	char   real_status;
	int    entrust_id;
}IF_TRADE_INFO;

//�ڻ��ɽ���ѯ[ǰ�û�]
typedef struct tagIFPcTradeInfo
{	
	char mobile[16];

	char   issue_cd[30];           //ϵͳ����
	char   OrderRef[13];
	char   ExchangeID[9];
	char   TradeID[21];
	char   direction;              //�������� B/S
	char   OrderSysID[21];
	char   ParticipantID[11];
	char   ClientID[11];
	char   TradingRole;
	char   ExchangeInstID[31];
	char   offset_flag;			   //��ƽ 0/1
	char   hedge_flag;             //����
	double trade_price;            //�ɽ��۸�
	double trade_quantity;         //�ɽ�����
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

//�ڻ���������ѯ
typedef struct tagIFStopPnlInfo
{	
	int    cond_entrust_id;		   //��������
	int    with_entrust_id;        //��Ӧί�к�
	char   pz_account[30];
	char   position_type;          //��λ����
	char   issue_cd[30];           //ϵͳ����
	char   direction;              //�������� B/S
	double entrust_quantity;       //ί������
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

//��Ʊ��λ��ѯ[ǰ�û�]
typedef struct tagSTPcPositionInfo
{	
	char position_type;         //��λ���� 1��3
	char issue_cd[32];			//֤ȯ����
	char security_type[8];
	char currency_cd[3];
	char ls;                    //�������� 'L':�� 'S':��
	double quantity;			//ʣ������
	double quantity_can_use;	//��������
	double real_open_amount;	//������
	double real_off_amount;		//��ƽ����
	double cost_balance;		//�ɱ����
	double keep_cost_price;		//�ɱ���
	int Position;               //�ܲ�λ=quantity
	int OpenVolume;             //������
	int CloseVolume;			//ƽ����
	double OpenAmount;			//���ֽ��
	double CloseAmount;			//ƽ�ֽ��
	double PositionCost;        //�ֲֳɱ�
	double OpenCost;            //���ֳɱ�
	int TodayPosition;          //���ճֲ�
}ST_PC_POSITION_INFO;

//�ڻ���λ��ѯ[ǰ�û�]
typedef struct tagIFPcPositionDetailInfo
{	
	char mobile[16];

	char   issue_cd[30];           //ϵͳ����
	char   hedge_flag;
	char   direction;              //�������� B/S
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

//5����ȡ������Ϣ�����˻��޹أ���datatype=5��
typedef struct tagBaseInfo
{
	/*������Ϣid 1--�����ײͲ���  2--֤ȯ�б�  3--����֤ȯ��Ϣ 4--�˻�����
	*/
	int requestid;			 
	char issue_cd[16];		//ϵͳ���� requestid=3ʱ��Ч

	char reserve[128];		//Ԥ��
}APP_BASE_INFO;

typedef struct tagMEPackage
{
	int sequence_no;            
	char cycle_type[20];		//����
	int cycle_value_from;       //ֵ��
	int cycle_value_to;         //ֵֹ
	int leverage;				//�ܸ�
	int amount_value_from;		//ֵ��
	int amount_value_to;		//ֵֹ
	int amount_increasing;		//�������
	char charging_mode[20];		//�Ʒѷ�ʽ
	double charging_rate;		//�Ʒѱ�׼
	char charging_unit[20];		//�Ʒѵ�λ
	char charging_method[20];	//�۷ѷ�ʽ
	char first_experience_flag; //���������־ 0:������ 1:����
}ME_PACKAGE;

typedef struct tagSecMaster
{
	char issue_cd[16];				//ϵͳ����
	char symbol[16];				//���ƴ���
	char security_short_name[16];	//֤ȯ���
	char exchange_cd[8];			//������
	char security_type[8];			//֤ȯ����
	char market[20];				//�г�
}SEC_MASTER;

typedef struct tagMasterFu
{
	char issue_cd[30];				//ϵͳ����
	char symbol[30];				//���ƴ���
	char exchange_cd[8];			//������
	char issue_name[20];			//�ڻ����
	char currency_cd[3];			//��������
	char country_cd[2];				//��������
	char security_type[8];			//�ڻ�����
	char fu_product_id[30];
	char fu_product_class;
	int delivery_year;
	int delivery_month;
	int max_market_order_volume;
	int min_market_order_volume;
	int max_limit_order_volume;
	int min_limit_order_volume;
	int volume_multiple;			//��Լ����
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
	char member_nickname[40];	 //�ǳ�
	double roe;                  //���ʲ�������
}ACCOUNT_ROE;
//-------------------------------------------------------

//6��������������datatype=6��
typedef struct tagMERequest
{
	int member_id;

	char mobile[16];
	char pzaccount[32];				//�����˺�
//	char password[64];				//��¼����
	bool first_experience_flag;		//���������־
	double initial_margin;			//��ʼռ�ñ�֤��
	int initial_leverage;			//�ܸ˱���
	double lending_rate;			//����
	double contract_value;			//���ʶ��
	int term;						//����
	double total_interest_and_fee;	//��Ϣ
	double stock_rate;				//��Ʊ����ռ�� �磺1.0 --100%��Ʊ����Ʊ���ڻ��ı���������ͨ�ڻ�Ĭ��Ϊ100��0����ͨ�ڻ�Ĭ��Ϊ30��70����

	char initial_cycle;             //���޵�λ

	char reserve[128];		//Ԥ��
}APP_ME_REQUEST;

//-------------------------------------------------------
//7�����ʶ������ɡ�datatype=7��
typedef struct tagMEOrder
{
	int member_id;

	char mobile[16];
	char pzaccount[32];		//�����˺�
	long long order_num;	//���ʶ�����
	double pay_sum;			//��Ҫ֧�����ܶ�    ΢��֧��
	double pay_actural;		//ʹ���˻�֧���Ķ�� �ɵֽ��

	char ticket_num[13];	//ʹ�ô���ȯ���
	double ticket_use_sum;	//����ȯʵ��ʹ�ý��

	char reserve[128];		//Ԥ��
}APP_ME_ORDER;

//-------------------------------------------------------
//8�����ʶ���������������ֵ����datatype=8��
typedef struct tagMEPay
{
	int member_id;

	char mobile[16];
	char pzaccount[32];				//�����˺�
	long long order_num;			//order_num>0 -- ���ʶ����ţ�
	bool order_valid;				//���ʶ�����true--������Ч��false--�������ϣ�
	double actural_pay_sum;			//���ʶ���ʵ��֧�����

	char reserve[128];		//Ԥ��
}APP_ME_PAY;

//��������ͳһ�ر���datatype=6 7 8��
typedef struct tagMERequestReply
{
	int success;			//0-�ɹ�

	long long order_num;	//���ʶ�����
}APP_ME_REQUEST_REPLY;

//12����ѡ�� datatype=12
typedef struct tagSelfSelection
{
	int requestid;                  //1.��� 2.ɾ��

    int member_id;
	char mobile[16];
	char symbol[16];				//֤ȯ����

	char reserve[128];			    //Ԥ�� 
}APP_SELF_SELECTION;

//13������ datatype=13
typedef struct tagReducePosition
{
    int member_id;

	char       mobile[16];
	long long    debt_id;           //��Լ��
	double     reduceCash;          //������

	char reserve[128];			    //Ԥ�� 
}APP_REDUCE_POSITION;

//14��չ�� datatype=14
typedef struct tagDelayDay
{
    int member_id;

	char       mobile[16];
	long long    debt_id;           //��Լ��

	char reserve[128];			    //Ԥ�� 
}APP_DELAY_DAY;
//-------------------------------------------------------

//15�����datatype=15��
typedef struct tagPushMoney
{
    int member_id;

	char mobile[16];
	char password[64];				//��¼����
	char pzaccount[32];				//�˺�
	double operate_amount;			//�����
	char ticket_num[13];	        //ʹ�ô���ȯ���
	double ticket_use_sum;	        //����ȯʵ��ʹ�ý��
	double pay_cash;                //�ֽ�֧�����
	double stock_future_proportion;	//��Ʊ:1 �ڻ�:0

	char reserve[128];			//Ԥ��
}APP_PUSH_MONEY;

//16�����ȷ�ϡ�datatype=16��
typedef struct tagPushMoneyPay
{
    int member_id;

	char mobile[16];
	char pzaccount[32];				//�����˺�
	long long order_num;			//order_num>0 -- �����ţ�
	bool order_valid;				//������true--������Ч��false--�������ϣ�
	double actural_pay_sum;			//����ʵ��֧�����

	char reserve[128];		//Ԥ��
}APP_PUSH_MONEY_PAY;

//������󷵻����ݽṹ���塾datatype=15 16��
typedef struct tagPUSHRequestReply
{
	int success;			    //0-�ɹ�

	long long order_num;		//��𶩵���
}APP_PUSH_REQUEST_REPLY;

//17������datatype=17��
typedef struct tagDrawMoney
{
    int member_id;

	char mobile[16];
	char password[64];				//��¼����
//	bool bOperateSuccess;			//�����Ƿ�ɹ�
	double operate_amount;			//������
    double stock_future_proportion;	//��Ʊ:1 �ڻ�:0

	char reserve[128];			//Ԥ��
}APP_DRAW_MONEY;

//18���û��˳���datatype=18��
typedef struct tagUserExit
{
	int requestid;                    //1.�����˳� 2.��ʱ�˳�

    int member_id;
	char mobile[16];

	char reserve[128];			//Ԥ��
}APP_USER_EXIT;

//19�����ʶ���������datatype=19��
typedef struct tagMEPayCancle
{
    int member_id;

	char mobile[16];
	long long order_num;				//order_num>0 -- ���ʶ����ţ�

	char reserve[128];		//Ԥ��
}APP_ME_PAY_CANCLE;

//20�����ʶ�����ѯ��datatype=20��
typedef struct tagMEPayFind
{
    int member_id;

	char mobile[16];
	long long order_num;				//order_num>0 -- ���ʶ����ţ�

	char reserve[128];		//Ԥ��
}APP_ME_PAY_FIND;

typedef struct tagMEFindRequest
{
	int success;			        //0-�ɹ�

    long long order_num;			//order_num>0 -- ���ʶ����ţ�
    double dcash;                   //�ʽ����
	double initial_margin;			//��ʼռ�ñ�֤��
	int initial_leverage;			//�ܸ˱���
	char initial_cycle;             //���޵�λ
	int initial_term;				//����
	double lending_rate;			//����
    double contract_value;			//���ʶ��
	double total_interest_and_fee;	//��Ϣ
    double paid_margin_from_asset;  //�ɵֽ��ʹ��
    double used_coupon;             //����ȯ
    double paid_cash;               //΢��֧��
	char debt_status;               //��Լ״̬
	char debt_type[20];             //��Լ����
}ME_FIND_REQUEST;

//21���˻�����������datatype=21��
typedef struct tagMEAccountSet
{
	int requestid;			     //���� 1--Ĭ���Ƿ�չ�� 2--Ĭ��������

	int member_id;

	char mobile[16];
	char is_auto_renewal;        //Ĭ���Ƿ�չ�� '0':��չ�� '1':չ��

	char fast_trade_b_option;    //������ '0':δ���� '1':���ٷֱ� '2':������
	double default_buy_percent;  //Ĭ����ٷֱ�
	int default_buy_amount;      //Ĭ��������
	char fast_trade_s_option;    //������ '0':δ���� '1':���ٷֱ� '2':������
	double default_sell_percent; //Ĭ�����ٷֱ�
    int default_sell_amount;     //Ĭ��������
    
	char reserve[128];		//Ԥ��
}APP_ME_ACCOUNT_SET;

//22���ҵ����á�datatype=22��
typedef struct tagMemberInfoSet
{
    int member_id;
	char mobile[16];
	char key[32];
	char values[512];

	char reserve[128];		//Ԥ��
}APP_MEMBER_INFO_SET;

//23��ָ����Ʊ�ֲ֡�datatype=23��
typedef struct tagSinglePosition
{
    int member_id;
	char mobile[16];
    char SecurityCode[32];	//֤ȯ����

	char reserve[128];		//Ԥ��
}APP_SINGLE_POSITION;

typedef struct tagMESinglePositionRequest
{
	int success;			        //0-�ɹ�
	SECURITY_POSITION field;
}ME_SINGLE_POSITION_REQUEST;

//24���������á�datatype=24��
typedef struct tagMailSet
{
	int requestid;			//���� 1--����״̬ 2--�ظ��Ƿ���δ���ʼ�

    int member_id;
	char mobile[16];
	char seq_id[512];	    //�ʼ��� 1:12:33

	char reserve[128];		//Ԥ��
}APP_MAIL_SET;

typedef struct tagMEMailStatusResponse
{
	int success;			//0-�ɹ�
	int requestid;          //1����״̬ -2--�ظ��Ƿ���δ���ʼ�
	char mail_status;       //'0'--��δ�� '1'--��δ��
}ME_MAIL_STATUS_RESPONSE;

//25���ʲ����ֲ�ѯ��datatype=25��
typedef struct tagMEShareRef
{
    int member_id;
	char mobile[16];

	char reserve[128];		//Ԥ��
}APP_ME_SHARE_REF;

//�ʲ����ֲ�ѯ����
typedef struct tagDailyShareInfo
{	
	char   asofdate[30];           //����
	double nav;                    //��ֵ
}DAILY_SHARE_INFO;

//�ʲ�������Ϣ���ؽṹ���壺
typedef struct tagUsrShareResponse
{
	char   success;		           //0-�ɹ�

	char   registered_date[30];   //��ʼ���� YYYY-MM-DD
	double recent_nav;            //�����ֵ
	double recent_drawdown;       //����س�
	char member_nickname[40];	  //�ǳ�

	int num;	                  //�ʲ���������
	//+num��DAILY_SHARE_INFO
}APP_SHARE_RESPONSE;

//26��֧����Ϣ���á�datatype=26��
typedef struct tagEbatongSet
{
	int requestid;			//���� 1--add 2--delete

	int member_id;
	char mobile[16];
	char customer_id[64];   
	char real_name[64];
	char cert_no[64];
	char cert_type[2];  
	char card_no[64];             //����
	char bank_code[18];           //���к�

	char reserve[128];		//Ԥ��
}APP_EBATONG_SET;

//�����������������ө����������������������ө�������������������
//��ҳ��ί������  ������				  ������              ��
//�����������������੤���������������������੤������������������
//���޼�          ��S1���޼�ί��		  ��S1���޼�ί��      ��
//�����������������੤���������������������੤������������������
//���м�		  ��SS3���嵵����ת�޼�	  ��SZ2���Է����ż۸� ��
//�����������������ܩ����������������������ة�������������������

//��ؽӿڶ��� ME<-->Monitor-------------------------------------------------------------------------
//������Ϣ�ṹ���塾datatype=60001��
typedef struct tagAlarm
{
	int nAlarmType;			//�������� 1-���˻��������� 2-��ծ 3-������Ʊ��ֵ 4-��ҵ����ֵ 5-�ʽ��˻���������
	int nAlarmLevel;		//�������� 0�����Ʊ����������أ� 1��Ԥ��1�� 2��Ԥ��2�� 3��Ԥ��3�������ᣩ -1���޼���

	char account[32];		//�˺�

	double dblThreshhold;	//������ֵ
	double dblAlarmValue;	//���������ĵ�ǰֵ
	int nAlarmDate;			//�������� YYYYMMDD
	int nAlarmTime;			//����ʱ�� HHMMSS
}ME_ALARM;

//���������Ϣ�ṹ���塾datatype=60002��
typedef struct tagAlarmCancel
{
	int nAlarmType;			//�������� 1-���˻��������� 2-��ծ 3-������Ʊ��ֵ 4-��ҵ����ֵ 5-�ʽ��˻���������

	char account[32];		//�˺�

	int nAlarmDate;			//�������� YYYYMMDD
	int nAlarmTime;			//����ʱ�� HHMMSS
}ME_ALARM_CANCEL;

typedef struct tagAssetMonitor
{	
	double dSetoff;			//�ɵֽ��
	double dMargin;			//��֤��
	double dAsset;			//���ʲ�
	double dNetAsset;		//���ʲ�
	double dDebt;			//��ծ
	double dMakretValue;	//����ֵ
	double dCash;			//�ֽ�
	double dblDrawableCash;	//�����ֽ��
	double dWarrantRate;	//��������
	double dAvaiableCash;	//���ý��������Ʊ�ȣ�

	double dMaxMarketValue1;	//����Ʊ��ֵ
	double dMaxMarketValue2;	//����ڻ���ֵ������!��

	double dWarningLine;	    //Ԥ����
	double dCloseLine;      	//ƽ����
	double dRiskDegree;         //���ն�
}USR_ASSET_MON;

//����ն��ʲ��ṹ���塾datatype=60003��
typedef struct tagMonitorAsset
{
	char account[32];		//�˺�

	USR_ASSET_MON asset_mon;
}MON_ASSET;

//�����ʻ���Ϣ�ṹ���� ��datatype=60004��
typedef struct tagMonitorRequest
{
	/*1:��λ 2.��Լ 3.�ʽ���ˮ 4.���˵��ս��� 5.������ʷ���� 
	6.���˵���ί�� 7.������ʷί�� 8.���˵��������� 9.�����ʲ�
	10.���ʺϼ��ʲ�*/
	int requestid;			

	char account[32];		//�˺�
	char start_date[30];    //��ʼ���� 2015-03-19 00:00:00
	char end_date[30];      //�������� 9999-12-31 23:59:59 Ĭ��
}MON_REQUEST;

//����ն�֤ȯ��λ�ṹ����
typedef struct tagMonitorSecurityInfo
{	
	char account[32];		    //+�˺�
	char position_type;         //+��λ���� 1��3
	char issue_cd[32];			//֤ȯ����
	char ls;                    //+�������� 'L':�� 'S':��
	double quantity;			//֤ȯ������
	double quantity_can_use;	//֤ȯ��������
	double real_open_amount;	//��������
	double real_off_amount;		//��������
	double cost_balance;		//�ɱ����
	double keep_cost_price;		//�ɱ���
	double last_price;			//���¼�

	char HedgeFlag;             //+Ͷ��
	double UseMargin;           //+ռ�ñ�֤��
	double PositionCost;        //+�ֲֳɱ�
	double OpenCost;            //+���ֳɱ�
	int TodayPosition;          //+���ճֲ�
}MON_SECUTIRY_INFO;

//����ն��˻���Լ����
typedef struct tagDebtEx
{	
	char account[32];		       //+�˺�
	long long    debt_id;          //��Լ��
	char   debt_type[20];          //��Լ����
	char   contract_date[30];      //��Լ���� YYYY-MM-DD
	double initial_leverage;       //�ܸ�
	
	double contract_value;         //���ʺ�Լ���
	char   maturity_date[30];      //������
	double total_interest_and_fee; //����
	double paid_principal;         //������
	char   last_maturity_date[30]; //չ��ǰ������
	int    renewal_times;          //չ�ڴ���
	char   debt_status;            //��Լ״̬

	double initial_margin;         //��֤��
	double lending_rate;           //����
	char   fund_account[30];       //�����˻�
	int    initial_term;           //��ʼ����

	double stock_future_proportion;//��Ʊ:1 �ڻ�:0
}SECUTIRY_DEBT_EX;

//����ն��˻��ʽ���ˮ����
typedef struct tagJournalEx
{	
	char account[32];		       //+�˺�
	int    journal_id;             //��ˮ��
	char   position_type;          //��λ����
	char   issue_cd[30];           //ϵͳ����
	char   trans_code[20];         //ҵ������ CASH_IN/CASH_OUT/PZ_FEE/buy/sell
	char   trans_date[30];         //�ɽ�����
	double trans_price2;           //�ɽ��۸�
	double trans_quantity;         //�ɽ�����
	double trans_value;            //�������
	double commission;             //Ӷ��
	double stamp_duty;             //ӡ��˰
	double transfer_fee;           //������
	double settlement_fee;         //�����
	char   original_journal_id[30];//ԭʼ��ˮ��
}SECUTIRY_JOURNAL_EX;

typedef struct tagIFTradingRecordInfo
{	
	char account[32];		       //+�˺�
	int    trade_id;               //�ɽ���
	char   position_type;          //��λ����
	char   issue_cd[30];           //ϵͳ����
	char   trans_code[20];         //ҵ������ FU_B_OPEN/FU_S_OPEN/FU_B_OFF/FU_S_OFF
	char   direction;              //+�������� B/S
	char   offset_flag;			   //+��ƽ 0/1
	char   hedge_flag;             //+����
	char   currency_cd[3];		   //+
	char   trade_date[30];         //�ɽ�����ʱ��
	double trade_price;            //�ɽ��۸�
	double trade_quantity;         //�ɽ�����
	double trade_value;
	char   real_type;              //+
	char   real_status;
	int    entrust_id;
}TRADING_RECORD_INFO;

//����ն�����ί�е�����
typedef struct tagTradingEntrustInfo
{	
	int    entrust_id;             //ί�к�
	char   position_type;          //��λ����
	char   issue_cd[30];           //ϵͳ����
	char   trans_code[20];         //ҵ������ buy/sell
	char   entrust_date[30];       //ί������ʱ��
	char   entrust_prop[20];       //ί������
	double entrust_price;          //ί�м۸�
	double entrust_quantity;       //ί������
	double trade_price;            //�ɽ��۸�
	double trade_quantity;         //�ɽ�����
	char   entrust_status;         //״̬
}TRADING_ENTRUST_INFO;

//����ն���������������
typedef struct tagTradingCondEntrustInfo
{	
	int    cond_entrust_id;        //ί�к�
	char   position_type;          //��λ����
	char   issue_cd[30];           //ϵͳ����
	char   trans_code[20];         //ҵ������ buy/sell
	char   entrust_date[30];       //����ί������ʱ��
	char   entrust_prop[20];       //����ί������
	double trigger_price;          //�����۸�
	double entrust_price;          //ί�м۸�
	double entrust_quantity;       //ί������
	char   cond_entrust_status;    //״̬
}TRADING_COND_ENTRUST_INFO;

typedef struct tagMonitorAssetEx
{
	char account[32];		//�˺�

	double dSetoff;			//�ɵֽ��
	double dMargin;			//��֤��
	double dAsset;			//���ʲ�
	double dNetAsset;		//���ʲ�
	double dDebt;			//��ծ
	double dMakretValue;	//����ֵ
	double dCash;			//�ֽ�
	double dblDrawableCash;	//�����ֽ��
	double dWarrantRate;	//��������
	double dAvaiableCash;	//���ý��������Ʊ�ȣ�

	double dMaxMarketValue1;	//����Ʊ��ֵ
	double dMaxMarketValue2;	//����ڻ���ֵ������!��

	double dWarningLine;	    //Ԥ����
	double dCloseLine;      	//ƽ����
	double dRiskDegree;         //���ն�
}USR_MONITOR_ASSET_EX;

typedef struct tagMonitorIFAsset
{
	char account[32];		//�˺�

	FUTURE_ASSET field;
}USR_MONITOR_IF_ASSET;

//COMMON_ASSET

//���ʺϼ��ʲ�
typedef struct tagMonitorCommonAsset
{
	char account[32];		//�˺�

	COMMON_ASSET field;
}USR_MONITOR_COMMON_ASSET;

//����ն˺���������ṹ���� ��datatype=60005��
typedef struct tagBlackListRequest
{
	int requestid;              //��������1.find_current 2.find_his 3.add 4.remove 

	char issue_cd[30];		    //֤ȯ����
    char add_date[30];          //��ʼ���� 2015-03-19 12:40:03
	char remove_date[30];    	//�������� 9999-12-31 23:59:59 Ĭ��
    unsigned char reason[20];   //ԭ��   linux 20
    char last_update_user[20];  //����Ա 
}MON_BLACK_LIST_REQUEST;

typedef struct tagCurrentBlackList
{	
	char issue_cd[30];		    //֤ȯ����
	char sec_blacklist_type[20];
	char add_date[30];          //��ʼ���� 2015-03-19 12:40:03
	char remove_date[30];    	//�������� 9999-12-31 23:59:59 Ĭ��
	unsigned char reason[40];   //ԭ��   linux 20*2
}CURRENT_BLACK_LIST;

typedef struct tagHisBlackList
{	
	char issue_cd[30];		    //֤ȯ����
	char sec_blacklist_type[20];
	char bl_set_type[20];       //�������� add/remove
	char bl_set_date[30];       //add/remove���� 2015-03-19 12:40:03
	unsigned char reason[40];   //ԭ��   linux 20*2
	char last_update_time[30];  //����ʱ��
	char last_update_user[20];  //����Ա 
}HIS_BLACK_LIST;

//�����ײ͡�datatype=60006��
typedef struct tagPzSetMealRequest
{
	int requestid;              //��������1.find 2.add 3.update 4.delete 

	int sequence_no;            
	char cycle_type[20];		//����
	int cycle_value_from;       //ֵ��
	int cycle_value_to;         //ֵֹ
	int leverage;				//�ܸ�
	int amount_value_from;		//ֵ��
	int amount_value_to;		//ֵֹ
	int amount_increasing;		//�������
	char charging_mode[20];		//�Ʒѷ�ʽ
	double charging_rate;		//�Ʒѱ�׼
	char charging_unit[20];		//�Ʒѵ�λ
	char charging_method[20];	//�۷ѷ�ʽ
	char first_experience_flag; //���������־ 0:������ 1:����
	char last_update_user[20];  //����Ա 
}MON_PZ_SET_MEAL_REQUEST;

typedef struct tagSetMealInfo
{	
	int sequence_no;            
	char cycle_type[20];		//����
	int cycle_value_from;       //ֵ��
	int cycle_value_to;         //ֵֹ
	int leverage;				//�ܸ�
	int amount_value_from;		//ֵ��
	int amount_value_to;		//ֵֹ
	int amount_increasing;		//�������
	char charging_mode[20];		//�Ʒѷ�ʽ
	double charging_rate;		//�Ʒѱ�׼
	char charging_unit[20];		//�Ʒѵ�λ
	char charging_method[20];	//�۷ѷ�ʽ
	char first_experience_flag; //���������־ 0:������ 1:����
	char status;                //״̬
	char last_update_user[20];  //����Ա 
}SET_MEAL_INFO;

//��ȡ��Ʊ��Ϣ�����˻��޹أ���datatype=60007��
typedef struct tagStockRequest
{
	int requestid;			//������Ϣid 1--֤ȯ�б� 2--ɾ�� 3--�޸� 4--����

	char issue_cd[30];				         //֤ȯ���
	char symbol[22];				         //֤ȯ����
	char security_eng_short_name[40];		 //֤ȯ����
	char security_eng_long_name[120];		 //֤ȯ����
	unsigned char security_short_name[30];	         //֤ȯ����
	unsigned char security_long_name[80];	         //֤ȯ����
	char exchange_cd[7];			         //������
	char currency_cd[3];			         //����
	char country_cd[2];			             //����
	char security_type[8];			         //֤ȯ����
	char market[20];				         //�г�
	double issue_size;			             //��������
	double issue_price;			             //�۸�
	double face_value;			             //��ֵ
	char face_value_currency_cd[3];			 //��������
	char issue_date[30];                     //������ YYYY-MM-DD
	char listing_date[30];                   //������ YYYY-MM-DD
	char initial_listing_date[30];           //�׷������� YYYY-MM-DD
	char delisting_date[30];                 //ժ������ YYYY-MM-DD
	char last_corporate_action_code[20];     //�����˾��Ϊ
	char last_corporate_action_date[30];     //�����˾��Ϊ���� YYYY-MM-DD
	char reserve[128];		//Ԥ��
}APP_STOCK_REQUEST;


typedef struct tagMonitorStockInfo
{
	char issue_cd[30];				         //֤ȯ���
	char symbol[22];				         //֤ȯ����
	char security_eng_short_name[40];		 //֤ȯ����
	char security_eng_long_name[120];		 //֤ȯ����
	unsigned char security_short_name[60];	         //֤ȯ���� linux 30*2
	unsigned char security_long_name[160];	         //֤ȯ���� linux 80*2
	char exchange_cd[7];			         //������
	char currency_cd[3];			         //����
	char country_cd[2];			             //����
	char security_type[8];			         //֤ȯ����
	char market[20];				         //�г�
	double issue_size;			             //��������
	double issue_price;			             //�۸�
	double face_value;			             //��ֵ
	char face_value_currency_cd[3];			 //��������
	char issue_date[30];                     //������ YYYY-MM-DD
	char listing_date[30];                   //������ YYYY-MM-DD
	char initial_listing_date[30];           //�׷������� YYYY-MM-DD
	char delisting_date[30];                 //ժ������ YYYY-MM-DD
	char last_corporate_action_code[20];     //�����˾��Ϊ
	char last_corporate_action_date[30];     //�����˾��Ϊ���� YYYY-MM-DD
}MONITOR_STOCK_INFO;

//��ȡ�˻���Ϣ��datatype=60008��
typedef struct tagPzaccountRequest
{
	int requestid;			  //������Ϣid 1--�˻���Ϣ 2--�˻����� 3--�˻��ⶳ 4--�˻�ƽ�� 5--�˻��޸� 6--�˻��ⶳ2

    char account[32];		  //�˺�
	char commission_type[20]; //����(5--�˻��޸�)
	double pz_credit_line;
	char reserve[128];		  //Ԥ��
}APP_PZACCOUNT_REQUEST;


typedef struct tagMonitorPzaccountInfo
{
	int member_id;
	char pz_account[30];		       //�˻�
	char pz_account_group[30];		   //�˻���
	char pz_account_type[20];	       //�˻�����
	char pz_open_date[30];             //YYYY-MM-DD
	int pz_account_level;			   
	double pz_credit_line;			   
	char pz_account_status;            //�˻�״̬
	char commission_type[20];	       //����
	unsigned char pz_account_name[80]; //linux 40*2
}MONITOR_PZACCOUNT_INFO;

//�����û���datatype=60009��
typedef struct tagUserRegister
{
    int requestid;	//1-�û�ע�� 2-�޸����� 3-�޸��û���Ϣ 4-�û���¼ 5-�û��ǳ� 6-��ȡ�û���Ϣ 7-ɾ���û� 8-��ѯ�����û� 9-ǿ�Ƶǳ� 10-�������

	char user_id[20];
    unsigned char user_name[50];
	char password[16];
    char newpassword[16];
	char user_role_cd[20];
	char user_phone[20];
	char user_email[50];
	char login_ip[20];
	char user_status[20]; //+

	char reserve[128];		//Ԥ��
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
	int success;			//0-�ɹ�
	int requestid;          //4-�û���¼ 9-ǿ�Ƶǳ�
	char user_id[20];
}MON_USER_LOGIN_REP;
//�����ֵ��ȯ����Ϣ��datatype=60010��
typedef struct tagPzCodeRequest
{
	int requestid;			//������Ϣid 1--code 2--broker 3--counter 4--broker_server 5--broker

	char reserve[128];		//Ԥ��
}APP_PZCODE_REQUEST;

typedef struct tagMonitorPzCodeInfo
{
	char code[20];		    //����
	char code_type[20];		//��������
	unsigned char code_name[80];	    //�������� linux 40*2
	int display_order;      //�˻�״̬
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
	char broker_id[20];						//���͹�˾�˺�
	char counter_cd[20];			        //��̨
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

//�����̲�����datatype=60011��
typedef struct tagBrokerOpRequest
{
	int requestid;			//������Ϣid 1--add 2--update 3--delete

	char broker_id[20];		            
	unsigned char broker_name[40];
	char broker_status;
	unsigned char comments[80];

	char reserve[128];		//Ԥ��
}BROKER_OP_REQUEST;

//�����̷��������datatype=60012��
typedef struct tagBrokerServerOpRequest
{
	int requestid;			//������Ϣid 1--add 2--update 3--delete

	char broker_id[20];						//���͹�˾�˺�
	char counter_cd[20];			        //��̨
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

	char reserve[128];		//Ԥ��
}BROKER_SERVER_OP_REQUEST;

//���顾datatype=60013��
typedef struct tagAccountGroup
{
	int requestid;	//1-�������� 2-�޸����� 3-ɾ������ 4-������Ϣ 5-������Ϣ2

	char pz_account_group[30];
	unsigned char pz_account_group_name[40];
	char pz_account_group_type[20];
	char pz_account_group_status;
	char last_update_user[20];

	char reserve[128];		//Ԥ��
}APP_ACCOUNT_GROUP;

typedef struct tagMonitorGroupInfo
{
	char pz_account_group[30];
	unsigned char pz_account_group_name[80];  //40*2
	char pz_account_group_type[20];
	char pz_account_group_status;
	char last_update_user[20];
}MONITOR_GROUP_INFO;

//��Ա��Ϣ��datatype=60014��
typedef struct tagMemberRequest
{
	int requestid;			//������Ϣid 1--��ȡ��Ա��Ϣ 2--��Ա��Ϣ�޸�

	int member_id;          //��Աid

	char mobile_phone[11];         
	unsigned char member_name[40];
	char email[40];
	unsigned char occupation[20];
	char last_update_user[20];

	char reserve[128];		//Ԥ��
}APP_MEMBER_REQUEST;

typedef struct tagMonitorMemberInfo
{
	int member_id;                 //��Աid
	char mobile_phone[11];         
	unsigned char member_name[80];          //40*2
	unsigned char member_nickname[80];      //40*2
	char registered_date[30];      //���� YYYY-MM-DD
	char identity_card[18];
	char verified_date_id[30];     //���� YYYY-MM-DD
	char email[40];
	char verified_date_e[30];      //���� YYYY-MM-DD
	char gender[20];
	char birthday[30];
	char education[20];
	char region[20];
	unsigned char occupation[40];           //linux 20*2
	unsigned char contact_address[160];     //linux 80*2
	char member_status;

}MONITOR_MEMBER_INFO;

//ָ��������Ϣ��datatype=60015��
typedef struct tagGroupRequest
{
	char dGroup[32];		//����
	int requestid;			//������Ϣid 1--�ʲ� 2--�ֲ�(������) 3--�����ʽ���ˮ

	char start_date[30];    //��ʼ���� 2015-03-19 12:40:03
	char end_date[30];      //�������� 9999-12-31 23:59:59 Ĭ��
	char reserve[128];		//Ԥ��
}APP_GROUP_REQUEST;

//�����ʲ���Ϣ
typedef struct tagMonitorGroupAssetEx
{
	char dGroup[32];		//����

	double dSetoff;			//�ɵֽ��
	double dMargin;			//��֤��
	double dAsset;			//���ʲ�
	double dNetAsset;		//���ʲ�
	double dDebt;			//��ծ
	double dMakretValue;	//����ֵ
	double dCash;			//�ֽ�
	double dblDrawableCash;	//�����ֽ��
	double dAvaiableCash;	//���ý��������Ʊ�ȣ�

	double dDebtToday;      //�����ʽ�
	int    dAccoutNum;      //���˻���Ŀ
    int    dAccoutNumToday; //�񿪻���Ŀ
}USR_MONITOR_GROUP_ASSET_EX;

//�����λ��Ϣ
typedef struct tagGroupInfo
{	
	char SecurityCode[32];		//֤ȯ����

	double quantity;			//֤ȯ������
	double quantity_can_use;	//֤ȯ��������
	double real_open_amount;	//��������
	double real_off_amount;		//��������


	double last_price;			//���¼�
}MON_GROUP_INFO;

//�����ʽ���ˮ
typedef struct tagJournalGroup
{	
    char pz_account[32];		    //�˻�
	SECUTIRY_JOURNAL_EX sp;         //���ʽṹ
}SECUTIRY_JOURNAL_GROUP;

//������ɫ��datatype=60016��
typedef struct tagUserRole
{
    int requestid;	//1-��ȡ��ɫ 2-������ɫ 3-�޸Ľ�ɫ 4-ɾ����ɫ
	char user_role_cd[20];
	unsigned char code_name[20];
    unsigned char user_role_desc[80];
	char is_sys_role;
	char management_terminal;
	char trade_terminal;
	int user_role_class;

	char reserve[128];		//Ԥ��
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

//�ʽ��˻���datatype=60017��
typedef struct tagFundAccount
{
	/*1-��ȡ 2-���� 3-�޸Ļ�����Ϣ 4-ɾ��[δ��] 
	5-��ȡ2 6-�����ʽ� 7-����[һ��һ] 8-�����ʽ�[һ��һ]*/
	int requestid;	

	char fund_account[30];                //investor_id.broker_id
	char investor_id[20];                 //fund_account ԭ
	char broker_id[20];
	char fund_password[16];
	char fund_account_type[20];			  //�ʲ���� '1':��Ʊ '3':�ڻ�
	unsigned char fund_name[40];
	char counter_cd[20];                  //��̨
	char open_date[30];                   //��������
	char investment_type[20];             //Ͷ������ ��������/����
	char risk_control_type[20];			  //������� ��ǰ���/Y�ͷ��
	char fund_account_status;             //�˻�״̬
	unsigned char comments[80];			  //��ע
	char last_update_user[20];			  //6
										  //fund_pz_amount_t
	double cash;                          //�����ʲ�6
	char currency_cd[3];				  //����6
	double min_amount_remain;			  //���ٱ����ʲ�6
	double amount_can_use;                //��ȡ�ʽ��˻��ɵ����ʲ�

	char asofdate[30];                    //fund_asset_adjust
	double initial_net_asset_value;
	char structured_flag;
	double priority_amount;
	double posterior_amount;

	char product_id[30];                  //product_fund_account

	char reserve[128];		  //Ԥ��
}APP_FUND_ACCOUNT;

typedef struct tagMonitorFundAccountInfo
{
	char fund_account[30];              //investor_id.broker_id
	char investor_id[20];               //fund_account ԭ
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
	char currency_cd[3];                //����
	double min_amount_remain;
	double amount_can_use;              //��ȡ�ʽ��˻��ɵ����ʲ�

	char asofdate[30];                  //fund_asset_adjust
	double initial_net_asset_value;
	char structured_flag;
	double priority_amount;
	double posterior_amount;

	char product_id[30];                //product_fund_account
}MONITOR_FUND_ACCOUNT_INFO;

//ָ���ʽ��˻���Ϣ��datatype=60018��
typedef struct tagFundAccountRequest
{
	/*������Ϣid 1--��Լ���� 2--��Լ��ϸ [1/2��Ч]
	3--�ʲ� 4--�ֲ� 5--���ճɽ� 6--��ʷ�ɽ� 7--�ʽ���ˮ
	8--ί��*/
	int requestid;			    

	char fund_account[32];		//�ʽ��˻�

	int start_date;
	int end_date;
	char reserve[128];		//Ԥ��
}APP_FUND_ACCOUNT_REQUEST;

//�ʽ��˻���Լ����
typedef struct tagMonFundAccDebtTotal
{
	char fund_account[32];	//�ʽ��˻�

    char currency_cd[3];    //����
	double dCashTotal;		//�ʽ��ܶ�
	int    dDebtNum;		//��Լ����
	double dHasQuota;		//������(��ծ)
	double interest_fee;    //����
	double dCanQuate;		//������
	char near_max_date[30]; //����������� 2015-03-19 12:40:03
	char far_max_date[30];  //��Զ�������� 9999-12-31 23:59:59 Ĭ��

}USR_MON_FUND_ACC_DEBT_TOTAL;

//�ʽ��˻���Լ��ϸ
typedef struct tagFundAccountDebt
{	
	SECUTIRY_DEBT_EX sp;            //���ʽṹ
}SECUTIRY_FUND_ACCOUNT_DEBT;

//��Ʊ�ʲ���¼
typedef struct tagMonitorFundInfo {
	char brokerId[16];			        //���͹�˾�˺�
	char accountId[16];					//�ʽ��˺�
	double asset;						//���ʲ�
	double marketValue;					//��Ʊ��ֵ
	double balance;						//�ʽ����
	double available;					//�����ʽ�
	double withdraw;					//��ȡ�ʽ�
	double todayBuyAmount;				//����������									 
	double todaySellAmount;				//�����������					
	char currency_cd[3];			    //��ֵ���ͣ� 1-�����CNY 2-��ԪUSD 3-�۱�HKD
}USR_MONITOR_FUND_INFO;

//�ڻ��ʲ���¼
typedef struct tagMonIFFundInfo
{
	char BrokerID[11];
	char InvestorID[13];

	double dStaticRight;				//��̬Ȩ��
	double dCloseProfit;				//ƽ��ӯ�� 
	double dPositionProfit;				//�ֲ�ӯ��
	double dDynamicRight;				//��̬Ȩ��
	double dMargin;						//ռ�ñ�֤��
	double dFrozenMargin;				//���ᱣ֤��
	double dFrozenCommission;			//����������
	double dCommission;					//������
	double dPreReserve;					//�ϴν���׼����
	double dWithdrawSum;				//����
	double dDepositSum;					//���
	double dFallbackCash;				//�����ʽ�
	double dblDrawableCash;				//��ȡ�ʽ�
	double dAvaiableSum;				//�����ʽ�
}USR_MON_IFFUND_INFO;

//��Ʊ��λ��¼
typedef struct tagMonitorFundPosition
{
	char brokerId[16];			        //���͹�˾�˺�
	char accountId[16];					//�ʽ��˺�
	int exchangeId;						//���������� 1:�Ͻ��� 2:���
	char symbol[16];					//֤ȯ����
	int volume;							//�ֲ�����
	int availableVolume;				//��������
	int yesterdayVolume;				//���
	double costPrice;					//�ɱ��۸�
	double lastPrice;					//���¼�
	double marketValue;					//֤ȯ��ֵ
	double floatProfit;					//����ӯ��
}USR_MONITOR_FUND_POSITION;

//�ڻ���λ��¼
typedef struct tagMonIFFundPosition
{
	char BrokerID[11];
	char InvestorID[13];
	char issue_cd[32];			//֤ȯ����
	char ls;                    //+�������� '2':�� '3':��
	double quantity;			//֤ȯ������
	double quantity_can_use;	//֤ȯ��������(Nothing)
	double real_open_amount;	//��������
	double real_off_amount;		//��������
	double last_price;			//���¼�

	char HedgeFlag;             //+Ͷ��
	double UseMargin;           //+ռ�ñ�֤��
	double PositionCost;        //+�ֲֳɱ�
	double OpenCost;            //+���ֳɱ�
	int TodayPosition;          //+���ճֲ�
	double PositionProfit;		//++�ֲ�ӯ��
}USR_MON_IF_FUND_POSITION;

//��Ʊ���׼�¼
typedef struct tagMonitorFundTrade
{
	char BrokerID[11];
	char InvestorID[13];
	char OrderRef[13];
	char TradeDate[30];		//�ɽ����ڣ���ʽ��20150205
	char TradeTime[30];		//�ɽ�ʱ�䣬��ʽ��10:12:12
	char symbol[16];		//֤ȯ����
	int direction;			//1:�� 2:��
	int volume;				//�ɽ�����
	double price;			//�ɽ��۸�
	double amount;			//�ɽ����
	char orderId[30];		//���������ص�ί�б��
	int exchangeId;			//���������� 1:�Ͻ��� 2:���
	char tradeId[30];		//�ɽ���
	char Position[30];		//�ɽ�λ��
}USR_MONITOR_FUND_TRADE;

//�ڻ����׼�¼
typedef struct tagMonIFFundTrade
{
	char BrokerID[11];
	char InvestorID[13];
	char position_type;     //��λ����
	char InstrumentID[31];	//��Լ����
	char ExchangeID[9];     //����������
	char TradeID[21];		//�ɽ��� 
	char OrderRef[13];		//�µ���
	char OrderSysID[21];	//���������ص�ί�б��
	char Direction;			//����'0'-���� '1'-����
	char OffsetFlag;        //��ƽ��־ '0'-���� '!0'-ƽ��
	char HedgeFlag;			//Ͷ���ױ���־
	char TradeDate[9];      //�ɽ�����
	char TradeTime[9];		//�ɽ�ʱ��
	double price;			//�ɽ��۸�
	int volume;			    //�ɽ�����
}USR_MON_IFFUND_TRADE;

//��Ʊ�ʽ���ˮ
typedef struct tagMonitorFundJournal
{
	char BrokerID[11];
	char InvestorID[13];
	double ChangeAmount;					//�䶯���
	double reserveValue;					//��� 
	char holderId[30];						//�ɶ��˺�
	int exchangeId;							//���������� 1:�Ͻ��� 2:���
	char symbol[16];						//֤ȯ����
	int direction;							//����1-���� 2-����
	int tradeVolume;						//�ɽ�����
	double tradePrice;						//�ɽ��۸�
	char tradeId[30];						//�ɽ���
	char flowId[20];						//��ˮ��
	char abstractType[12];					//ժҪ���
	char orderId[30];						//���������ص�ί�б��
	char currency_cd[3];					//��ֵ���� 1-�����CNY 2-��ԪUSD 3-�۱�HKD
	char TradeDate[30];						//�ɽ����ڣ���ʽ��20150205
	char TradeTime[30];						//�ɽ�ʱ�䣬��ʽ��10:12:12
	double tradeValue;						//�ɽ����
	double commission;						//Ӷ��
	double transferFee;						//������
	double stampTax;						//ӡ��˰
	double otherFee;						//��������
	unsigned char business_abstract[64];	//ҵ��ժҪ   linux 32*2
}USR_MONITOR_FUND_JOURNAL;

//��Ʊί�е�
typedef struct tagMonitorFundOrder
{
	char BrokerID[11];
	char InvestorID[13];
	char OrderRef[13];		//��������
	char SessionId[30];		//�Ự���
	char symbol[16];		//֤ȯ����
	int exchangeId;			//���������� 1:�Ͻ��� 2:���
	int direction;			//����1-���� 2-����
	int priceType;			//���۷�ʽ
	double price;			//ί�м۸�
	int volume;				//ί������
	int orderWay;			//ί�з�ʽ
	int businessId;			//ҵ������
	int AcceptedVolume;		//��������
	int FrozenVolume;		//��������
	double FrozenAmount;	//������
	int TradeVolume;		//��������
	char orderId[30];		//���������ص�ί�б��
	char InsertDate[30];	//ί�����ڣ���ʽ��20150205
	char InsertTime[30];	//ί��ʱ�䣬��ʽ��10:12:12
	int status;				//ί��״̬
}USR_MONITOR_FUND_ORDER;

//�ڻ�ί�е�
typedef struct tagMonIFFundOrder
{
	char	InstrumentID[31];			//��Լ����
	char	OrderRef[13];				//��������
	char    OrderPriceType;				//�����۸�����+
	char    Direction;                  //��������
	char    CombOffsetFlag[5];			//��Ͽ�ƽ��־
	char    CombHedgeFlag[5];           //���Ͷ���ױ���־
	double  LimitPrice;                 //�۸�
	int     VolumeTotalOriginal;        //����
	char    TimeCondition;				//��Ч������
	char    GTDDate[9];					//GTD����
	char    VolumeCondition;			//�ɽ�������
	int     MinVolume;					//��С�ɽ���
	char    ContingentCondition;		//��������
	double  StopPrice;					//ֹ���
	char    ForceCloseReason;			//ǿƽԭ��
	int     IsAutoSuspend;				//�Զ������־
	char    BusinessUnit[21];			//ҵ��Ԫ
	char    OrderSubmitStatus;			//�����ύ״̬
	char    OrderStatus;				//����״̬
	int		RequestID;					//������	
	char	OrderLocalID[13];			//���ر������	
	char	ExchangeID[9];				//����������	
	char	ParticipantID[11];			//��Ա����	
	char	ClientID[11];				//�ͻ�����	
	char	ExchangeInstID[31];			//��Լ�ڽ������Ĵ���	
	char	TraderID[21];				//����������Ա����	
	int		InstallID;					//��װ���	
	int		NotifySequence;				//������ʾ���	
	char	TradingDay[9];				//������	
	int		SettlementID;				//������	
	char	OrderSysID[21];				//�������	
	char	OrderSource;				//������Դ	
	char	OrderType;					//��������	
	int		VolumeTraded;				//��ɽ�����	
	int		VolumeTotal;				//ʣ������	
	char	InsertDate[9];				//��������	
	char	InsertTime[9];				//ί��ʱ��	
	char	ActiveTime[9];				//����ʱ��	
	char	SuspendTime[9];				//����ʱ��	
	char	UpdateTime[9];				//����޸�ʱ��	
	char	CancelTime[9];				//����ʱ��	
	char	ActiveTraderID[21];			//����޸Ľ���������Ա����	
	char	ClearingPartID[11];			//�����Ա���
	int		SequenceNo;					//���	
	char	StatusMsg[81];				//״̬��Ϣ	
	int		UserForceClose;				//�û�ǿ����־	
	char	ActiveUserID[16];			//�����û�����	
	int		BrokerOrderSeq;				//���͹�˾�������	
	char	RelativeOrderSysID[21];		//��ر���	
	int		ZCETotalTradedVolume;		//֣�����ɽ�����
	int		IsSwapOrder;				//��������־
	char	UserProductInfo[11];		//+��Դ
}USR_MON_IFFUND_ORDER;

//�ʽ������Ϣ��datatype=60019��
typedef struct tagFundReportRequest
{
	int requestid;			    //������Ϣid 1--����

	char fund_account[32];		//�ʽ��˻�
	char start_date[30];        //��ʼ���� 1900-01-01
	char end_date[30];          //�������� 9999-12-31

	char reserve[128];		    //Ԥ��
}APP_FUND_REPORT_REQUEST;

typedef struct tagMonitorFundReport
{
	char fund_account[32];	//�ʽ��˻�
	char asofdate[30];      //����������� 2015-03-19
	char currency_cd[3];	//��ֵ���� 1-�����CNY 2-��ԪUSD 3-�۱�HKD
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

//��ȡ���й���ģ�顾datatype=60020��
typedef struct tagUiModuleRequest
{
	int requestid;			//������Ϣid 1--��ȡ���й���ģ��

	char reserve[128];		//Ԥ��
}APP_UI_MODULE_REQUEST;
	
typedef struct tagMonitorUiModuleInfo
{
	char ui_module_cd[8];
    unsigned char code_name[60];        //linux 30*2
    unsigned char description[112];     //linux 56*2
}MONITOR_UI_MODULE_INFO;

//����ģ�顾datatype=60021��
typedef struct tagRoleUiModule
{
	int requestid;	//1-��ȡ 2-��� 3-ɾ�� 4-�����û�ID��ȡ����ģ�� 5-��ȡ2 
	char user_id[20];
	char user_role_cd[20];
	char ui_module_cd[8];

	char reserve[128];		//Ԥ��
}APP_ROLE_UI_MODULE;

typedef struct tagMonitorRoleUiModuleInfo
{
	char user_role_cd[20];
	char ui_module_cd[8];
}MONITOR_ROLE_UI_MODULE_INFO;

//�û��˻����á�datatype=60022��
typedef struct tagUserPzModule
{
	int requestid;	//1-ָ����ȡ 2-��� 3-ɾ�� 4-ȫ����ȡ
	char user_id[20];
	char pz_account[30];
	char pz_account_type[20];

	char reserve[128];		//Ԥ��
}APP_USER_PZ;

typedef struct tagMonitorUserPzInfo
{
	char user_id[20];
	char pz_account[30];
	char pz_account_type[20];
}MONITOR_USER_PZ_INFO;

//�û��ʽ��˻����á�datatype=60023��
typedef struct tagUserFundAcc
{
	int requestid;	//1-��ȡ 2-��� 3-ɾ�� 4-��ȡ2
	char user_id[20];
	char fund_account[30];
	char account_type[20];

	char reserve[128];		//Ԥ��
}APP_USER_FUND_ACC;

typedef struct tagMonitorUserFundInfo
{
	char user_id[20];
	char fund_account[30];
	char account_type[20];
}MONITOR_USER_FUND_INFO;

//�˻���ز�����datatype=60024��
typedef struct tagRiskRuleItem
{
	int requestid;	//1-��ȡ���в����б� 2-��ȡ��ع����б� 3-������ع��� 4-ɾ��

	char rc_rule[20];
	unsigned char description[48];
	unsigned char comments[255];
    char last_update_user[20];

	char reserve[128];		//Ԥ��
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

//ָ�������ºϹ�������á�datatype=60025��
typedef struct tagRcRuleItem
{
	int requestid;	//1-��ȡ 2-�޸�

	char rc_rule[20];
	char item_code[20];
	char const_code[30];
	char constant_value[38];
	char alert_level1[38];
	char alert_level2[38];
	char alert_level3[38];
	char item_status;
	int priority;

	char reserve[128];		//Ԥ��
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

//��������ͷ�ع���datatype=60026��
typedef struct tagRcGroupRule
{
    int requestid;	//1-��������ͷ�ع���(add/update) 2-��ȡ�����������

	char pz_account_group[30];
	char rc_rule[20];

	char reserve[128];		//Ԥ��
}APP_RC_GROUP_RULE;

typedef struct tagMonitorRcGroupRuleInfo
{
    char pz_account_group[30];
	char rc_rule[20];
}MONITOR_RC_GROUP_RULE_INFO;

//�ʽ��˻���ز�����datatype=60027��
typedef struct tagFundRiskRuleItem
{
	int requestid;	//1-��ȡ���в����б� 2-��ȡ��ع����б� 3-������ع��� 4-ɾ��

	char f_rc_rule[20];
	unsigned char description[48];
	unsigned char comments[255];
	char last_update_user[20];

	char reserve[128];		//Ԥ��
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

//ָ�������ºϹ�������á�datatype=60028��
typedef struct tagFundRcRuleItem
{
	int requestid;	//1-��ȡ 2-�޸�

	char f_rc_rule[20];
	char item_code[20];
	char const_code[30];
	char constant_value[38];
	char alert_level1[38];
	char alert_level2[38];
	char alert_level3[38];
	char item_status;
	int priority;

	char reserve[128];		//Ԥ��
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

//��������ͷ�ع���datatype=60029��
typedef struct tagFundRcGroupRule
{
	int requestid;	//1-��������ͷ�ع���(add/update) 2-��ȡ�����������

	char fund_account_group[30];
	char f_rc_rule[20];

	char reserve[128];		//Ԥ��
}APP_FUND_RC_GROUP_RULE;

typedef struct tagMonFundRcGroupRuleInfo
{
	char fund_account_group[30];
	char f_rc_rule[20];
}MON_FUND_RC_GROUP_RULE_INFO;

//��ȡ���˺Ϲ�Ԥ����datatype=60030��
typedef struct tagRcAlertJournalRequest
{
	int requestid;		     //1--���˺Ϲ�Ԥ����Ϣ

	char start_date[30];    //��ʼ���� 2015-03-19 12:40:03
	char end_date[30];      //�������� 9999-12-31 23:59:59 Ĭ��
	char reserve[128];		//Ԥ��
}APP_RC_ALERT_JOURNAL_REQUEST;

//���˺Ϲ�Ԥ����Ϣ
typedef struct tagRcAlertJournalInfo
{	
	int sequence_no;		
	char pz_account[30];
	char item_code[20];
	char const_code[30];
	char alert_date[30];    //���� 2015-03-19 12:40:03
	char alert_level[38];
	char alert_level_value[38];
    char actual_value[38];
}MON_RC_ALERT_JOURNAL_INFO;

//��ȡ֤ȯ��Ȩ��Ϣ�����˻��޹أ���datatype=60031��
typedef struct tagXDRightRequest
{
	int requestid;			//������Ϣid 1--����֤ȯ��Ȩ 2--�޸� 3--ɾ�� 4--��ȡ 
							//5--��ȡδ���� 6--��ȡʱ��� 7��ȡָ����Ʊʱ���

	char issue_cd[30];				             //֤ȯ���
	char ex_dividend_date[30];                   //��Ȩ��Ϣ�� YYYY-MM-DD	6/7 begin_date
	char declaration_date[30];                   //�������� YYYY-MM-DD	6/7 end_date
	char record_date[30];                        //��Ȩ�Ǽ��� YYYY-MM-DD
	char stk_div_flag;                           //'0' false '1' true
	char div_flag;
	char reverse_stk_flag;
	char allot_flag;
	double stock_splits_per10;			         //���
	double reverse_stock_splits_per10;			 //����
	char xr_listing_date[30];                    //��ת�������� YYYY-MM-DD
	double div_cash_per10_pre_tax;			     //��������˰��
	double div_cash_per10_after_tax;			 //������˰��
	char currency_cd[3];				         //�ֺ����
	char payment_date[30];                       //��Ϣ�� YYYY-MM-DD
	double allotment_per10;			             //���
	double allotment_price;			             //��ɼ�
	double total_allotment_amount;			     //ʵ�������
	char allotment_listing_date[30];             //����ɷ������� YYYY-MM-DD
	unsigned char comments[20];                  //��ע˵��
	char stk_div_status;                           
	char stk_listing_status;
	char div_status;
	char reverse_stk_status;
	char allot_status;
	char xd_status;                              //״̬

	char reserve[128];		//Ԥ��
}APP_XDRIGHT_REQUEST;

typedef struct tagMonitorXDRightInfo
{
	char issue_cd[30];				             //֤ȯ���
	char ex_dividend_date[30];                   //��Ȩ��Ϣ�� YYYY-MM-DD
	char declaration_date[30];                   //�������� YYYY-MM-DD
	char record_date[30];                        //��Ȩ�Ǽ��� YYYY-MM-DD
	char stk_div_flag;                           //'0' false '1' true
	char div_flag;
	char reverse_stk_flag;
	char allot_flag;
	double stock_splits_per10;			         //���
	double reverse_stock_splits_per10;			 //����
	char xr_listing_date[30];                    //��ת�������� YYYY-MM-DD
	double div_cash_per10_pre_tax;			     //��������˰��
	double div_cash_per10_after_tax;			 //������˰��
	char currency_cd[3];				         //�ֺ����
	char payment_date[30];                       //��Ϣ�� YYYY-MM-DD
	double allotment_per10;			             //���
	double allotment_price;			             //��ɼ�
	double total_allotment_amount;			     //ʵ�������
	char allotment_listing_date[30];             //����ɷ������� YYYY-MM-DD
	unsigned char comments[40];                           //��ע˵�� linux 20*2
	char stk_div_status;                           
	char stk_listing_status;
	char div_status;
	char reverse_stk_status;
	char allot_status;
	char xd_status;                              //״̬
}MONITOR_XDRIGHT_INFO;

//��ȡ���ʺ��ʽ��˻�ί�С��ɽ���datatype=60032��
typedef struct tagMonitorReconcileReq
{
	int requestid;			//1:����ί�� 2.�ʽ��˻�ί�� 3.���ʳɽ� 4.�ʽ��˻��ɽ�

	char reserve[128];		//Ԥ��
}MON_RECONCILE_REQUEST;

//����ն�ί�е�����
typedef struct tagReconcileEntrustInfo
{	
	int    entrust_id;             //ί�к�
	char   account[30];            //���ʡ��ʽ��˻�
	char   position_type;          //��λ����
	char   issue_cd[30];           //ϵͳ����
	char   trans_code[20];         //ҵ������ buy/sell
	char   direction;              //��������
	char   entrust_date[30];       //ί������ʱ��
	char   entrust_prop[20];       //ί������
	double entrust_price;          //ί�м۸�
	double entrust_quantity;       //ί������
	char   currency_cd[3];         //����
	double trade_price;            //�ɽ��۸�
	double trade_quantity;         //�ɽ�����
	char   entrust_way;            //ί�з�ʽ
	char   entrust_status;         //״̬
	unsigned char cancle_info[40]; //linux 20*2
	double withdraw_amount;        
	char   original_entrust[30];   //ԭʼί�к�/OrderRef
	char   reconcile_flag;

	char   fund_account[30];       //�ʽ��˻���������Ч��

	char   offset_flag;            //��ƽ��־ '0'-�� '1'-ƽ '3'-ƽ��+
	char   hedge_flag;			   //Ͷ�� '1'+
}RECONCILE_ENTRUST_INFO;

//����ն˽��׶���
typedef struct tagReconcileRecordInfo
{	
	int    trade_id;               //�ɽ���
	char   account[30];            //���ʡ��ʽ��˻�
	char   position_type;          //��λ����
	char   issue_cd[30];           //ϵͳ����
	char   trans_code[20];         //ҵ������ buy/sell
	char   direction;              //��������
	char   currency_cd[3];         //����
	char   trade_date[30];         //�ɽ�����ʱ��
	double trade_price;            //�ɽ��۸�
	double trade_quantity;         //�ɽ�����
	double trade_value;            //�ɽ����
	char   real_type;
	char   real_status;            //״̬
	int    entrust_id;             //ί�кš��ʽ��˻�ί�к�
	char   original_trade_id[30];
	char   original_entrust_id[30];//ԭʼί�к�
	char   reconcile_flag;

    char   fund_account[30];       //�ʽ��˻���������Ч��

	char   offset_flag;            //��ƽ��־ '0'-�� '1'-ƽ '3'-ƽ��+
	char   hedge_flag;			   //Ͷ�� '1'+
}RECONCILE_RECORD_INFO;

//��ȡ����ί���޸ġ�datatype=60033��
typedef struct tagMonitorEntrustOpReq
{
	int requestid;			//1.����ί������ 2.�޸�

	int    entrust_id;             //ί�к�
	char   account[30];            //���ʡ��ʽ��˻�
	char   position_type;          //��λ����
	char   issue_cd[30];           //ϵͳ����
	char   trans_code[20];         //ҵ������ buy/sell
	char   direction;              //��������
	char   entrust_date[30];       //ί������ʱ��
	char   entrust_prop[20];       //ί������
	double entrust_price;          //ί�м۸�
	double entrust_quantity;       //ί������
	char   currency_cd[3];         //����
	double trade_price;            //�ɽ��۸�
	double trade_quantity;         //�ɽ�����
	char   entrust_way;            //ί�з�ʽ
	char   entrust_status;         //״̬
	unsigned char cancle_info[20];
	double withdraw_amount;        
	char   original_entrust[30];   //ԭʼί�к�
	char   reconcile_flag;
	char   fund_account[30];       //�ʽ��˻���������Ч��
	char   offset_flag;            //��ƽ��־ '0'-�� '1'-ƽ '3'-ƽ��+
	char   hedge_flag;			   //Ͷ�� '1'+

	char reserve[128];		//Ԥ��
}MON_ENTRUST_OP_REQUEST;

//��ȡ���ʳɽ��޸ġ�datatype=60034��
typedef struct tagMonitorRecordOpReq
{
	int requestid;			//1.���ʳɽ����� 2.�޸�

	int    trade_id;               //�ɽ���
	char   account[30];            //���ʡ��ʽ��˻�
	char   position_type;          //��λ����
	char   issue_cd[30];           //ϵͳ����
	char   trans_code[20];         //ҵ������ buy/sell
	char   direction;              //��������
	char   currency_cd[3];         //����
	char   trade_date[30];         //�ɽ�����ʱ��
	double trade_price;            //�ɽ��۸�
	double trade_quantity;         //�ɽ�����
	double trade_value;            //�ɽ����
	char   real_type;
	char   real_status;            //״̬
	int    entrust_id;             //ί�кš��ʽ��˻�ί�к�
	char   original_trade_id[30];
	char   original_entrust_id[30];//ԭʼί�к�
	char   reconcile_flag;
	char   fund_account[30];       //�ʽ��˻���������Ч��
	char   offset_flag;            //��ƽ��־ '0'-�� '1'-ƽ '3'-ƽ��+
	char   hedge_flag;			   //Ͷ�� '1'+

	char reserve[128];		//Ԥ��
}MON_RECORD_OP_REQUEST;

//��Ʒ��Ϣ��datatype=60035��
typedef struct tagProductInfoReq
{
	/*������Ϣid 1-��ȡ 2-add 3-update[״̬��˵��] 4-delete[δ��] 5-��ȡ2
	6-�ʲ����� 7-add[һ��һ]*/
	int requestid;			    

	char product_id[30];		//product_id
	char asofdate[30];          //���� 1900-01-01
	//pz_jy_fuanda.product_account                           
	char product_type[20];		//����:'AM'��������:'IND'
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
	
	char reserve[128];		    //Ԥ��
}APP_PRODUCT_INFO_REQ;

typedef struct tagMonProductInfoRep
{
	char product_id[30];		//product_id
	char asofdate[30];          //���� 1900-01-01
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
	double usable_cash;				//+�ɷ����ʽ�
}USR_MON_PRODUCT_INFO_REP;

//������ϵ��Ϣ��datatype=60036��
typedef struct tagPzConnectAccountReq
{
	int requestid;			    //������Ϣid 1--��ȡ�����ʽ��˻� 2--��ȡ���ʲ�Ʒ
	//char product_id[30];		//product_id

	char reserve[128];		    //Ԥ��
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

//�ڻ���Լ��datatype=60037��
typedef struct tagFutureRequest
{
	int requestid;			//������Ϣid 1.�ڻ���Լ 2.��֤���� 3.���� 

	char reserve[128];		//Ԥ��
}APP_FUTURE_REQUEST;

typedef struct tagMonitorFutureInfo
{
	char issue_cd[30];				         //֤ȯ���
	char symbol[30];				         //֤ȯ����
	char exchange_cd[8];			         //������
	unsigned char issue_name[80];	         //֤ȯ���� linux 20*2
	char currency_cd[3];			         //����
	char country_cd[2];			             //����
	char security_type[8];			         //֤ȯ����
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

//�����������datatype=60038��
typedef struct tagMonPzAccountReq
{
	int requestid;			//������Ϣid 1--add 2--find 3--update 4--��֤����ע��

	char product_id[30];    //find��

	int member_id;          //update��
	char pz_account[30];	//update��

	char mobile[16];
	char password[64];
	unsigned char pz_account_name[40];  //��������
	char pz_account_type[20];  //��������
	char pz_open_date[30];     //�������� 2015-09-08
	double pz_credit_line;     //���ö��
	char pz_account_status;    //����״̬
	int  fund_num;
	char fund_account_type1;   //��Ʊ:'1' �ڻ�:'3'
	char fund_accout1[30];
	char fund_account_type2;
	char fund_accout2[30];
	char fund_account_type3;
    char fund_accout3[30];		//Ԥ���ʽ��˻�

	char reserve[128];			//Ԥ��
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
	unsigned char pz_account_name[80];   //+�������� linux 40*2
	char pz_account_type[20];            //��������
	char pz_open_date[30];               //�������� 2015-09-08
	char commission_type[20];            
	double pz_credit_line;               //���ö��
	char pz_account_status;              //����״̬
	int  fund_num;
	char fund_account_type1;			 //��Ʊ:'1' �ڻ�:'3'
	char fund_accout1[30];
	char fund_account_type2;
	char fund_accout2[30];
	char fund_account_type3;
    char fund_accout3[30];  //Ԥ���ʽ��˻�

}MON_PRODUCT_PZ_ACC_REPLY;

//��ϵ����Ϣ��datatype=60039��
typedef struct tagContactReq
{
	int requestid;			    //������Ϣid 1-��Ʒ��ϵ�� 2-��Ʒ��ϵ�˸��� 3-�ʽ��˻���ϵ�� 4-�ʽ��˻���ϵ�˸���

	char account[30];		    //product_id/fund_account

	int contact_num;            //1~4
	unsigned char contact_name[20];
	char contact_phone[20];
	char contact_mobile[11];
	unsigned char contack_desc[40];

	char reserve[128];		    //Ԥ��
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

//�����ʲ����䡾datatype=60040��
typedef struct tagMonAccAssetAdjustReq
{
	/*������Ϣid 1--��ȡָ����Ʒ��������Ϣ 2-�����ʲ����� */
	int requestid;			    

	char product_id[30];    //��ȡָ����Ʒ��������Ϣ

	char fund_account[30];
	char pz_account[30];
	char position_type;          //��λ����
	double adjust_cash;             
	double initial_net_asset_value;
	char structured_flag;
	double priority_amount;
	double posterior_amount;
	double pp_proportion;
	char last_update_user[20];			  

	char reserve[128];		    //Ԥ��
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

//��ز������ࡾdatatype=60041��
typedef struct tagRiskCtrlDef
{
	int requestid;	//1-��ȡ���в����б� 2-��ȡ�������

	char reserve[128];		//Ԥ��
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

//�������ṹ���� ��datatype=60042��
typedef struct tagRiskCtrlRuleReq
{
	/*��������1.find 2.add 3.rule_cur 4.rule_his 5.all_rule_cur 6.all_rule_his
	7.���� 8.��ͣ 9.update*/
	int requestid; 

	/* 1:�ڰ����� 2:���ɳֱֲ������� 3:���ɳɽ������� 4:��ֵ����
	5:�����׿��� 6:��Լ������ 7:�ֵ���λ���� 8:ͬ���ʲ���������*/
	int  item_type;             
	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL
	char account_id[30];		//��ָproduct_id/fund_account/pz_account��"0"Ϊȫ�� 
	
	char start_date[30];        //��ʼ���� 2015-03-19 12:40:03
	char end_date[30];    	    //�������� 9999-12-31 23:59:59 Ĭ��
	unsigned char comments[80]; //ԭ��   linux 80
	char rc_rule_status;        //��ͣ״̬ '1'δ���ã�'2'���ã�'3'��ͣ��'4'ͣ�� 
	char set_type[20];          //�������� ADD/USE/BLOCK/STOP
	char last_update_user[20];  //����Ա 
}MON_RISK_CTRL_RULE_REQ;

typedef struct tagBlackWhiteList
{	
	int rc_sequence_no;
	char item_code[20];
	char account_id[30];
	char position_type;
	char issue_cd[30];		    //֤ȯ����
	char rc_sec_bw_list_type[20];
	char add_date[30];          //��ʼ���� 2015-03-19 12:40:03
	char remove_date[30];    	//��������
	unsigned char reason[40];   //ԭ��   linux 20*2
	char status;                //'0'���� '1'��ͣ
}BLACK_WHITE_LIST;

typedef struct tagStockTradeList
{	
	int rc_sequence_no;
	char item_code[20];
	char account_id[30];
	char position_type;
	char comparison_direction;  //'G'���� 'L'С��
	double threshold_level1;
	char action_level1[20];     //FORBIDDEN ALERT2 ALERT3
	double threshold_level2;
	char action_level2[20];
	double threshold_level3;
	char action_level3[20];
	char status;                //'0'���� '1'��ͣ
}STOCK_TRADE_LIST;

typedef struct tagNavRList
{	
	int rc_sequence_no;
	char item_code[20];
	char account_id[30];
	char position_type;
	char comparison_direction;  //'G'���� 'L'С��
	double threshold_level1;
	char action_level1[20];     //FORBIDDEN ALERT2 ALERT3
	double threshold_level2;
	char action_level2[20];
	double threshold_level3;
	char action_level3[20];
	char status;                //'0'���� '1'��ͣ
}NAV_R_LIST;

typedef struct tagReversTradeList
{	
	int rc_sequence_no;
	char item_code[20];
	char account_id[30];
	char position_type;
	char add_date[30];          //��ʼ���� 2015-03-19 12:40:03
	char remove_date[30];    	//��������
	char status;                //'0'���� '1'��ͣ
}REVERS_TRADE_LIST;

typedef struct tagFuMaturityList
{	
	char issue_cd[30];
	char expire_date[30];       //������ 2015-03-19
	char end_deliv_date[30];    //��󽻸���
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
	char comparison_direction;  //'G'���� 'L'С��
	double threshold_level1;
	char action_level1[20];     //FORBIDDEN ALERT2 ALERT3
	double threshold_level2;
	char action_level2[20];
	double threshold_level3;
	char action_level3[20];
	char status;                //'0'���� '1'��ͣ
}NAV_POS_CTRL_LIST;

typedef struct tagAssetClassList
{	
	int rc_sequence_no;
	char item_code[20];
	char sub_item_code[20];
	char account_id[30];
	char position_type;
	char comparison_direction;  //'G'���� 'L'С��
	double threshold_level1;
	char action_level1[20];     //FORBIDDEN ALERT2 ALERT3
	double threshold_level2;
	char action_level2[20];
	double threshold_level3;
	char action_level3[20];
	char status;                //'0'���� '1'��ͣ
}ASSET_CLASS_LIST;

typedef struct tagRuleCurList
{	
	int rc_sequence_no;
	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL
	char account_id[30];		//��ָproduct_id/fund_account/pz_account��"0"Ϊȫ�� 
	char start_date[30];        //��ʼ���� 2015-03-19 12:40:03
	char end_date[30];    	    //��������
	unsigned char comments[160];//ԭ��   linux 160
	char rc_rule_status;        //��ͣ״̬ 1δ���ã�2���ã�3��ͣ��4ͣ�� 
}RULE_CUR_LIST;

typedef struct tagRuleHisList
{	
	int sequence_no;
	int rc_sequence_no;
	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL
	char account_id[30];		//��ָproduct_id/fund_account/pz_account��"0"Ϊȫ�� 
	char set_type[20];          //�������� ADD/USE/BLOCK/STOP
	unsigned char comments[160];//ԭ��   linux 160
}RULE_HIS_LIST;

//��غڰ���������ṹ���� ��datatype=60043��
typedef struct tagBNWRequest
{
	int requestid;              //��������1.save

	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL
	char account_id[30];		//��ָproduct_id/fund_account/pz_account��"0"Ϊȫ�� 

	char op;                    //'0':������ '1':��� '2':�Ƴ�
	char black_white_flag;      //'0':black '1':white
	char item_code[20];
	char position_type;
	char issue_cd[30];		    //֤ȯ����
	char rc_sec_bw_list_type[20];
	char add_date[30];          //��ʼ���� 2015-03-19 12:40:03
	char remove_date[30];    	//�������� 9999-12-31 23:59:59 Ĭ��
	unsigned char reason[20];   //ԭ��   linux 20
	char status;                //'0'���� '1'��ͣ
	char last_update_user[20];  //����Ա 
}MON_BNW_REQUEST;

//��ظ��ɳֱֲ���/�ɽ�������ṹ���� ��datatype=60044��
typedef struct tagStockTradeRequest
{
	int requestid;              //��������1.save

	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL
	char account_id[30];		//��ָproduct_id/fund_account/pz_account��"0"Ϊȫ�� 

	char item_code[20];
	char position_type;
	char comparison_direction;  //'G'���� 'L'С��
	double threshold_level1;
	char action_level1[20];     //FORBIDDEN ALERT2 ALERT3
	double threshold_level2;
	char action_level2[20];
	double threshold_level3;
	char action_level3[20];
	char status;                //'0'���� '1'��ͣ
	char last_update_user[20];  //����Ա 
}STOCK_TRADE_REQUEST;

//��ؾ�ֵ��������ṹ���� ��datatype=60045��
typedef struct tagNavRRequest
{
	int requestid;              //��������1.save

	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL
	char account_id[30];		//��ָproduct_id/fund_account/pz_account��"0"Ϊȫ�� 

	char item_code[20];
	char position_type;
	char comparison_direction;  //'G'���� 'L'С��
	double threshold_level1;
	char action_level1[20];     //FORBIDDEN ALERT2 ALERT3
	double threshold_level2;
	char action_level2[20];
	double threshold_level3;
	char action_level3[20];
	char status;                //'0'���� '1'��ͣ
	char last_update_user[20];  //����Ա 
}NAV_R_REQUEST;

//�����׿�������ṹ���� ��datatype=60046��
typedef struct tagReversTradeRequest
{
	int requestid;              //��������1.save 2.delete����һ��ɾ��

	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL

	char account_id[30];		//��ָproduct_id/fund_account/pz_account��"0"Ϊȫ�� 
	char item_code[20];
	char position_type;
	char add_date[30];          //��ʼ���� 2015-03-19 12:40:03
	char remove_date[30];    	//�������� 9999-12-31 23:59:59 Ĭ��
	char status;                //'0'���� '1'��ͣ
	char last_update_user[20];  //����Ա 
}REVERS_TRADE_REQUEST;

//���ں�Լ��������ṹ���� ��datatype=60047��
typedef struct tagFuMaturityRequest
{
	int requestid;              //��������1.save

	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL

	char account_id[30];		//��ָproduct_id/fund_account/pz_account��"0"Ϊȫ�� 
	char item_code[20];
	char position_type;
	char start_date[30];        //��ʼ���� 2015-03-19 12:40:03
	char end_date[30];    	    //�������� 9999-12-31 23:59:59 Ĭ��
	char status;                //'0'���� '1'��ͣ
	char last_update_user[20];  //����Ա 
}FU_MATURITY_REQUEST;

//�ֵ���λ��������ṹ���� ��datatype=60048��
typedef struct tagNavPosCtrlRequest
{
	int requestid;                  //��������1.save 2.delete

	//int  record_num;            

	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL
	char account_id[30];		//��ָproduct_id/fund_account/pz_account��"0"Ϊȫ�� 

	char item_code[20];
	char sub_item_code[20];
	char position_type;         //'0'ȫ�� '1'��Ʊ '3'�ڻ�
	double from_nav_ex;
	double to_nav_in;
	char comparison_direction;  //'G'���� 'L'С��
	double threshold_level1;
	char action_level1[20];     //FORBIDDEN ALERT2 ALERT3
	double threshold_level2;
	char action_level2[20];
	double threshold_level3;
	char action_level3[20];
	char status;                //'0'���� '1'��ͣ
	char last_update_user[20];  //����Ա 
}NAV_POS_CTRL_REQUEST;

//ͬ���ʲ���������ṹ���� ��datatype=60049��
typedef struct tagAssetClassRequest
{
	int  requestid;             //��������1.save 2.delete

	//int  record_num;            

	char item_category[20];
	char class_type[20];        //PB/PRODUCT/FUND/SUB
	char time_type[20];			//TR/IN/CL
	char account_id[30];		//��ָproduct_id/fund_account/pz_account��"0"Ϊȫ�� 

	char item_code[20];
	char sub_item_code[20];
	char position_type;         //'0'ȫ�� '1'��Ʊ '3'�ڻ�
	char comparison_direction;  //'G'���� 'L'С��
	double threshold_level1;
	char action_level1[20];     //FORBIDDEN ALERT2 ALERT3
	double threshold_level2;
	char action_level2[20];
	double threshold_level3;
	char action_level3[20];
	char status;                //'0'���� '1'��ͣ
	char last_update_user[20];  //����Ա 
}ASSET_CLASS_REQUEST;

//ָ������Ϣ����ṹ���� ��datatype=60050��
typedef struct tagInstJrnalReq
{
	int requestid;             //1.in_check 2.tr_check 3.ָ����Ϣ

	int entrust_inst_id;       //2ʹ��
	int limit;                 //��ȡ����
	int offset;				   //�ڼ�����ʼ 1~
}INST_JRNAL_REQ;

typedef struct tagMonInCheckInfo
{
	int  sequence_no;
	char item_code[20];
	char sub_item_code[20];
	char account_id[30];			//��ָproduct_id/fund_account/pz_account��"0"Ϊȫ�� 
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
	int  entrust_inst_id;			//ָ����	
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
	int	   entrust_inst_id;				//ָ����	

	char   pz_account[30];				//�����˺�
	char   position_type;				//'1'��Ʊ '3'�ڻ�
	char   issue_cd[30];				//��Լ����
	char   product_id[30];
	char   work_flow_type[20];          //������
	char   from_user_id[20];			//ָ����Դ
	char   order_type[20];				//�������ͣ���ͨ����/�㷨���� 
	char   quote_type[20];				//���۷�ʽ��
	double single_over_price;			//���ʳ��ۣ�%��
	//����Ϊ�㷨���׶���-----
	char   single_quantity[20];			//���ʻ�׼��
	double single_quantity_p;			//��׼������
	double order_interval;				//�µ����
	double withdraw_interval;			//�������
	int    over_price_order_amt;		//�������ñ���
	double volatility_range;			//��������
	int    singe_min_volume;			//������С��
	int    singe_max_volume;			//���������
	int    effective_time;				//��Чʱ��
	int    max_entrust_num;				//���ί�д���
	//------
	char   trans_code[20];			    //BUY/SELL/FU_B_OPEN/FU_S_OPEN/FU_B_OFF/FU_S_OFF
	char   direction;					//����'B'-�� 'S'-��
	char   offset_flag;                 //'0'-�� '1'-ƽ '3'-ƽ��
	char   hedge_flag;				    //'1' 
	char   entrust_prop[20];			//ί������ �޼ۡ��м۵� 
	double entrust_inst_price;			//ָ��۸�
	double entrust_inst_quantity;		//ָ������
	char   cond_entrust_type[20];		//����������
	char   inst_start_date[30];			//ָ�ʼʱ��
	char   currency_cd[3];				//�������� 'CNY'����� 'USD'��Ԫ 'HKD'�۱�

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

//�û��Ͳ�Ʒ��ϵ����ṹ���� ��datatype=60051��
typedef struct tagUserProductReq
{
	/*��������1.save 2.find[key:user_id] 3.delete[key:user_id]
	4.find[key:product_id] 5.delete[key:product_id] 6.find
	*/
	int requestid;                     

	char user_id[20];
	char product_id[30];
	char account_type[20];		
	char last_update_user[20];  //����Ա 
}USER_PRODUCT_REQ;

typedef struct tagUserProductRep
{
	char user_id[20];
	char product_id[30];
	char account_type[20];		
	char last_update_user[20];  //����Ա 
}USER_PRODUCT_REP;

//��Ʒ��Ϣ����ṹ���� ��datatype=60052��
typedef struct tagProductIdInfoReq
{
	/*������Ϣid 1--�ʲ� */
	int requestid;			    

	char product_id[30];		//��Ʒid
}PRODUCT_ID_INFO_REQ;

typedef struct tagProductAssetsInfo
{
	double dDynamicRight;		//���ʲ�
	double dMargin;			    //ռ�ñ�֤��
	double dFrozenMargin;	    //���ᱣ֤��
	double dblDrawableCash;	    //��ȡ�ʽ�
	double dAvaiableSum;	    //�����ʽ�
	double market_value;		//֤ȯ����ֵ
	double dHasQuota;		    //��ծ
	double Nav;					//��ֵ
	double Nav_A;				//A���� ��ֵ
	double Nav_B;				//B���� ��ֵ
}PRODUCT_ASSETS_INFO;

typedef struct tagMonProductIdAssets
{
	int success;				//0-�ɹ�
	int requestid;				//1-�ʲ�
	char product_id[30];		//��Ʒid

	PRODUCT_ASSETS_INFO field;  //��Ʒ�ʲ�
}MON_PRODUCT_ID_ASSETS;

//���ʺ��û���ϵ����ṹ���� ��datatype=60053��
typedef struct tagSubAccUserReq
{
	int requestid;				//��������1.save 2.find 3.delete

	char pz_account[30];		//�����˺�
	char work_flow_type[20];	//"TR_1ROLE"/"TR_3ROLE" 
	char user_id[20];
}SUBACC_USER_REQ;

typedef struct tagSubAccUserRep
{
	char pz_account[30];		//�����˺�
	char work_flow_type[20];	//"TR_1ROLE"/"TR_3ROLE" 
	char user_id[20];
}SUBACC_USER_REP;

//��Ʒ���ʺ��û���ϵ����ṹ���� ��datatype=60054��
typedef struct tagPdSubAccUserReq
{
	int requestid;				//��������1.save 2.find 3.delete

	char product_id[30];		//��Ʒid
	char work_flow_type[20];	//"TR_1ROLE"/"TR_3ROLE"
	char user_id[20];
	char user_role_cd[20];
}PD_SUBACC_USER_REQ;

typedef struct tagPdSubAccUserRep
{
	char product_id[30];		//��Ʒid
	char work_flow_type[20];	//"TR_1ROLE"/"TR_3ROLE" 
	char user_id[20];
	char user_role_cd[20];
}PD_SUBACC_USER_REP;

//��Ʒ����Ȩ������ṹ���� ��datatype=60055��
typedef struct tagProductEquityReq
{
	/*������Ϣid 1--add 2--modify 3--delete 4--find*/
	int requestid;			    

	char product_id[30];		//��Ʒid
	char asofdate[30];			//��ѯ����
	unsigned char equity_name[40];
	double equity_value;
	char last_update_user[20];  //����Ա 

	char flag;                  //'0':Ĭ������ '1':ӯ��
}PRODUCT_EQUITY_REQ;

typedef struct tagProductEquityInfo
{
	char product_id[30];			//��Ʒid
	char asofdate[30];
	unsigned char equity_name[80];	//Ȩ������ linux 40*2
	double equity_value;			//Ȩ��ֵ
	char last_update_user[20];		//����Ա 
}PRODUCT_EQUITY_INFO;

//�����ջ�׼������ṹ���� ��datatype=60056��
typedef struct tagBaseDateReq
{
	int requestid;				//�������� 1.find
}BASE_DATE_REQ;

typedef struct tagBaseDateRep
{
	char base_date_cd[20];
	char asofdate[30]; 
	char action_status;
	char last_date[30];
	char next_date[30];
}BASE_DATE_REP;

//�ڻ���Լ��������ṹ���� ��datatype=60057��
typedef struct tagMarketDataFutureReq
{
	int requestid;				//�������� 1.find

	char asofdate[30]; 
}MARKET_DATA_FUTURE_REQ;

//�������ƽṹ�嶨��  ��datatype = 60058��
typedef struct tagTradeLimitReq
{
	int requestid; //1��find 2��update

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

//������Ϣ(Datatype��999)
typedef struct tagMonitorHeartInfo
{
	int serverType;		//1�����ף�2�����飬3���ʹܣ�4��Web
	int date;			//�磺20150408
	int time;			//�磺134550
}MONITOR_HEART_INFO;

//�û�������Ϣ
typedef struct tagUserLoginInfo
{
	char username[20];
	char loginIP[20];
}USER_LOGIN_INFO;
//--------------------------------------------------------------------------------------
//MD<-->�ʹ� 

//---------------------------------------------------------------------------------
//10�������µ�--���롾datatype=10��/������datatype=11��
typedef struct tagStockTrade
{
	int member_id;
	char mobile[16];				
	int direction;					//����1-���� 2-���� 3-��������������
	char symbol[16];				//֤ȯ����
	double quantity;				//����
	int mode;						//�µ�ģʽ��
									//1-�޼�ί��
									//2-�мۡ�����ַ����ż۸�ί�С�
									//3-�мۡ�������ż۸�ί�С�
									//4-�мۡ��ʱ�ɽ�ʣ�೷��ί�С�
									//5-�мۡ����������嵵������ί�С�
									//6-�мۡ���ȫ��ɽ�����ί�С�
									//7-�мۡ��������嵵��ת�޼�ί�С�
									//
									//
									//������������100-����ֹ�����¼۵��ڴ����۸�������ת��Ϊ�м�ί�У���
									//������������101-����ֹ�����¼۵��ڴ����۸�������ת��Ϊ�м�ί�У���
	double price;					//���ۣ��м�ί��ʱ��APP�ṩ��ͣ�ۣ�
	double condition_price;			//�����۸�
	char UserProductInfo[11];		//+��Դ
//ǰ�û�����
	char OrderRef[13];              //��������
}APP_BUY_SALE;

//�����µ����ؽṹ���� ���롾datatype=10��/������datatype=11��
typedef struct tagEntrustReply
{
	int success;

	APP_BUY_SALE field;	//��ע�������Ʊ����������ʱ,quantity����������
}APP_ENTRUST_REPLY;

//50�����󳷵����ݽṹ���塾datatype=50��
typedef struct tagStockCancel
{
	int member_id;
	int EntrustID;					//�µ���
	char mobile[16];
	int direction;					//����1-���������룩 2-������������ 3-������������1�� 4-һ��ƽ��
	char symbol[16];				//��Լ��
}STOCK_CANCEL;

//���ؽṹ���塾datatype=50��
typedef struct tagStockCancelReply
{
	int success;	//0-�ɹ�
	int nEntrustID;
}STOCK_CANCEL_REPLY;

//----------------------------------------------------------------------
//ME-->TS
//ί�С�datatype=201�� ������datatype=204�� ����Ա������datatype=206�� 
typedef struct tagEntrust
{
	int EntrustID;					//�µ���
	char mobile[16];				//����pz_account
	int direction;					//����1-���� 2-����
	char symbol[16];				//֤ȯ����
	double quantity;				//����
	int mode;						//�µ�ģʽ��
									//1-�޼�ί��
									//2-�мۡ�����ַ����ż۸�ί�С�
									//3-�мۡ�������ż۸�ί�С�
									//4-�мۡ��ʱ�ɽ�ʣ�೷��ί�С�
									//5-�мۡ����������嵵������ί�С�
									//6-�мۡ���ȫ��ɽ�����ί�С�
									//7-�мۡ��������嵵��ת�޼�ί�С�
	double price;					//���ۣ��޼�ί��ʱ��Ч��
}ME_ENTRUST;

//---------------------------------------------------------------------------
//--- public���� ---

typedef struct tagSecPositionEx
{
	std::string position_type;
	std::string security_type;

	SECURITY_POSITION sp;
	double dNewestPrice;		//���¼�
	double settled_quantity;	//�ϴν���׼���� +�ڻ� 2015/08/12
}SECURITY_POSITION_EX;

typedef struct tagMarginDebt
{
	double contract_value;
	double paid_principal;
	double initial_leverage;
	double margin;

	double accrued_interest;	//+Ӧ����Ϣ 20150323
}ST_MARGIN_DEBT;


typedef struct tagMarginDebtTimer
{
	std::string account;	//�˺�

	long long llDebtID;		//��Լ��
	int maturity_date;		//��Լ�������� YYYYMMDD
	double contract_value;	//�����Ǯ��Լ���
	double paid_principal;	//�Ѿ�֧��������
	double lending_rate;	//����
	int initial_term;		//չ�����ޣ�������
	bool bAutoExtend;		//�Զ�չ�ڱ�־

	double initial_leverage;
	double margin;
	double accrued_interest;	//+Ӧ����Ϣ 20150323	

	std::string debt_type;	//PZTY-�����ײ� PZ-��/���ײ�
	int contract_date;
	char initial_cycle;		//D-���ײ� M-���ײ�
}MARGIN_DEBT_TIMER;

//֤ȯ��λ����
typedef struct tagPositionTimer
{	
	char SecurityCode[32];		//֤ȯ����

	std::string position_type;
	std::string security_type;

	double quantity;			//֤ȯ������
	double quantity_can_use;	//֤ȯ��������
	double real_open_amount;	//��������
	double real_off_amount;		//��������
	double cost_balance;		//�ɱ����
	double keep_cost_price;		//�ɱ���

	long long debt_id;
}SECURITY_POSITION_TIMER;

typedef struct tagConditionBuy
{
	APP_BUY_SALE field;

	std::string header_session;
	std::string header_usrid;
	int nOrderID;
}CONDITION_BUY;

//�ʽ��˻����ָ�궨�塾datatype=60501��
typedef struct tagFundMon
{
	char account[32];		//�ʽ��˻�

	double dblAsset;		//���ʲ�
	double dblNetAsset;		//���ʲ�
	double dblMarketValue;	//֤ȯ��ֵ
	double dblDebt;			//��ծ
	double dblMargin3rd;	//�������ʲ�����������֤��
	double dblProfit;		//����ӯ��
	double dblPreAlertLine;	//Ԥ����
	double dblCoverLine;	//ƽ����
	double dblRiskDegree;	//���ն�
}FUND_MON;

// ���ģ������Ԥ���ṹ�嶨��
// �ʹ� -- �����նˡ�datatype=60502�� MULTI_MSGS_HEAD��requestid=1
// �ʹ� --  CTPǰ�á�datatype=70003�� MULTI_MSGS_HEAD��requestid=1
typedef struct tagAlarmIn
{
	int nAlarmDate;						//�������� YYYYMMDD
	int nAlarmTime;						//����ʱ�� HHMMSS	
	
	int nRiskCtrlType;					//������� 
											// 1-�ڰ�����
											// 2-�ֲֹɱ�
											// 3-�ɽ���
											// 4-��ֵ
											// 5- λ����
											// 6-������
											// 7-���ں�Լ
											// 8-�ʲ�����

	char class_type[20];				// 0 / PRODUCT / FUND / SUB
	char item_code[20];					//���������
	char sub_item_code[20];				//���ָ��

	int nAlarmLevel;					//Ԥ������ 
											// -1����ɫԤ���������أ� -2����ɫԤ��(ALERT2) -3����ɫԤ��(ALERT3) -4����ɫԤ��(ALERT4-���ᣩ 0���޼���

	char account[30];					//�˺�
	char issue_cd[30];					//֤ȯ����

	double dblParamThreshhold;			//�������õı�����ֵ
	double dblAlarmValue;				//���������ĵ�ǰֵ
	char other_info[160];				//CTPFRONT����
	unsigned char unother_info[160];	//ADMIN����
}ALARM_IN;

#pragma pack (pop)      /*��ԭĬ���ֽڶ���*/

#endif

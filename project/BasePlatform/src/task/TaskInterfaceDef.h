#ifndef WORKPLAN_TASK_INTERFACE_DEF_H_
#define WORKPLAN_TASK_INTERFACE_DEF_H_

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

#define STOCK_SECURITY_TYPE          "1"    //��Ʊ
#define FUTURE_SECURITY_TYPE         "2"    //�ڻ�


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
	int num;
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

typedef struct tagMemberIdRep
{
	int success;		//0-�ɹ�
	int member_id;		//��Աid
}APP_MEMBER_ID_REP;

#pragma pack (pop)      /*��ԭĬ���ֽڶ���*/

#endif

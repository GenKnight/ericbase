#ifndef ITSTATION_DATASERVER_PROCTROL_H_
#define ITSTATION_DATASERVER_PROCTROL_H_

#include "dataserver/DataServerStruct.h"

namespace itstation {

#define REQ_HIS_KLINE '0'
#define REQ_HIS_TICK '1'
#define REQ_RUN_TICK '2'

#define RSP_HIS_KLINE 'a'
typedef char ClientRequestType;

#define COUNT_MOD_ALL '0'	//����K��
#define COUNT_MOD_IN_NUMBER '1'	//��K����������
#define COUNT_MOD_TIME_RANGE '2'	//��ʱ�䷶Χ����
typedef char KlineCountMode;	//K�߼�����ʽ

#define SYMBOL_FOR_ALL Symbol(PRODUCT_STOCK, EXCHANGE_SSE, "999999")
#define NAN_SYMBOL Symbol(PRODUCT_OTHER, EXCHANGE_OTHER, "")

#pragma pack(1)
struct ProtocolHead {
	ClientRequestType type;
};

struct HisKlineRequtInfo {
	Symbol sym;
	KlineDimensionType dim;
	short dim_count;
	KlineCountMode count_mode;
	long long mode_data;	//��ʾK�߸�������ʼ����(����20141022)

	HisKlineRequtInfo() : sym(Symbol()), dim(DIMENSION_MINUTE)
		, dim_count(1), count_mode(COUNT_MOD_ALL), mode_data(0)
	{

	}

	bool operator==(const HisKlineRequtInfo& other) const {
		return sym == other.sym && dim == other.dim && dim_count == other.dim_count
			&& count_mode == other.count_mode && mode_data == other.mode_data;
	}
	bool operator!=(const HisKlineRequtInfo& other) const {
		return !(*this == other);
	}
	bool operator<(const HisKlineRequtInfo& other) const {
		return sym < other.sym || (sym == other.sym && dim < other.dim) ||
			(sym == other.sym && dim == other.dim && dim_count < other.dim_count) || 
			(sym == other.sym && dim == other.dim && dim_count == other.dim_count && count_mode < other.count_mode) || 
			(sym == other.sym && dim == other.dim && dim_count == other.dim_count && count_mode == other.count_mode && mode_data < other.mode_data);
	}
};

struct HisKlineRequt : public ProtocolHead{
	int num;
	HisKlineRequtInfo info[0];
};

struct RunTickRequt : public ProtocolHead{
	int num;
	bool is_sub;	//true:����  false:ȡ������
	Symbol symbols[0];
};

struct RspHisKline : public ProtocolHead {
	HisKlineRequtInfo info;
	int num;
	Kline data[0];
};
#pragma pack()

}

#endif
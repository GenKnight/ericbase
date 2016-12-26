#include <iostream>
#include <sstream>
#include <map>
#include <signal.h>
#include <stdio.h>
#include <memory>
#include <vector>
#include <set>
#include <assert.h>
#include <unordered_map>
#include <boost/thread.hpp> 
#include <boost/bind/bind.hpp>
#include <queue>
#include <Winsock2.h>  
//#include "./samplecode/hello-world.h"

#include <boost/progress.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/ref.hpp>
#include <functional>
#include <numeric>

#include "../../../BasePlatform/src/task/TaskInterfaceDef.h"
#include "AsioTcpServer/AsioNetLibrary.h"

#include "utility/Applog.h"

using namespace boost;
using namespace std;
using namespace itstation;

char * mystrcpy(char *strDest, const char *strSrc)
{
	assert(strDest != NULL && strSrc != NULL);

	char *temp = strDest;
	while ( (*strDest++ = *strSrc++) != '\0' )
		NULL;

	return temp;
}

int mystrlen(const char *str)
{
	assert(str != NULL);
	int len = 0;
	while ( *str++ != '\0' )
	{
		len++;
	}

	return len;
}

void BubbleSort(vector<int> &data)
{
	int count = data.size();
	bool tag = false;

	for ( int i = 0; i < count; i++ )
	{
		tag = false;
		for ( int j = 0; j < count-i-1; j++ )
		{
			if ( data[j] > data[j+1] )
			{
				tag = true;
				int temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}

		if ( !tag )
		{
			break;
		}
	}
}

void QuickSort( vector<int> &data, int left, int right )
{
	if ( left < right )
	{
		int index = data[left];
		int low = left;
		int high = right;

		while ( low < high )
		{
			while ( low < high && index < data[high] ) high--;
			data[low] = data[high];
			while ( low < high && index > data[low] ) low++;
			data[high] = data[low];
		}

		data[low] = index;

		QuickSort(data, left, low-1);
		QuickSort(data, low+1, right);
	}
}


void SelectSort( vector<int> &data )
{
	int count = data.size();
	for ( int i = 0; i < count; i++ )
	{
		int min = data[i]; 
		int index = i;
		for ( int j = i+1; j < count; j++ )
		{
			if ( min > data[j] )
			{
				min = data[j];
				index = j;
			}
		}

		if ( i != index )
		{
			int temp = data[i];
			data[i] = data[index];
			data[index] = temp;
		}
	}
}

typedef struct tagMemOrderInfo
{	
	int	   entrust_id;				//指令编号
	char OrderRef[30];
	char pz_account[30];				//子账账号
	string issue_cd;				//合约代码
	string entrust_prop;
	double entrust_price;			//委托价格
	double entrust_quantity;		//委托数量
	double trade_price;	
	double trade_quantity;
	double frozen_value;
	double frozen_fee;
	string UserProductInfo;
	char   entrust_status;
	string fund_account;
}MEM_ORDER_INFO;

class CB
{
public:
	virtual void f(int) = 0;
};

class CD : public CB
{
public:
	void f(int) { cout << "CD::f(int,int)" << endl; }
	void test() { }
};

void Permutation(char* pStr, char* pBegin)  
{  
	assert(pStr && pBegin);  

	if(*pBegin == '\0')  
		printf("%s\n",pStr);  
	else  
	{  
		for(char* pCh = pBegin; *pCh != '\0'; pCh++)  
		{  
			swap(*pBegin,*pCh);  
			Permutation(pStr, pBegin+1);  
			swap(*pBegin,*pCh);  
		}  
	}  
}  

void sockfunc()
{
	WSADATA  Ws;   
	WSAStartup(MAKEWORD(2,2), &Ws);

	SOCKET hs = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(sockaddr_in));  
	addr.sin_family = AF_INET;            /*地址类型为AF_INET*/  
	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	addr.sin_port = htons(61616);   /*端口号*/ 

	connect(hs,(struct sockaddr *)&addr,sizeof(addr));

	send(hs, "hello", sizeof("hello"), 0);
}

class Basee
{
public:
	typedef void result_type;

	void operator()(int &x)
	{
		x *= x;
	}
};

template <typename TP> 
struct COne 
{   // default member is public
	typedef TP one_value_type;
}; 
template <typename COne>   // 用一个模板类作为模板参数, 这是很常见的
struct CTwo 
{
	// 请注意以下两行
	//typedef COne::one_value_type  two_value_type;   // *1  原来这里为Cone:one_value我改成Cone::value
	typedef typename COne::one_value_type  two_value_type; // *2  原来这里为Cone:one_value我改成Cone::value
}; 

class Client
	: public ITcpMessageNotify
{
public:

	explicit Client()
	{

	}
	virtual ~Client()
	{

	}
protected:

	virtual void OnMessageStream( const std::string& stream )
	{
		static int n = 0;
		if (n == 0)
		{
			SYSTEMTIME st;
			GetLocalTime(&st);
			//nDate = st.wYear * 10000 + st.wMonth * 100 + st.wDay;
			long nTime = st.wHour * 10000 * 1000 + st.wMinute * 100 * 1000 + st.wSecond * 1000 + st.wMilliseconds;
			std::cout << "start time" << nTime << std::endl;
		}
		n++;
		if (n == 10000)
		{
			SYSTEMTIME st;
			GetLocalTime(&st);
			//nDate = st.wYear * 10000 + st.wMonth * 100 + st.wDay;
			long nTime = st.wHour * 10000 * 1000 + st.wMinute * 100 * 1000 + st.wSecond * 1000 + st.wMilliseconds;
			std::cout << "end time" << nTime << std::endl;
		}
		//cout << stream << endl;
	}
};

int kidding(int &a, int &b)
{
	a ^= b ^= a ^= b;

	return 0;
}

struct atp_message
{
	int type;
	std::shared_ptr<std::string> param1;
	void* param2;
};

void shareptr_test(atp_message msg)
{
	cout << msg.param1.use_count() << endl;
}

template<typename T>
class InnerClass {
public:
	static void DoTest() {
		printf("This is InterClass::DoTest().\n");
	}
};

template<typename T>
class OuterClass {
public:
	template<typename T2>
	void func() {
		T2::DoTest();
	}
};

template<typename T>
void DoTest(OuterClass<T>& outClass) {
	//限定符.前面的变量outClass的类型依赖于模板参数，而其后面的限定符也是一个
	//模板符号，在这种情况下，为了使编译器能够确切的清楚func符号的类型，我们
	//需要在.和func之间插入template关键字，以明确告诉编译器func的类型。
	outClass.template func<InnerClass<T> >();
}

int main_main(int argc,char *argv[])
{
    int i = 16;

    int j = i >> 4;

    cout << j << endl;

	OuterClass<int> outClass;
	DoTest(outClass);

    //std::string buf = "123456789";
    //int kHeaderLen = 1;
    //int nameLen = 3;
    //std::string typeName(buf.begin() + kHeaderLen, buf.begin() + kHeaderLen + nameLen - 1);

    //std::cout << typeName << std::endl;
	getchar();
	return 0;
}


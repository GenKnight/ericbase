#include <iostream>
#include "utility/include_common.h"
#include "utility/QThread.h"
#include "utility/QClientSocket.h"
using namespace std;
using namespace utility;

class client 
	: public IThreadRunner
{
public:
	static client* instance();
	static client* getinstance();

	void start_client();
	void stop_client();

	//thread
	virtual void run();
private:
	client();
	virtual ~client();
	client(const client&);
	client& operator = (const client&);

	static client* m_pinstance;
private:
	bool m_bstop;

	QClientSocket *tcpclient;
};
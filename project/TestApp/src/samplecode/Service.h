#include <iostream>

#include "utility/QThread.h"
#include "utility/tcpserver.h"
using namespace std;
using namespace utility;

class server 
	: public IThreadRunner
{
public:
	static server* instance();
	static server* getinstance();

	void start_server();
	void stop_server();

	//thread
	virtual void run();
private:
	server();
	virtual ~server();
	server(const server&);
	server& operator = (const server&);

	static server* m_pinstance;
private:
	bool m_bstop;

	TCPServer *tcpserver;
};
#include "Service.h"

server* server::m_pinstance = NULL;

server::server(){}

server::~server(){}

server* server::instance()
{
	if (m_pinstance == NULL) {
		m_pinstance = new server();
	}
	return m_pinstance;
}

server* server::getinstance()
{
	if (m_pinstance == NULL) {
		std::cout << "server not int" << std::endl;
	}
	return m_pinstance;
}

void server::start_server()
{
	m_bstop = false;

	std::string host_name = "127.0.0.1";
	std::string port = "9977";
	tcpserver = new TCPServer(host_name, port);

	QCThreadManager::createThread(*tcpserver);
	QCThreadManager::createThread(*this);
}

void server::stop_server()
{
	if (tcpserver) {
		tcpserver->Stop();

		delete tcpserver;
		tcpserver = NULL;
	}

	m_bstop = true;
}

void server::run()
{
	while(!m_bstop) {
		q_sleep(1000);
	}
}

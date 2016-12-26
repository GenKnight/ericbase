#include "Client.h"
#include "utility/QAddress.h"

client* client::m_pinstance = NULL;

client::client(){}

client::~client(){}

client* client::instance()
{
	if (m_pinstance == NULL) {
		m_pinstance = new client();
	}
	return m_pinstance;
}

client* client::getinstance()
{
	if (m_pinstance == NULL) {
		std::cout << "client not int" << std::endl;
	}
	return m_pinstance;
}

void client::start_client()
{
	m_bstop = false;

	std::string host_name = "127.0.0.1";
	std::string port = "9977";
	QAddress addr;
	addr.host_name = "127.0.0.1";
	addr.port = "9977";
	tcpclient = new QClientSocket();
	tcpclient->connectServer(addr);

	QCThreadManager::createThread(*this);
}

void client::stop_client()
{
	if (tcpclient) {
		delete tcpclient;
		tcpclient = NULL;
	}

	m_bstop = true;
}

void client::run()
{
	while(!m_bstop) {
		std::string data;
		tcpclient->receiveData(data);

		cout << data << endl;

		tcpclient->sendData(data);
	}
}

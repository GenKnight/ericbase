#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <iostream>
using boost::asio::ip::tcp;
#define max_len 1024
class clientSession
	:public boost::enable_shared_from_this<clientSession>
{
public:
	clientSession(boost::asio::io_service& ioservice)
		:m_socket(ioservice)
	{
		memset(data_,'\0',sizeof(data_));
	}
	~clientSession()
	{}
	tcp::socket& socket()
	{
		return m_socket;
	}
	void start()
	{
		boost::asio::async_write(m_socket,
			boost::asio::buffer("link successed!"),
			boost::bind(&clientSession::handle_write,shared_from_this(),
			boost::asio::placeholders::error));

		/*async_read���ͻ���һ�������ǲ��ܽ���handle_read����,��������ҵ��������ڣ�������ң�лл*/

		// --�Ѿ������boost::asio::async_read(...)��ȡ���ֽڳ��Ȳ��ܴ����������ĳ��ȣ�����ͻ����
		// ioservice.run()�̵߳ȴ���read����ľͲ�ִ���ˡ�
		//boost::asio::async_read(m_socket,boost::asio::buffer(data_,max_len),

		//         boost::bind(&clientSession::handle_read,shared_from_this(),

		//         boost::asio::placeholders::error));
		//max_len���Ի��ɽ�С�����֣��ͻᷢ��async_read_some������������δ���������

		m_socket.async_read_some(boost::asio::buffer(data_,max_len),
			boost::bind(&clientSession::handle_read,shared_from_this(),
			boost::asio::placeholders::error));
	}
private:
	void handle_write(const boost::system::error_code& error)
	{

		if(error)
		{
			m_socket.close();
		}

	}
	void handle_read(const boost::system::error_code& error)
	{

		if(!error)
		{
			std::cout << data_ << std::endl;
			//boost::asio::async_read(m_socket,boost::asio::buffer(data_,max_len),

			//     boost::bind(&clientSession::handle_read,shared_from_this(),

			//     boost::asio::placeholders::error));

			m_socket.async_read_some(boost::asio::buffer(data_,max_len),
				boost::bind(&clientSession::handle_read,shared_from_this(),
				boost::asio::placeholders::error));
		}
		else
		{
			m_socket.close();
		}

	}
private:
	tcp::socket m_socket;
	char data_[max_len];
};

class serverApp
{
	typedef boost::shared_ptr<clientSession> session_ptr;
public:
	serverApp(boost::asio::io_service& ioservice,tcp::endpoint& endpoint)
		:m_ioservice(ioservice),
		acceptor_(ioservice,endpoint)
	{
		session_ptr new_session(new clientSession(ioservice));
		acceptor_.async_accept(new_session->socket(),
			boost::bind(&serverApp::handle_accept,this,boost::asio::placeholders::error,
			new_session));
	}
	~serverApp()
	{
	}
private:
	void handle_accept(const boost::system::error_code& error,session_ptr& session)
	{
		if(!error)
		{
			std::cout << "get a new client!" << std::endl;
			//ʵ�ֶ�ÿ���ͻ��˵����ݴ���

			session->start();
			//�����Ӧ�ÿ���ΪʲôҪ��session���˰ɣ�ÿһ��session����һ���ͻ���

			session_ptr new_session(new clientSession(m_ioservice));
			acceptor_.async_accept(new_session->socket(),
				boost::bind(&serverApp::handle_accept,this,boost::asio::placeholders::error,
				new_session));
		}
	}
private:
	boost::asio::io_service& m_ioservice;
	tcp::acceptor acceptor_;
};

int main(int argc , char* argv[])
{
	boost::asio::io_service myIoService;
	short port = 8100/*argv[1]*/;
	//�����õ���inet4

	tcp::endpoint endPoint(tcp::v4(),port);
	//�նˣ����Կ���sockaddr_in����ɺ󣬾�Ҫaccept��

	serverApp sa(myIoService,endPoint);
	//�����շ��߼�

	myIoService.run();
	return 0;
}
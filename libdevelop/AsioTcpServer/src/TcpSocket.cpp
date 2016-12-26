#include "TcpSocket.h"
#include <sstream>
#include <string.h>
#include <string>
#include "utility/Thread.h"
namespace itstation {

	clientSession::clientSession(boost::asio::io_service& ioservice, ITcpMessageNotify* ptrNotify)
		: m_socket(ioservice), m_ptrNotify(ptrNotify)
	{
	}
	clientSession::~clientSession()
	{

	}

	void clientSession::SetCallBackError(const std::function<void(int)>& f)
	{
		m_callbackError = f;
	}

	void clientSession::StartUp()
	{
		//boost::asio::async_read(...)��ȡ���ֽڳ��Ȳ��ܴ����������ĳ��ȣ�����ͻ����
		//ioservice.run()�̵߳ȴ���read����ľͲ�ִ���ˡ�
		boost::asio::async_read(m_socket,
			boost::asio::buffer((char*)headlen, kHeaderLen),
			boost::bind(&clientSession::__HandleReadHead,shared_from_this(),
			boost::asio::placeholders::error));

		//��������»᷵�أ�1.����������2.transfer_at_leastΪ��(�յ��ض������ֽڼ�����)��3.�д�����
		//boost::asio::async_read(m_socket, boost::asio::buffer(&m_MessageHead,sizeof(TCP_MSG_HEAD)),
		//	[this](const boost::system::error_code& ec, size_t size)
		//{
		//	if( ec != nullptr )
		//	{
		//		__HandleError(ec);
		//		return;
		//	}
		//	else
		//	{
		//		std::cout << m_MessageHead.datatype << " " << m_MessageHead.datasize  << std::endl;

		//		char *messageBody = new char(m_MessageHead.datasize);

		//		boost::asio::async_read(m_socket,boost::asio::buffer(messageBody, m_MessageHead.datasize),
		//			boost::bind(&clientSession::Handle_Callback,shared_from_this(),
		//			boost::asio::placeholders::error));

		//		TCP_MSG_HEAD header;
		//		memcpy(&header, &m_MessageHead, sizeof(TCP_MSG_HEAD));
		//		const char *ptrData = messageBody;

		//		m_ptrNotify->OnMessageStream( ptrData, header);

		//		delete[] messageBody;
		//		messageBody = NULL;
		//	}

		//	StartUp();
		//});

		//max_len���Ի��ɽ�С�����֣��ͻᷢ��async_read_some������������δ���������
		//m_socket->async_read_some(boost::asio::buffer(&m_MessageHead,sizeof(TCP_MSG_HEAD)),
		//	boost::bind(&clientSession::handle_read,shared_from_this(), boost::asio::placeholders::error));
	}

	void clientSession::__HandleReadHead(const boost::system::error_code& error)
	{
		if(!error)
		{
			//std::cout << m_MessageHead.datatype << " " << m_MessageHead.datasize  << std::endl;
			//std::shared_ptr<char> messageBody(new char[m_MessageHead.datasize], std::default_delete<char[]>());

			int32_t len = 0;
			memcpy(&len, headlen, sizeof(int32_t));
			len = ntohl(len);

			messageStream.resize(len);

			boost::asio::async_read(m_socket,
				boost::asio::buffer(&messageStream[0], len ),
				boost::bind(&clientSession::__HandleReadBody, shared_from_this(),
				boost::asio::placeholders::error));
		}
		else
		{
			__HandleError(error);
			return;
		}
	}

	void clientSession::__HandleReadBody(const boost::system::error_code& error)
	{

		if(!error)
		{
			m_ptrNotify->SetSessionPtr(GetSelf());

			//������headeͷ������,���շ����Ѿ���ͷ�ӵ��ˣ��ص�����ֱ��decode
			m_ptrNotify->OnMessageStream( messageStream );

			StartUp();
		}
		else
		{
			__HandleError(error);
			return;
		}

	}

	void clientSession::__handleWrite(const std::string &stream, const boost::system::error_code& error)
	{
		if(error)
		{
			__HandleError(error);
			return;
		}

	}

	void clientSession::SendMessages( const std::string &stream )
	{
		if ( stream.length() <= 0 )
		{
			cout << "data error" << endl;
			return;
		}

		//boost::asio::async_write(m_socket,
		//	boost::asio::buffer(stream.c_str(), stream.length()),
		//	boost::bind(&clientSession::__handleWrite,shared_from_this(), stream, boost::asio::placeholders::error));

		//ͬ������
		boost::system::error_code ec;
		write(m_socket, boost::asio::buffer(stream.c_str(), stream.length()), ec);
		if (ec != nullptr)
		{
			__HandleError(ec);
			return;
		}
	}

	boost::asio::ip::tcp::socket& clientSession::GetSocket()
	{
		return m_socket;
	}

	void clientSession::CloseSocket()
	{
		boost::system::error_code ec;
		m_socket.shutdown(boost::asio::ip::tcp::socket::shutdown_send, ec);
		m_socket.close(ec);
	}

	void clientSession::SetConnId(int connId)
	{
		m_connId = connId;
	}

	int clientSession::GetConnId() const
	{
		return m_connId;
	}

	void clientSession::__HandleError( const boost::system::error_code& ec )
	{
		CloseSocket(); 
		cout << ec.message() << endl;
		if (m_callbackError)
			m_callbackError(m_connId);
	}

}

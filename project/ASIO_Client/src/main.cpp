#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
using boost::asio::ip::tcp;
class client : public boost::enable_shared_from_this<client>
{
public:
	client(boost::asio::io_service& io_service)
		: socket(io_service)//����Ͱ�socketʵ������
	{
		memset(getBuffer,'\0',1024);
	}
	~client()
	{}

	void start_connect(tcp::endpoint& endpoint)
	{
		//���ӷ���� connect
		socket.async_connect(endpoint,
			boost::bind(&client::handle_connect,shared_from_this(),boost::asio::placeholders::error)
			);
	}
private:
	void handle_connect(const boost::system::error_code& error)
	{
		if(!error)
		{
			//һ���ϣ��������˷�����Ϣ
			boost::asio::async_write(socket,boost::asio::buffer("hello,server!"),
				boost::bind(&client::handle_write,shared_from_this(),boost::asio::placeholders::error));

			/**��ȡ����˷���������Ϣ
			*�������֣���async_read�����Ͳ��ܽ���handle_read����
			**/

			// --�Ѿ������boost::asio::async_read(...)��ȡ���ֽڳ��Ȳ��ܴ����������ĳ��ȣ�����ͻ����
			// ioservice.run()�̵߳ȴ���read����ľͲ�ִ���ˡ�
			//boost::asio::async_read(socket,
			//     boost::asio::buffer(getBuffer,1024),
			//     boost::bind(&client::handle_read,this,boost::asio::placeholders::error)
			//    );
			socket.async_read_some(boost::asio::buffer(getBuffer,1024),
				boost::bind(&client::handle_read,shared_from_this(),boost::asio::placeholders::error)
				);
		}
		else
		{
			socket.close();
		}
	}
	void handle_read(const boost::system::error_code& error)
	{
		if(!error)
		{
			std::cout << getBuffer << std::endl;
			//boost::asio::async_read(socket,
			//         boost::asio::buffer(getBuffer,1024),
			//         boost::bind(&client::handle_read,this,boost::asio::placeholders::error)
			//        );

			//�����Ϳ���ʵ��ѭ����ȡ�ˣ��൱��while��1��
			//��Ȼ���������������������Ѿ�Ӧ���൱��Ϥ�ˣ�һЩ�߼��Ϳ���������չ��
			//���������ҵ����ѿ����ö��߳���ʵ��
			socket.async_read_some(
				boost::asio::buffer(getBuffer,1024),
				boost::bind(&client::handle_read,shared_from_this(),boost::asio::placeholders::error)
				);
		}
		else
		{
			socket.close();
		}
	}
	void handle_write(const boost::system::error_code& error)
	{
	}

private:
	tcp::socket socket;
	char getBuffer[1024];
};

int main(int argc,char* argv[])
{
	//if(argc != 3)
	//{
	// std::cerr << ��Usage: chat_client <host> <port>\n��;
	//    return 1;
	//}

	//�Ҿ�IO_SERVICE��һ�������ԵĽӿڣ�������ͨ���õ�����ʵ������Ҫͨ����������
	//�������ǿ��Կ���socket
	boost::asio::io_service io_service;
	//����ն˾��Ƿ�����
	//���Ķ���Ϳ��Կ���ʱsockaddr_in,��������������IP��PORT
	tcp::endpoint endpoint(boost::asio::ip::address_v4::from_string("127.0.0.1"/*argv[1]*/),8100/*argv[2]*/);
	//��Ȼsocket��sockaddr_in�Ѿ�������ˣ���ô���Ϳ���CONNECT��
	//֮����Ϊ��Ҫ�����Ӻ����ݴ�����һ���࣬����Ϊ�˷����������,����ڷ���˾ͻ������Եĸо���
	boost::shared_ptr<client> client_ptr(new client(io_service));
	client_ptr->start_connect(endpoint);
	//ִ���շ����ݵĺ���
	io_service.run();
	return 0;
}
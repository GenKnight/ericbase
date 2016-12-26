#ifndef LIBEVENT_TCP_SOCKET_H_
#define LIBEVENT_TCP_SOCKET_H_

#ifdef WIN32

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <WinSock2.h>
typedef SOCKET HSocket; 
#define NAN_SOCKET INVALID_SOCKET

#else
#include <unistd.h>
#include <netinet/in.h>  
#include <sys/socket.h>  
#include <sys/types.h>  
typedef int HSocket;  
#define SOCKET_ERROR  (-1)  
#define INVALID_SOCKET  0 
#include <arpa/inet.h>
#define NAN_SOCKET INVALID_SOCKET
#endif

#include <stdlib.h>
#include <ctype.h>
#include <string>
#include "utility/SpinLock.h"
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event.h>
#include <memory>

namespace libeventtcp 
{

	class TcpSocket;
    typedef std::shared_ptr<TcpSocket> session_ptr;

    class ILibeventNotify
    {
    public:
        virtual void OnMessageStream(const std::string& stream) = 0;

        void SetSessionPtr(TcpSocket* ptrSocket)
        {
            m_ptrSocket = ptrSocket;
        }

        TcpSocket* GetSessionPtr()
        {
            return m_ptrSocket;
        }

    private:
        TcpSocket* m_ptrSocket;
    };

	class ISocketDisconNotify {
	public:
		virtual void OnDisconNotify(TcpSocket *tcp_sock) = 0;
	};

	class TcpSocket
	{
    public:
        enum {
            SIZE_VALUE_LEN = sizeof(int),
            MAX_BUF_SIZE = 1024,
            MAX_MSG_SIZE = 1000000000
        };

	public:
        TcpSocket(struct event_base *p_base, ILibeventNotify* ptrNotify, ISocketDisconNotify* ptrDisconNotify);
		~TcpSocket(void);

        TcpSocket* GetSelf()
        {
            return this;
        }

		static bool WinStartUp(std::string& err);
		static void WinClean();

		bool ConnectServer(const char *ip, int port, std::string& err);

		bool SetBufSize(HSocket socket, bool is_recv, int size, std::string& err);
		bool SetBufferevent(HSocket socket, std::string& err);

		bool SendMessages(const std::string& stream);

		HSocket GetSocket();
		bool GetInvalid();
		void SetInvalid(bool arg);

	private:
		bool GetAddressFrom(sockaddr_in *addr, const char *ip, int port, std::string& err);
		HSocket SocketOpen(std::string& err);
		void SocketClose(HSocket &handle);

        bool CheckTitle(char* title, int len);
        void ReadBuf(char* buf, int len);

		static void ReadCb(struct bufferevent *, void *);
		static void EventCb(struct bufferevent *, short, void *);

	private:
		struct event_base* m_p_base;	//外部对象，不需要再本类中区销毁资源
        ILibeventNotify* m_ptrNotify;
		ISocketDisconNotify* m_ptrDisconNotify;

		HSocket m_socket;
		struct bufferevent *m_bev;
		bool invalid_;
		utility::SpinLock inva_mtx_;

		static bool m_winstart_status;

        char m_msg_title[SIZE_VALUE_LEN];
        char* m_buf;
        int m_buf_len;
        bool m_first_read;
        int m_read_size;
	};

}

#endif

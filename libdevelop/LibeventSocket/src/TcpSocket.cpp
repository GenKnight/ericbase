#include "TcpSocket.h"
#include <sstream>
#include <string.h>
#include "utility/Thread.h"

namespace libeventtcp 
{
    inline int asInt32(const char* buf)
    {
        int be32 = 0;
        memcpy(&be32, buf, sizeof(be32));
        return ntohl(be32);
    }

	bool TcpSocket::m_winstart_status = false;

	////////////////////////////////////////////////////////////////////////////////////

    TcpSocket::TcpSocket(struct event_base *p_base, ILibeventNotify* ptrNotify, ISocketDisconNotify* ptrDisconNotify)
      : m_p_base(p_base),
        m_ptrNotify(ptrNotify),
        m_ptrDisconNotify(ptrDisconNotify),
        m_bev(NULL),
        invalid_(true),
        m_buf(NULL),
        m_buf_len(0),
        m_first_read(true),
        m_read_size(0)
	{	
	}

	TcpSocket::~TcpSocket(void)
	{
		if (m_bev) { 
            bufferevent_free(m_bev); 
        }
	}

	bool TcpSocket::WinStartUp(std::string& err)
	{
#if defined(WIN32)  
		if (m_winstart_status) { return true; }

		WSADATA  Ws;  
		//Init Windows Socket  
		if (WSAStartup(MAKEWORD(2,2), &Ws) == 0)  
		{  
			m_winstart_status = true;
			return true;
		}
		err = "WSAStartup error";
		return false;
#else
		return true;
#endif 
	}

	void TcpSocket::WinClean()
	{
#if defined(WIN32)  
		if (!m_winstart_status) { return; }
		WSACleanup();  
		m_winstart_status = false;
#endif  
	}

	bool TcpSocket::GetAddressFrom(sockaddr_in *addr, const char *ip, int port, std::string& err)
	{
		if (ip == NULL || port <= 0)
		{
			err = "invalid address/port";
			return false;
		}
		memset(addr, 0, sizeof(sockaddr_in));  
		addr->sin_family = AF_INET;            /*��ַ����ΪAF_INET*/  
		addr->sin_addr.s_addr = inet_addr(ip); 
		addr->sin_port = htons(port);   /*�˿ں�*/  
		return true;
	}

	HSocket TcpSocket::SocketOpen(std::string& err)
	{
		int protocol = 0;  
		HSocket hs;  
#if defined(WIN32)  
		protocol=IPPROTO_TCP;  
#endif  
		hs = socket(AF_INET, SOCK_STREAM, protocol);  
		if (hs == NAN_SOCKET) 
		{
#if defined(WIN32) 
			int err_code = WSAGetLastError();
			switch(err_code)
			{			
			case WSAEAFNOSUPPORT:
				{
					err = "The specified address is not supported.";
					break;
				}			
			case WSAEINVAL:
				{
					err = "invalid argument was supplied.";
					break;
				}	
			default:
				{
					err = "invalid socket";
					break;
				}
			}
#else
			err = "invalid socket";
#endif  
		}
		//if (evutil_make_socket_nonblocking(hs) < 0) 
		//{
		//	evutil_closesocket(hs);
		//	err = "invalid socket";
		//}
		return hs;  
	}

	void TcpSocket::SocketClose(HSocket &handle)  
	{  
#if defined(WIN32)  
		closesocket(handle);  
#else
		close(handle);  
#endif  
	} 

	bool TcpSocket::ConnectServer(const char *ip, int port, std::string& err)
	{
		if (!WinStartUp(err)) { return false; }

		if (m_p_base == NULL)
		{
			err = "the libevent is null";
			return false;
		}

		struct sockaddr_in sin;
		if (!GetAddressFrom(&sin, ip, port, err)) { return false; }

		//��ɾ��m_bevʱ���Զ��ر��׽��֣����Բ���Ҫ�ڴ˹ر�
		//if (m_socket == INVALID_SOCKET) { 
		//	SocketClose(m_socket);
		//	m_socket = NAN_SOCKET; 
		//}

		m_socket = SocketOpen(err);
		if (m_socket == INVALID_SOCKET) { return false; }

		int ret = connect(m_socket,(struct sockaddr *)&sin,sizeof(sin));
		if (ret < 0) {
#if defined(WIN32)  
			int err_code = WSAGetLastError();
			switch(err_code)
			{
			case WSAEAFNOSUPPORT:
				{
					err = "Addresses in the specified family cannot be used with this socket.";
					break;
				}
			case WSAEFAULT:
				{
					err = "Addresses in the specified family cannot be used with this socket.";
					break;
				}
			case WSAEINVAL:
				{
					err = "The parameter is a listening socket.";
					break;
				}
			default:
				{
					err = "connect error";
					break;
				}
			}
#else
			err = "connect error";
#endif
			SocketClose(m_socket);
			m_socket = NAN_SOCKET; 
			return false;
		}

		if (!SetBufferevent(m_socket, err))
		{
			return false;
		}

		return true;
	}

	bool TcpSocket::SetBufSize(HSocket socket, bool is_recv, int size, std::string& err)
	{
		if (socket == INVALID_SOCKET) { 
			err = "Invalid socket";
			return false; 
		}
		m_socket = socket;

		int opt_name = SO_RCVBUF;
		if (!is_recv) {
			opt_name = SO_SNDBUF;
		}

		int ret = 0;
#if defined(WIN32)  
		ret = setsockopt(m_socket, SOL_SOCKET, opt_name, (char*) &size, sizeof(size));
		if (ret == SOCKET_ERROR)
		{      
			int err_code = WSAGetLastError();
			std::stringstream ss;
			ss << "err code: " << err_code;
			err = ss.str();
			return false;
		}
#else
		ret = setsockopt(m_socket, SOL_SOCKET, opt_name, (const void*) &size, (socklen_t)sizeof(size));
		if (-1 == ret)
		{
			err = "error on setsockopt";
			return false;
		}
#endif

		int new_size = 0;
		int size_len = sizeof(new_size);
#if defined(WIN32)
		ret = getsockopt(m_socket, SOL_SOCKET, opt_name, (char*) &new_size, &size_len);
		if (ret == SOCKET_ERROR) { 
			err = "error on getsockopt";
			return false;
		}
#else
		ret = getsockopt(m_socket, SOL_SOCKET, opt_name, (void*) &new_size, (socklen_t*)&size_len);
		if (ret == -1) { 
			err = "error on getsockopt";
			return false;
		}
#endif

		if (new_size != size)
		{
			err = "SetBufSize error";
			return false;
		}

		return true;
	}

	bool TcpSocket::SetBufferevent(HSocket socket, std::string& err)
	{
		if (socket == INVALID_SOCKET) { 
			err = "Invalid socket";
			return false; 
		}

		if (m_p_base == NULL)
		{
			err = "event_base is null";
			return false;
		}

		if (NULL != m_bev) 
		{ 
			bufferevent_free(m_bev); 
			m_bev = NULL; 
		}

        if (evutil_make_socket_nonblocking(socket) < 0) {
            evutil_closesocket(socket);
            err = "evutil_make_socket_nonblocking error";
        }

		m_bev = bufferevent_socket_new(m_p_base, socket, BEV_OPT_CLOSE_ON_FREE);
		if (!m_bev) {
			err = "bufferevent_socket_new error\n";
			return false;
		}

		bufferevent_setcb(m_bev, ReadCb, NULL, EventCb, (void*)this);
		if (bufferevent_enable(m_bev, EV_READ|EV_WRITE) != 0 )
		{
			err = "bufferevent_enable erro";
			bufferevent_free(m_bev);
			m_bev = NULL;
			return false;
		}

		return true;
	}

	bool TcpSocket::SendMessages(const string& stream)
	{
		string err;
		if (NULL == m_bev) {
			err = "the socket is not open";
			return false;
		}

		if (stream.empty()) {
			err = "invalid argument";
			return false;
		}

#if 0
		if (bufferevent_write(m_bev, stream.c_str(), stream.length()) != 0) {
			err = "bufferevent write error";
			return false;
		}
#endif
#if 1
        while (send(m_socket, stream.c_str(), stream.length(), 0) <= 0) {
#if defined(WIN32) 
			int err_code = WSAGetLastError();
			printf("err code: %d\n", err_code);
			if (err_code == 10035) {
				q_sleep(100); //����
			} else {
				err = "TcpSocket::SendMessages error";
				return false;
			}
#else
			err = "TcpSocket::SendMessages error";
			return false;
#endif
		}
#endif
		return true;
	}

	bool TcpSocket::GetInvalid() 
	{
		utility::Locker locker(&inva_mtx_);
		return invalid_;
	}

	void TcpSocket::SetInvalid(bool arg) 
	{
		utility::Locker locker(&inva_mtx_);
		invalid_ = arg;
	}

	HSocket TcpSocket::GetSocket()
	{
		return m_socket;
	}

    bool TcpSocket::CheckTitle(char* title, int len)
    {
        if (len >= SIZE_VALUE_LEN) {
            //char size_val[SIZE_VALUE_LEN + 1] = { 0 };
            //memcpy(size_val, title, SIZE_VALUE_LEN);
            //m_buf_len = atoi(size_val);	//˳��������ݳ���

            m_buf_len = asInt32(title);
            if (m_buf_len <= 0 || m_buf_len > MAX_MSG_SIZE) {
                return false;
            }
        }

        return true;
    }

    void TcpSocket::ReadBuf(char* buf, int len)
    {
        if (m_first_read)
        {
            char* tmp_buf = buf;
            int tmp_len = len;
            int title_size = SIZE_VALUE_LEN;
            if (m_read_size > 0) {	//֮ǰ������ͷû����
                tmp_len = len + m_read_size;
                tmp_buf = new char[tmp_len];
                memcpy(tmp_buf, m_msg_title, m_read_size);
                memcpy(tmp_buf + m_read_size, buf, len);
                memset(m_msg_title, 0, sizeof(m_msg_title));
                m_read_size = 0;
            }

            if (!CheckTitle(tmp_buf, tmp_len)) {
                printf("����������:%d\ndata:%s\n", tmp_len, tmp_buf);
   
                memset(m_msg_title, 0, sizeof(m_msg_title));
				if (m_read_size != 0) {
					delete[] tmp_buf;
					tmp_buf = NULL;	
					m_read_size = 0;
				}
				
                return;
            }

            if (tmp_len <= title_size){	//����ͷδ���꣬�������ȡ����
                memcpy(m_msg_title, tmp_buf, tmp_len);
				if (m_read_size != 0) {
					delete[] tmp_buf;
					tmp_buf = NULL;
				}
				m_read_size = tmp_len;

                return;
            }

            //��������
            if (tmp_len == title_size + m_buf_len) {
                if (NULL != m_ptrNotify && GetInvalid()) {
                    m_ptrNotify->SetSessionPtr(GetSelf());

                    std::string stream(tmp_buf + title_size, tmp_buf + title_size + m_buf_len);
                    m_ptrNotify->OnMessageStream(stream);
                }
				if (m_read_size != 0) {
					delete[] tmp_buf;
					tmp_buf = NULL;
					m_read_size = 0;
				}
                return;
            } else if (tmp_len > title_size + m_buf_len) {
                if (NULL != m_ptrNotify && GetInvalid()) { 
                    m_ptrNotify->SetSessionPtr(GetSelf());

                    std::string stream(tmp_buf + title_size, tmp_buf + title_size + m_buf_len);
                    m_ptrNotify->OnMessageStream(stream);
                }
                ReadBuf(tmp_buf + title_size + m_buf_len, tmp_len - title_size - m_buf_len); 
				if (m_read_size != 0) {
					delete[] tmp_buf;
					tmp_buf = NULL;
					m_read_size = 0;
				}
                return;
            } else { //���ݲ���һ���¶���  
                m_buf = new char[m_buf_len];
                memcpy(m_buf, tmp_buf + title_size, tmp_len - title_size);
				if (m_read_size != 0) {
					delete[] tmp_buf;
					tmp_buf = NULL;
				}
				m_read_size = tmp_len - title_size; //�����m_read_size��ʾ�Ѷ�ȡ�����ݳ���
				m_first_read = false; //�´ν��������

                return;
            }
        }

        //��ȡ����
		if (m_buf_len > m_read_size + len) {	//������δ���� 
            memcpy(m_buf + m_read_size, buf, len);
            m_read_size += len;
            return;
        }

        int rese_len = m_read_size + len - m_buf_len;
        memcpy(m_buf + m_read_size, buf, m_buf_len - m_read_size);
        if (NULL != m_ptrNotify && GetInvalid()) {
            m_ptrNotify->SetSessionPtr(GetSelf());

            std::string stream(m_buf, m_buf + m_buf_len);
            m_ptrNotify->OnMessageStream(stream);
        }
        m_read_size = 0;
        m_first_read = true;
		m_buf_len = 0;
        delete[] m_buf;
        m_buf = NULL;

        if (rese_len > 0) {	//�����������
            ReadBuf(buf + len - rese_len, rese_len);
        }
    }

	void TcpSocket::ReadCb(struct bufferevent *bev, void *user_data)
	{
		TcpSocket *this_ptr = (TcpSocket*)user_data;
        int now_read = 0;
        char buf[MAX_BUF_SIZE];
        do
        {
            memset(buf, 0, MAX_BUF_SIZE);
            now_read = bufferevent_read(bev, buf, MAX_BUF_SIZE);
            this_ptr->ReadBuf(buf, now_read);
        } while (now_read == MAX_BUF_SIZE);
	}

	void TcpSocket::EventCb(struct bufferevent *bev, short events, void *user_data)
	{
	/*
        �ص���ˮλ
        ÿ��bufferevent������������صĻص���һ����ȡ�ص���һ��д��ص���Ĭ������£��ӵײ㴫��˿ڶ�ȡ��������������֮�����ö�ȡ�ص���������������㹻�������ݱ���յ��ײ㴫��˿ں�д��ص��ᱻ���á�ͨ������bufferevent�Ķ�ȡ��д�롰ˮλ��watermarks�������Ը�����Щ������Ĭ����Ϊ��
        ÿ��bufferevent���ĸ�ˮλ��
        l ��ȡ��ˮλ����ȡ����ʹ�����뻺�������������ڴ˼�����߸���ʱ����ȡ�ص��������á�Ĭ��ֵΪ0������ÿ����ȡ�������ᵼ�¶�ȡ�ص������á�
        l ��ȡ��ˮλ�����뻺�����е��������ﵽ�˼����bufferevent��ֹͣ��ȡ��ֱ�����뻺�������㹻�������ݱ���ȡ��ʹ�����������ڴ˼���Ĭ��ֵ�����ޣ�������Զ������Ϊ���뻺�����Ĵ�С��ֹͣ��ȡ��
        l д���ˮλ��д�����ʹ��������������������ﵽ���ߵ��ڴ˼���ʱ��д��ص��������á�Ĭ��ֵ��0������ֻ������������յ�ʱ��Ż����д��ص���
        l д���ˮλ��buffereventû��ֱ��ʹ�����ˮλ������bufferevent��������һ��bufferevent�ĵײ㴫��˿�ʱ���������塣�뿴������ڹ�����bufferevent�Ľ��ܡ�
        buffereventҲ�С����󡱻��ߡ��¼����ص���������Ӧ��֪ͨ���������ݵ��¼����������Ѿ��رջ��߷������󡣶����������¼���־��
        l BEV_EVENT_READING����ȡ����ʱ����ĳ�¼��������������¼��뿴������־��
        l BEV_EVENT_WRITING��д�����ʱ����ĳ�¼��������������¼��뿴������־��
        l BEV_EVENT_ERROR������ʱ�������󡣹��ڴ���ĸ�����Ϣ�������EVUTIL_SOCKET_ERROR()��
        l BEV_EVENT_TIMEOUT��������ʱ��
        l BEV_EVENT_EOF�������ļ�����ָʾ��
        l BEV_EVENT_CONNECTED����������ӹ����Ѿ���ɡ�
        
    */
		TcpSocket *this_ptr = (TcpSocket*)user_data;
		this_ptr->SetInvalid(false);

		printf("Connection closed.\n");

		if (NULL != this_ptr->m_ptrDisconNotify )
		{
			this_ptr->m_ptrDisconNotify->OnDisconNotify(this_ptr);
		}

	}

}

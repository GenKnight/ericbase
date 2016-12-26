#include "fndAsyncConsumer.h"

AmqAsyncConsumer::AmqAsyncConsumer(  IAmqAsyncConsumerNotify *AsyncConsumerNotify, const std::string& brokerURI, const std::string& destURI, bool bUseTopic )
	:m_ptrAsyncConsumerNotify(AsyncConsumerNotify),
	connection(NULL),
	session(NULL),
	destination(NULL),
	consumer(NULL),
	useTopic(bUseTopic),
	clientAck(false),
	brokerURI(brokerURI),
	destURI(destURI)
{
}

AmqAsyncConsumer::~AmqAsyncConsumer()
{
	cleanup();
}

void AmqAsyncConsumer::close()
{
	cleanup();
}

void AmqAsyncConsumer::runConsumer() 
{
	try {

		// Create a ConnectionFactory
		ActiveMQConnectionFactory* connectionFactory =
			new ActiveMQConnectionFactory( brokerURI );

		// Create a Connection
		connection = connectionFactory->createConnection();
		delete connectionFactory;

		ActiveMQConnection* amqConnection = dynamic_cast<ActiveMQConnection*>( connection );
		if( amqConnection != NULL ) {
			amqConnection->addTransportListener( this );
		}

		connection->start();

		connection->setExceptionListener(this);

		// Create a Session
		if( clientAck ) {
			session = connection->createSession( Session::CLIENT_ACKNOWLEDGE );
		} else {
			session = connection->createSession( Session::AUTO_ACKNOWLEDGE );
		}

		// Create the destination (Topic or Queue)
		if( useTopic ) {
			destination = session->createTopic( destURI );
		} else {
			destination = session->createQueue( destURI );
		}

		// Create a MessageConsumer from the Session to the Topic or Queue
		consumer = session->createConsumer( destination );
		consumer->setMessageListener( this );

	} catch (CMSException& e) {
		e.printStackTrace();
	}
}

// Called from the consumer since this class is a registered MessageListener.
void AmqAsyncConsumer::onMessage( const Message* message )
{
	static int count = 0;

	try
	{
		count++;

		int len=0;
		char start;
		char end;

		// Got a bytes msg.
		const cms::BytesMessage* bytesMsg =
			dynamic_cast<const cms::BytesMessage*>( message );
		if( bytesMsg != NULL ) 
		{
			// --- START ---
			//数据包合法性校验
			try
			{
				start	= bytesMsg->getByteProperty( "start" );
				end		= bytesMsg->getByteProperty( "end" );
				len		= bytesMsg->getIntProperty( "length" );
			}
			catch(CMSException&e)
			{
				//非法数据包，立即丢弃！
				if( clientAck ) {
					message->acknowledge();
					printf( "Error:illegal package(1)!" );
				}
				return;
			}
			if ( len!=bytesMsg->getBodyLength() || start!=0x55 || end!=0x16 )
			{
				//非法数据包，立即丢弃！
				if( clientAck ) {
					message->acknowledge();
					printf( "Error:illegal package(2)!" );
				}
				return;
			}
			// --- END ---

			CMS_HEADER header;
			header.datasize = len;

			if ( message->propertyExists( "usrid" ) )
			{
				header.usrid = bytesMsg->getStringProperty( "usrid" );
			} else 
			{
				header.usrid = "";
			}
			
			if ( message->propertyExists( "session_id" ) )
			{
				header.session_id = bytesMsg->getStringProperty( "session_id" );
			} else
			{
				header.session_id = "";
			}

			if ( message->propertyExists( "datatype" ) )
			{
				header.datatype	= bytesMsg->getIntProperty( "datatype" );
			} else
			{
				header.datatype	= 0;
			}
			
			if ( message->propertyExists( "sec_type" ) )
			{
				header.security_type = bytesMsg->getStringProperty( "sec_type" );
			} else
			{
				header.security_type = "1";
			}
			
			if ( message->propertyExists( "datasrc" ) )
			{
				header.datasource	= bytesMsg->getIntProperty( "datasrc" );
			} else
			{
				header.datasource = 0;
			}
			// Notify external caller
			unsigned char *pucBytes = bytesMsg->getBodyBytes();
			m_ptrAsyncConsumerNotify->OnMessageStream( (const char*)pucBytes, header );
			delete pucBytes;
			pucBytes = NULL;
		} else
		{
			// other type message
			printf( "Error:illegal package(3)!" );
		}

		if( clientAck ) {
			message->acknowledge();
		}

		//printf( "[%d]Message #%d Received: %s\n", nID, count, text.c_str() );

	} catch (CMSException& e) {
		e.printStackTrace();
		printf( "Exception(onMessage)!" );
	}
}

/** 
   * 对消息传输命令进行监控 
   */  
void AmqAsyncConsumer::onCommand( const Pointer<Command> command AMQCPP_UNUSED ) {  
    //logger.debug("onCommand检测到服务端命令:{}", o);  
	//printf( "MQ command:%s\n", command->toString().c_str() );
  }

/** 
   * 与服务器连接发生错误 
   * 
   * @param error 
   */
void AmqAsyncConsumer::onException( const CMSException& ex AMQCPP_UNUSED ) 
{
	printf("CMS Exception occurred.  Shutting down client.\n");
	//exit(1);
}

/** 
   * 消息服务器连接发生中断 
   */ 
void AmqAsyncConsumer::transportInterrupted() 
{
	std::cout << "The Connection's Transport has been Interrupted." << std::endl;

	if ( m_ptrAsyncConsumerNotify )
	{
		m_ptrAsyncConsumerNotify->OnTransportInterrupted();
	}
}

/** 
   * 恢复与服务器的连接 
   */ 
void AmqAsyncConsumer::transportResumed() 
{
	std::cout << "The Connection's Transport has been Restored." << std::endl;

	if ( m_ptrAsyncConsumerNotify )
	{
		m_ptrAsyncConsumerNotify->OnTransportResumed();
	}
}



void AmqAsyncConsumer::cleanup(){

	//*************************************************
	// Always close destination, consumers and producers before
	// you destroy their sessions and connection.
	//*************************************************

	// Destroy resources.
	try{
		if( destination != NULL ) delete destination;
	}catch (CMSException& e) {}
	destination = NULL;

	try{
		if( consumer != NULL ) delete consumer;
	}catch (CMSException& e) {}
	consumer = NULL;

	// Close open resources.
	try{
		if( session != NULL ) session->close();
		if( connection != NULL ) connection->close();
	}catch (CMSException& e) {}

	// Now Destroy them
	try{
		if( session != NULL ) delete session;
	}catch (CMSException& e) {}
	session = NULL;

	try{
		if( connection != NULL ) delete connection;
	}catch (CMSException& e) {}
	connection = NULL;
}

void AmqAsyncConsumer::AmqStart()
{
	runConsumer();
}

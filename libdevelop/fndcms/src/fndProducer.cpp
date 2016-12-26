#include "fndProducer.h"

////////////////////////////////////////////////////////////////////////////////
void AmqProducer::run() {
	try {

		// Create a ConnectionFactory
		auto_ptr<ActiveMQConnectionFactory> connectionFactory(
			new ActiveMQConnectionFactory( brokerURI ) );

		// Create a Connection
		try{
			connection = connectionFactory->createConnection();
			connection->start();
		} catch( CMSException& e ) {
			e.printStackTrace();
			throw e;
		}

		// Create a Session
		if( clientAck ) {
			session = connection->createSession( Session::CLIENT_ACKNOWLEDGE );
		} else {
			session = connection->createSession( Session::AUTO_ACKNOWLEDGE );
		}

		//为连接设置唯一的客户端ID
		//connection->setClientID("MyId");

		// Create the destination (Topic or Queue)
		if( useTopic ) {
			destination = session->createTopic( destURI );
		} else {
			destination = session->createQueue( destURI );
		}

		// Create a MessageProducer from the Session to the Topic or Queue
		producer = session->createProducer( destination );
		producer->setDeliveryMode( DeliveryMode::NON_PERSISTENT );
#if 0
		// Create the Thread Id String
		string threadIdStr = Long::toString( Thread::currentThread()->getId() );

		// Create a messages（100 bytes）
		DWORD dwTick1 = GetTickCount();
		string text = (string)"1234567890" + threadIdStr;
		string textTmp;
		for( unsigned int ix=0; ix<numMessages; ++ix ){
			TextMessage* message = session->createTextMessage( text );

			message->setIntProperty( "Integer", ix );

			// Tell the producer to send the message
			//printf( "Sent message #%d from thread %s\n", ix+1, threadIdStr.c_str() );
			producer->send( message );

			delete message;
		}

		DWORD dwTick2 = GetTickCount();
		printf( "花费时间：%d(s)\n", (dwTick2 - dwTick1) / 1000 );
#endif
	}
	catch ( CMSException& e ) 
	{
		e.printStackTrace();
	}
}

void AmqProducer::cleanup(){

	// Destroy resources.
	try{
		if( destination != NULL ) delete destination;
	}catch ( CMSException& e ) { e.printStackTrace(); }
	destination = NULL;

	try{
		if( producer != NULL ) delete producer;
	}catch ( CMSException& e ) { e.printStackTrace(); }
	producer = NULL;

	// Close open resources.
	try{
		if( session != NULL ) session->close();
		if( connection != NULL ) connection->close();
	}catch ( CMSException& e ) { e.printStackTrace(); }

	try{
		if( session != NULL ) delete session;
	}catch ( CMSException& e ) { e.printStackTrace(); }
	session = NULL;

	try{
		if( connection != NULL ) delete connection;
	}catch ( CMSException& e ) { e.printStackTrace(); }
	connection = NULL;
}

/*
////////////////////////////////////////////////////////////////////////////////
int main(int argc AMQCPP_UNUSED, char* argv[] AMQCPP_UNUSED) {

    activemq::library::ActiveMQCPP::initializeLibrary();

    std::cout << "=====================================================\n";
    std::cout << "Starting the example:" << std::endl;
    std::cout << "-----------------------------------------------------\n";

    // Set the URI to point to the IPAddress of your broker.
    // add any optional params to the url to enable things like
    // tightMarshalling or tcp logging etc.  See the CMS web site for
    // a full list of configuration options.
    //
    //  http://activemq.apache.org/cms/
    //
    // Wire Format Options:
    // =====================
    // Use either stomp or openwire, the default ports are different for each
    //
    // Examples:
    //    tcp://127.0.0.1:61616                      default to openwire
    //    tcp://127.0.0.1:61616?wireFormat=openwire  same as above
    //    tcp://127.0.0.1:61613?wireFormat=stomp     use stomp instead
    //
    std::string brokerURI =
        "failover://(tcp://127.0.0.1:61616"
//        "?wireFormat=openwire"
//        "&connection.useAsyncSend=true"
//        "&transport.commandTracingEnabled=true"
//        "&transport.tcpTracingEnabled=true"
//        "&wireFormat.tightEncodingEnabled=true"
        ")";

    //============================================================
    // Total number of messages for this producer to send.
    //============================================================
    unsigned int numMessages = 1000000;//2000;

    //============================================================
    // This is the Destination Name and URI options.  Use this to
    // customize where the Producer produces, to have the producer
    // use a topic or queue set the 'useTopics' flag.
    //============================================================
    std::string destURI = "TEST.1000000";

    //============================================================
    // set to true to use topics instead of queues
    // Note in the code above that this causes createTopic or
    // createQueue to be used in the producer.
    //============================================================
    bool useTopics = false;

    // Create the producer and run it.
    AmqProducer producer( brokerURI, numMessages, destURI, useTopics );

    // Publish the given number of Messages
    producer.run();

    // Before exiting we ensure that all CMS resources are closed.
    producer.close();

    std::cout << "-----------------------------------------------------\n";
    std::cout << "Finished with the example." << std::endl;
    std::cout << "=====================================================\n";

    activemq::library::ActiveMQCPP::shutdownLibrary();
}
*/

void AmqProducer::AmqStart()
{
	run();
}

void AmqProducer::AmqSendText( const char* text, const char* _usrid )
{
	if ( producer==NULL )
		return;

	TextMessage* message = session->createTextMessage( text );

	message->setByteProperty( "start", 0x55 );
	message->setByteProperty( "end", 0x16 );
	message->setIntProperty( "length", strlen(text) );

	if ( _usrid && strlen(_usrid) )
		message->setStringProperty( "usrid", std::string(_usrid) );
	else if ( usrid.size() )
		message->setStringProperty( "usrid", usrid );

	// Tell the producer to send the message
	try{
		producer->send( message );
	}
	catch( CMSException &e ){
		e.printStackTrace();
	}

	delete message;
}

void AmqProducer::AmqSendStream( const char* stream, CMS_HEADER &header, long long llTimeToLive, int nDeliveryMode, int nPriority )
{
	int nDataSize = header.datasize;
	if ( producer==NULL || stream==NULL || nDataSize<1 )
		return;

	BytesMessage* message = session->createBytesMessage( (const unsigned char*)stream, nDataSize );

	message->setByteProperty( "start", 0x55 );
	message->setByteProperty( "end", 0x16 );
	message->setIntProperty( "length", nDataSize );

	if ( header.usrid.size() )
	{
		message->setStringProperty( "usrid", header.usrid );
	} else if ( usrid.size() )
	{
		message->setStringProperty( "usrid", usrid );
	}

	message->setStringProperty( "session_id", header.session_id );
	message->setIntProperty( "datatype", header.datatype );

	if ( header.security_type.size() )
	{
		message->setStringProperty( "sec_type", header.security_type );
	} else
	{
		message->setStringProperty( "sec_type", "1" );
	}

	message->setIntProperty( "datasrc", header.datasource );

	if ( nDeliveryMode!=DeliveryMode::NON_PERSISTENT && nDeliveryMode!=DeliveryMode::PERSISTENT )
		nDeliveryMode = DeliveryMode::NON_PERSISTENT;
	if ( nPriority<0 || nPriority>9 )
		nPriority = 4;

	producer->send( message, nDeliveryMode, nPriority, llTimeToLive  );
	
	delete message;
}

void AmqProducer::AmqSendStream( const char* stream, CMS_HEADER &header )
{
	int nDataSize = header.datasize;
	if ( producer==NULL || stream==NULL || nDataSize<1 )
		return;

	static int ix=1;

	BytesMessage* message = session->createBytesMessage( (const unsigned char*)stream, nDataSize );

	message->setByteProperty( "start", 0x55 );
	message->setByteProperty( "end", 0x16 );
	message->setIntProperty( "length", nDataSize );
	
	if ( header.usrid.size() )
	{
		message->setStringProperty( "usrid", header.usrid );
	} else if ( usrid.size() )
	{
		message->setStringProperty( "usrid", usrid );
	}

	message->setStringProperty( "session_id", header.session_id );
	message->setIntProperty( "datatype", header.datatype );

	if ( header.security_type.size() )
	{
		message->setStringProperty( "sec_type", header.security_type );
	} else
	{
		message->setStringProperty( "sec_type", "1" );
	}

	message->setIntProperty( "datasrc", header.datasource );

	producer->send( message );
	
	delete message;
}


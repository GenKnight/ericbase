#include "fndcms.h"
#include "fndProducer.h"
#include "fndAsyncConsumer.h"

#ifdef WIN32
	#include "direct.h"
#else
	#include<unistd.h>
#endif

void AmqInit()
{
	static bool bFirst=true;
	if ( bFirst )
	{
		printf( "AmqInit[V3.8.3]\n" );

		bFirst = false;
		activemq::library::ActiveMQCPP::initializeLibrary();
	}
}

void AmqUninit()
{
	static bool bFirst=true;
	if ( bFirst )
	{
		bFirst = false;
		activemq::library::ActiveMQCPP::shutdownLibrary();
	}
}

IAmqProducer * AmqCreateProducer( const char *usrid, bool bUseTopic, const char * amqAddress, const char * cmsQueueOrTopicName )
{
	AmqInit();

	std::string _usrid="";
	if ( usrid != NULL && strlen(usrid) > 0 )
	{
		_usrid = std::string(usrid);
	}

	std::string amqAdd;
	if ( amqAddress != NULL && strlen(amqAddress) > 0 )
	{
		char szAmqAdd[64]={0};
		sprintf( szAmqAdd, "failover://(tcp://%s)", amqAddress );
		amqAdd = std::string( szAmqAdd );
	}
#ifdef _DEBUG
	printf( "broker=%s\n", amqAdd.c_str() );
#endif

	std::string dest;
	if ( cmsQueueOrTopicName != NULL && strlen(cmsQueueOrTopicName) > 0 )
	{
		dest = std::string( cmsQueueOrTopicName );
	}
#ifdef _DEBUG
	printf( "name=%s\n", dest.c_str() );
#endif


	//return new AmqProducer( "failover://(tcp://127.0.0.1:61616)", 0, "FND.MOM.MD", false, false );
	return new AmqProducer( _usrid, amqAdd, 0, dest, bUseTopic, false );
}

void AmqDeleteProducer( IAmqProducer * &producer )
{
	if ( producer )
	{
		delete producer;
		producer = NULL;
	}

	AmqUninit();
}

IAmqAsyncConsumer* AmqCreateAsyncConsumer( IAmqAsyncConsumerNotify *AsyncConsumerNotify, bool bUseTopic, const char * amqAddress, const char * cmsQueueOrTopicName  )
{
	AmqInit();

	std::string amqAdd;
	if ( amqAddress !=NULL && strlen(amqAddress) > 0 )
	{
		char szAmqAdd[64]={0};
		sprintf( szAmqAdd, "failover://(tcp://%s)", amqAddress );
		amqAdd = std::string( szAmqAdd );
	}
#ifdef _DEBUG
	printf( "broker=%s\n", amqAdd.c_str() );
#endif

	std::string dest;
	if ( cmsQueueOrTopicName !=NULL && strlen(cmsQueueOrTopicName) > 0 )
	{
		dest = std::string( cmsQueueOrTopicName );
	}
#ifdef _DEBUG
	printf( "name=%s\n", dest.c_str() );
#endif

	return new AmqAsyncConsumer( AsyncConsumerNotify, amqAdd, dest, bUseTopic );
}

void AmqDeleteAsyncConsumer( IAmqAsyncConsumer* &AsyncConsumer )
{
	if ( AsyncConsumer )
	{
		delete AsyncConsumer;
		AsyncConsumer = NULL;
	}

	AmqUninit();
}

#ifdef _WIN32
#pragma once
#endif

#ifndef _header_interface_amq_20150115_
#define _header_interface_amq_20150115_

#include <string>

#ifndef _WIN32
	#define EXPORT_INTERFACE_CLASS
#else
	#ifdef EXPORT_DLL_CLASS 
		#define EXPORT_INTERFACE_CLASS _declspec(dllexport)
	#else
		#define EXPORT_INTERFACE_CLASS _declspec(dllimport)
	#endif
#endif

typedef struct tagHeaderInfo
{
	int datasize;
	std::string usrid;
	std::string session_id;
	int datatype;
	std::string security_type;	//证券品种 "1"--股票 "2"--期货
	int datasource;				//数据来源	1-webservice 2-ctp front server 3-market data(stock) 4-market data(ctp) 5-transaction server(stock)
								//			6-transaction server(ctp) 7-admin terminal	8-background batch  9-With funding server

	tagHeaderInfo()
		:datasource(0),datasize(0),datatype(0)
		,usrid(""),session_id(""),security_type("")
	{
	}
}CMS_HEADER;

/**
* 
* Create producer
*
*/
class EXPORT_INTERFACE_CLASS IAmqProducer
{

public:

	virtual ~IAmqProducer(){};

	/**
     * Start producer
     *
     * @since 1.0
     */
	virtual void AmqStart() = 0;

	/**
     * Send text data to broker
     * @text 
	 *		to be delivered messages.
     *
     * @since 1.0
     */
	virtual void AmqSendText( const char* text, const char* usrid=NULL ) = 0;

	/**
     * Send binary data to broker
     * @stream 
     *      The binary stream message to be sent.
	 * @header 
	 *		The information of delivered messages.
    * @param llTimeToLive
     *      The time to live value for this message in milliseconds.
     * @param nDeliveryMode
     *      The delivery mode to be used(PERSISTENT = 0,NON_PERSISTENT = 1).
     * @param nPriority
     *      The priority for this message(0-lowest,..., 9-highest).
     *
     * @since 1.0
     */
	virtual void AmqSendStream( const char* stream, CMS_HEADER &header ) = 0;
	virtual void AmqSendStream( const char* stream, CMS_HEADER &header, long long llTimeToLive/*=0*/, int nDeliveryMode/*=1*/, int nPriority/*=4*/ ) = 0;
};

extern "C"
{
	/**
     * Create one instantce of ActiveMQ producer
     *  
	 *
     *
     * @since 1.0
     */
	EXPORT_INTERFACE_CLASS IAmqProducer * AmqCreateProducer( const char *usrid=NULL, bool bUseTopic=false, const char * amqAddress=NULL, const char * cmsQueueOrTopicName=NULL );

	EXPORT_INTERFACE_CLASS void AmqDeleteProducer( IAmqProducer * &producer );
}

/**
* 
* Create Synchronous consumer -- Not support temporarily.
*
*/

class EXPORT_INTERFACE_CLASS IAmqSyncConsumer
{
public:
	virtual ~IAmqSyncConsumer(){};

	/**
     * Start synchronous consumer
     *
     * @since 1.0
     */
	virtual void AmqStart() = 0;

	/**
     * Send text data to broker
     * @text 
	 *		to be delivered messages.
     *
     * @since 1.0
     */
	virtual bool AmqSyncReceive( int nDataType, char* data, int nDataSize ) = 0;

};

extern "C"
{
	/**
     * Create one instantce of ActiveMQ consumer
     *  
	 *
     *
     * @since 1.0
     */
	EXPORT_INTERFACE_CLASS IAmqSyncConsumer * AmqCreateSyncCosumer( const char * amqAddress=NULL, const char * cmsQueueName=NULL );
}

/**
* 
* Create Asynchronous consumer
*
*/

class EXPORT_INTERFACE_CLASS IAmqAsyncConsumer
{
public:
	
	virtual ~IAmqAsyncConsumer(){};

	/**
     * Start Asynchronous consumer
     *
     * @since 1.0
     */
	virtual void AmqStart() = 0;

};

class IAmqAsyncConsumerNotify
{
public:
	virtual void OnMessageText( const char* usrid, int type, const char* text )=0;

	virtual void OnMessageStream( const char* stream, CMS_HEADER &header )=0;

	virtual void OnTransportInterrupted()=0;
	virtual void OnTransportResumed()=0;
};


extern "C"
{
	/**
     * Create one instantce of ActiveMQ Asynchronous consumer
     *  
	 *
     *
     * @since 1.0
     */
	EXPORT_INTERFACE_CLASS IAmqAsyncConsumer* AmqCreateAsyncConsumer( IAmqAsyncConsumerNotify *AsyncConsumerNotify, bool bUseTopic=false, const char * amqAddress=NULL, const char * cmsQueueOrTopicName=NULL  );

	EXPORT_INTERFACE_CLASS void AmqDeleteAsyncConsumer( IAmqAsyncConsumer* &AsyncConsumer );
}

#endif

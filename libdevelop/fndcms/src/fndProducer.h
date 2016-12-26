/*
* Licensed to the Apache Software Foundation (ASF) under one or more
* contributor license agreements.  See the NOTICE file distributed with
* this work for additional information regarding copyright ownership.
* The ASF licenses this file to You under the Apache License, Version 2.0
* (the "License"); you may not use this file except in compliance with
* the License.  You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifdef _WIN32
#pragma once
#endif

#ifndef _header_producer_20150115_
#define _header_producer_20150115_

#include <decaf/lang/Thread.h>
#include <decaf/lang/Runnable.h>
#include <decaf/util/concurrent/CountDownLatch.h>
#include <decaf/lang/Long.h>
#include <decaf/util/Date.h>
#include <activemq/core/ActiveMQConnectionFactory.h>
#include <activemq/util/Config.h>
#include <activemq/library/ActiveMQCPP.h>
#include <cms/Connection.h>
#include <cms/Session.h>
#include <cms/TextMessage.h>
#include <cms/BytesMessage.h>
#include <cms/MapMessage.h>
#include <cms/ExceptionListener.h>
#include <cms/MessageListener.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <memory>
#include <string.h>

#include "fndcms.h"

using namespace activemq;
using namespace activemq::core;
using namespace decaf;
using namespace decaf::lang;
using namespace decaf::util;
using namespace decaf::util::concurrent;
using namespace cms;
using namespace std;

////////////////////////////////////////////////////////////////////////////////
class AmqProducer : public Runnable, public IAmqProducer
{
private:

	Connection* connection;
	Session* session;
	Destination* destination;
	MessageProducer* producer;
	bool useTopic;
	bool clientAck;
	unsigned int numMessages;
	std::string brokerURI;
	std::string destURI;
	std::string usrid;		//µÇÂ½ÕËºÅ

private:

	AmqProducer( const AmqProducer& );
	AmqProducer& operator= ( const AmqProducer& );

public:

	AmqProducer( const std::string &usrid, const std::string& brokerURI, unsigned int numMessages,
		const std::string& destURI, bool useTopic = false, bool clientAck = false ) :
		connection(NULL),
		session(NULL),
		destination(NULL),
		producer(NULL),
		useTopic(useTopic),
		clientAck(clientAck),
		numMessages(numMessages),
		usrid(usrid),
		brokerURI(brokerURI),
		destURI(destURI) {
	}

	virtual ~AmqProducer(){
		cleanup();
	}

	void close() {
		this->cleanup();
	}

	virtual void run();

	virtual void AmqStart();
	virtual void AmqSendText( const char* text, const char* usrid=NULL );
	virtual void AmqSendStream( const char* stream, CMS_HEADER &header );
	virtual void AmqSendStream( const char* stream, CMS_HEADER &header, long long llTimeToLive=0, int nDeliveryMode=1, int nPriority=4 );

private:

	void cleanup();
};

#endif

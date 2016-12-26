#ifndef PROTO_BUF_PARSE_H
#define PROTO_BUF_PARSE_H

#include <string>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>


#include "stdio.h"
#include <cstdlib>
#include <stdint.h>

#ifdef WIN32
#include <boost/asio.hpp>
#include <winsock2.h>
#include <Windows.h> 
#else
#include <arpa/inet.h>
#endif
#define CHECK_SUM_VALUE 4569

const int kHeaderLen = sizeof(int32_t);

//encode时，是把head头数据加进去了,发送方需要发送头
inline void encode(std::string& result,const google::protobuf::Message& message)
{
	result.resize(kHeaderLen);

	const std::string& typeName = message.GetTypeName();
	int32_t nameLen = static_cast<int32_t>(typeName.size()+1);
	int32_t be32 = htonl(nameLen);
	result.append(reinterpret_cast<char*>(&be32), sizeof be32);
	result.append(typeName.c_str(), nameLen);
	bool succeed = message.AppendToString(&result);

	if (succeed)
	{
		const char* begin = result.c_str() + kHeaderLen;
		int32_t checkSum = CHECK_SUM_VALUE;//adler32(1, reinterpret_cast<const Bytef*>(begin), result.size()-kHeaderLen);	//加密
		int32_t be32 = htonl(checkSum);
		result.append(reinterpret_cast<char*>(&be32), sizeof be32);


		int32_t len = htonl(result.size() - kHeaderLen);
		std::copy(reinterpret_cast<char*>(&len),
			reinterpret_cast<char*>(&len) + sizeof len,
			result.begin());
	}
	else
	{
		result.clear();
	}
}

inline google::protobuf::Message* createMessage(const std::string& type_name)
{
	google::protobuf::Message* message = NULL;
	const google::protobuf::Descriptor* descriptor =
		google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(type_name);
	if (descriptor)
	{
		const google::protobuf::Message* prototype =
			google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
		if (prototype)
		{
			message = prototype->New();
		}
	}
	return message;
}

inline int32_t asInt32(const char* buf)
{
	int32_t be32 = 0;
	memcpy(&be32, buf, sizeof(be32));
	return ntohl(be32);
}

//decode时，已经不包括heade头数据了,接收方，已经把头接掉了
inline google::protobuf::Message* decode(const std::string& buf)
{
	google::protobuf::Message* result = NULL;

	int32_t len = static_cast<int32_t>(buf.size());
	if (len >= 10)
	{
		int32_t expectedCheckSum = asInt32(buf.c_str() + buf.size() - kHeaderLen);
		const char* begin = buf.c_str();
		int32_t checkSum = CHECK_SUM_VALUE;//adler32(1, reinterpret_cast<const Bytef*>(begin), len-kHeaderLen);
		if (checkSum == expectedCheckSum)
		{
			int32_t nameLen = asInt32(buf.c_str());
			if (nameLen >= 2 && nameLen <= len - 2*kHeaderLen)
			{
				std::string typeName(buf.begin() + kHeaderLen, buf.begin() + kHeaderLen + nameLen - 1);
				google::protobuf::Message* message = createMessage(typeName);
				if (message)
				{
					const char* data = buf.c_str() + kHeaderLen + nameLen;
					int32_t dataLen = len - nameLen - 2*kHeaderLen;
					if (message->ParseFromArray(data, dataLen))
					{
						result = message;
					}
					else
					{
						// parse error
						delete message;
					}
				}
				else
				{
					// unknown message type
				}
			}
			else
			{
				// invalid name len
			}
		}
		else
		{
			// check sum error
		}
	}

	return result;
}

inline const google::protobuf::Descriptor * getDescriptor( const std::string& buf )
{
	const google::protobuf::Descriptor * result = NULL;

	if (!buf.empty())
	{
		result = decode(buf)->GetDescriptor();
	}
	return result;
}

#endif
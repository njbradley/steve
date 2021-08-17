#ifndef MESSAGES_H
#define MESSAGES_H

#include "defs.h"

class Message { public:
	template <typename MessageType>
	static void send(MessageType* message, udp::socket* sock, udp::endpoint dest);
};

class VersionMessage : public Message { public:
	int32_t version = 60002;
	uint64_t services = 0;
	int64_t timestamp;
	// network address:
	uint64_t services2 = 0;
	char ipaddr[16];
	uint16_t port;
	//
	char addr_from[26] = {0};
	uint64_t nonce;
	// username:
	int user_agent_length = 71;
	char user_agent[71] = "steve_3a902a19b6f9f8df5c9f5eefe9749662d1defd6f420af2d416edc1d97a72180a";
	int32_t start_height = 0;
	
	VersionMessage(udp::endpoint dest);
};







template <typename MessageType>
void Message::send(MessageType* message, udp::socket* sock, udp::endpoint destaddr) {
	char* data = (char*) message;
	sock->send_to(boost::asio::buffer(data, sizeof(MessageType)), destaddr);
}


#endif

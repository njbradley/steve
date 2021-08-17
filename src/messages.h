#ifndef MESSAGES_H
#define MESSAGES_H

#include "defs.h"

class Message { public:
	virtual send(udp::socket* sock, udp::endpoint dest);
};


class VersionMessage : public Message { public:
	int32_t version;
	uint64_t services;
	int64_t timestamp;
	// network address:
	uint64_t services2;
	char ipaddr[16];
	uint16_t port;
	//
	char addr_from[26] = {0};
	uint64_t nonce;
	// username:
	int username_len;
	const char* username;
	int32_t start_height;
	
	VersionMessage();
};

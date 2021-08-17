#include "messages.h"
#include <ctime>
#include <cstring>



VersionMessage::VersionMessage(udp::endpoint dest) {
	timestamp = time(NULL);
	string address = dest.address().to_string();
	strcpy(ipaddr, address.c_str());
	port = dest.port();
	nonce = rand();
}

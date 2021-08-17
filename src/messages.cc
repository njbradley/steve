#include "messages.h"
#include <ctime>

template <typename MessageType>
void Message::send(MessageType* message, udp::socket* sock, udp::endpoint destaddr) {
	char* data = (char*) message;
	sock->send_to(boost::asio::buffer(data, sizeof(MessageType)), destaddr);
}

VersionMessage(udp::endpoint dest) {
	timestamp = time();
	string address = dest.address().to_string();
	strcpy(ipaddr, address.c_str());
	port = dest.port();
	nonce = rand();
}

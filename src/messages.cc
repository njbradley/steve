#include "messages.h"

Message::send(udp::socket* sock, udp::endpoint destaddr) {
	char* data = (char*) this;
	sock->send_to(boost::asio::buffer(data, sizeof(*this)), destaddr);
}

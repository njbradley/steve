#include "messages.h"







int main(int numargs, char** args) {
		if (numargs != 4) {
				cout << "usage: sock_test local-port dest-ip dest-port" << endl;
				return 1;
		}
		int localport = atoi(args[1]);
		string ip = args[2];
		int destport = atoi(args[3]);
		
		boost::asio::io_service service;
		udp::endpoint localaddr(udp::v4(), localport);
		udp::endpoint destaddr(ip::address::from_string(ip), destport);
		
		udp::socket sock(service);
		sock.open(udp::v4());
		sock.bind(localaddr);
		
    VersionMessage version_message(destaddr);
    Message::send(&version_message, &sock, destaddr);
}

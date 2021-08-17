#ifndef STEVE_DEFS_H
#define STEVE_DEFS_H

#include <iostream>
#include <string>

#include <boost/asio.hpp>

using std::cout;
using std::endl;
using std::string;

namespace ip = boost::asio::ip;
using boost::asio::ip::udp;

class Message;
class VersionMessage;


#endif

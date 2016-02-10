#pragma once
#include "SocketTools.h"
#include <ws2tcpip.h>

class SocketAddress
{
	sockaddr_in m_adress;
public:
	SocketAddress();
	SocketAddress(const std::string &inString);
	SocketAddress(const in_addr &ip, uint16_t port);
	SocketAddress(SocketAddress &a);
	~SocketAddress();

	int setAddress(const std::string &inString);
	int setAddress(const in_addr &ip, uint16_t port);

	friend std::ostream& operator<<(std::ostream& os, SocketAddress a);
};


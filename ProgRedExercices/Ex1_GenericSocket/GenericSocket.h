#pragma once

#include "SocketTools.h"

#define TCP 1
#define UDP 2

class GenericSocket
{
	SOCKET _socket;

public:
	GenericSocket();
	~GenericSocket();

	GenericSocket(int type);
};


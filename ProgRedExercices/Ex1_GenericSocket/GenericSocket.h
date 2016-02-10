#pragma once

#include "SocketTools.h"


class GenericSocket
{
	SOCKET _socket;

public:
	
	~GenericSocket();

	GenericSocket(int type);
};


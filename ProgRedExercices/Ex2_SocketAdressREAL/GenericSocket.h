#pragma once
#include "SocketTools.h"

class GenericSocket
{
	SOCKET m_socket;
	int m_type;
public:
	GenericSocket(int type);
	~GenericSocket();
};
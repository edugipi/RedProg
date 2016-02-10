#include "SocketTools.h"



SocketTools::SocketTools()
{
}


SocketTools::~SocketTools()
{
}

void SocketTools::loadLib() {
	 if (WSAStartup(MAKEWORD(2,2),0) != 0) showError("StartUp error num: ") ;
}

void SocketTools::cleanLib() {
	if (WSACleanup() != 0) showError("CleanUp error num: ");
}

void SocketTools::showError(std::string message) {
	throw std::exception(message.c_str() + WSAGetLastError());
}

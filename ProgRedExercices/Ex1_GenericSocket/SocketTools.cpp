#include "SocketTools.h"



void SocketTools::loadLib() {
	WSADATA voidObject;
	if (WSAStartup(MAKEWORD(2,2),&voidObject) == -1) showError("StartUp error, num: ") ;
}

void SocketTools::cleanLib() {
	if (WSACleanup() == -1) showError("CleanUp error, num: ");
}

void SocketTools::showError(const std::string &message) {
	throw std::exception(message.c_str() + WSAGetLastError());
}

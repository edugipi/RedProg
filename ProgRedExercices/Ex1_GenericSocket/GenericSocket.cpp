#include "GenericSocket.h"



GenericSocket::GenericSocket()
{
}


GenericSocket::~GenericSocket()
{
}

GenericSocket::GenericSocket(int type){
	if (type == 1) {
		_socket = socket(AF_INET, SOCK_STREAM, 0);
	}
	else if (type == 2) {
		_socket = socket(AF_INET, SOCK_DGRAM, 0);
	}
}
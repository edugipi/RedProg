#include "GenericSocket.h"





GenericSocket::~GenericSocket()
{
	int error = closesocket(_socket);
	if ( error == -1) SocketTools::showError("error closing socket, num: ");
}

//Overloaded constructor with socket type selection (TCP or UDP)
GenericSocket::GenericSocket(int type){

		if (_socket = socket(AF_INET, type, 0) == INVALID_SOCKET) SocketTools::showError("error creating socket, num: ");
}
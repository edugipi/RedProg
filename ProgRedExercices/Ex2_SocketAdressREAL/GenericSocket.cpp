#include "GenericSocket.h"

GenericSocket::GenericSocket(int type) : m_type(type) {
	m_socket = socket(AF_INET, type, IPPROTO_IP);
	if (m_socket == INVALID_SOCKET) SocketTools::ShowError("Socket could not be initialised");
}

GenericSocket::~GenericSocket() {
	//if (m_type == SOCK_STREAM) shutdown(m_socket, SD_BOTH);
	if (closesocket(m_socket) != 0) SocketTools::ShowError("Socket could not be destroyed");
}

#include "SocketAddress.h"
#include <iostream>

SocketAddress::SocketAddress() {
	uint16_t sin_port = htons(3490);
	in_addr sin_ip;
	sin_ip.S_un.S_un_b.s_b1 = 127;
	sin_ip.S_un.S_un_b.s_b2 = 0;
	sin_ip.S_un.S_un_b.s_b3 = 0;
	sin_ip.S_un.S_un_b.s_b4 = 1;
	setAddress(sin_ip, sin_port);
}

SocketAddress::SocketAddress(const std::string & inString) {
	setAddress(inString);
}

SocketAddress::SocketAddress(const in_addr &ip, uint16_t port) {
	setAddress(ip, port);
}

SocketAddress::SocketAddress(SocketAddress &a) {
	m_adress = a.m_adress;
}

SocketAddress::~SocketAddress() {

}

int SocketAddress::setAddress(const std::string & inString) {
	//inString.find_last_of
	//Retorna la posicion de la ultima aparicion de este caracter.
	//Si no aparece, retorna string::npos.
	size_t pos = inString.find_last_of(':');
	std::string host, service;

	//npos es una constante que tiene el valor mayor posible que puede alcanzar una variable del tipo size_t.
	//size_t es un tipo num?rico tal que tiene el n?mero de bits sufientes para representar el n?mero m?s grande de tama?o de array que puede existir.
	//npos vale -1, porque como size_t es un tipo unsigned, -1 es el valor m?s grande que puede representarse (cuando da la vuelta en binario)
	if (pos != std::string::npos)
	{
		host = inString.substr(0, pos);
		service = inString.substr(pos + 1);
	}
	else
	{
		host = inString;
		//0 es el puerto por defecto
		service = "0";
	}

	addrinfo hint;
	//Fuerzo que toda la memoria que corresponde a hint valga 0. As? en getaddrinfo no habr? lugar a malentendidos
	//Recordamos que la funci?n de hint ser? la de filtrar los resultados que me retorne getaddrinfor.
	//En este caso, s?lo me retornar? aquellas direcciones que sean IPv4.
	memset(&hint, 0, sizeof(hint));
	hint.ai_family = AF_INET;

	//En result se almacenar? una lista de las direcciones IP:puerto que conincidan con mis
	//criterios de b?squeda
	addrinfo* result;
	int error = getaddrinfo(host.c_str(), service.c_str(), &hint, &result);

	if (error != 0 && result != nullptr)
	{
		freeaddrinfo(result);
		return -1;
	}
	//Recorro las direcciones de result en busca de una v?lida
	while (!result->ai_addr && result->ai_next)
	{
		result = result->ai_next;
	}
	if (!result->ai_addr)
	{
		freeaddrinfo(result);
		return -1;
	}

	//memcpy copia byte a byte la direcci?n v?lida de result en la direcci?n atributo 
	//de la clase.
	memcpy(&m_adress, result->ai_addr, sizeof(sockaddr_in));
	freeaddrinfo(result);

	return 0;
}

int SocketAddress::setAddress(const in_addr &ip, uint16_t port) {
	//inString.find_last_of
	//Retorna la posici?n de la ?ltima aparici?n de este caracter.
	//Si no aparece, retorna string::npos.
	//size_t pos = inString.find_last_of(':');
	std::string host, service;
	host = ip.S_un.S_addr;
	service = port;

	addrinfo hint;
	//Fuerzo que toda la memoria que corresponde a hint valga 0. As? en getaddrinfo no habr? lugar a malentendidos
	//Recordamos que la funci?n de hint ser? la de filtrar los resultados que me retorne getaddrinfor.
	//En este caso, s?lo me retornar? aquellas direcciones que sean IPv4.
	memset(&hint, 0, sizeof(hint));
	hint.ai_family = AF_INET;

	//En result se almacenar? una lista de las direcciones IP:puerto que conincidan con mis
	//criterios de b?squeda
	addrinfo* result;
	int error = getaddrinfo(host.c_str(), service.c_str(), &hint, &result);

	if (error != 0 && result != nullptr)
	{
		freeaddrinfo(result);
		return -1;
	}
	//Recorro las direcciones de result en busca de una v?lida
	while (!result->ai_addr && result->ai_next)
	{
		result = result->ai_next;
	}
	if (!result->ai_addr)
	{
		freeaddrinfo(result);
		return -1;
	}

	//memcpy copia byte a byte la direcci?n v?lida de result en la direcci?n atributo 
	//de la clase.
	memcpy(&m_adress, result->ai_addr, sizeof(sockaddr_in));
	freeaddrinfo(result);

	return 0;
}

std::ostream& operator<<(std::ostream& os, SocketAddress a) {
	return os << "Ip: " << a.m_adress.sin_addr.S_un.S_addr << "\nPort: " << a.m_adress.sin_port << std::endl;
}

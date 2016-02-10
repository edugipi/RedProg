#include "GenericSocket.h"
#include "SocketAddress.h"
#include <iostream>

void run() {
	in_addr sa_in;
	sa_in.S_un.S_un_b.s_b1 = 127;
	sa_in.S_un.S_un_b.s_b2 = 0;
	sa_in.S_un.S_un_b.s_b3 = 0;
	sa_in.S_un.S_un_b.s_b4 = 1;
	SocketAddress addr("127.0.0.1:0");
	std::cout << addr << std::endl;
	GenericSocket gsocket(SOCK_DGRAM);
}

int main() {
	try {
		SocketTools::BuildLibrary();
		run();
		SocketTools::UnloadLibrary();
		system("pause");
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		system("pause");
	}
	return 0;
}
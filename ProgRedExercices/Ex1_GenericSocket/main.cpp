#include "GenericSocket.h"

#include <iostream>


void run() {
	//creamos socket
	GenericSocket socketUDP(SOCK_DGRAM);
}

int main() {
		//cargamos libreria
		SocketTools::loadLib();
		
		run(); //aqui se crea el socket i al salir del ambito se destruye
		//entonces ya podemos descargar la libreria

		SocketTools::cleanLib();

	return 0;
}

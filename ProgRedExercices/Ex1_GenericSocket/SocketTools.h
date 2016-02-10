#pragma once

#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>
#include <Windows.h>
#include <string>

class SocketTools
{
public:
	SocketTools();
	~SocketTools();

	static void loadLib();
	static void cleanLib();
	static void showError(std::string message);
};


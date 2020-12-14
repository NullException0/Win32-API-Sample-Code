// Win32 API UDP Server.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
	https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsastartup
	https://docs.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-socket
	https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-bind
	https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-recvfrom
	https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-sendto
	https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-closesocket
	https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsacleanup
*/

#include <Windows.h>
#include <iostream>
#include <winsock.h>
using namespace std;

int main()
{
	// Local Variable definitions

	cout << "\t\t------- UDP Server---" << endl;
	cout << endl;

	WSADATA   WinSockData;
	int       iWsaStartup;
	int       iWsaCleanup;

	SOCKET    UDPSocketServer;
	struct    sockaddr_in UDPClient;

	char      Buffer[512];
	int       iBufferLen = 1 + strlen(Buffer);

	int       iBind;
	int       iReceiveFrom;

	int       iUDPClientLen = sizeof(UDPClient);
	int       iCloseSocket;

	// STEP-1 Initialization of Winsock
	iWsaStartup = WSAStartup(MAKEWORD(2, 2), &WinSockData);

	if (iWsaStartup != 0)
		cout << "WSAStartUp Fun Failed" << endl;
	else
		cout << "WSAStartUp Success" << endl;

	//STEP-2 Fill the UDPClient(SOCKET ADDRESS) Structure
	UDPClient.sin_family = AF_INET;
	UDPClient.sin_addr.s_addr = inet_addr("127.0.0.1");
	UDPClient.sin_port = htons(8001);

	// STEP-3 Socket Creation
	UDPSocketServer = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (UDPSocketServer == INVALID_SOCKET)
		cout << "Socket Creation Failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "Socket Creation Success" << endl;

	// STEP-4 bind the server
	iBind = bind(
		UDPSocketServer,
		(SOCKADDR*)&UDPClient,
		sizeof(UDPClient));
	if (iBind == SOCKET_ERROR)
		cout << "Binding Failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "Binding Success" << endl;

	//STEP-5 RecvFrom Fun from receive data from client
	iReceiveFrom = recvfrom(
		UDPSocketServer,
		Buffer,
		iBufferLen,
		MSG_PEEK,
		(SOCKADDR*)&UDPClient,
		&iUDPClientLen);

	if (iReceiveFrom == SOCKET_ERROR)
		cout << "Receiving failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "Receiving Success | Receive Data -> " << Buffer << endl;

	//STEP-6 CloseSocket Function
	iCloseSocket = closesocket(UDPSocketServer);

	if (iCloseSocket == SOCKET_ERROR)
		cout << "Socket Closing failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "Socket CLosing Success" << endl;

	//STEP-7 WSACLeanUp Fun for Terminating the use of DLL
	iWsaCleanup = WSACleanup();
	if (iWsaCleanup == SOCKET_ERROR)
		cout << "WSA CleanUp failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "WSA CleanUp Success" << endl;

	system("PAUSE");
	return 0;
}
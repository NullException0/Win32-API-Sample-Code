// Win32 API UDP Client.cpp : This file contains the 'main' function. Program execution begins and ends there.

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
#include <winsock.h>
#include <iostream>
using namespace std;

int main()
{
	cout << "\t\t------UDP Client------" << endl;
	cout << endl;
	// Local Variable 
	WSADATA   WinSockData;
	int       iWsaStartup;
	int       iWsaCleanup;

	SOCKET               UDPSocketClient;
	struct  sockaddr_in  UDPServer;

	char Buffer[512] = "Hello from Client!";
	int iSendto;

	int  iBufferLen = strlen(Buffer) + 1;
	int  iUDPServerLen = sizeof(UDPServer);
	int  iCloseSocket;

	// STEP-1 Initialization of Winsock

	iWsaStartup = WSAStartup(MAKEWORD(2, 2), &WinSockData);
	if (iWsaStartup != 0)
		cout << "WSAStartup Failed = " << iWsaStartup << endl;
	else
		cout << "WSAStartup Success" << endl;

	// STEP-2 Fill the UDPServer Structure
	UDPServer.sin_family = AF_INET;
	UDPServer.sin_addr.s_addr = inet_addr("127.0.0.1");
	UDPServer.sin_port = htons(8001);

	// STEP-3 Socket Creation

	UDPSocketClient = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (UDPSocketClient == INVALID_SOCKET)
		cout << "Socket Creation Failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "UDP Socket Creation Success" << endl;

	//STEP-4 Sendto Fun.
	iSendto = sendto(
		UDPSocketClient,
		Buffer,
		iBufferLen,
		MSG_DONTROUTE,
		(SOCKADDR*)&UDPServer,
		sizeof(UDPServer));

	if (iSendto == SOCKET_ERROR)
		cout << "Sending Data Failed | Error No->" << WSAGetLastError() << endl;
	else
		cout << "Sending Data Success" << endl;

	// STEP-5 CloseSocket Function

	iCloseSocket = closesocket(UDPSocketClient);
	if (iCloseSocket == SOCKET_ERROR)
		cout << "Socket Closing failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "Close Socket Success" << endl;

	// STEP-6 WSACleanUp fun for Terminating the Winsock DLL

	iWsaCleanup = WSACleanup();
	if (iWsaCleanup == SOCKET_ERROR)
		cout << "WSA CleanUp failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "Cleanup Success" << endl;

	system("PAUSE");
	return 0;
}

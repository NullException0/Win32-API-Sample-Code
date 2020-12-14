// Win32 API TCP Client.cpp : This file contains the 'main' function. Program execution begins and ends there.


/*
	https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsastartup
	https://docs.microsoft.com/en-us/windows/win32/winsock/sockaddr-2
	https://docs.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-socket
	https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-bind
	https://docs.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-listen
	https://docs.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-accept
	https://docs.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-send
	https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-recv
*/
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include<winsock2.h>
#include<iostream>
using namespace std;
int main()
{
	cout << "\t\t------ TCP CLIENT --------" << endl << endl;
	//Local Variable
	WSADATA       WinSockData;
	int           iWsaStartup;
	int           iWsaCleanup;

	SOCKET        TCPClientSocket;
	int           iCloseSocket;

	struct   sockaddr_in     TCPServerAdd;

	int           iConnect;

	int           iRecv;
	char          Buffer[512];
	int           iRecvBuffer = 1 + sizeof(Buffer);

	int        iSend;
	char       SenderBuffer[512] = "Hello from Client!";
	int        iSenderBuffer = 1 + sizeof(SenderBuffer);

	//STEP-1 WSASatrtUp Fun
	iWsaStartup = WSAStartup(MAKEWORD(2, 2), &WinSockData);
	if (iWsaStartup != 0)
		cout << "WSAStartUp Failed" << endl;
	else
		cout << "WSAStartUp Success" << endl;
	// STEP-2 Socket Creation
	TCPClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (TCPClientSocket == INVALID_SOCKET)
		cout << "TCP Client Socket Creation Failed | Error Code - " << WSAGetLastError() << endl;
	else
		cout << "TCP Client Socket Creation Success" << endl;

	// STEP-3 Fill Server Structure
	TCPServerAdd.sin_family = AF_INET;
	TCPServerAdd.sin_addr.s_addr = inet_addr("127.0.0.1");
	TCPServerAdd.sin_port = htons(8000);

	// STEP-4 Connect Fun
	iConnect = connect(
		TCPClientSocket,
		(SOCKADDR*)&TCPServerAdd,
		sizeof(TCPServerAdd));
	if (iConnect == SOCKET_ERROR)
		cout << "Connection Failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "Connection Success" << endl;

	// STEP-5 RECV Data From Server Side
	iRecv = recv(TCPClientSocket, Buffer, iRecvBuffer, 0);
	if (iRecv == SOCKET_ERROR)
		cout << "Receive Data Failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "DATA RECEIVED -> " << Buffer << endl;


	// STEP-6 Send Data to Server
	iSend = send(TCPClientSocket, SenderBuffer, iSenderBuffer, 0);
	if (iSend == SOCKET_ERROR)
		cout << "Sending Failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "Data Sending Success " << endl;

	// STEP-7 Close Socket Fun
	iCloseSocket = closesocket(TCPClientSocket);
	if (iCloseSocket == SOCKET_ERROR)
		cout << "Closing Socket Failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "Closing Socket Success" << endl;

	// STEP-8 WSA CleanUp Fun;
	iWsaCleanup = WSACleanup();
	if (iWsaCleanup == SOCKET_ERROR)
		cout << "CleanUp Fun Failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "CleanUp Fun Success" << endl;
	system("PAUSE");
	return 0;
}
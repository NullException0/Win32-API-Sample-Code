// Win32 API TCP Server.cpp : This file contains the 'main' function. Program execution begins and ends there.


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
	cout << "\t\t------ TCP SERVER ---------" << endl;
	cout << endl;
	//Local Variable
	WSADATA   Winsockdata;
	int       iWsaStartup;
	int       iWsaCleanup;

	SOCKET   TCPServerSocket;
	int      iCloseSocket;

	struct  sockaddr_in  TCPServerAdd;
	struct  sockaddr_in  TCPClientAdd;
	int     iTCPClientAdd = sizeof(TCPClientAdd);

	int iBind;

	int iListen;

	SOCKET sAcceptSocket;

	int   iSend;
	char  SenderBuffer[512] = "Hello from Server!";
	int   iSenderBuffer = sizeof(SenderBuffer) + 1;

	int  iRecv;
	char Buffer[512];
	int  iRecvBuffer = 1 + sizeof(Buffer);

	// STEP -1 WSAStartUp Fun
	iWsaStartup = WSAStartup(MAKEWORD(2, 2), &Winsockdata);
	if (iWsaStartup != 0)
		cout << "WSAStartUp Failed" << endl;
	else
		cout << "WSAStartUp Success" << endl;

	// STEP-2 Fill the Structure
	TCPServerAdd.sin_family = AF_INET;
	TCPServerAdd.sin_addr.s_addr = inet_addr("127.0.0.1");
	TCPServerAdd.sin_port = htons(8000);

	//STEP -3 Socket Creation
	TCPServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (TCPServerSocket == INVALID_SOCKET)
		cout << "TCP Server Socket Creation Failed | Error Code - " << WSAGetLastError() << endl;
	else
		cout << "TCP Server Socket Creation Success" << endl;

	//STEP-4 bind fun
	iBind = bind(
		TCPServerSocket,
		(SOCKADDR*)&TCPServerAdd,
		sizeof(TCPServerAdd));
	if (iBind == SOCKET_ERROR)
		cout << "Binding Failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "Binding Success" << endl;

	//STEP-5 Listen fun
	iListen = listen(TCPServerSocket, 2);
	if (iListen == SOCKET_ERROR)
		cout << "Listen Fun Failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "Listen Fun Success" << endl;

	// STEP-6 Accept
	sAcceptSocket = accept(
		TCPServerSocket,
		(SOCKADDR*)&TCPClientAdd,
		&iTCPClientAdd);
	if (sAcceptSocket == INVALID_SOCKET)
		cout << "Accept Failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "Connection Accepted" << endl;

	// STEP-7 Send Data to Client
	iSend = send(sAcceptSocket, SenderBuffer, iSenderBuffer, 0);
	if (iSend == SOCKET_ERROR)
		cout << "Sending Failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "Data Sending Success " << endl;

	// STEP-8 Recv Data from Client
	iRecv = recv(sAcceptSocket, Buffer, iRecvBuffer, 0);
	if (iRecv == SOCKET_ERROR)
		cout << "Receive Data Failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "DATA RECEIVED -> " << Buffer << endl;


	// STEP-9 Close Socket
	iCloseSocket = closesocket(TCPServerSocket);
	if (iCloseSocket == SOCKET_ERROR)
		cout << "Closing Socket Failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "Closing Socket Success" << endl;

	// STEP-10 CleanUp from DLL
	iWsaCleanup = WSACleanup();
	if (iWsaCleanup == SOCKET_ERROR)
		cout << "CleanUp Fun Failed | Error No-> " << WSAGetLastError() << endl;
	else
		cout << "CleanUp Fun Success" << endl;

	system("PAUSE");
	return 0;
}
// Win32 API CreateNamedPipe Server.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createnamedpipea
// http://awinsyspro.com/16-named-pipe-windows/

/*
	Is a bidirectional or Unidirectional or full duplex
	simultaneously can perform read and write operation
	used over the network
	extension of traditional pipe

	HANDLE CreateNamedPipeA(
	  LPCSTR                lpName,
	  DWORD                 dwOpenMode,
	  DWORD                 dwPipeMode,
	  DWORD                 nMaxInstances,
	  DWORD                 nOutBufferSize,
	  DWORD                 nInBufferSize,
	  DWORD                 nDefaultTimeOut,
	  LPSECURITY_ATTRIBUTES lpSecurityAttributes
	);

*/


#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{
	cout << "....NAMED PIPE SERVER....\n\n" << endl;

	//Named Pipe Local Variable
	HANDLE hCreateNamedPipe = INVALID_HANDLE_VALUE;

	char   szInputBuffer[1023] = { 0 };
	char   szOutputBuffer[1023] = { 0 };
	DWORD  dwszInputBuffer = sizeof(szInputBuffer);
	DWORD  dwszOutputBuffer = sizeof(szOutputBuffer);

	//ConnectNamedpipe Local Variable
	BOOL bConnectNamedPipe = FALSE;

	//WriteFile Local Variable
	BOOL  bWritefile = FALSE;
	char  szWriteFileBuffer[1023] = "Hello From NamedPipe Server!!";
	DWORD dwWriteBufferSize = sizeof(szWriteFileBuffer);
	DWORD dwNoBytesWrite = 0;

	//FlushBuffer
	BOOL bFlushFIleBuffer = FALSE;

	//ReadFile Local Variable
	BOOL  bReadfile = FALSE;
	char  szReadFileBuffer[1023] = { 0 };
	DWORD dwReadBufferSize = sizeof(szWriteFileBuffer);
	DWORD dwNoBytesRead = 0;


	//CreateNamedPipe function
	hCreateNamedPipe = CreateNamedPipe(L"\\\\.\\pipe\\MyPIPE", PIPE_ACCESS_DUPLEX, PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, PIPE_UNLIMITED_INSTANCES, dwszOutputBuffer, dwszInputBuffer, 0, NULL);
	if (hCreateNamedPipe == INVALID_HANDLE_VALUE)
		cout << "NamedPipe Creation Failed | Error No - " << GetLastError() << endl;
	else
		cout << "NamedPipe Creation Success" << endl;


	//ConnectNamedPipe function
	bConnectNamedPipe = ConnectNamedPipe(hCreateNamedPipe, NULL);
	if (!bConnectNamedPipe)
		cout << "Connection Failed & Error No - " << GetLastError() << endl;
	else
		cout << "Connection Success" << endl;


	//WriteFile function
	bWritefile = WriteFile(hCreateNamedPipe, szWriteFileBuffer, dwWriteBufferSize, &dwNoBytesWrite, NULL);

	if (!bWritefile)
		cout << "WriteFile Failed = " << GetLastError() << endl;
	else
		cout << "WriteFile Success" << endl;


	//FlushFileBuffers function
	bFlushFIleBuffer = FlushFileBuffers(hCreateNamedPipe);
	if (!bFlushFIleBuffer)
		cout << "FLushfileBuffer Failed & Error No - " << GetLastError() << endl;
	else
		cout << "FLushfileBuffer Success" << endl;


	//ReadFile function
	bReadfile = ReadFile(hCreateNamedPipe, szReadFileBuffer, dwReadBufferSize, &dwNoBytesRead, NULL);

	if (!bReadfile)
		cout << "ReadFile Failed = " << GetLastError() << endl;
	else
		cout << "ReadFile Success" << endl;

	cout << " DATA READING FROM CLIENT -> " << szReadFileBuffer << endl;

	//Disconnect the Named Pipe 
	DisconnectNamedPipe(hCreateNamedPipe);//Named Pipe Handle

	//CloseHandle 
	CloseHandle(hCreateNamedPipe);

	system("PAUSE");
	return 0;
}


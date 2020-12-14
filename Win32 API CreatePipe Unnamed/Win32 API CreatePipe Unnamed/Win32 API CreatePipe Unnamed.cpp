// Win32 API CreatePipe Unnamed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://docs.microsoft.com/en-us/windows/win32/api/namedpipeapi/nf-namedpipeapi-createpipe
//http://awinsyspro.com/15-pipes-anonymous-pipes-windows/

/*
	
	Inter-process communication is a mechanism that allows to communicate between processes.

	BOOL CreatePipe(
	  PHANDLE               hReadPipe,
	  PHANDLE               hWritePipe,
	  LPSECURITY_ATTRIBUTES lpPipeAttributes,
	  DWORD                 nSize
	);
*/

#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{
	BOOL     bCreatepipe = FALSE;
	BOOL     bWritefile = FALSE;
	BOOL     bReadfile = FALSE;

	HANDLE   hRead;
	HANDLE   hWrite;

	char     szBuffer[512] = "Hello Pipe";
	DWORD    dwBufferSize = sizeof(szBuffer);
	DWORD    dwNoBytesWrite = 0;
	DWORD    dwNoBytesRead = 0;

	bCreatepipe = CreatePipe(&hRead, &hWrite, NULL, dwBufferSize);

	if (!bCreatepipe)
		cout << GetLastError() << endl;
	else
		cout << "CreatePipe success" << endl;

	//write operation

	bWritefile = WriteFile(hWrite, szBuffer, dwBufferSize, &dwNoBytesWrite, NULL);

	if (!bWritefile)
		cout << GetLastError() << endl;
	else
		cout << "WriteFile Success" << endl;

	CloseHandle(hWrite);

	//read operation

	bReadfile = ReadFile(hRead, szBuffer, dwBufferSize, &dwNoBytesRead, NULL);

	if (!bReadfile)
		cout << GetLastError() << endl;
	else
		cout << "Readfile Success" << endl;

	//data from pipe
	cout << "Your Data : " << szBuffer << endl;

	CloseHandle(hRead);


	system("PAUSE");
	return 0;
}


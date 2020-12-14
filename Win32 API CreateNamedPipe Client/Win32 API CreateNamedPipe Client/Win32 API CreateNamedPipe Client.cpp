// Win32 API CreateNamedPipe Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createnamedpipea
// http://awinsyspro.com/16-named-pipe-windows/

#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{
	cout << "....NAMED PIPE CLIENT....\n\n" << endl;

	//Local Variable 
	HANDLE hCreatefile = INVALID_HANDLE_VALUE;

	//Readfile Local Variable
	BOOL      bReadfile = FALSE;
	DWORD     dwNoBytesRead = 0;
	char      szReadFileBuffer[1023] = { 0 };
	DWORD     dwReadFileBufferSize = sizeof(szReadFileBuffer);

	//WriteFile Local Variable 
	BOOL      bWritefile = FALSE;
	DWORD     dwNoBytesWrite = 0;
	char      szWriteFileBuffer[1023] = "Hello From NamedPipe Client!";
	DWORD     dwWriteFileBufferSize = sizeof(szWriteFileBuffer);


	//CreateFile for PipeClient
	hCreatefile = CreateFile(L"\\\\.\\pipe\\MyPIPE", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hCreatefile == INVALID_HANDLE_VALUE)
		cout << "File Creation Failed | Error No = " << GetLastError() << endl;
	else
		cout << "File Creation Success" << endl;


	//read data from NamedPipe Server (ReadFile)
	bReadfile = ReadFile(hCreatefile, szReadFileBuffer, dwReadFileBufferSize, &dwNoBytesRead, NULL);

	if (!bReadfile)
		cout << "ReadFile Failed = " << GetLastError() << endl;
	else
		cout << "ReadFile Success" << endl;

	cout << " DATA READING FROM SERVER -> " << szReadFileBuffer << endl;


	//Writing data to NamedPipe Server(Writefile)

	bWritefile = WriteFile(hCreatefile, szWriteFileBuffer, dwWriteFileBufferSize, &dwNoBytesWrite, NULL);

	if (!bWritefile)
		cout << "WriteFile Failed = " << GetLastError() << endl;
	else
		cout << "WriteFile Success" << endl;


	//Flush Files Buffers
	FlushFileBuffers(hCreatefile);


	//STEP-5 Close Handle
	CloseHandle(hCreatefile);

	system("PAUSE");
	return 0;
}

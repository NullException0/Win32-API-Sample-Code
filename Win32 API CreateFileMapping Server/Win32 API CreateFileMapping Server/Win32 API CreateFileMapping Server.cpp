// Win32 API CreateFileMapping Server.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createfilemappinga
// https://docs.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffile
// https://docs.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-unmapviewoffile
// http://awinsyspro.com/18-file-mapping-windows/

#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{
	cout << "...SERVER or PARENT PROCESS..\n\n" << endl;

	HANDLE   hFileMap;
	BOOL     bResult;
	PCHAR    lpBuffer = NULL;
	char     Buffer[1024] = "Hi from File Map Server";
	size_t   szBuffer = sizeof(Buffer);


	//CreateFileMapping function

	hFileMap = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 256, L"Local\\PetaFileSaya");

	if (!hFileMap)
		cout << "CreateFileMapping Failed | Error : "<< GetLastError() << endl;

	else
		cout << "CreateFileMapping Success" << endl;


	//MapViewOfFile function

	lpBuffer = (PCHAR)MapViewOfFile(hFileMap, FILE_MAP_ALL_ACCESS, 0, 0, 256);

	if (lpBuffer == NULL)
		cout << "MapViewOfFile failed | Error No : " << GetLastError() << endl;
	else
		cout << "MapViewOfFile Success" << endl;


	//CopyMemory Function

	CopyMemory(lpBuffer, Buffer, szBuffer);


	//UnmapViewOfFile Function

	bResult = UnmapViewOfFile(lpBuffer);

	if (bResult == FALSE)
		cout << "UnMapViewOfFIle Failed | Error No : " << GetLastError() << endl;
	else
		cout << "UnMapViewOfFIle Success" << endl;


	system("PAUSE");
	return 0;
}


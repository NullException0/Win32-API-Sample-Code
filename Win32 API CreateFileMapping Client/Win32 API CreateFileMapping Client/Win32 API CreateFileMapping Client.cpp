// Win32 API CreateFileMapping Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-openfilemappinga
// https://docs.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffile
// https://docs.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-unmapviewoffile
// http://awinsyspro.com/18-file-mapping-windows/

/*
	HANDLE CreateFileMappingA(
	  HANDLE                hFile,
	  LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
	  DWORD                 flProtect,
	  DWORD                 dwMaximumSizeHigh,
	  DWORD                 dwMaximumSizeLow,
	  LPCSTR                lpName
	);
*/

#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{
	cout << "..CLIENT or CHILD PROCESS..\n\n" << endl;

	HANDLE   hFileMap;
	BOOL     bResult;
	PCHAR    lpBuffer = NULL;

	//OpenFileMapping function

	hFileMap = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"Local\\PetaFileSaya");

	if (hFileMap == NULL)
		cout << "OpenFIleMap Failed | Error No : " << GetLastError() << endl;
	else
		cout << "OpenFIleMap Success" << endl;


	//MapViewOfFile function

	lpBuffer = (PCHAR)MapViewOfFile(hFileMap, FILE_MAP_ALL_ACCESS, 0, 0, 256);
	if (lpBuffer == NULL)
		cout << "MapViewOfFile Failed | Error No : " << GetLastError() << endl;
	else
		cout << "MapViewOfFile Success" << endl;


	//Accessing data

	cout << "DATA READED FROM SERVER or PARENT PROCESS" << endl;

	cout << lpBuffer << endl;


	//UnmapViewOfFile function

	bResult = UnmapViewOfFile(lpBuffer);
	if (bResult == NULL)
		cout << "Unmapping Failed | Error No : " << GetLastError() << endl;
	else
		cout << "Unmapping Success" << endl;


	//Close Handle

	CloseHandle(hFileMap);
	system("PAUSE");
	return 0;
}


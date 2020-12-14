// Win32 API WriteFile and ReadFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
		https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-writefile
		https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-readfile

		BOOL WriteFile(
		  HANDLE       hFile,
		  LPCVOID      lpBuffer,
		  DWORD        nNumberOfBytesToWrite,
		  LPDWORD      lpNumberOfBytesWritten,
		  LPOVERLAPPED lpOverlapped
		);


		BOOL ReadFile(
		  HANDLE       hFile,
		  LPVOID       lpBuffer,
		  DWORD        nNumberOfBytesToRead,
		  LPDWORD      lpNumberOfBytesRead,
		  LPOVERLAPPED lpOverlapped
		);
*/

#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{
	HANDLE hFile;
	BOOL tutupHandle, writeMyFile, readMyFile;

	char chBuffer[] = "Writing a sample thest to write and read API";

	DWORD dwNoByteToWrite = strlen(chBuffer);
	DWORD dwNoByteToWritten = 0;


	DWORD dwNoByteToRead = strlen(chBuffer);
	DWORD dwNoByteRead = 0;

	hFile = CreateFile(L"C:\\Users\\azizi\\Desktop\\testFile.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
		cout << "Fail to create file \nError No : " << GetLastError() << endl;
	else
		cout << "File created" << endl;

	//write to file

	writeMyFile = WriteFile(hFile, chBuffer, dwNoByteToWrite, &dwNoByteToWritten, NULL);

	if (!writeMyFile)
		cout << "Fail to write to file \nError No : " << GetLastError() << endl;
	else
		cout << "File written" << endl;


	//read file

	writeMyFile = ReadFile(hFile, chBuffer, dwNoByteToRead, &dwNoByteRead, NULL);

	if (!writeMyFile)
		cout << "Fail to read the file \nError No : " << GetLastError() << endl;
	else
		cout << "File read" << endl;



	//close an open object handle
	tutupHandle = CloseHandle(hFile);

	//checking is optional
	if (!tutupHandle)
		cout << "Fail to close handle object \nError No : " << GetLastError() << endl;
	else
		cout << "handle object closed" << endl;

	cout << "Data read from file : " << chBuffer << endl;

	system("PAUSE");
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

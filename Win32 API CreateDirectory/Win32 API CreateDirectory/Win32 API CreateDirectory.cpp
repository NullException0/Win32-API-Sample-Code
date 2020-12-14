// Win32 API CreateDirectory.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createdirectorya

/*
	lpPathName = The path of the directory to be created.
	lpSecurityAttributes = A pointer to a SECURITY_ATTRIBUTES structure

	BOOL RemoveDirectoryA(LPCSTR lpPathName);
	BOOL CreateDirectory(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
*/

#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{
	BOOL cDir;

	//create directory

	cDir = CreateDirectory(L"C:\\Users\\azizi\\Desktop\\test", NULL);

	if (!cDir)
		cout << "Create Directory Failed : " << GetLastError() << endl;
	else
		cout << "Create Directory success : " << endl;

	//remove directory

	cDir = RemoveDirectory(L"C:\\Users\\azizi\\Desktop\\test");

	if (!cDir)
		cout << "Remove Directory Failed : " << GetLastError() << endl;
	else
		cout << "Remove Directory success : " << endl;

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

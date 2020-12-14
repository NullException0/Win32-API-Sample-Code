// Win32 API Copy File.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-copyfile

/*
		BOOL CopyFile(LPCTSTR lpExistingFileName, LPCTSTR lpNewFileName, BOOL bFailIfExists);
	
	cpFile = CopyFile(L"Drive:\\location\\to\\file", L"Drive:\\location\\to\\file", TRUE);

	If this parameter is TRUE and the new file specified by lpNewFileName already exists, the function fails.
	If this parameter is FALSE and the new file already exists, the function overwrites the existing file and succeeds
*/

#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	BOOL cpFile;

	cpFile = CopyFile(L"C:\\Users\\azizi\\Desktop\\oldFile.txt", L"C:\\Users\\azizi\\Desktop\\newFile.txt", TRUE);

	if (!cpFile)
		cout << "File copy is failed : " << GetLastError() << endl;
	else
		cout << "File copy is successful" << endl;

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

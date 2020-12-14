// Wind32 API Rename and Moving.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-movefile

/*
	For files and folder, can be used for rename or move file or folder.

	BOOL MoveFile( LPCTSTR lpExistingFileName, LPCTSTR lpNewFileName );

	lpExistingFileName = The current name of the file or directory on the local computer.
	lpNewFileName = The new name for the file or directory. The new name must not already exist. A new file may be on a different file system or drive. A new directory must be on the same drive.
	return value = If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.

	MoveFile function will move (rename) either a file or a directory (including its children) either in the same directory or across directories. 
	The one caveat is that the MoveFile function will fail on directory moves when the destination is on a different volume.
*/

#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{
	BOOL mvFile;

	mvFile = MoveFile(L"C:\\Users\\azizi\\Desktop\\newFile.txt", L"C:\\Users\\azizi\\Desktop\\newFile2.txt");

	if (!mvFile)
		cout << "Failed to move file : " << GetLastError() << endl;
	else
		cout << "Move file successfull: " << GetLastError() << endl;

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

// Win32 API HardLink File.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createhardlinka

/*
  
     BOOL CreateHardLinkA(
      LPCSTR                lpFileName,
      LPCSTR                lpExistingFileName,
      LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );

*/

#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{
    BOOL chLink;
    chLink = CreateHardLink(L"C:\\Users\\azizi\\source\\repos\\Win32 API HardLink File\\HardFile.txt", L"C:\\Users\\azizi\\source\\repos\\Win32 API HardLink File\\TestFile.txt", NULL);

    if (!chLink)
        cout << "Create Hardlink file failed : " << GetLastError() << endl;
    else
        cout << "Hardlink file created" << endl;

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

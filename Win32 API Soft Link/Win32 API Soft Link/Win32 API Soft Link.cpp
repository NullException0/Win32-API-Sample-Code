// Win32 API Soft Link.cpp : This file contains the 'main' function. Program execution begins and ends there.
// if you delete your original file/folder, you cannot open the soft link file/folder created
//https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createsymboliclinka

/*
        BOOLEAN CreateSymbolicLinkA(
          LPCSTR lpSymlinkFileName,
          LPCSTR lpTargetFileName,
          DWORD  dwFlags
        );
*/

#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{
    BOOL simpLink;
    simpLink = CreateSymbolicLink(L"C:\\Users\\azizi\\Desktop\\softLink.txt",L"C:\\Users\\azizi\\Desktop\\original.txt", 0);

    if (!simpLink)
        cout << "Failed to create soft link file intended | error no : " << GetLastError() << endl;
    else
        cout << "Created soft link file intended" << endl;

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

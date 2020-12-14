// Win32 API Mutex.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://docs.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-createmutexa
// https://docs.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-openmutexw

/*
    + Mutex only used for thread synchronization
    + Mutex is a locking mechanism
    + Only one state Locked or Unlocked
    + If locked more that once in non-recusive the deadlock will occure
    + In Windows has 2 type of Mutex
        - Named Mutex
        - Unnamed Mutex

        HANDLE CreateMutexA(
          LPSECURITY_ATTRIBUTES lpMutexAttributes,
          BOOL                  bInitialOwner,
          LPCSTR                lpName
        );


*/
#include <iostream>
#include <Windows.h>
using namespace std;

//Unname Mutex

    int main()
    {
        HANDLE hMutex;

        cout << "Mutex 1" << endl;

        hMutex = CreateMutex(NULL, FALSE, L"MyMutex");

        if (hMutex == NULL)
            cout << "CreateMutex Failed : " << GetLastError() << endl;
        else
            cout << "CreateMutex is success" << endl;

        getchar();

        //CloseHandle(hMutex);

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

// Win32 API CreateSemaphore.cpp : This file contains the 'main' function. Program execution begins and ends there.


/*

        A semaphore is an integer variable
        Is a signalling Mechanism
        Its value can be modified by WAIT & SIGNAL2
        Has 2 types:
            Binary semaphore
            Counting semaphore
        Semaphore vluew modified by any process by acquiring or releasing the semaphore

        HANDLE OpenSemaphoreW(
          DWORD   dwDesiredAccess,
          BOOL    bInheritHandle,
          LPCWSTR lpName
        );

        https://docs.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-opensemaphorew

*/


#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{
    HANDLE hSem;

    hSem = OpenSemaphore(SEMAPHORE_ALL_ACCESS,FALSE, L"MySemaphore");

    if (hSem == NULL)
        cout << "Open Semaphore failed : " << GetLastError() << endl;
    else
        cout << "Open semaphore success" << endl;

    CloseHandle(hSem);


    system("PAUSE");
    return 0;
}


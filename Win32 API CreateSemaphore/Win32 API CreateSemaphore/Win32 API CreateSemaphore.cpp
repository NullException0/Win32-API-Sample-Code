// Win32 API CreateSemaphore.cpp : This file contains the 'main' function. Program execution begins and ends there.


/*

        A semaphore is an integer variable
        Is a signalling Mechanism
        Its value can be modified by WAIT & SIGNAL2
        Has 2 types:
            Binary semaphore
            Counting semaphore
        Semaphore vluew modified by any process by acquiring or releasing the semaphore

        HANDLE CreateSemaphoreA(
          LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
          LONG                  lInitialCount,
          LONG                  lMaximumCount,
          LPCSTR                lpName
        );

*/


#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{
    HANDLE hSem;

    /* Unnamed semaphore

        hSem = CreateSemaphore(NULL, 1, 1, NULL);

    */

    //Named semaphore
    hSem = CreateSemaphore(NULL, 1, 1, L"MySemaphore");

    if (hSem == NULL)
        cout << "Create Semaphore failed : " << GetLastError() << endl;
    else
        cout << "Create semaphore success" << endl;

    getchar();

    CloseHandle(hSem);


    system("PAUSE");
    return 0;
}


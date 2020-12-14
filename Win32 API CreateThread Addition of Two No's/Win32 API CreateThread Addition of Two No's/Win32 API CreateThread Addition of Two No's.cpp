// Win32 API CreateThread Addition of Two No's.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createthread

/*
    HANDLE CreateThread(
      LPSECURITY_ATTRIBUTES   lpThreadAttributes,
      SIZE_T                  dwStackSize,
      LPTHREAD_START_ROUTINE  lpStartAddress,
      __drv_aliasesMem LPVOID lpParameter,
      DWORD                   dwCreationFlags,
      LPDWORD                 lpThreadId
    );
*/

#include <iostream>
#include <Windows.h>
using namespace std;

int a[2];

DWORD WINAPI ThreadFun(LPVOID lpParam) {

    int x, y, result;

    x = a[0];
    y = a[1];

    result = x + y;

    cout << "Addition : " << result << endl;

    return 0;

}


int main()
{
    HANDLE hThread;
    DWORD ThreadID;

    cout << "Enter your number" << endl;
    cin >> a[0];
    cout << "Enter your number" << endl;
    cin >> a[1];

    hThread = CreateThread(NULL, 0, ThreadFun, (void*)&a, 0, &ThreadID);

    if (hThread == NULL)
        cout << "Thread Creation failed successfully | Error : " << GetLastError() << endl;
    else
        cout << "Thread Creation successfully" << endl;

    cout << "Thread ID : " << ThreadID << endl;

    CloseHandle(hThread);

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

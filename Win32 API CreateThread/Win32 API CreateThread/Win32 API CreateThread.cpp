// Win32 API CreateThread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createthread

/*

    Thread is independent entity run within a process
    Terminating a thread does not necessarily remove the thread object from operating system
    Can create 2048 MAX thread in process

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

DWORD WINAPI ThreadFun(LPVOID lpParam) {

    cout << "Thread Running" << endl;
    return 0;

}


int main()
{
    HANDLE hThread;
    DWORD ThreadID;

    hThread = CreateThread(NULL, 0, ThreadFun,NULL,0,&ThreadID);

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

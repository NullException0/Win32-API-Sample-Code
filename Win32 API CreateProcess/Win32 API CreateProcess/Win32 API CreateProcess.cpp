// Win32 API CreateProcess.cpp : This file contains the 'main' function. Program execution begins and ends there.


/*
    https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessa

        BOOL CreateProcessA(
          LPCSTR                lpApplicationName,
          LPSTR                 lpCommandLine,
          LPSECURITY_ATTRIBUTES lpProcessAttributes,
          LPSECURITY_ATTRIBUTES lpThreadAttributes,
          BOOL                  bInheritHandles,
          DWORD                 dwCreationFlags,
          LPVOID                lpEnvironment,
          LPCSTR                lpCurrentDirectory,
          LPSTARTUPINFOA        lpStartupInfo,
          LPPROCESS_INFORMATION lpProcessInformation
        );

    https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocessid

        DWORD GetProcessId(
          HANDLE Process
        );

    https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getthreadid

        DWORD GetThreadId(
          HANDLE Thread
        );

    https://docs.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject

    //kiling parent process can cause zombie or orphan process
        DWORD WaitForSingleObject(
          HANDLE hHandle,
          DWORD  dwMilliseconds
        );

    https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/ns-processthreadsapi-startupinfoa


*/

#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{

    HANDLE hProcess = NULL;
    HANDLE hThread = NULL;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD dwProcessId = 0;
    DWORD dwThreadId = 0;
    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));

    wstring test = L"C:\\WINDOWS\\system32\\cmd.exe /c systeminfo";

    BOOL bCP;
    bCP = CreateProcess(L"C:\\WINDOWS\\system32\\cmd.exe", &test[0], NULL, NULL,FALSE,0,NULL,NULL,&si,&pi);

    if (!bCP)
        cout << "Failed to create process : " << GetLastError() << endl;
    else
        cout << "create process successfull" <<  endl;

    cout << "Process ID : " << pi.dwProcessId << endl;
    cout << "Thread ID : " << pi.dwThreadId << endl;
    cout << "Get Process ID : " << GetProcessId(pi.hProcess) << endl;

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);

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

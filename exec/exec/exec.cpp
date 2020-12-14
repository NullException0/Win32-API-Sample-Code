
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

    wstring cmd = L"C:\\WINDOWS\\system32\\cmd.exe";
    wstring test = L"/c sc query WinDefend > %homepath%\Desktop\query.txt";
    wstring test1 = L"/c netsh advfirewall show allprofiles > %homepath%\Desktop\systeminfo.txt";

    BOOL bCP;
    bCP = CreateProcess(&cmd[0], &test[0], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

    if (!bCP)
        cout << "Failed to create process : " << GetLastError() << endl;
    else
        cout << "create process successfull: " << &pi << endl;
    
    bCP = CreateProcess(&cmd[0], &test1[0], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

    if (!bCP)
        cout << "Failed to create process : " << GetLastError() << endl;
    else
        cout << "create process successfull: " << &pi << endl;

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);

    system("PAUSE");

    return 0;
}

// Win32 API Thread Synchronization Using CreateMutex and CreateThread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


/*

	1. Printing Odd and even number using Thread and Mutex
	2. CreateMutex
	3. Create 2 thread
	4. Create ThreadFunc. In ThreadFunc use WaitForSingleObject and ReleaseMutex API
	5 In Main function, use CloseHandle API

	https://docs.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-releasemutex



*/


#include <iostream>
#include <Windows.h>
using namespace std;

HANDLE hMutex;
int gcount = 1;

DWORD WINAPI ThreadFuncEven(LPVOID lpParam) {

	while (gcount < 10)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if (gcount % 2 == 0) {
			cout << "Even : " << gcount++ << endl;
		}
		ReleaseMutex(hMutex);
	}
	return 0;
}

DWORD WINAPI ThreadFuncOdd(LPVOID lpParam) {

	while (gcount < 10)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if (gcount % 2 == 1) {
			cout << "Odd : " << gcount++ << endl;
		}
		ReleaseMutex(hMutex);
	}
	return 0;
}


int main()
{
	HANDLE hThread1, hThread2;

	hMutex = CreateMutex(NULL, FALSE, NULL);

	hThread1 = CreateThread(NULL, 0, ThreadFuncEven, NULL, 0, NULL);


	hThread2 = CreateThread(NULL, 0, ThreadFuncOdd, NULL, 0, NULL);

	CloseHandle(hThread1);
	CloseHandle(hThread2);
	CloseHandle(hMutex);

	system("PAUSE");
	return 0;
}
// Win32 API Create Registry.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


/*
        Registry is a centralized, Hierarchical database for application and system configuration information

        Registry contains following information:
            + windows version, build number and registred user
            + about computers processor type
            + user specific information
            + security information
            + installed service
            + file name and extension
*/

/*
        Registry Key type
            1.HKEY_CLASSES_ROOT
                + Contains file type information and Which program are used open a particular file type.
                + Mappings of file extensions such as .doc and .docx mapped to Microsoft Word.
            2.HKEY_CURRENT_USER
                + Contains user specific information, including environment variable, pointers.
                + Application preferences which apply to the current user.
            3.HKEY_LOCAL_MACHINE
                + Store Physical information or hardware about the machine and installed software.
                + Generally, most of the local user used this key.
            4.HKEY_USERS
                + Contains User Configuration information.
                + Including Settings for Program ,Desktop Configuration etc.
            5.HKEY_CURRENT_CONFIG
                + Store current settings of Hardware ,Display resolution and fonts.


        Registry Function List - https://msdn.microsoft.com/en-us/library/windows/desktop/ms724875(v=vs.85).aspx
        RegistryCreate Key API - https://msdn.microsoft.com/en-us/library/windows/desktop/ms724844(v=vs.85).aspx

                LONG LSTATUS RegCreateKeyExA(
                  HKEY                        hKey,
                  LPCSTR                      lpSubKey,
                  DWORD                       Reserved,
                  LPSTR                       lpClass,
                  DWORD                       dwOptions,
                  REGSAM                      samDesired,
                  const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
                  PHKEY                       phkResult,
                  LPDWORD                     lpdwDisposition
                );

        Registry Set Value API - https://msdn.microsoft.com/en-us/library/windows/desktop/ms724923(v=vs.85).aspx

                LONG LSTATUS RegSetValueExA(
                  HKEY       hKey,
                  LPCSTR     lpValueName,
                  DWORD      Reserved,
                  DWORD      dwType,
                  const BYTE *lpData,
                  DWORD      cbData
                );

        Registry Close Key API - https://msdn.microsoft.com/en-us/library/windows/desktop/ms724837(v=vs.85).aspx
*/


#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{
    //need to run as admin

    //Create Registry Path

    HKEY hKey;

    LONG lReg;

    DWORD dwData = 1234;

    
    lReg = RegCreateKeyEx(HKEY_LOCAL_MACHINE, L"Software\\Test\\Product\\SmartId", 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS | KEY_WOW64_64KEY, NULL, &hKey, NULL);

    if (lReg != ERROR_SUCCESS)
        cout << "Failed to create registry key | Error : " << GetLastError() << endl;
    else
        cout << "Registry key created successfully" << endl;


    //Create registry value

    lReg = RegSetValueEx(hKey, L"VALUE", NULL, REG_DWORD, (LPBYTE)&dwData,sizeof(dwData));

    if (lReg != ERROR_SUCCESS)
        cout << "Failed to create registry key | Error : " << GetLastError() << endl;
    else
        cout << "Registry key created successfully" << endl;


    //Close handler

    RegCloseKey(hKey);

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

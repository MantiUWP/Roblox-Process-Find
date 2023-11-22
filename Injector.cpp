#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>

int main() {
    std::cout << "[+]Byfron Bypasser[BETA]" << std::endl;
    Sleep(5000);
    std::cout << "[+]Roblox Scanning..." << std::endl;

    DWORD processId = 0;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (snapshot != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32 processEntry;
        processEntry.dwSize = sizeof(PROCESSENTRY32);

        if (Process32First(snapshot, &processEntry) == TRUE) {
            do {
                if (_wcsicmp(processEntry.szExeFile, L"Windows10Universal.exe") == 0) {
                    processId = processEntry.th32ProcessID;

                    // Display a message box when the process is found
                    MessageBox(nullptr, L"Injected Succefly!", L"Roblox UWP Found!", MB_OK | MB_ICONINFORMATION);

                    break;
                }
            } while (Process32Next(snapshot, &processEntry) == TRUE);
        }

        CloseHandle(snapshot);
    }

    if (processId != 0) {
        std::cout << "[+]Roblox Process ID: " << processId << std::endl;
    }
    else {
        std::cout << "[+]Roblox UWP Not Found!" << std::endl;
    }

    // Wait for a key press before closing the console window
    getchar();

    return 0;
}

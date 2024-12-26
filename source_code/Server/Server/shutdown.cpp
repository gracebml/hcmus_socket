#include "shutdown.h"
#include <thread>
#include <chrono>

bool ShutDownPC() {
    // Adjust privileges to enable shutdown
    HANDLE hToken;
    TOKEN_PRIVILEGES tkp;
    // Get a token for this process
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
        std::cout << "Failed to get process token.\n";
        return false;
    }
    // Get the LUID for the shutdown privilege
    if (!LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid)) {
        std::cout << "Failed to lookup shutdown privilege.\n";
        CloseHandle(hToken);
        return false;
    }
    tkp.PrivilegeCount = 1;  // Set one privilege
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    // Adjust the token privileges to enable shutdown
    if (!AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, NULL, 0)) {
        std::cout << "Failed to adjust token privileges.\n";
        CloseHandle(hToken);
        return false;
    }
    // Check for any errors from AdjustTokenPrivileges
    if (GetLastError() == ERROR_NOT_ALL_ASSIGNED) {
        std::cout << "The token does not have the required privileges.\n";
        CloseHandle(hToken);
        return false;
    }
    std::cout << "System shutting down...\n";

    if (!InitiateSystemShutdownEx(
        NULL,                   // Target computer
        NULL,        // Modifiable wide string
        15,                      // Timeout in seconds
        TRUE,                   // Force applications to close
        TRUE,                  // Do not reboot after shutdown
        SHTDN_REASON_MAJOR_OTHER | SHTDN_REASON_FLAG_PLANNED)) {
        std::cout << "Failed to shutdown.\n";
        CloseHandle(hToken);
        return false;
    }
    
    CloseHandle(hToken);
    return true;
}

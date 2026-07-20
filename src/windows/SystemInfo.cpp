#include "../../include/SystemInfo.hpp"
#include <iostream>
#include <string>
#include <windows.h>
#include <winreg.h>

std::string computerName(){
    char buffer[256] = {};
    DWORD value = 256;
    GetComputerNameA(buffer, &value);
    std::string username(buffer);
    return username;
}

unsigned long long computerTotalRam(){
    MEMORYSTATUSEX buffer;
    buffer.dwLength = sizeof(buffer);
    GlobalMemoryStatusEx(&buffer);
    return buffer.ullTotalPhys/(1024*1024);
}

unsigned long long computerAvaRam(){
    MEMORYSTATUSEX buffer;
    buffer.dwLength = sizeof(buffer);
    GlobalMemoryStatusEx(&buffer);
    return buffer.ullAvailPhys/(1024*1024);
}

std::string centralProc(){
    HKEY hkey = HKEY_LOCAL_MACHINE;
    LPCTSTR lpSubKey = "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0";
    LPCTSTR lpValue = "ProcessorNameString";
    DWORD type;
    char buffer[256] = {};
    DWORD value = 256;
    RegGetValueA(hkey, lpSubKey, lpValue, RRF_RT_REG_SZ, &type, buffer, &value);
    std::string centralProcessorName(buffer);
    return centralProcessorName;
}

std::string motherBoard(){
    HKEY hkey = HKEY_LOCAL_MACHINE;
    LPCTSTR lpSubKey = "HARDWARE\\DESCRIPTION\\System\\BIOS";
    LPCTSTR lpValue = "BaseBoardProduct";
    DWORD type;
    char buffer[256] = {};
    DWORD value = 256;
    RegGetValueA(hkey, lpSubKey, lpValue, RRF_RT_REG_SZ, &type, buffer, &value);
    std::string motherBoard(buffer);
    return motherBoard;
}

std::string graphicsCard(){
    HKEY hkey = HKEY_LOCAL_MACHINE;
    LPCTSTR lpSubKey = "SYSTEM\\ControlSet001\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000";
    LPCTSTR lpValue = "DriverDesc";
    DWORD type;
    char buffer[256] = {};
    DWORD value = 256;
    RegGetValueA(hkey, lpSubKey, lpValue, RRF_RT_REG_SZ, &type, buffer, &value);
    std::string graphicsCard(buffer);
    return graphicsCard;
}

SystemInfo collectSystemInfo(){
    SystemInfo info;
    info.username = computerName();
    info.totalRamMB = computerTotalRam();
    info.availableRamMB = computerAvaRam();
    info.CPU = centralProc();
    info.motherBoard = motherBoard();
    info.GPU = graphicsCard();
    return info;
}

//hello

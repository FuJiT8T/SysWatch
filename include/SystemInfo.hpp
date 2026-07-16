#pragma once
#include <string>
#include <windows.h>

struct SystemInfo
{
    std::string username;
    unsigned long long totalRamMB;
    unsigned long long availableRamMB;
};

SystemInfo collectSystemInfo();
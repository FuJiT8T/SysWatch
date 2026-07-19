#pragma once
#include <string>

struct SystemInfo
{
    std::string username;
    unsigned long long totalRamMB;
    unsigned long long availableRamMB;
};

SystemInfo collectSystemInfo();
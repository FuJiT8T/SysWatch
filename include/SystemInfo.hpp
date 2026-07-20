#pragma once
#include <string>

struct SystemInfo
{
    std::string username;
    unsigned long long totalRamMB;
    unsigned long long availableRamMB;
    std::string CPU;
    std::string motherBoard;
    std::string GPU;
};

SystemInfo collectSystemInfo();
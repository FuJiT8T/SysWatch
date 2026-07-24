#include "../../include/SystemInfo.hpp"
#include <string> 
#include <stdlib.h>

std::string computerName(){
    std::string username = std::to_string(system("cat /etc/hostname"));
    return username;
}

unsigned long long computerTotalRam(){
    unsigned long long totalRam = system("grep -m 1 \"MemTotal\" /proc/meminfo")*1024;
    return totalRam;
}

unsigned long long computerAvaRam(){
    unsigned long long avaRam = system("grep -m 1 \"MemFree\" /proc/meminfo")*1024;
    return avaRam;
}

std::string centralProc(){
    std::string centralProcessorName = std::to_string(system("grep -m 1 \"model name\" /proc/cpuinfo"));
    return centralProcessorName;
}

std::string motherBoard(){
    std::string boardName = std::to_string(system("cat /sys/class/dmi/id/board_name"));
    return boardName;
}

std::string graphicsCard(){
    return "---";
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
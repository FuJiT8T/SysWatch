#include <iostream>
#include "../include/SystemInfo.hpp"
#include "windows/SystemInfo.cpp"
#include <windows.h>

int main(){
    std::cout << "The username: " << collectSystemInfo().username << std::endl;
    std::cout << "The total RAM: " << collectSystemInfo().totalRamMB << std::endl;
    std::cout << "The available amount of RAM: " << collectSystemInfo().availableRamMB << std::endl;
    std::cout << "The proccesor is: " << collectSystemInfo().CPU << std::endl;
    std::cout << "The motherboard is: " << collectSystemInfo().motherBoard << std::endl;
    std::cout << "The GPU is: " << collectSystemInfo().GPU << std::endl;
    return 0;
}
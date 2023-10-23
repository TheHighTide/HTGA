#pragma once

#include <iostream>
#include <string>

std::string getOsName()
{
    #ifdef _WIN32
    return "Windows32";
    #elif _WIN64
    return "Windows64";
    #elif __APPLE__ || __MACH__
    return "MacOSX";
    #elif __linux__
    return "Linux";
    #elif __FreeBSD__
    return "FreeBSD";
    #elif __unix || __unix__
    return "Unix";
    #else
    return "Other";
    #endif
}

void pause() {
    std::string key;
    getline(cin, key); // Read the line and print it to the key string variable!
}
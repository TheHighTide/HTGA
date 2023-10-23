#pragma once

#include <string>
#include <iostream>
#include "os.h"

void OpenURL(std::string url) {
    std::string osName = getOsName();
    if (osName == "Windows32" || osName == "Windows64") {
        std::string cmdString = std::string("start ").append(url);
        system(cmdString.c_str());
    }
    else if (osName == "Linux") {
        std::string cmdString = std::string("xdg-open ").append(url);
        system(cmdString.c_str());
    }
    else {
        std::cout << "\033[1,31mThis feature doesn't support your OS!\033[0m\n";
    }
}
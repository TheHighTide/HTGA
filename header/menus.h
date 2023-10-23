#pragma once

#include <iostream>
void DisplayMenu(int menuId) { // std::cout << "1. \n";
    if (menuId == 0) {
        std::cout << "--------------------Commands--------------------\n";
        std::cout << "1. help         = Display a list of all commands\n";
        std::cout << "2. osname       = Get the name of your OS\n";
        std::cout << "3. jsplayground = Open the JS playground website\n";
        std::cout << "4. quit/exit    = Exit the app\n";
        std::cout << "------------------------------------------------\n";
    }
    if (menuId == 1) {
        bool currentLetter = false;
        std::cout << "--------------------Credits-------------------\n";
        std::cout << "       Creator: ";
        for (char str : "TheHighTide (HiggyTiggy)") {
            if (currentLetter) {
                std::cout << "\033[31m" << str;
            }
            else {
                std::cout << "\033[36m" << str;
            }
            currentLetter = !currentLetter;
        }
        std::cout << "\n";
        std::cout << "----------------------------------------------\n";
    }
}
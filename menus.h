#pragma once

#include <iostream>
void DisplayMenu(int menuId) {
    if (menuId == 0) {
        std::cout << "-------------------Commands-------------------\n";
        std::cout << "1. help       = Display a list of all commands\n";
        std::cout << "2. quit/exit  = Exit the app\n";
        std::cout << "----------------------------------------------\n";
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
#include <iostream>
#include <string>

#include "header/menus.h"
#include "header/errors.h"
#include "header/os.h"
#include "header/webmanagement.h"

using namespace std;

int main(int argc, char* argv[]) {
    string userInput; // The main variable for user input
    string osName = getOsName();

    cout << "Welcome to HTGA!\nFor a list of commands type 'help'\n";
    while (true) {
        getline(cin, userInput);
        if (userInput == "help") {
            DisplayMenu(0); // Display a menu containing all the commands
        }
        else if (userInput == "credits") {
            DisplayMenu(1); // Displays the menu containing the credits for the app
        }
        else if (userInput == "osname") {
            if (osName == "Windows32" || osName == "Windows64")
                cout << "OS: Windows\n";
            if (osName == "Linux")
                cout << "OS: Linux\n";
            if (osName == "MacOSX")
                cout << "OS: Mac OSX\n";
            if (osName == "Unix")
                cout << "OS: Unix\n";
            if (osName == "FreeBSD")
                cout << "OS: FreeBSD\n";
            if (osName == "Other")
                cout << "OS: Unknown OS\n";
        }
        else if (userInput == "jsplayground") {
            if (osName == "Windows32" || osName == "Windows64" || osName == "Linux") {
                cout << "You are about to open a website!\nPress 'enter/return' to continue...\n";
                pause();
                OpenURL("https://hightide.coolpage.biz/projects/javascript/windows/winjs.html");
            }
            else {
                cout << "\033[1;31mJS Playground doesn't support your OS!\033[0m\n";
            }
        }
        else if (userInput == "quit" || userInput == "exit") {
            cout << "Exiting the application...\n";
            break;
        }
        else {
            DisplayErrorMsg(0); // This is displayed if the command entered is invalid
        }
    }
    return 0;
}

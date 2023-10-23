#include <iostream>
#include <string>
#include "menus.h"
#include "errors.h"

using namespace std;

int main(int argc, char* argv[]) {
    string userInput; // The main variable for user input

    cout << "Welcome to HTGA!\nFor a list of commands type 'help'\n";
    while (true) {
        getline(cin, userInput);
        if (userInput == "help") {
            DisplayMenu(0); // Display a menu containing all the commands
        }
        else if (userInput == "credits") {
            DisplayMenu(1); // Displays the menu containing the credits for the app
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

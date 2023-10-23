#include <iostream>
#include <string>

using namespace std;

void DisplayErrorMsg(int errorId){
    if (errorId == 0){
        cout << "\033[1;31m" << "Please enter a valid command!" << "\033[0m" <<"\n";
    }
}

void DisplayMenu(int menuId){
    if (menuId == 0){
        cout << "-------------------Commands-------------------\n";
        cout << "1. help       = Display a list of all commands\n";
        cout << "2. quit/exit  = Exit the app\n";
        cout << "----------------------------------------------\n";
    }
}

int main(int argc, char *argv[]){
    string userInput; // The main variable for user input

    cout << "Welcome to HTGA!\nFor a list of commands type 'help'\n";
    while (true){
        getline(cin, userInput);
        if (userInput == "help"){
            DisplayMenu(0); // Display a menu containing all the commands
        }
        else if (userInput == "quit" || userInput == "exit"){
            cout << "Exiting the application...\n";
            break;
        }
        else{
            DisplayErrorMsg(0); // This is displayed if the command entered is invalid
        }
    }
    return 0;
}

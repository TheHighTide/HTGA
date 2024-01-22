#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <limits>
#include <string>

#include "apploader.h"       // The most important header needed to load files that the program uses
#include "statman.h"         // The main header for editing statistics
#include "errormsg.h"        // This is required for displaying error messages
#include "artviewer.h"       // This is for viewing art in the console
#include "randomize.h"       // This is for random number or word generation

using namespace std;

int delay(int milliseconds) { // This is used to delay the execution of the code
    clock_t goal = milliseconds + clock(); // The target result time
    while (goal > clock()); // Executes the delay
    return 0;
}

int main() {
    auto start = std::chrono::system_clock::now(); // The variable that tracks the start time of the application
    string userInput;                              // The variable responsible for user input
    string timesLaunched;
    string coolpageMainSite = "https://hightide.coolpage.biz/home.html";

    string applicationVersion = "0.5";
    string cppVersion = "17";

    cout << "Loading...\n";
    system("title HighTideGA");
    LoadFileToData("data/timeslaunched.userdata", false, "0", false);
    LoadFileToData("data/note.notedata", false, "This note hasn't been changed...", false);
    delay(1000 * 5);
    IncrementStatistic("data/timeslaunched.userdata", 1);
    ifstream tlFile("data/timeslaunched.userdata");
    getline(tlFile, timesLaunched); // Gets the amount of times the user launched the program
    tlFile.close();
    if (timesLaunched == "1") {
        cout << "You have launched the HTGA " << timesLaunched << " time now!\n";
    }
    else {
        cout << "You have launched the HTGA " << timesLaunched << " times now!\n";
    }
    cout << "Press \"enter/return\" to continue..." << endl;
    getline(cin, userInput);
    system("cls");
    ifstream file("data/username.userdata");
    if (file) {
        string fileText;
        cout << "Welcome back ";
        while (getline(file, fileText)) { cout << fileText; }
        cout << "!\n";
        file.close();
    }
    else { // This statement is responsible for creating the username for the user
        file.close();
        ofstream file("data/username.userdata");
        cout << "Welcome user! It looks like this is your first time here.\nPlease start by stating the username you would like...\nUsername: ";
        getline(cin, userInput);
        file << userInput;
        file.close();
        cout << "Alright " << userInput << ", welcome to the HTGA!\nPress \"enter\" to continue" << endl;
        getline(cin, userInput);
        system("cls");
    }

    while (true) { // The main loop for the appliation
        cout << "HTGA: ";
        getline(cin, userInput); // The input required to get the inputted command
        if (userInput == "help") { // The command responsible for displaying all the commands
            cout << "Here is a list of available commands:\n"
                 << "help               lists all available commands\n"
                 << "version            Displays the version of the HTGA\n"
                 << "osinfo             Displays some important os information\n"
                 << "note               Can save or view a note the user set\n"
                 << "clearscreen        Clears the console screen. Good if it gets cluttered\n"
                 << "gdmainlvl          View HighTide's progress in the main GD levels\n"
                 << "dice               Roll a 6 sided die\n"
                 << "exit/quit          Closes the application\n";
        }
        else if (userInput == "version") {
            cout << "Application Version: " << applicationVersion << "\n"
                 << "Current Language Version: " << cppVersion << "\n";
        }
        else if (userInput == "stats") {
            cout << "Here is a list of statistics for this program:\n"
                 << "Times Run: " << timesLaunched << "\n";
        }
        else if (userInput == "osinfo") { // Displays some useful system information
            system("systeminfo | findstr /B /C:\"OS Name\" /B /C:\"OS Version\" /B /C:\"System Boot Time\" /B /C:\"Host Name\" /B /C:\"System Manufacturer\" /B /C:\"BIOS Version\" /B /C:\"System Type\" /B /C:\"System Model\" /B /C:\"System Manufacturer\"");
        }
        else if (userInput == "coolpage") {
            cout << "Are you sure you want to open the HighTide Coolpage in a new internet tab? (Y/N)\nAnswer: ";
            while (true) { // Command loop
                getline(cin, userInput); // Get the Y or N answer
                if (userInput == "Y" || userInput == "y") {
                    string cmdToExecute = "start /max " + coolpageMainSite; // Generate the command to execute in batch
                    cout << "Opening new browser tab...\n";
                    system(cmdToExecute.c_str()); // Execute the command in the cmdToExecute variable
                    break; // Break out of the loop
                }
                else if (userInput == "N" || userInput == "n") {
                    cout << "Alright then\n";
                    break; // Break out of the loop
                }
                else {
                    DisplayErrMsg(2);
                    cout << "Answer: ";
                }
            }
        }
        else if (userInput == "note") {
            cout << "Do you want to \"view\" or \"save\" the note?\n";
            while (true) {
                cout << "Option: ";
                getline(cin, userInput);
                if (userInput == "view") {
                    cout << "The current note includes: \n";
                    ifstream noteFile("data/note.notedata"); // Create a file object reference to the note file
                    string textFromNote;
                    while (getline(noteFile, textFromNote)) { cout << textFromNote; } // Display all content of the note file line by line
                    cout << endl;
                    noteFile.close(); // Close the note file to prevent any errors
                    break;
                }
                else if (userInput == "save") {
                    cout << "Please enter the new content that the note will store:\nContent: ";
                    getline(cin, userInput); // Get the user input and save it to the userInput variable
                    ofstream noteFile("data/note.notedata"); // Create a file object reference
                    noteFile.clear(); // Clear the note file to make space for the new text
                    noteFile << userInput; // Write the user input to the note file
                    noteFile.close(); // Close the note file to prevent any errors
                    cout << "Successfully saved a note!\n";
                    break;
                }
                else {
                    DisplayErrMsg(2);
                }
            }
        }
        else if (userInput == "gdmainlvl") {
            cout << "What level do you want to view? (1, 2, 3, 4, etc.)\n";
            while (true) {
                getline(cin, userInput);
                ifstream lvlFile("program/gd/lvl" + userInput + ".gdlvl"); // Create a new file object reference
                if (lvlFile) { // Check if the file successfully opened as a reference
                    string lvlFileText;
                    cout << "Level Data for TheHighTide:\n--------------------------\n";
                    while (getline(lvlFile, lvlFileText)) { cout << lvlFileText << endl; } // Display the contents of the file line by line
                    lvlFile.close(); // Close the file to prevent any more errors
                    break;
                }
                else {
                    lvlFile.close(); // Close the file to prevent any errors
                    DisplayErrMsg(3); // Display the level nonexistant error
                }
            }
        }
        else if (userInput == "clearscreen") {
            system("cls"); // Execute the batch command to clear the screen
            cout << "Successfully cleared the screen...\n"; // Display this message if the command was successfull
        }
        else if (userInput == "dice") {
            cout << "How many sides does the dice you want to doll have? 2, 6, 12, 24\n";
            while (true) {
                getline(cin, userInput);
                if (userInput == "2") {
                    int random = randInt(1, 2); // Generate a random number between 1 and 2
                    cout << "The dice rolled: \x1b[1m" << random << "\x1b[0m\n";
                    break;
                }
                else if (userInput == "6") {
                    int random = randInt(1, 6); // Generate a random number between 1 and 6
                    cout << "The dice rolled: \x1b[1m" << random << "\x1b[0m\n";
                    break;
                }
                else if (userInput == "12") {
                    int random = randInt(1, 12); // Generate a random number between 1 and 12
                    cout << "The dice rolled: \x1b[1m" << random << "\x1b[0m\n";
                    break;
                }
                else if (userInput == "24") {
                    int random = randInt(1, 24); // Generate a random number between 1 and 24
                    cout << "The dice rolled: \x1b[1m" << random << "\x1b[0m\n";
                    break;
                }
                else {
                    DisplayErrMsg(2);
                }
            }
        }
        else if (userInput == "exit" || userInput == "quit" || userInput == "exit/quit") {
            if (userInput == "exit/quit") {
                cout << "For future reference, all you have to do to get here is type \"exit\" OR \"quit\".\nPress \"enter/return\" to continue...";
                getline(cin, userInput);
            }
            cout << "Closing the HTGA..." << endl;
            break; // Closes the current application
        }
        else if (userInput == "rainbow") {
            DisplayArt("rainbow"); // Get the art and display it
        }
        else {
            DisplayErrMsg(1); // Display the invalid command error message
        }
    }
    system("exit");
    return 0; // Keep this line or the program wont exit properly
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <limits>
#include <string>
#include <vector>

#include "apploader.h"       // The most important header needed to load files that the program uses
#include "statman.h"         // The main header for editing statistics
#include "errormsg.h"        // This is required for displaying error messages
#include "artviewer.h"       // This is for viewing art in the console
#include "randomize.h"       // This is for random number or word generation
#include "logger.h"          // This is required if you plan on logging to the log file
#include "adminmode.h"       // This is required for everything in the app!

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

    string applicationVersion = "0.9.0";    // The version string for HTGA
    string cplusplusVersion = "cpp17";      // The version string for c++

    cout << "Loading...\n";
    system("title HighTideGA");
    LoadFileToData("data/timeslaunched.userdata", false, "0", false);
    LoadFileToData("data/note.notedata", false, "This note hasn't been changed...", false);
    delay(1000 * 5);
    Log("Finished loading app", false);
    IncrementStatistic("data/timeslaunched.userdata", 1);
    Log("Changed statistic \"TimesLaunched\"", false); // Log this when the timesLaunched is changed with a mod of 1
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
    ifstream file("data/username.userdata"); // Creates a file reference to the username file
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
        Log("User sent command: " + userInput, false); // Log the command that the user sent
        if (userInput == "help") { // The command responsible for displaying all the commands
            Log("Attempting to display all commands", false);
            cout << "Here is a list of available commands:\n"
                 << "help               lists all available commands\n"
                 << "version            Displays the version of the HTGA\n"
                 << "osinfo             Displays some important os information\n"
                 << "note               Can save or view a note the user set\n"
                 << "clearscreen        Clears the console screen. Good if it gets cluttered\n"
                 << "gdmainlvl          View HighTide's progress in the main GD levels\n"
                 << "dice               Roll a 6 sided die\n"
                 << "exit/quit          Closes the application\n"
                 << "logo               Display HighTide's logo\n"
                 << "lettermess         Generates a custom amount of letters and prints them to the console\n"
                 << "gdprofile          Downloads a user profile from the Geometry Dash servers and displays their stats\n"
                 << "reset              Resets the program back to default\n"
                 << "Admin Commands are hidden...\n";
            Log("Displayed all commands via help command", false);
        }
        else if (userInput == "version") {
            cout << "Current Language Version: cpp17\n"
                 << "Application Version:" << applicationVersion << endl
                 << "Changelog:\nNone...";
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
            while (true) {
                getline(cin, userInput);
                if (userInput == "Y" || userInput == "y") {
                    Log("Trying to open a link.", false);
                    string cmdToExecute = "start /max " + coolpageMainSite;
                    cout << "Opening new browser tab...\n";
                    system(cmdToExecute.c_str());
                    Log("Opened a link in a new browser tab", false);
                    break;
                }
                else if (userInput == "N" || userInput == "n") {
                    cout << "Alright then\n";
                    Log("User denied the webpage from opening", false);
                    break;
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
                    ifstream noteFile("data/note.notedata");
                    string textFromNote;
                    while (getline(noteFile, textFromNote)) { cout << textFromNote; }
                    cout << endl;
                    noteFile.close();
                    break;
                }
                else if (userInput == "save") {
                    cout << "Please enter the new content that the note will store:\nContent: ";
                    getline(cin, userInput);
                    ofstream noteFile("data/note.notedata");
                    noteFile.clear();
                    noteFile << userInput;
                    cout << "Successfully saved a note!\n";
                    break;
                }
                else {
                    DisplayErrMsg(2);
                }
            }
        }
        else if (userInput == "gdmainlvl") {
            cout << "What level type? (tower or classic)\n";
            Log("Starting gdmainlvl command loop", false);
            while (true) {
                cout << "Answer: ";
                getline(cin, userInput);
                if (userInput == "classic") {
                    cout << "What is the ID of the level you want? (1, 2, 3, 4, ect.)\n";
                    cout << "ID: ";
                    getline(cin, userInput);
                    ifstream lvlFile("program/gd/lvl" + userInput + ".gdlvl");
                    if (lvlFile) {
                        Log("Level file was valid getting level info...", false);
                        string lvlFileText;
                        cout << "Level Data for TheHighTide:\n--------------------------\n";
                        Log("Retrieved level info. Now printing it", false);
                        while (getline(lvlFile, lvlFileText)) { cout << lvlFileText << endl; }
                        lvlFile.close();
                        break;
                    }
                    else {
                        Log("An error occured while trying to read the level file", false); // Log when file fails
                        lvlFile.close(); // Close the file to prevent any errors
                        DisplayErrMsg(3); // Display error when the file can't be displayed
                    }
                }
                else if (userInput == "tower") {
                    cout << "What is the ID of the level you want? (1, 2, 3, 4, ect.)\n";
                    cout << "ID: ";
                    getline(cin, userInput);
                    ifstream lvlFile("program/gd/tlvl" + userInput + ".gdlvl");
                    if (lvlFile) {
                        Log("Level file was valid getting level info...", false);
                        string lvlFileText;
                        cout << "Level Data for TheHighTide:\n--------------------------\n";
                        Log("Retrieved level info. Now printing it", false);
                        while (getline(lvlFile, lvlFileText)) { cout << lvlFileText << endl; }
                        lvlFile.close();
                        break;
                    }
                    else {
                        Log("An error occured while trying to read the level file", false); // Log when file fails
                        lvlFile.close(); // Close the file to prevent any errors
                        DisplayErrMsg(3); // Display error when the file can't be displayed
                    }
                }
                else {
                    Log("Invalid use of options", false);
                    DisplayErrMsg(2);
                }
            }
        }
        else if (userInput == "clearscreen" || userInput == "cls" || userInput == "clearscr" || userInput == "clrscreen") {
            system("cls"); // Execute the command that clears the screen
            Log("User cleared the screen", false); // Log that the screen was cleared
            cout << "Successfully cleared the screen...\n";
        }
        else if (userInput == "dice") {
            cout << "How many sides on the die? (2, 6, 12, or 24)\n";
            Log("User called dice menu.", false); // Log this when a user uses the dice command
            while (true) {
                Log("Opened dice menu.", false);
                getline(cin, userInput);
                if (userInput == "2") {
                    cout << "Your die landed on: " << randInt(1, 2) << "\n";
                    Log("User rolled a 2 sided dice", false); // Log to the log file to show it worked
                    break;
                }
                else if (userInput == "6") {
                    cout << "Your die landed on: " << randInt(1, 6) << "\n";
                    Log("User rolled a 6 sided dice", false); // Log to the log file to show it worked
                    break;
                }
                else if (userInput == "12") {
                    cout << "Your die landed on: " << randInt(1, 12) << "\n";
                    Log("User rolled a 12 sided dice", false); // Log to the log file to show it worked
                    break;
                }
                else if (userInput == "24") {
                    cout << "Your die landed on: " << randInt(1, 24) << "\n";
                    Log("User rolled a 24 sided dice", false); // Log to the log file to show it worked
                    break;
                }
                else {
                    Log("Failed to roll user's die", false); // Log to the log file to show it didn't work
                    DisplayErrMsg(2); // Display this if the input isn't valid
                }
            }
        }
        else if (userInput == "logo") {
            Log("User called logo viewing", false);
            DisplayArt("htlogo"); // Display HighTide's logo
        }
        else if (userInput == "lettermess") {
            cout << "Please enter the amount of letters you want to generate.\n";
            int userTargetNumber;
            while (true) {
                cout << "Amount: ";
                cin >> userTargetNumber;
                if (cin.fail()) {
                    Log("User entered an invalid number", false); // Log this if the input is an invalid integer
                    cout << "Please enter a number not a letter or word!\n";
                    getline(cin, userInput);
                }
                else {
                    Log("User entered a valid number", false); // Log this if the input is a valid integer
                    break;
                }
            }
            for (int i = 0; i < userTargetNumber; i++) {
                cout << randChar(); // Generate a random letter then print it
            }
            Log("User generated a total of " + to_string(userTargetNumber) + " letters", false); // Log this when finished generating the letters
            cout << endl;
            getline(cin, userInput);
        }
        else if (userInput == "reset") {
            Log("User called application reset", false);
            cout << "Are you sure you want to reset?\nType \"confirm reset\" to reset the program...\n";
            getline(cin, userInput);
            if (userInput == "confirm reset") {
                cout << "Resetting the program...\n";
                system("del data\\note.notedata data\\username.userdata htga.log"); // Executes the command to reset the program
                cout << "The program has reset! Now exiting program...\n";
                cout << "Press 'enter' to continue...\n";
                getline(cin, userInput); // Wait for the user to press the enter key
                exit(0);
            }
            else {
                Log("User canceled the application reset\n", false); // Log this line when the user doesn't confirm the reset
                cout << "Reset canceled\n"; // Also display this when the reset doesn't continue
            }
        }
        else if (userInput == "gdprofile") {
            system("@echo off");
            system("echo Downloading TheHighTide's user profile...");
            Log("Now downloading geometrydash userdata", false);
            system("curl https://hightide.coolpage.biz/htga.thehightide.gddata -o thehightide.txt -s");
            Log("Finished downloading geometrydash userdata", false);
            system("@echo on");
            string line;
            vector<string> lines;
            ifstream inputStream("thehightide.txt");
            while (getline(inputStream, line)) {
                lines.push_back(line);
            }
            inputStream.close();

            fstream outputStream("thehightide.txt", ios::out | ios::trunc);
            if (outputStream.is_open())
            {
                for (int i = 0; i < lines.size() - 1; i++)
                {
                    outputStream << lines[i] << "\n";
                }
                outputStream.close();
            }

            ifstream gdUserFile("thehightide.txt", ios::in);
            if (gdUserFile) {
                string gdUserFileText;
                while (getline(gdUserFile, gdUserFileText)) { cout << gdUserFileText << endl; }
                gdUserFile.close(); // Close the user file
                system("del thehightide.txt");
            }
            else {
                cout << "That user profile wasn't downloaded properly!";
            }
        }
        else if (userInput == "adminmode") {
            cout << "Checking your admin status...\n";
            if (CheckForAdminRights(false)) { // Checks if admin rights were confirmed
                cout << "Admin rights confirmed! Admin mode is activated!\n";
                Log("Admin mode was activated.", false); // Logs the admin mode activation
                SetAdminMode(true); // Finalizes the admin mode activation
            }
            else {
                cout << "Admin rights unconfirmed! Admin mode denied!\n";
                Log("Admin rights denied.", false); // Log that the admin rights were denied
            }
        }
        else if (userInput == "printlogs" && IsAdminMode()) {
            cout << "Warning, this can fill up the console really quickly. Are you sure you want this? (Y or n):\n";
            cout << "Answer: ";
            getline(cin, userInput);
            if (userInput == "y" || userInput == "Y") {
                Log("Admin called printlogs.", false); // Log the display thats about to happen
                ifstream logFile("htga.log", ios::in); // Open the log file as an input file
                string logFileText;
                while (getline(logFile, logFileText)) { cout << logFileText << endl; } // Display the entire log file to console
                logFile.close(); // Close the log file to prevent any errors
            }
            else if (userInput == "n" || userInput == "N") {
                Log("Admin denied printlogs.", false); // Log to the log file that the user became an admin
                cout << "Alright! The logs will not be listed\n";
            }
            else {
                cout << "That wasn't a valid response so it will be treated like an \"N\"\n";
            }
        }
        else if (userInput == "clearlogfile" && IsAdminMode()) {
            ofstream logFile("htga.log", ios::out); // Open the log file as an output file
            logFile.clear(); // Clear all the contents of the log file
            logFile.close(); // Close the log file
        }
        else if (userInput == "exit" || userInput == "quit" || userInput == "exit/quit") {
            if (userInput == "exit/quit") {
                cout << "For future reference, all you have to do to get here is type \"exit\" OR \"quit\".\nPress \"enter/return\" to continue...";
                getline(cin, userInput);
            }
            cout << "Closing the HTGA..." << endl;
            Log("User called application exit", false);
            break; // Closes the current application
        }
        else if (userInput == "rainbow") {
            DisplayArt("rainbow");
        }
        else {
            Log("Sent command was invalid", false); // Log when command is invalid
            DisplayErrMsg(1); // Display the invalid command error message
        }
    }
    system("exit");
    Log("Shutting down application.", false);
    return 0; // Keep this line or the program wont exit properly
}
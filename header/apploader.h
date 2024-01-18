#include <iostream>
#include <fstream>

using namespace std;

int LoadFileToData(string filePath, bool logResult, string creationContents, bool isCreationContentsInt){
    ifstream file(filePath);
    if(file){ // Doesn't do anything because the file already exists
        file.close(); // Closes the file so that there are no issues
        if(logResult){
            cout << "That file already exists!\n";
        }
    }
    else{
        file.close(); // Closes the file so that there are no issues
        if(logResult){
            cout << "That file doesn't exist so I am creating it...\n";
        }
        ofstream file(filePath);
        file << creationContents; // Inserts the contents specified to the target file
        file.close(); // Closes the file when the insertion is completed
    }
    return 0;
}
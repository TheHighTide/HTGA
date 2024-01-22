#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int IncrementStatistic(string filePath, int increment) { // This is the function that edits statistics files
    ifstream targetFile(filePath, ios::in);
    string currentData;
    targetFile >> currentData;
    int curNum = stoi(currentData); // Gets the current string in the file and converts it to a int value
    int newNum = curNum + increment; // Increments the converted int value by the specified increment
    targetFile.close();
    ofstream file(filePath, ios::out);
    file.clear();
    file << to_string(newNum); // Writes the new number to the file in the old ones place
    file.close();
    return 0;
}
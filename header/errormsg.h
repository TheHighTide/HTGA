#include <iostream>

using namespace std;

int DisplayErrMsg(int errId){ // Displays an error message according to the error ID given
    if(errId == 1){
        cout << "\x1b[31mThat command is invalid!\x1b[39m\n";
    }
    if(errId == 2){
        cout << "\x1b[31mThat inputted value is invalid!\x1b[39m\n";
    }
    if(errId == 3){
        cout << "\x1b[31mThat file doesn't exist! Please re-enter a valid value!\x1b[39m\n";
    }
    return 0;
}
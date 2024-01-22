#include <iostream>

using namespace std;

int DisplayArt(string artName) {
    if (artName == "rainbow") {
        cout << "\x1b[31m      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
            << "\x1b[33m     XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
            << "\x1b[32m    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
            << "\x1b[34m  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
            << "\x1b[36m XXXXXXX                                        XXXXXXX\n"
            << "\x1b[35m XXXXXXX                                        XXXXXXX\n"
            << "\x1b[31mXXXXXXX                                          XXXXXXX\n"
            << "\x1b[33mXXXXXX                                            XXXXXX\x1b[39m\n";
    }
    else {
        cout << "That art doesn't exist...\n";
    }
    return 0;
}
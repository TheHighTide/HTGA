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
    else if (artName == "htlogo") {
        cout << "\x1b[34mXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
             << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
             << "XXXXXXXXXXXXX\x1b[36m||\x1b[34mXXXX\x1b[36m||========\x1b[34mXXXXXXXXXXXX\n"
             << "XXXXXXXXXXXXX\x1b[36m||\x1b[34mXXXX\x1b[36m||\x1b[34mXXX\x1b[36m||\x1b[34mXXXXXXXXXXXXXXX\n"
             << "XXXXXXXXXXXXX\x1b[36m||\x1b[34mXXXX\x1b[36m||\x1b[34mXXX\x1b[36m||\x1b[34mXXXXXXXXXXXXXXX\n"
             << "XXXXXXXXXXXXX\x1b[36m||====||\x1b[34mXXX\x1b[36m||\x1b[34mXXXXXXXXXXXXXXX\n"
             << "XXXXXXXXXXXXX\x1b[36m||\x1b[34mXXXX\x1b[36m||\x1b[34mXXX\x1b[36m||\x1b[34mXXXXXXXXXXXXXXX\n"
             << "XXXXXXXXXXXXX\x1b[36m||\x1b[34mXXXX\x1b[36m||\x1b[34mXXX\x1b[36m||\x1b[34mXXXXXXXXXXXXXXX\n"
             << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
             << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\x1b[39m\n";
    }
    else {
        cout << "That art doesn't exist...\n";
    }
    return 0;
}
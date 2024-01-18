#include <iostream>

int randInt(int min, int max){
    int random = min + (rand() % max);
    return random;
}
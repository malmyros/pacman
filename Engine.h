#ifndef PACMAN_ENGINE_H
#define PACMAN_ENGINE_H

#include <string>
#include <iostream>
#include <fstream>
#include "ncurses.h"

using namespace std;

const int MAX_GEMS = 10;

class Engine {

public:
    Engine();

    std::string levelName;

    void printLevels();

    void getUserLevelInput();

    void loadLevel();

    void run();
};


#endif //PACMAN_ENGINE_H

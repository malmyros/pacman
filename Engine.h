#ifndef PACMAN_ENGINE_H
#define PACMAN_ENGINE_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Engine {

public:
    Engine();

    static void generateLevel();

    static string generateRows();

    static string addItemToMap(string &map, char item);

    static void saveMap(const string& level);

    static string generateMap();
};


#endif //PACMAN_ENGINE_H

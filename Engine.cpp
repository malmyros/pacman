#include "Engine.h"

string LEVEL_PATH = "/Users/michailalmyros/CLionProjects/pacman/levels/level.txt";
string WALL = "************************\n";

const int TOTAL_WALL_ROWS = 2;
const int MAX_ROWS = 20;

const int MAX_GEMS = 10;
const char GEM = 'G';
const char SCROLL = 'S';
const char POTTER = 'P';
const char GNOME = 'M';
const char TRALL = 'T';

Engine::Engine() {
    generateLevel();
}

void Engine::generateLevel() {
    string map = generateMap();
    map = addItemToMap(map, POTTER);
    map = addItemToMap(map, GNOME);
    map = addItemToMap(map, TRALL);
    cout << map;
    saveMap(map);
}

string Engine::generateMap() {
    string map;
    map.append(WALL);
    map.append(generateRows());
    map.append(WALL);
    return map;
}

string Engine::generateRows() {
    string rows;
    for (int i = 0; i < MAX_ROWS; i++) {
        rows.append("*                      *\n");
    }
    return rows;
}

string Engine::addItemToMap(string &map, char item) {
    istringstream ss(map);
    string token;

    string updatedMap;
    int totalRows = MAX_ROWS + TOTAL_WALL_ROWS;
    int currentRow = 0;
    int randomRow = rand() % 20 + 1;
    bool isItemAdded = false;

    while (std::getline(ss, token, '\n')) {

        bool isPopulateAllowed = (
                currentRow != 0 &&
                currentRow != totalRows &&
                currentRow == randomRow);

        if (isPopulateAllowed && !isItemAdded) {
            token[10] = item;
            isItemAdded = true;
        }

        updatedMap.append(token + "\n");
        currentRow++;
    }

    return updatedMap;
}

void Engine::saveMap(const string &level) {
    ofstream fileStream;
    fileStream.open(LEVEL_PATH);
    fileStream << level;
    fileStream.close();
}

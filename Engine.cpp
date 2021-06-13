#include "Engine.h"

Engine::Engine() {
    getUserLevelInput();
    loadLevel();
    run();
}

void Engine::printLevels() {
    printf("Παρακαλώ επιλέξετε ένα από τα παρακάτω επίπεδα.\n");
    printf(" - level1\n");
    printf(" - level2\n");
}

void Engine::getUserLevelInput() {
    int level = 0;
    while (level < 1 || level > 2) {
        printLevels();
        cin >> level;
        levelName = "level" + std::to_string(level);
    }
    printf("Επιλέξατε το επίπεδο: %s\n", levelName.c_str());
}

void Engine::loadLevel() {
    string map;
    string mapFileName = "/Users/michailalmyros/CLionProjects/pacman/levels/" + levelName + ".txt";
    ifstream mapFile(mapFileName);

    while (getline (mapFile, map)) {
        cout << map + "\n";
    }

    mapFile.close();
}

void Engine::run() {
    int keyboardInput;
    do {
        keyboardInput = getch ();
    } while(keyboardInput != 68);
    endwin();
}
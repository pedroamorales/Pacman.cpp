#include "GhostSpawner.h"
#include "Ghost.h"

GhostSpawner::GhostSpawner(int x, int y, int width, int height, EntityManager* em, ofImage sprite) : Entity(x, y, width, height) {
    this->em = em;
    this->sprite = sprite;
    spawnGhost("red");
    spawnGhost("pink");
    spawnGhost("cyan");
    spawnGhost("orange");
}

void GhostSpawner::tick() {
    std::vector<string> colors;
    colors.push_back("red");
    colors.push_back("pink");
    colors.push_back("cyan");
    colors.push_back("orange");

    if (em->ghosts.size()<4) {
        if (spawnCounter == 0) {
            spawnGhost(colors[ofRandom(4)]);
            spawnCounter = 30*5;
        }
        else {
            spawnCounter--;
        }
    }
}

void GhostSpawner::spawnGhost(string color) {
    Ghost* g = new Ghost(x,y,width-2,height-2,sprite,em, color);
    em->ghosts.push_back(g);
}

void GhostSpawner::keyPressed(int key) {
    int randomizer = 0;
    if (key == 'g') {
    randomizer = rand() % 4;
    if (em->ghosts.size()<8) { 
    switch (randomizer) 
    {
    case 0:
        spawnGhost("red");
        break;
    case 1:
        spawnGhost("pink");
        break;
    case 2:
        spawnGhost("cyan");
        break;
    case 3:
        spawnGhost("orange");
        break;
    }
    }
    }
}
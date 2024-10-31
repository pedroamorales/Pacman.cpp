#include "RandomPowerUp.h"

RandomPowerup::RandomPowerup(Player* p) {
    this->p = p;
}

void RandomPowerup::activate() {
    int multiplier = rand() % 10;
    p->setScore(p->getScore() + 50*multiplier);
}

string RandomPowerup::toString() {
    return "Free Score";
}
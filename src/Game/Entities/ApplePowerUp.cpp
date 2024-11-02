#include "ApplePowerup.h"
#include "Player.h"

ApplePowerup::ApplePowerup(Player* p) {
    this->p = p;
}

void ApplePowerup::activate() {
    p->speed = 8;
    p->increasedSpeedTimer = 30*3;
}

string ApplePowerup::toString() {
    return "Apple";
}
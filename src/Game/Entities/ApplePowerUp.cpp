#include "ApplePowerup.h"
#include "Player.h"

ApplePowerup::ApplePowerup(Player* p) {
    this->p = p;
}

void ApplePowerup::activate() {
    p->speed = 8;
}

string ApplePowerup::toString() {
    return "Apple";
}
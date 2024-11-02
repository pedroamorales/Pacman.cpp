#include "ApplePowerup.h"
#include "Entity.h"

ApplePowerup::ApplePowerup(Player* p) {
    this->p = p;
}

void ApplePowerup::activate() {
    Entity* toTeleport = em->entities[ofRandom(em->entities.size())];
    p->setPosX(toTeleport->getPosX());
    p->setPosY(toTeleport->getPosY());
}

string ApplePowerup::toString() {
    return "Apple";
}
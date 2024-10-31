#pragma once
#include "Player.h"
#include "PowerUp.h"

class UltimatePowerup: public Powerup {

    public:
        UltimatePowerup(Player* p);
        void activate();
        Player* p;
        string toString();
    private:
        Player *player;
};
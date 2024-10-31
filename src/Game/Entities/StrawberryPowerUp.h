#pragma once
#include "PowerUp.h"
#include "Player.h"

class StrawberryPowerup: public Powerup {
    public:
        StrawberryPowerup(Player* p);
        void activate();
        Player* p;
        string toString();

    private:
        int rank = 2;
};
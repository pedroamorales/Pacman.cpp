#pragma once
#include "PowerUp.h"
#include "Player.h"

class ApplePowerup: public Powerup {
    public:
        void activate();
        ApplePowerup(Player* p);
        Player* p;
        string toString();
    
    private:
        int rank = 3;
};
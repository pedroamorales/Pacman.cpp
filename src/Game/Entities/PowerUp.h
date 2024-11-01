#pragma once
#include "Entity.h"
#include "EntityManager.h"

// Abstract Powerup class

class Powerup {
    public:
        int rank;
        EntityManager* em;
        Entity* p = 0;
        virtual void activate() = 0; // pure virtual function
        virtual string toString() = 0;
};
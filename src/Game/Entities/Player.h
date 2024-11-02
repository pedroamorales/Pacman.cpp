#pragma once

#include "Animation.h"
#include "EntityManager.h"
#include "PowerUp.h"

enum MOVING {
	MUP,
	MDOWN,
	MLEFT,
	MRIGHT,
};

class Player: public Entity {

    private:
        int spawnX, spawnY;
        unsigned int health=3;
        int score=0;
        bool canMoveUp, canMoveDown, canMoveRight, canMoveLeft;

        bool walking = false;
        bool containsPowerup = false;
        bool ultimateKeySpawned = false;
        MOVING moving;
        FACING facing = DOWN;
        ofImage up, down, left, right;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        EntityManager* em;
        Powerup* powerup;

    public:
        Player(int, int, int , int, EntityManager*);
        ~Player();
        int getHealth();
        int getScore();
        int speed = 4;
        FACING getFacing();
        void setHealth(int);
        void setScore(int);
        void setFacing(FACING facing);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void damage(Entity* damageSource);
        void mousePressed(int, int, int);
        void reset();
        void checkCollisions();
        void die();
        int CurrentDotCount();
        int DotCount;
        int DotsEaten;
        
        vector<Powerup*> powerupList;
        ofImage spritesheet;
        int unkillableTimer = 10*30;
};
#pragma once

#include "ofMain.h" 
#include "Map.h"
#include "Dot.h"
#include "BigDot.h"
#include "Ghost.h"


class MapBuilder {
    public:
        MapBuilder();
	    Map* createMap(ofImage);
        Entity* getRandomDot(Map* map);
        
	private:
        vector<ofImage> bound;
        vector<Entity> dots;
        int pixelMultiplier;
        ofColor boundBoundBlock;
        ofColor pacman;
        ofColor ghostC;
	    ofColor dotC;
	    ofColor bigDotC;
        ofImage pacmanSpriteSheet;
        ofImage tempBound;
        ofImage getSprite(ofImage, int, int);
        EntityManager* entityManager;
};
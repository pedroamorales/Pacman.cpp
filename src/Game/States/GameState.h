#pragma once

#include "State.h"
#include "Player.h"
#include "MapBuilder.h"

class GameState: public State {
    
	public: 
        GameState();
		~GameState();
		void reset();
		void tick();
		void render();
		void ContinueState();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
		int getFinalScore();
		int GetDotCountState();
	
	private:
		ofSoundPlayer music;
		ofImage mapImage;
		Map* map;
		int finalScore=0;
};
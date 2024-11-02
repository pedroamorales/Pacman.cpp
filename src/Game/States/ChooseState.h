#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h" 

class ChooseState : public State {
private:
	ofImage img1;
	ofImage img2;
	Button *PacmanButton;
    Button *MrsPacmanButton;
	Animation* anim;
	int IDc;

public:
	ChooseState();
	~ChooseState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	void setScore(int);
	int getIDc();
	void ContinueState();
};
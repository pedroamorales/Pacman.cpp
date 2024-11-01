#include "ChooseState.h"
#include "MenuState.h"
#include "GameState.h"

ChooseState::ChooseState() {
	
	PacmanButton = new Button(ofGetWidth()/2-200, ofGetHeight()/2, 64, 50, "Pacman");
    MrsPacmanButton = new Button(ofGetWidth()/2+220, ofGetHeight()/2, 64, 50, "Mrs. Pacman");
	
	img1.load("images/pacman.png");
	vector<ofImage> rightAnimframes;
    ofImage temp;
	for (int i=0; i<3; i++) {
        temp.cropFrom(img1, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }

	anim = new Animation(10,rightAnimframes);
}

void ChooseState::tick() {
	PacmanButton->tick();
	MrsPacmanButton->tick();
	anim->tick();
	if (PacmanButton->wasPressed()) {
		setID(0);
		setNextState("Menu");
		setFinished(true);
	}
	if(MrsPacmanButton->wasPressed()) {
		setID(1);
		setNextState("Menu");
		setFinished(true);
	}
}

void ChooseState::render() {
	ofDrawBitmapString("Choose your character:", ofGetWidth()/2, ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	anim->getCurrentFrame().draw(ofGetWidth()/2, ofGetHeight()/2-100, 100, 100);
	PacmanButton->render();
	MrsPacmanButton->render();

}

void ChooseState::mousePressed(int x, int y, int button) {
	PacmanButton->mousePressed(x, y);
	MrsPacmanButton->mousePressed(x, y);
}

void ChooseState::reset() {
	setFinished(false);
	setNextState("");
	PacmanButton->reset();
	MrsPacmanButton->reset();
}

void ChooseState::setScore(int sc) {

}

ChooseState::~ChooseState() {
	delete PacmanButton;
    delete MrsPacmanButton;
	delete anim;
	setNextState("");
}

void ChooseState::keyPressed(int key) {
   
}

void ChooseState::ContinueState() {

}

int ChooseState::getIDc() {
	return IDc;
}





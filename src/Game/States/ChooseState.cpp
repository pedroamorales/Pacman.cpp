#include "ChooseState.h"
#include "MenuState.h"
#include "GameState.h"

ChooseState::ChooseState() {
	
	yellowButton = new Button(ofGetWidth()/2-200, ofGetHeight()/2, 64, 50, "Yellow");
    blueButton = new Button(ofGetWidth()/2-100, ofGetHeight()/2, 64, 50, "Blue");
	greenButton = new Button(ofGetWidth()/2+200, ofGetHeight()/2, 64, 50, "Green");
	redButton = new Button(ofGetWidth()/2+100, ofGetHeight()/2, 64, 50, "Red");
	
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
	yellowButton->tick();
	blueButton->tick();
	greenButton->tick();
	redButton->tick();
	anim->tick();
	if (yellowButton->wasPressed()) {
		setID(0);
		setNextState("Menu");
		setFinished(true);
	}
	if(blueButton->wasPressed()) {
		setID(1);
		setNextState("Menu");
		setFinished(true);
	}
	if (redButton->wasPressed()) {
		setID(2);
		setNextState("Menu");
		setFinished(true);
	}
	if (greenButton->wasPressed()) {
		setID(3);
		setNextState("Menu");
		setFinished(true);
	}
}

void ChooseState::render() {
	ofDrawBitmapString("Choose your character.", ofGetWidth()/2, ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	anim->getCurrentFrame().draw(ofGetWidth()/2, ofGetHeight()/2-100, 100, 100);
	yellowButton->render();
	blueButton->render();
	greenButton->render();
	redButton->render();
}

void ChooseState::mousePressed(int x, int y, int button) {
	yellowButton->mousePressed(x, y);
	blueButton->mousePressed(x, y);
	greenButton->mousePressed(x, y);
	redButton->mousePressed(x, y);
}

void ChooseState::reset() {
	setFinished(false);
	setNextState("");
	yellowButton->reset();
	blueButton->reset();
	greenButton->reset();
	redButton->reset();
}

void ChooseState::setScore(int sc) {

}

ChooseState::~ChooseState() {
	delete yellowButton;
    delete blueButton;
	delete greenButton;
	delete redButton;
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





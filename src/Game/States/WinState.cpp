#include "WinState.h"
#include "MenuState.h"
#include "GameState.h"

WinState::WinState() {
	resumeButton = new Button(ofGetWidth()/2+132, ofGetHeight()/2, 64, 50, "Play Again");
    quitButton = new Button(ofGetWidth()/2-132, ofGetHeight()/2, 64, 50, "Quit");
	img1.load("images/pacman.png");
	vector<ofImage> rightAnimframes;
    ofImage temp;
	for(int i=0; i<3; i++){
        temp.cropFrom(img1, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
	anim = new Animation(10,rightAnimframes);
}

void WinState::tick() {
	resumeButton->tick();
	quitButton->tick();
	anim->tick();
	if(resumeButton->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
	if(quitButton->wasPressed()) {
		setNextState("Menu");
		setFinished(true);
	}
}

void WinState::render() {
	ofDrawBitmapString("WINNER!!", ofGetWidth()/2, ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	anim->getCurrentFrame().draw(ofGetWidth()/2, ofGetHeight()/2-100, 100, 100);
	resumeButton->render();
	quitButton->render();
}

void WinState::mousePressed(int x, int y, int button) {
	resumeButton->mousePressed(x, y);
	quitButton->mousePressed(x, y);
}

void WinState::reset() {
	setFinished(false);
	setNextState("");
	resumeButton->reset();
	quitButton->reset();
}

void WinState::ContinueState() {

}

void WinState::setScore(int sc) {
    score = sc;
}

WinState::~WinState() {
	delete resumeButton;
    delete quitButton;
	delete anim;
	setNextState("");
}

void WinState::keyPressed(int key) {
   
}

#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofSetWindowTitle("C++ Game Box");
	//States
	chooseState = new ChooseState();
	menuState = new MenuState();
	gameState = new GameState();
	gameOverState = new GameOverState();
	pauseState = new PauseState();
	winState = new WinState();
	
	// Initial State
	currentState = chooseState;
}

//--------------------------------------------------------------
void ofApp::update() {
	currentState->setID(chooseState->getIDc());
	if (currentState != nullptr) {
		
		currentState->tick();
		if (currentState->hasFinished()) {
			if (currentState->getNextState() == "Menu") {
				if (Pcheck) {
					Pcheck = false;
				}
				currentState = menuState;
				currentState->reset();
			}
			else if (currentState->getNextState() == "Game") {
				currentState = gameState;
				Wcheck = false;
				if (Pcheck) {
					Pcheck = false;
					currentState->ContinueState();
				}
				else {
				currentState->reset();
				}
			}
			else if (currentState->getNextState() == "Pause") {
				currentState = pauseState;
				currentState->reset();
			}
			else if (currentState->getNextState() == "Win" && !Wcheck) {
				currentState = winState;
				currentState->reset();
				Wcheck = true;
			}
			else if (currentState->getNextState() == "over") {
				gameOverState->setScore(gameState->getFinalScore());
				currentState = gameOverState;
				gameState->reset();
				currentState->reset();
			}
		}
	}
	if (gameState->GetDotCountState() == 0 && !Wcheck) {
		currentState->setNextState("Win");
		currentState->setFinished(true);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (currentState != nullptr)
		currentState->render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (currentState != nullptr) {
		currentState->keyPressed(key);
	}

	//Turn Volume Down (Mute)	
	if ( key == '-' ) {
		ofSoundSetVolume(0);
	}
	
	//Turn Volume Back Up
	if ( key == '=' ) {
		ofSoundSetVolume(1);
	}

	if (key == 'p') {
		currentState->setNextState("Pause");
		currentState->setFinished(true);
		Pcheck = true;
	}

	if (key == 'y') {
		currentState->setNextState("Win");
		currentState->setFinished(true);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if (currentState != nullptr)
			currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	if (currentState != nullptr)
			currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	if (currentState != nullptr)
			currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}

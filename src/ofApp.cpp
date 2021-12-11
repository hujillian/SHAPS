#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//https://openframeworks.cc/ofBook/chapters/game_design.html

	ofSetVerticalSync(true);
	ofSetWindowShape(1280, 900);

	arduino.connect("COM3", 57600);

	//start position for player
	xPos = 640;
	yPos = 700;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//*************Background*************//

	ofColor colorOne(236, 246, 254);		//lightblue
	ofColor colorTwo(254, 254, 254);		//white

	ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);

	//*************Start Screen Layout Design*************//

	/*ofSetColor(174, 217, 251);
	ofDrawRectRounded(550, 600, 200, 80, 5);

	ofSetColor(174, 217, 251);
	ofDrawRectRounded(350, 200, 600, 280, 5);*/

	//*************Game Screen Layout Design*************//

	ofSetColor(174, 237, 251);			//red
	ofDrawRectangle(326, 0, 100, 900);

	ofSetColor(251, 174, 192);			//blue
	ofDrawRectangle(526, 0, 100, 900);

	ofSetColor(186, 251, 174);			//green
	ofDrawRectangle(726, 0, 100, 900);

	spawn_c.Draw();

	ofSetColor(174, 217, 251);			//player
	ofDrawRectangle(xPos, yPos, 40, 40);		//xpos and ypos change from keyPressed, thus they are currently used to change position
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//*************To Move (left, right, up, down)*************//
	if (key == OF_KEY_LEFT) {
		xPos = xPos - 10;
	}
	if (key == OF_KEY_RIGHT) {
		xPos = xPos + 10;
	}	
	if (key == OF_KEY_UP) {
		yPos = yPos - 10;
	}	
	if (key == OF_KEY_DOWN) {
		yPos = yPos + 10;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

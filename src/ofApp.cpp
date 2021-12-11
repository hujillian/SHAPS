#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetWindowShape(1280, 900);

	arduino.connect("COM3", 57600);
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
	ofSetColor(174, 217, 251);
	ofDrawRectRounded(550, 600, 200, 80, 5);

	ofSetColor(174, 217, 251);
	ofDrawRectRounded(350, 200, 600, 280, 5);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

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

	game_state = "start";
	score = 0;

	// fonts
	titleFont.load("raleway-bold.ttf", 120);
	subtitleFont.load("raleway-bold.ttf", 42);

	// start page variables
	shapsRectX = 350;
	shapsRectY = 200;
	shapsRectWidth = 600;
	shapsRectHeight = 280;
	startRectX = 550;
	startRectY = 600;
	startRectWidth = 200;
	startRectHeight = 80;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (game_state == "start") {

	}
	else if (game_state == "game") {
		// update circles
		for (int i = 0; i < circles.size(); i++) {
			circles[i].update();
			// if shape moves offscreen, delete it
			if (circles[i].yPos > ofGetScreenHeight()) {
				//circles[i].erase(circles.begin() + i);
				//delete circles[i];
			}
		}

		// update rectangles
		for (int i = 0; i < rectangles.size(); i++) {
			rectangles[i].update();
		}

		// update triangles
		for (int i = 0; i < triangles.size(); i++) {
			triangles[i].update();
		}
	}
	else if (game_state == "end") {

	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//*************Background*************//

	ofColor colorOne(236, 246, 254);		//lightblue
	ofColor colorTwo(254, 254, 254);		//white

	ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);

	if (game_state == "start") {
		//*************Start Screen Layout Design*************//

		ofSetColor(174, 217, 251);
		ofDrawRectRounded(shapsRectX, shapsRectY, shapsRectWidth, shapsRectHeight, 5);
		ofDrawRectRounded(startRectX, startRectY, startRectWidth, startRectHeight, 5);

		ofSetColor(240, 240, 240);
		titleFont.drawString("SHAPS!", shapsRectX + 15, shapsRectY + 200);
		subtitleFont.drawString("START", startRectX + 10, startRectY + 60);

		
	}
	else if (game_state == "game") {
		//*************Game Screen Layout Design*************//

		ofSetColor(251, 180, 200);			//red
		ofDrawRectangle(326, 0, 100, 900);

		ofSetColor(174, 237, 251);			//blue
		ofDrawRectangle(526, 0, 100, 900);

		ofSetColor(186, 251, 174);			//green
		ofDrawRectangle(726, 0, 100, 900);

		// draw shapes
		for (int i = 0; i < circles.size(); i++) {
			circles[i].draw();
		}
		for (int i = 0; i < rectangles.size(); i++) {
			rectangles[i].draw();
		}
		for (int i = 0; i < triangles.size(); i++) {
			triangles[i].draw();
		}


		//spawn_c.Draw();
		//spawn_c.Move();
		//spawn_r.Draw();



		//ofSetColor(174, 217, 251);			//player
		//ofDrawRectangle(xPos, yPos, 40, 40);		//xpos and ypos change from keyPressed, thus they are currently used to change position
	}
	else if (game_state == "end") {

	}



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == OF_KEY_SHIFT) {
		circle newCircle;
		circles.push_back(newCircle);
		rectangle newRectangle;
		rectangles.push_back(newRectangle);
		triangle newTriangle;
		triangles.push_back(newTriangle);
	}


	//*************To Move (left, right, up, down)*************//
	/*
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
	}*/
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
	if (game_state == "start") {
		// If player presses the SHAPS! button
		if ((x > shapsRectX) && (x < shapsRectX + shapsRectWidth) &&
			(y > shapsRectY) && (y < shapsRectY + shapsRectHeight)) {
				// instructions?
			}
		// If player presses the START button
		else if ((x > startRectX) && (x < startRectX + startRectWidth) &&
				(y > startRectY) && (y < startRectY + startRectHeight)) {
			game_state = "game";
		}
	}
	else if (game_state == "game") {

	}
	else if (game_state == "end") {

	}
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

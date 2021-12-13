#include "ofApp.h"

//-------------------------------------------------------------- setup
void ofApp::setup(){

	//https://openframeworks.cc/ofBook/chapters/game_design.html

	//setting window
	ofSetVerticalSync(true);
	ofSetWindowShape(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);

	//arduino setup
	arduino.connect("COM3", 57600);

	//game states setup (used to create different pages)
	gameState = Constants::START;
	score = 0;

	//song setup
	song.load("bensound-littleidea.mp3");
	
	// arrows
	arrowRight.load("arrow-right.png");
	arrowLeft.load("arrow-left.png");
	arrowRightPos = ofVec2f(80, 275);
	arrowLeftPos = ofVec2f(60, Constants::PLAYER_Y);
	arrowA = 255;
	arrowAInc = false;
	drawRight = false;
	drawLeft = false;

	// fonts
	titleFont.load("raleway-bold.ttf", 120);
	subtitleFont.load("raleway-bold.ttf", 42);
	textFont.load("raleway-bold.ttf", 20);

	// colours
	lightBlue = ofColor(236, 246, 254);
	offWhite = ofColor(240, 240, 240);
	mediumBlue = ofColor(150, 200, 242);
	
}

//-------------------------------------------------------------- update
void ofApp::update(){

	//starting page -- arrow flashes update
	if (gameState == Constants::START) {
		// flashing arrow
		if (arrowAInc) {
			arrowA += 3;
			if (arrowA >= 255) {
				arrowAInc = false;
			}
		}
		else {
			arrowA -= 3;
			if (arrowA <= 10) {
				arrowAInc = true;
			}
		}

	}
	//game page -- if shapes are collected, they grow bigger (then shrink again)
	else if (gameState == Constants::GAME) {

		// UPDATE CIRCLES
		for (int i = 0; i < circles.size(); i++) { // circles
			// if shape moves offscreen, delete it
			if (circles[i].yPos > Constants::SCREEN_HEIGHT) {
				//circles[i].erase(circles.begin() + i);
				//delete circles[i];
			}

			// circle grows if pressed at the right time, then shrinks
			if (circles[i].shapePressed >= 1 && !(circles[i].shrink)) {
				circles[i].radius += 1;
				if (circles[i].radius > 55) {
					circles[i].shrink = true;
				}
			}
			else if (circles[i].radius > 35 && circles[i].shrink) {
				circles[i].radius -= 1;
			}

			circles[i].update();
		}

		// UPDATE TRIANGLES
		for (int i = 0; i < triangles.size(); i++) { // triangles
			// triangle grows and shrinks
			if (triangles[i].shapePressed >= 1 && !(triangles[i].shrink)) {
				triangles[i].width += 1.5;
				triangles[i].xPos -= 0.8;
				if (triangles[i].width > 100) {
					triangles[i].shrink = true;
				}
			}
			else if (triangles[i].width > 70 && triangles[i].shrink) {
				triangles[i].width -= 1.5;
				triangles[i].xPos += 0.8;
			}

			triangles[i].update();
		}

		// UPDATE RECTANGLES
		for (int i = 0; i < rectangles.size(); i++) {  // rectangles
			// rectangle grows and shrinks
			if (rectangles[i].shapePressed >= 1 && !(rectangles[i].shrink)) {
				rectangles[i].width += 1;
				rectangles[i].height += 1;
				rectangles[i].xPos -= 0.5;
				if (rectangles[i].width > 80) {
					rectangles[i].shrink = true;
				}
			}
			else if (rectangles[i].width > 60 && rectangles[i].shrink) {
				rectangles[i].width -= 1;
				rectangles[i].height -= 1;
				rectangles[i].xPos += 0.5;
			}

			rectangles[i].update();
		}
		

		// create shapes based on times of the song
		if ((song.getPositionMS() > 9920 - Constants::SHAPE_MOVE_TIME) &&
			(song.getPositionMS() < 23744 - Constants::SHAPE_MOVE_TIME)) {
			spawnTriangles();
			if ((song.getPositionMS() > 22744)) {
				drawLeft = true;
			}
		}
		else if ((song.getPositionMS() > 23744 - Constants::SHAPE_MOVE_TIME) && 
			(song.getPositionMS() < 39509 - Constants::SHAPE_MOVE_TIME)) {
			spawnCircles();
		}
		else if ((song.getPositionMS() > 39509 - Constants::SHAPE_MOVE_TIME) &&
			(song.getPositionMS() < 55168 - Constants::SHAPE_MOVE_TIME)) {
			spawnTriangles();
			spawnCircles();
			if ((song.getPositionMS() > 54000)) {
				drawLeft = false;
				drawRight = true;
			}
		}
		else if ((song.getPositionMS() > 55168 - Constants::SHAPE_MOVE_TIME) &&
			(song.getPositionMS() < 78805 - Constants::SHAPE_MOVE_TIME)) {
			spawnRects();
		}
		else if ((song.getPositionMS() > 78805 - Constants::SHAPE_MOVE_TIME) &&
			(song.getPositionMS() < 110293 - Constants::SHAPE_MOVE_TIME)) {
			spawnTriangles();
			spawnCircles();
		}
		else if ((song.getPositionMS() > 110293 - Constants::SHAPE_MOVE_TIME) &&
			(song.getPositionMS() < 134208 - Constants::SHAPE_MOVE_TIME)) {
			spawnRects();
			spawnTriangles();
		}
		else if ((song.getPositionMS() > 134208 - Constants::SHAPE_MOVE_TIME) &&
			(song.getPositionMS() < 165000 - Constants::SHAPE_MOVE_TIME)) {
			spawnTriangles();
			spawnCircles();
			spawnRects();
		}


		// end game when song ends
		if (song.getPosition() == 1.0f) {
			arrowRightPos = ofVec2f(80, Constants::PLAY_AGAIN_Y - 20);
			gameState = Constants::END;
		}
	}
	//end game state
	else if (gameState == Constants::END) {
		// flashing arrow
		if (arrowAInc) {
			arrowA += 3;
			if (arrowA >= 255) {
				arrowAInc = false;
			}
		}
		else {
			arrowA -= 3;
			if (arrowA <= 10) {
				arrowAInc = true;
			}
		}
	}
}

//-------------------------------------------------------------- Spawning 
void ofApp::spawnCircles() {
	if (ofGetElapsedTimef() > circleTimer + 4) {
		circle newCircle;
		circles.push_back(newCircle);
		circleTimer = ofGetElapsedTimef();
	}
}

void ofApp::spawnTriangles() {
	if (ofGetElapsedTimef() > triangleTimer + 4) {
		triangle newTriangle;
		triangles.push_back(newTriangle);
		triangleTimer = ofGetElapsedTimef();
	}
}

void ofApp::spawnRects() {
	if (ofGetElapsedTimef() > rectTimer + 2) {
		rectangle newRect;
		rectangles.push_back(newRect);
		rectTimer = ofGetElapsedTimef();
	}
}

//-------------------------------------------------------------- draw
void ofApp::draw(){
	//*************Background*************//

	ofBackgroundGradient(lightBlue, offWhite, OF_GRADIENT_LINEAR);

	if (gameState == Constants::START) {
		//*************Start Screen Layout Design*************//

		ofSetColor(mediumBlue);
		ofDrawRectRounded(Constants::SHAPS_RECT_X, Constants::SHAPS_RECT_Y, Constants::SHAPS_RECT_WIDTH, Constants::SHAPS_RECT_HEIGHT, 5);
		ofDrawRectRounded(Constants::START_RECT_X, Constants::START_RECT_Y, Constants::START_RECT_WIDTH, Constants::START_RECT_HEIGHT, 5);

		ofSetColor(offWhite);
		titleFont.drawString("SHAPS!", Constants::SHAPS_RECT_X + 15, Constants::SHAPS_RECT_Y + 200);
		subtitleFont.drawString("START", Constants::START_RECT_X + 10, Constants::START_RECT_Y + 60);

		ofSetColor(255, 255, 255, arrowA);
		arrowRight.draw(arrowRightPos);
	}
	else if (gameState == Constants::GAME) {
		//*************Game Screen Layout Design*************//
		ofSetColor(mediumBlue);
		textFont.drawString("score: " + std::to_string(score), Constants::SCREEN_WIDTH - 150, 30);

		// drawing lanes
		ofSetColor(251, 180, 200); //red
		ofDrawRectangle(Constants::LANE1_X, 0, Constants::LANE_WIDTH, Constants::SCREEN_HEIGHT);

		ofSetColor(174, 237, 251); //blue
		ofDrawRectangle(Constants::LANE2_X, 0, Constants::LANE_WIDTH, Constants::SCREEN_HEIGHT);

		ofSetColor(186, 251, 174); //green
		ofDrawRectangle(Constants::LANE3_X, 0, Constants::LANE_WIDTH, Constants::SCREEN_HEIGHT);

		ofSetColor(offWhite);
		ofDrawRectangle(Constants::LANE1_X, Constants::PLAYER_Y, Constants::LANE_WIDTH, Constants::PLAYER_HEIGHT);
		ofDrawRectangle(Constants::LANE2_X, Constants::PLAYER_Y, Constants::LANE_WIDTH, Constants::PLAYER_HEIGHT);
		ofDrawRectangle(Constants::LANE3_X, Constants::PLAYER_Y, Constants::LANE_WIDTH, Constants::PLAYER_HEIGHT);


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

		// draw arrows
		ofSetColor(255, 255, 255);
		if (drawLeft) {
			arrowLeft.draw(arrowLeftPos);
		}
		if (drawRight) {
			arrowRight.draw(arrowRightPos);
		}

	}
	else if (gameState == Constants::END) {
		//*************End Screen Layout Design*************//
		ofSetColor(mediumBlue);
		titleFont.drawString("SCORE: " + std::to_string(score), Constants::SCORE_X, Constants::SCORE_Y);
		ofDrawRectRounded(Constants::PLAY_AGAIN_X, Constants::PLAY_AGAIN_Y, Constants::PLAY_AGAIN_WIDTH, Constants::PLAY_AGAIN_HEIGHT, 5);

		ofSetColor(offWhite);
		subtitleFont.drawString("PLAY AGAIN", Constants::PLAY_AGAIN_X + 10, Constants::PLAY_AGAIN_Y + 70);

		ofSetColor(255, 255, 255, arrowA);
		arrowRight.draw(arrowRightPos);
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	//*************Start Screen Layout Design*************//
	if (gameState == Constants::START) {
		if (key == 13) { // enter key to select a button
			// If player presses the START button
			if (arrowRightPos == ofVec2f(80, 275)) {
				// instructions
			}
			else if (arrowRightPos == ofVec2f(80, Constants::START_RECT_Y - 20)) {
				gameState = Constants::GAME;
				song.play();
			}
		}
		if (key == OF_KEY_UP) {
			arrowRightPos = ofVec2f(80, 275);
		}
		if (key == OF_KEY_DOWN) {
			arrowRightPos = ofVec2f(80, Constants::START_RECT_Y - 20);

		}
	}
	//*************Game Screen Layout Design*************//
	else if (gameState == Constants::GAME) {
		// A for circle
		if (key == 65 || key == 97) { // A or a
			circlePressed();
		}
		// S for triangle
		if (key == 83 || key == 115) {// S or s
			trianglePressed();
		}
		// D for rectangle
		if (key == 68 || key == 100) {// D or d
			rectPressed();
		}
	}
	//*************End Screen Layout Design*************//
	else if (gameState == Constants::END) {
		if (key == 13) { // ENTER key
			gameState = Constants::GAME;
			song.play();
		}
	}
}

//-------------------------------------------------------------- if shapes pressed
void ofApp::circlePressed() {
	for (int i = 0; i < circles.size(); i++) {
		if ((circles[i].yPos > Constants::PLAYER_Y) &&
			(circles[i].yPos < Constants::PLAYER_Y + Constants::PLAYER_HEIGHT)) {
			circles[i].shapePressed += 1;
			if (circles[i].shapePressed == 1) {
				score += 1;
			}
		}
	}
}

void ofApp::trianglePressed() {
	for (int i = 0; i < triangles.size(); i++) {
		if ((triangles[i].yPos > Constants::PLAYER_Y) &&
			(triangles[i].yPos < Constants::PLAYER_Y + Constants::PLAYER_HEIGHT)) {
			triangles[i].shapePressed += 1;
			if (triangles[i].shapePressed == 1) {
				score += 1;
			}
		}
	}
}

void ofApp::rectPressed() {
	for (int i = 0; i < rectangles.size(); i++) {
		if ((rectangles[i].yPos + rectangles[i].width > Constants::PLAYER_Y) &&
			(rectangles[i].yPos + rectangles[i].width < Constants::PLAYER_Y + Constants::PLAYER_HEIGHT)) {
			rectangles[i].shapePressed += 1;
			if (rectangles[i].shapePressed == 1) {
				score += 1;
			}
		}
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

//-------------------------------------------------------------- moused pressed
void ofApp::mousePressed(int x, int y, int button){
	//*************Start Screen Layout Design*************//
	if (gameState == Constants::START) {
		// If player presses the SHAPS! button
		if ((x > Constants::SHAPS_RECT_X) && (x < Constants::SHAPS_RECT_X + Constants::SHAPS_RECT_WIDTH) &&
			(y > Constants::SHAPS_RECT_Y) && (y < Constants::SHAPS_RECT_Y + Constants::SHAPS_RECT_HEIGHT)) {
				// instructions?
			}

		// If player presses the START button
		else if ((x > Constants::START_RECT_X) && (x < Constants::START_RECT_X + Constants::START_RECT_WIDTH) &&
				(y > Constants::START_RECT_Y) && (y < Constants::START_RECT_Y + Constants::START_RECT_HEIGHT)) {
			gameState = Constants::GAME;
			//song.setPosition(0.0f); // restart song
			song.play();
		}
	}
	//*************Game Screen Layout Design*************//
	else if (gameState == Constants::GAME) {
		std::cout << song.getPositionMS() << std::endl;
	}
	//*************End Screen Layout Design*************//
	else if (gameState == Constants::END) {
		// If player presses the play again button
		if ((x > Constants::PLAY_AGAIN_X) && (x < Constants::PLAY_AGAIN_X + Constants::PLAY_AGAIN_WIDTH) &&
			(y > Constants::PLAY_AGAIN_Y) && (y < Constants::PLAY_AGAIN_Y + Constants::PLAY_AGAIN_HEIGHT)) {
			gameState = Constants::GAME;
			//song.setPosition(0.0f); // restart song
			song.play();
		}
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

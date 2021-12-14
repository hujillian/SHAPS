#pragma once

#include "ofMain.h"
#include "ofEvents.h"
#include "ofEventUtils.h"
#include "shapes.h"
#include "Constants.h"
#include "arduino.h"


class ofApp : public ofBaseApp{
	
	public:

		//*************Arduino init.*************//
		arduino controller;


		//*************Song init.*************//
		ofSoundPlayer song;


		//*************Game State init.*************//
		Constants::GAME_STATE gameState;
		int score;
		int circleTimer;
		int triangleTimer;
		int rectTimer;
		

		//*************Arrows*************//
		ofImage arrowRight;
		ofImage arrowLeft;
		ofVec2f arrowRightPos;
		ofVec2f arrowLeftPos;
		int arrowA;
		bool arrowAInc;
		bool drawRight;
		bool drawLeft;


		//*************Font*************//
		ofTrueTypeFont titleFont;
		ofTrueTypeFont subtitleFont;
		ofTrueTypeFont textFont;


		//*************Colour*************//
		ofColor lightBlue;
		ofColor offWhite;
		ofColor mediumBlue;


		//*************Shape Vectors*************//
		std::vector<circle> circles;
		vector<rectangle> rectangles;
		vector<triangle> triangles;

		bool drawInstructions;

		void setup();
		void update();
		void draw();


		//*************Functions*************//
		void circlePressed();
		void trianglePressed();
		void rectPressed();
		void spawnCircles(int spawnTime);
		void spawnTriangles(int spawnTime);
		void spawnRects(int spawnTime);

		void startGame();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
};

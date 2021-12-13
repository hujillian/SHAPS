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
		//arduino controller;
		//ofArduino arduino;
		//ofArduino ard;
		arduino controller;
		bool bSetupArduino;
		string buttonState;
		string potValue;

		void setupArduino(const int & version);
		void digitalPinChanged(const int & pinNum);
		void analogPinChanged(const int & pinNum);
		void updateArduino();


		//*************Song init.*************//
		ofSoundPlayer song;


		//*************Game State init.*************//
		Constants::GAME_STATE gameState;

		//string game_state;
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

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
};

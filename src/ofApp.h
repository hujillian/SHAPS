#pragma once

#include "ofMain.h"
#include "ofEvents.h"
#include <chrono>
#include <thread>
#include "shapes.h"
#include "Constants.h"

class ofApp : public ofBaseApp{

	public:
		ofArduino arduino;
		bool bSetupArduino;

		void setupArduino(const int & version);
		void digitalPinChanged(const int & pinNum);
		void analogPinChanged(const int & pinNum);
		void updateArduino();

		string buttonState;
		string potValue;

		Constants::GAME_STATE gameState;

		//string game_state;
		int score;
		int circleTimer;
		int triangleTimer;
		int rectTimer;
		

		// fonts
		ofTrueTypeFont titleFont;
		ofTrueTypeFont subtitleFont;
		ofTrueTypeFont textFont;

		// colours
		ofColor lightBlue;
		ofColor offWhite;
		ofColor mediumBlue;
		
		//player position 
		//float xPos;
		//float yPos;

		std::vector<circle> circles;
		vector<rectangle> rectangles;
		vector<triangle> triangles;

		void setup();
		void update();
		void draw();

		void circlePressed();
		void trianglePressed();
		void rectPressed();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};

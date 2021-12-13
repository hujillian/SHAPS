#pragma once

#include "ofMain.h"
#include "ofEvents.h"
#include <chrono>
#include <thread>
#include "shapes.h"

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

		string game_state;
		//string start = "START";
		//ofTrueTypeFont start;
		int score;

		// fonts
		ofTrueTypeFont titleFont;
		ofTrueTypeFont subtitleFont;

		// start page
		int shapsRectX;
		int shapsRectY;
		int shapsRectWidth;
		int shapsRectHeight;
		int startRectX;
		int startRectY;
		int startRectWidth;
		int startRectHeight;
		
		//player position 
		float xPos;
		float yPos;

		//circle spawn_c;
		//rectangle spawn_r;
		std::vector<circle> circles;
		vector<rectangle> rectangles;
		vector<triangle> triangles;

		void setup();
		void update();
		void draw();

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

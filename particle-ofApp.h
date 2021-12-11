#pragma once

#include "ofMain.h"

// particles
// my particle code is based on this tutorial:
// https://www.youtube.com/watch?v=XghI0B4EhQI&ab_channel=danbuzzo
struct particle {
	float m_xPos;
	float m_yPos;
	float m_radius;

	ofVec2f m_force;
	ofVec2f m_position;
	ofVec2f m_direction;

	particle(int startX, int startY);
	~particle();
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mouseMoved(int x, int y);

		vector<particle> particles; // this is the array of particles
		
};

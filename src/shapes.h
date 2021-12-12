#pragma once
#include "ofMain.h"

class shapes {
public:
	float xPos;
	float yPos;
	float speedY;
	float speedX;

	//void setup();
	//void update();
	//void draw();

	ofVec2f m_force;
	ofVec2f m_position;
	ofVec2f m_direction;

	shapes();
	//shapes(int xPos, int yPos);
	~shapes();
};

class circle : public shapes {
public:
	ofColor colorOne;
	void Draw();
	void Move();
	void Update();
	circle();
	~circle();
};

class rectangle : public shapes {
public:
	ofColor colorTwo;
	void Draw();
	rectangle();
	~rectangle();
};

class triangle : public shapes {
public:
	ofColor colorThree;
	void Draw();

};
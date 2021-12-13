#pragma once
#include "ofMain.h"

class shapes {
public:
	ofColor shapeCol;
	float xPos;
	float yPos;

	float yDirection;
	float yForce;
	//float speedY;
	//float speedX;

	//ofVec2f m_force;
	//ofVec2f m_position;
	//ofVec2f m_direction;
	ofVec2f force;
	ofVec2f position;
	ofVec2f direction;

	//void setup();
	void update();
	void draw();
	shapes();
	//shapes(int xPos, int yPos);
	~shapes();
};

class circle : public shapes {
public:
	//void Draw();
	//void Move();
	//void Update();
	
	int radius;

	void update();
	void draw();
	circle();
	~circle();
};

class rectangle : public shapes {
public:
	int width;
	int height;

	void update();
	void draw();
	rectangle();
	~rectangle();
};

class triangle : public shapes {
public:
	int width;

	void update();
	void draw();
	triangle();
	~triangle();
};
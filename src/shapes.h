#pragma once
#include "ofMain.h"

class shapes {
public:
	ofColor shapeCol;
	float xPos;
	float yPos;
	float yDirection;
	float yForce;
	int shapePressed;
	bool shrink;

	shapes();
	~shapes();
};

class circle : public shapes {
public:
	float radius;

	void update();
	void draw();
	circle();
	~circle();
};

class rectangle : public shapes {
public:
	float width;
	float height;

	void update();
	void draw();
	rectangle();
	~rectangle();
};

class triangle : public shapes {
public:
	float width;

	void update();
	void draw();
	triangle();
	~triangle();
};
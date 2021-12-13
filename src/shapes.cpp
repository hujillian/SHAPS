#include "shapes.h"

//--------------------------------------------------------------
shapes::shapes()
{
	shapePressed = 0;
	shrink = false;
}


shapes::~shapes()
{
	//deconstructor
}

//--------------------------------------------------------------
circle::circle()
{
	radius = 35;
	xPos = 375.0;
	yPos = -1 * (radius);

	yDirection = 1.5; // moves down
	yForce = 0; // no force for now

	shapeCol = ofColor(255, 90, 92);
}
circle::~circle()
{
	//deconstructor
}
void circle::draw()
{
	ofSetColor(shapeCol);
	ofDrawCircle(xPos, yPos, radius);
}

void circle::update()
{
	yPos += yDirection;
	yDirection += yForce;
}


//--------------------------------------------------------------
rectangle::rectangle()
{
	width = 60;
	height = 60;
	xPos = 745;
	yPos = -1 * (height);

	yDirection = 1.5; 
	yForce = 0; 

	shapeCol = ofColor(87, 207, 98);
}

rectangle::~rectangle()
{
	//deconstructor
}

void rectangle::draw()
{
	ofSetColor(shapeCol);
	ofDrawRectangle(xPos, yPos, width, height);
}

void rectangle::update() {
	yPos += yDirection;
	yDirection += yForce;
}

//--------------------------------------------------------------
triangle::triangle()
{
	xPos = 540;
	yPos = 0;
	width = 70;

	yDirection = 1.5;
	yForce = 0;

	shapeCol = ofColor(100, 178, 237);
}

triangle::~triangle() {
	// deconstructor
}

void triangle::draw()
{
	ofSetColor(shapeCol);
	ofDrawTriangle(xPos, yPos, xPos + width / 2, yPos - width, xPos + width, yPos);
}

void triangle::update() {
	yPos += yDirection;
	yDirection += yForce;
}
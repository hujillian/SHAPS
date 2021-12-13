#include "shapes.h"

//--------------------------------------------------------------
shapes::shapes()
{
	
}


/*shapes::shapes(int xPos, int yPos) {

	m_position = ofVec2f(xPos, yPos);
	//m_direction = ofVec2f(ofRandom(-2.0, 2.0), ofRandom(-2.0, 2.0)); // direction that the particles move in is random
		//down, each shape has specific direction
	m_force = ofVec2f(0, 0); // starting force on the particles is 0

}*/

shapes::~shapes()
{
	//deconstructor
}

//--------------------------------------------------------------
circle::circle()
{
	/*
	m_position = ofVec2f(xPos, yPos);
	m_direction = ofVec2f(xPos, 200);
	m_force = ofVec2f(0, 200);*/
	xPos = 375.0;
	yPos = 0;
	radius = 35;

	yDirection = 2.0; // moves down
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
	xPos = 745;
	yPos = 0;
	width = 60;
	height = 60;

	yDirection = 2.0; 
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

	yDirection = 2.0;
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
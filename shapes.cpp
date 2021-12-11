#include "shapes.h"

void shapes::setup()
{
}

void shapes::update()
{
}

void shapes::draw()
{
}
shapes::shapes(int startX, int startY) {

	m_position = ofVec2f(startX, startY);
	//m_direction = ofVec2f(ofRandom(-2.0, 2.0), ofRandom(-2.0, 2.0)); // direction that the particles move in is random
		//down, each shape has specific direction
	m_force = ofVec2f(0, 0); // starting force on the particles is 0

}
shapes::~shapes()
{
	//deconstructor
}

void circle::draw()
{
	colorOne = (174, 218, 251);
	ofSetColor(colorOne);
	ofDrawCircle(xPos,yPos,0,5);

}

void rectangle::draw()
{
}

void triangle::draw()
{
}

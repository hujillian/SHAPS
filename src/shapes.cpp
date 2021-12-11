#include "shapes.h"


shapes::shapes()
{
	xPos = 0;
	yPos = 0;
	speedX = 0;
	speedY = 0;
}

/*shapes::shapes(int startX, int startY) {

	m_position = ofVec2f(startX, startY);
	//m_direction = ofVec2f(ofRandom(-2.0, 2.0), ofRandom(-2.0, 2.0)); // direction that the particles move in is random
		//down, each shape has specific direction
	m_force = ofVec2f(0, 0); // starting force on the particles is 0

}*/

shapes::~shapes()
{
	//deconstructor
}

void circle::Draw()
{
	colorOne = (174, 218, 251);
	xPos = 350;
	yPos = 100;

	ofSetColor(colorOne);
	ofDrawCircle(xPos,yPos,10);

}

void rectangle::Draw()
{
	//fg
}

void triangle::Draw()
{
	//dk
}

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
	xPos = 370;
	yPos = 100;

	ofSetColor(174, 218, 251);
	ofDrawCircle(xPos,yPos,30);

}

void rectangle::Draw()
{
	//fg
}

void triangle::Draw()
{
	//dk
}

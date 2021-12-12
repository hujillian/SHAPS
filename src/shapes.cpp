#include "shapes.h"

//--------------------------------------------------------------
shapes::shapes()
{
	xPos = 0;
	yPos = 0;
	speedX = 0;
	speedY = 0;
}

void shapes::update()
{
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

//--------------------------------------------------------------
circle::circle()
{
	xPos = 375;
	yPos = 100;
}
circle::~circle()
{
	//deconstructor
}
void circle::Draw()
{
	colorOne = (174, 218, 251);			//trying to assign colour

	ofSetColor(174, 218, 251);
	ofDrawCircle(xPos,yPos,30);

}

//--------------------------------------------------------------
rectangle::rectangle()
{
	xPos = 730;
	yPos = 100;
}

rectangle::~rectangle()
{
	//deconstructor
}

void rectangle::Draw()
{
	ofSetColor(140, 236, 149);
	ofDrawRectangle(xPos, yPos, 90, 40);
}

//--------------------------------------------------------------
void triangle::Draw()
{
	/*colorThree = (174, 218, 251);
	xPos = 570;
	yPos = 100;

	ofSetColor(251, 175, 174);
	ofDrawTriangle(0,0,0,0,0,0);*/
}



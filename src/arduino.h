#pragma once
#include "ofMain.h"
#include "ofEvents.h"

class arduino
{
public:
	//*************Arduino init.*************//
	ofArduino ard;
	bool bSetupArduino;
	string buttonState;
	string potValue;

	bool redButtonPressed;
	bool blueButtonPressed;
	bool greenButtonPressed;
	string joystick;
	bool joystickPressed;

	void initialSetup();
	void setupArduino(const int & version);
	void digitalPinChanged(const int & pinNum);
	void analogPinChanged(const int & pinNum);
	void updateArduino();
	void lightOn(std::string lightCol);
};


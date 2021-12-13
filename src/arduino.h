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

	void initialSetup();
	void setupArduino(const int & version);
	void digitalPinChanged(const int & pinNum);
	void analogPinChanged(const int & pinNum);
	void updateArduino();
};


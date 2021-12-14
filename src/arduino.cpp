#include "arduino.h"

//--------------------------------------------------------------
void arduino::initialSetup() {
	ard.connect("COM3", 57600);
	ofAddListener(ard.EInitialized, this, &arduino::setupArduino);
	bSetupArduino = false;

	redButtonPressed = false;
	blueButtonPressed = false;
	greenButtonPressed = false;
	joystick = "up";
	joystickPressed = false;
}

//--------------------------------------------------------------
void arduino::setupArduino(const int & version) {
	ofRemoveListener(ard.EInitialized, this, &arduino::setupArduino);
	bSetupArduino = true;

	// print firmware name and version to the console
	std::cout << ard.getFirmwareName() << std::endl;
	std::cout << "firmata v" << ard.getMajorFirmwareVersion() << "." << ard.getMinorFirmwareVersion() << std::endl;

	// set pins A0 and A5 to analog, and 8 to digital input
	ard.sendAnalogPinReporting(0, ARD_ANALOG);
	ard.sendAnalogPinReporting(5, ARD_ANALOG); // not sure if this is right
	ard.sendDigitalPinMode(8, ARD_INPUT);
	ard.sendDigital(8, ARD_LOW);

	// set pins 2, 4, 6, 7, to digital input
	ard.sendDigitalPinMode(2, ARD_INPUT);
	ard.sendDigitalPinMode(4, ARD_INPUT);
	ard.sendDigitalPinMode(6, ARD_INPUT);
	ard.sendDigitalPinMode(7, ARD_INPUT);

	// set LED lights pins 10, 12, 13 to PWM/digital output
	ard.sendDigitalPinMode(10, ARD_OUTPUT);
	ard.sendDigitalPinMode(12, ARD_OUTPUT);
	ard.sendDigitalPinMode(13, ARD_OUTPUT);

	// Listen for changes on the digital and analog pins
	ofAddListener(ard.EDigitalPinChanged, this, &arduino::digitalPinChanged);
	ofAddListener(ard.EAnalogPinChanged, this, &arduino::analogPinChanged);
}

//--------------------------------------------------------------
void arduino::updateArduino() {
	ard.update();

	ofSetColor(255, 255, 255);
	// do not send anything until the arduino has been set up
	if (bSetupArduino) {

		// button with red light
		if (ard.getDigital(2)) {
			redButtonPressed = true;
		}
		else {
			redButtonPressed = false;
			ard.sendDigital(10, ARD_LOW);
		}
		// button with blue light
		if (ard.getDigital(4)) {
			blueButtonPressed = true;
		}
		else {
			ard.sendDigital(12, ARD_LOW);
			blueButtonPressed = false;
		}
		// button with green light
		if (ard.getDigital(7)) {
			greenButtonPressed = true;
		}
		else {
			ard.sendDigital(13, ARD_LOW);
			greenButtonPressed = false;
		}

		// tilt switch with blue light 
		if (ard.getDigital(6)) {
			//ard.sendDigital(12, ARD_HIGH);
		}
		else {
			//ard.sendDigital(12, ARD_LOW);
		}

		// joystick
		//std::cout << ard.getAnalog(0) << " ," << ard.getAnalog(5) << std::endl;
		if (ard.getAnalog(5) < 0) {// initial value
			joystick = "up";
		}
		else if (ard.getAnalog(5) < 480) { // down
			joystick = "down";
			
		}
		else if (ard.getAnalog(5) > 535) { // up
			joystick = "up";
		}
		// joystick button
		if (ard.getDigital(8)) {
			joystickPressed = true;
			cout << "yes pressed\n";
		}
		else {
			joystickPressed = false;
			cout << "not pressed\n";
		}
	}
}

void arduino::lightOn(std::string lightCol) {
	if (lightCol == "red") {
		ard.sendDigital(10, ARD_HIGH);
	}
	else if (lightCol == "blue") {
		ard.sendDigital(12, ARD_HIGH);
	}
	else if (lightCol == "green") {
		ard.sendDigital(13, ARD_HIGH);
	}
}

//--------------------------------------------------------------
void arduino::digitalPinChanged(const int & pinNum) {
	// do something with the digital input. here we're simply going to print the pin number and
	// value to the screen each time it changes
	//buttonState = "digital pin: " + ofToString(pinNum) + " = " + ofToString(ard.getDigital(pinNum));
}

// analog pin event handler, called whenever an analog pin value has changed

//--------------------------------------------------------------
void arduino::analogPinChanged(const int & pinNum) {
	// do something with the analog input. here we're simply going to print the pin number and
	// value to the screen each time it changes
	potValue = "analog pin: " + ofToString(pinNum) + " = " + ofToString(ard.getAnalog(pinNum));
}
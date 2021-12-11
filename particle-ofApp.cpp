#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

	// particles
	for (int i = 0; i < particles.size(); i++) { // loop through all of the particles
		particles[i].m_position += particles[i].m_direction; // add the direction to the position value to move the particle
		particles[i].m_direction += particles[i].m_force; // add the force to the direction to change the speed and direction of its motion

		if (particles[i].m_radius > 1) { 
			particles[i].m_radius -= 0.07; // particle decreases in size
		}
		else if (particles[i].m_radius > 0.5) {
			particles[i].m_radius -= 0.001; // particle decreases in size
		}
		else {
			particles.erase(particles.begin() + i); // if particle is very small, delete it
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	
		// particles
		for (int i = 0; i < particles.size(); i++) {
			// particles "fall" with the strength of the voice's value
			particles[i].m_force = ofVec2f(0, m_circlesBrightness_3 / 5); 
			// draw particles
			ofDrawCircle(particles[i].m_position, particles[i].m_radius);
		}
	}
}

void ofApp::mouseMoved(int x, int y) {
	particle newParticle(x, y); // new particles appear at the mouse cursor
	particles.push_back(newParticle); // add this particle to the list of particles
}

// create a particle
particle::particle(int startX, int startY) {
	m_position = ofVec2f(startX, startY); 
	m_direction = ofVec2f(ofRandom(-2.0, 2.0), ofRandom(-2.0, 2.0)); // direction that the particles move in is random
	m_force = ofVec2f(0, 0); // starting force on the particles is 0
	m_radius = 20; // size of circles
}

particle::~particle() {
	// particle destructor	
}

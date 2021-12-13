#pragma once
#include "ofMain.h"

namespace Constants {
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 900;

	enum GAME_STATE { START, GAME, END };


	// start page constants
	const int SHAPS_RECT_X = 350;
	const int SHAPS_RECT_Y = 200;
	const int SHAPS_RECT_WIDTH = 600;
	const int SHAPS_RECT_HEIGHT = 280;
	const int START_RECT_X = 550;
	const int START_RECT_Y = 600;
	const int START_RECT_WIDTH = 200;
	const int START_RECT_HEIGHT = 80;

	// game constants
	const int PLAYER_Y = 700;
	const int PLAYER_HEIGHT = 100;
	const int LANE1_X = 326;
	const int LANE2_X = 526;
	const int LANE3_X = 726;
	const int LANE_WIDTH = 100;
}
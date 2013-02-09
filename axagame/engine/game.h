/*************************************************************************************
 *   Created on: Jan 12, 2013
 *
 *	AxaGame - http://axatrikx.com
 *	Copyright (C) 2013  Amal Bose
 *
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **************************************************************************************/

#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include "../utils/logger.h"
#include "imports.h"
#include "singleton.h"
#include "state.h"
#include "config.h"
#include "irrcontroller.h"
#include "event.h"
#include "defaults.h"
#include "stateman.h"
#include "constants.h"

/**
 * The main Game class which handles the creation of irrlicht driver and the game loop.
 */
class GameClass {
public:

	/**
	 * Initializes the game by getting values from configuration and creating Irrlicht driver.
	 * @param argc
	 * @param argv
	 * @return
	 */
	int init(int argc, char** argv);

	/**
	 * Game update method.
	 */
	void update();

	/**
	 * Deletes irrlicht driver.
	 */
	void close();

	/**
	 * Checks if game is running or not.
	 * @return False if not running and True otherwise.
	 */
	bool isDone() {
		return !isRunning;
	}

	/**
	 * Sets the value for isRunning.
	 * @param value Whether running or not.
	 */
	void setDone(bool value) {
		isRunning = !value;
	}

	/**
	 * Gets the current state.
	 * @return current state.
	 */
	State* getCurrentState() {
		return stateManager->getCurrentState();
	}

private:

	bool isRunning, isWindowActive;
	StateManager *stateManager;
	int loops;
	float nextTick, interpolation;
	const int TICKS_PER_SECOND = 25;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 5;
};

typedef Singleton<GameClass> Game;

#endif /* GAME_H_ */

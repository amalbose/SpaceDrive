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

class GameClass {
public:

	int init(int argc, char** argv);
	void update();
	void close();

	bool isDone() {
		return !isRunning;
	}
	void setDone(bool value) {
		isRunning = !value;
	}

	//states
	IEventReceiver* event;

private:

	bool isRunning, isWindowActive;
	StateManager *stateManager;
	int loops;
	float nextTick,interpolation;
	const int TICKS_PER_SECOND = 25;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 5;
};

typedef Singleton<GameClass> Game;

#endif /* GAME_H_ */

/*************************************************************************************
 *   Created on: Jan 23, 2013
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

#ifndef PLAY_H_
#define PLAY_H_

#include "../engine/imports.h"
#include "../engine/globals.h"
#include "../engine/constants.h"
#include "../engine/state.h"
#include "../utils/logger.h"
#include "level.h"

class Play: public State {
public:
	Play();
	virtual ~Play();

	int init();
	int close();

	bool onKeyPress(int key);
	bool onKeyLift(int key);
	void onMouseMotion(float valueX, float valueY);
	bool onMousePress(int button, int valueX, int valueY);
	void onMouseLift(int button, int valueX, int valueY);
	void onMouseWheel(float direction);

	void update();
	void updateRender();
	void render(float interpolation);

	Level* getCurrentLevel() {return currentLevel; }
	void setCurrentLevel(Level* level) {currentLevel = level; }

private:
	core::array<Level*> levelList;
	Level* currentLevel;
};

#endif /* PLAY_H_ */

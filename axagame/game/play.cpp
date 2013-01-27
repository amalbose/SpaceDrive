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

#include "play.h"

Play::Play() {
	setStateName(STATE_PLAY);
	Level* levelOne = new Level("LevelOne");
	levelList.push_back(levelOne);
	setCurrentLevel(levelOne);
}

Play::~Play() {
	// TODO Auto-generated destructor stub
}

int Play::init() {
	getCurrentLevel()->init();
	return 1;
}
int Play::close() {
	return 1;
}

bool Play::onKeyPress(int key) {
	return getCurrentLevel()->onKeyPress(key);
}
bool Play::onKeyLift(int key) {
	return getCurrentLevel()->onKeyLift(key);
}
void Play::onMouseMotion(float valueX, float valueY) {
	getCurrentLevel()->onMouseMotion(valueX,valueY);
}
bool Play::onMousePress(int button, int valueX, int valueY) {
	return getCurrentLevel()->onMousePress(button,valueX,valueY);
}
void Play::onMouseLift(int button, int valueX, int valueY) {
	getCurrentLevel()->onMouseLift(button,valueX,valueY);
}
void Play::onMouseWheel(float direction) {
	getCurrentLevel()->onMouseWheel(direction);
}
void Play::update() {
}
void Play::updateRender() {
}
void Play::render(float interpolation) {
}

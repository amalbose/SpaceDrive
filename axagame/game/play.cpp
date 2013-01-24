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
}

Play::~Play() {
	// TODO Auto-generated destructor stub
}

int Play::init() {
	return 1;
}
int Play::close() {
	return 1;
}

bool Play::onKeyPress(int key) {
	return false;
}
bool Play::onKeyLift(int key) {
	return false;
}
void Play::onMouseMotion(float valueX, float valueY) {
}
bool Play::onMousePress(int button, int valueX, int valueY) {
	return false;
}
void Play::onMouseLift(int button, int valueX, int valueY) {
}
//		virtual void onMouseWheel(float direction) { }

void Play::update() {
}
void Play::updateRender() {
}
void Play::render(float interpolation) {
}

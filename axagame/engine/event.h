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

#ifndef EVENT_H_
#define EVENT_H_

#include "imports.h"
#include "singleton.h"
#include "game.h"

class Event: public irr::IEventReceiver {

public:

	enum MouseButtonType {
		MOUSE_LEFT, MOUSE_RIGHT, MOUSE_MIDDLE, MOUSE_COUNT,
	};

	Event();

	bool OnEvent(const irr::SEvent& event);

	bool onEvent(const irr::SEvent& event) {	return OnEvent(event);	}

	void resetEvents();
	bool getKeyState(int key) const { return Keys[key]; }
	bool getMouseState(int button) const { return MouseButtons[button]; }

	int getMouseX() const { return mouseX; }
	int getMouseY() const { return mouseY; }

	static irr::EKEY_CODE getKey(std::string keyVal);

private:
	bool Keys[KEY_KEY_CODES_COUNT], MouseButtons[MOUSE_COUNT];
	int mouseX,mouseY;

	void setKeyState(int key, bool state) { Keys[key] = state; }
	void setMouseState(int button, bool state) { MouseButtons[button] = state; }
};

typedef Singleton<Event> EventReceiver;

#endif /* EVENT_H_ */

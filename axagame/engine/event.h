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

/**
 * Manages the event receiver by extending from IEventReceiver.
 */
class Event: public irr::IEventReceiver {

public:

	/**
	 * Enum for various mouse button types.
	 */
	enum MouseButtonType {
		MOUSE_LEFT, MOUSE_RIGHT, MOUSE_MIDDLE, MOUSE_COUNT,
	};

	/**
	 * Event class contructor which resets events.
	 */
	Event();

	bool OnEvent(const irr::SEvent& event);

	/**
	 * Handles onEvent by calling IEventReceiver's OnEvent method
	 * @param event
	 * @return
	 */
	bool onEvent(const irr::SEvent& event) {	return OnEvent(event);	}

	/**
	 * Resets keys array to 0.
	 */
	void resetEvents();

	/**
	 * Gets the key state for the given key.
	 * @param key int value for key
	 * @return Key state for the given key
	 */
	bool getKeyState(int key) const { return Keys[key]; }

	/**
	 * Gets the mouse state for given mouse button.
	 * @param button int value for mouse button.
	 * @return mouse state for given mouse button.
	 */
	bool getMouseState(int button) const { return MouseButtons[button]; }

	/**
	 * Gets x value for mouse
	 * @return x value for mouse
	 */
	int getMouseX() const { return mouseX; }

	/**
	 * Gets y value for mouse
	 * @return y value for mouse
	 */
	int getMouseY() const { return mouseY; }

	/**
	 * Gets the key code for given key
	 * @param keyVal key value in string format
	 * @return Key Code in irr::EKEY_CODE format.
	 */
	static irr::EKEY_CODE getKey(std::string keyVal);

private:
	bool Keys[KEY_KEY_CODES_COUNT], MouseButtons[MOUSE_COUNT];
	int mouseX,mouseY;

	/**
	 * Sets the key to the given state
	 * @param key the key to set
	 * @param state the state to be set for the key
	 */
	void setKeyState(int key, bool state) { Keys[key] = state; }

	/**
	 * Sets the mouse button to given state
	 * @param button the button to set
	 * @param state the state to be set for the button
	 */
	void setMouseState(int button, bool state) { MouseButtons[button] = state; }
};

/**
 * Singleton class for Event class.
 */
typedef Singleton<Event> EventReceiver;

#endif /* EVENT_H_ */

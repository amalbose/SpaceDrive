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

#include "event.h"

Event::Event() :
		mouseX(0), mouseY(0) {
	resetEvents();
}

void Event::resetEvents() {
	for (int i = 0; i < KEY_KEY_CODES_COUNT; i++) {
		Keys[i] = 0;
	}
}

bool Event::OnEvent(const SEvent &event) {

	switch (event.EventType) {
	case EET_KEY_INPUT_EVENT:
		// Send key press events
		if (event.KeyInput.PressedDown) {
			if (event.KeyInput.Key == KEY_KEY_X) {
				Game::Instance().setDone(true);
			}
			Game::Instance().getCurrentState()->onKeyPress(event.KeyInput.Key);
		} else if (!event.KeyInput.PressedDown) {
			Game::Instance().getCurrentState()->onKeyLift(event.KeyInput.Key);
		}

		setKeyState(event.KeyInput.Key, event.KeyInput.PressedDown);
		break;
	case EET_MOUSE_INPUT_EVENT:

		switch (event.MouseInput.Event) {
		case EMIE_LMOUSE_PRESSED_DOWN:
		case EMIE_RMOUSE_PRESSED_DOWN:
		case EMIE_MMOUSE_PRESSED_DOWN:
			setMouseState(event.MouseInput.Event, true);
			return Game::Instance().getCurrentState()->onMousePress(event.MouseInput.Event, event.MouseInput.X,
					event.MouseInput.Y);

		case EMIE_LMOUSE_LEFT_UP:
		case EMIE_RMOUSE_LEFT_UP:
		case EMIE_MMOUSE_LEFT_UP:
			setMouseState(event.MouseInput.Event - MOUSE_COUNT, false);
			Game::Instance().getCurrentState()->onMouseLift(event.MouseInput.Event - MOUSE_COUNT, event.MouseInput.X,
					event.MouseInput.Y);
			break;
		case EMIE_MOUSE_MOVED:
			mouseX = event.MouseInput.X;
			mouseY = event.MouseInput.Y;
			Game::Instance().getCurrentState()->onMouseMotion(mouseX, mouseY);
			break;
		case EMIE_MOUSE_WHEEL:
			Game::Instance().getCurrentState()->onMouseWheel(event.MouseInput.Wheel);
			break;
		default:
			break;
		}
		return false;
		break;
	case EET_GUI_EVENT:
	default:
		break;
	}
	return false;
}

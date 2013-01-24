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
		} else if (!event.KeyInput.PressedDown) {

		}
		break;
	case EET_MOUSE_INPUT_EVENT:

		switch (event.MouseInput.Event) {
		case EMIE_LMOUSE_PRESSED_DOWN:
		case EMIE_RMOUSE_PRESSED_DOWN:
		case EMIE_MMOUSE_PRESSED_DOWN:
		case EMIE_LMOUSE_LEFT_UP:
		case EMIE_RMOUSE_LEFT_UP:
		case EMIE_MMOUSE_LEFT_UP:
		case EMIE_MOUSE_MOVED:
		case EMIE_MOUSE_WHEEL:
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

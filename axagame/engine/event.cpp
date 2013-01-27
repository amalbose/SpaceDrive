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

irr::EKEY_CODE Event::getKey(char* key) {
	irr::EKEY_CODE keyCode;
	if (std::strcmp(key, "a") == 0 || std::strcmp(key, "A") == 0) {
		keyCode = KEY_KEY_A;
	} else if (std::strcmp(key, "b") == 0 || std::strcmp(key, "B") == 0) {
		keyCode = KEY_KEY_B;
	} else if (std::strcmp(key, "c") == 0 || std::strcmp(key, "C") == 0) {
		keyCode = KEY_KEY_C;
	} else if (std::strcmp(key, "d") == 0 || std::strcmp(key, "D") == 0) {
		keyCode = KEY_KEY_D;
	} else if (std::strcmp(key, "e") == 0 || std::strcmp(key, "E") == 0) {
		keyCode = KEY_KEY_E;
	} else if (std::strcmp(key, "f") == 0 || std::strcmp(key, "F") == 0) {
		keyCode = KEY_KEY_F;
	} else if (std::strcmp(key, "g") == 0 || std::strcmp(key, "G") == 0) {
		keyCode = KEY_KEY_G;
	} else if (std::strcmp(key, "h") == 0 || std::strcmp(key, "H") == 0) {
		keyCode = KEY_KEY_H;
	} else if (std::strcmp(key, "i") == 0 || std::strcmp(key, "I") == 0) {
		keyCode = KEY_KEY_I;
	} else if (std::strcmp(key, "j") == 0 || std::strcmp(key, "J") == 0) {
		keyCode = KEY_KEY_J;
	} else if (std::strcmp(key, "k") == 0 || std::strcmp(key, "K") == 0) {
		keyCode = KEY_KEY_K;
	} else if (std::strcmp(key, "l") == 0 || std::strcmp(key, "L") == 0) {
		keyCode = KEY_KEY_L;
	} else if (std::strcmp(key, "m") == 0 || std::strcmp(key, "M") == 0) {
		keyCode = KEY_KEY_M;
	} else if (std::strcmp(key, "n") == 0 || std::strcmp(key, "N") == 0) {
		keyCode = KEY_KEY_N;
	} else if (std::strcmp(key, "o") == 0 || std::strcmp(key, "O") == 0) {
		keyCode = KEY_KEY_O;
	} else if (std::strcmp(key, "p") == 0 || std::strcmp(key, "P") == 0) {
		keyCode = KEY_KEY_P;
	} else if (std::strcmp(key, "q") == 0 || std::strcmp(key, "Q") == 0) {
		keyCode = KEY_KEY_Q;
	} else if (std::strcmp(key, "r") == 0 || std::strcmp(key, "R") == 0) {
		keyCode = KEY_KEY_R;
	} else if (std::strcmp(key, "s") == 0 || std::strcmp(key, "S") == 0) {
		keyCode = KEY_KEY_S;
	} else if (std::strcmp(key, "t") == 0 || std::strcmp(key, "T") == 0) {
		keyCode = KEY_KEY_T;
	} else if (std::strcmp(key, "u") == 0 || std::strcmp(key, "U") == 0) {
		keyCode = KEY_KEY_U;
	} else if (std::strcmp(key, "v") == 0 || std::strcmp(key, "V") == 0) {
		keyCode = KEY_KEY_V;
	} else if (std::strcmp(key, "w") == 0 || std::strcmp(key, "W") == 0) {
		keyCode = KEY_KEY_W;
	} else if (std::strcmp(key, "x") == 0 || std::strcmp(key, "X") == 0) {
		keyCode = KEY_KEY_X;
	} else if (std::strcmp(key, "y") == 0 || std::strcmp(key, "Y") == 0) {
		keyCode = KEY_KEY_Y;
	} else if (std::strcmp(key, "z") == 0 || std::strcmp(key, "Z") == 0) {
		keyCode = KEY_KEY_Z;
	} else if (std::strcmp(key, "0") == 0) {
		keyCode = KEY_KEY_0;
	} else if (std::strcmp(key, "1") == 0) {
		keyCode = KEY_KEY_1;
	} else if (std::strcmp(key, "2") == 0) {
		keyCode = KEY_KEY_2;
	} else if (std::strcmp(key, "3") == 0) {
		keyCode = KEY_KEY_3;
	} else if (std::strcmp(key, "4") == 0) {
		keyCode = KEY_KEY_4;
	} else if (std::strcmp(key, "5") == 0) {
		keyCode = KEY_KEY_5;
	} else if (std::strcmp(key, "6") == 0) {
		keyCode = KEY_KEY_6;
	} else if (std::strcmp(key, "7") == 0) {
		keyCode = KEY_KEY_7;
	} else if (std::strcmp(key, "8") == 0) {
		keyCode = KEY_KEY_8;
	} else if (std::strcmp(key, "9") == 0) {
		keyCode = KEY_KEY_9;
	} else if (std::strcmp(key, "left") == 0 || std::strcmp(key, "LEFT") == 0) {
		keyCode = KEY_LEFT;
	} else if (std::strcmp(key, "right") == 0 || std::strcmp(key, "RIGHT") == 0) {
		keyCode = KEY_RIGHT;
	} else if (std::strcmp(key, "up") == 0 || std::strcmp(key, "UP") == 0) {
		keyCode = KEY_UP;
	} else if (std::strcmp(key, "down") == 0 || std::strcmp(key, "DOWN") == 0) {
		keyCode = KEY_DOWN;
	} else if (std::strcmp(key, "space") == 0 || std::strcmp(key, "SPACE") == 0) {
		keyCode = KEY_SPACE;
	} else if (std::strcmp(key, "shift") == 0 || std::strcmp(key, "SHIFT") == 0) {
		keyCode = KEY_SHIFT;
	} else if (std::strcmp(key, "ctrl") == 0 || std::strcmp(key, "CTRL") == 0) {
		keyCode = KEY_CONTROL;
	} else if (std::strcmp(key, "tab") == 0 || std::strcmp(key, "TAB") == 0) {
		keyCode = KEY_TAB;
	} else if (std::strcmp(key, "alt") == 0 || std::strcmp(key, "ALT") == 0) {
		keyCode = KEY_MENU;
	} else if (std::strcmp(key, "enter") == 0 || std::strcmp(key, "ENTER") == 0) {
		keyCode = KEY_RETURN;
	} else if (std::strcmp(key, "esc") == 0 || std::strcmp(key, "ESC") == 0) {
		keyCode = KEY_ESCAPE;
	}
	return keyCode;
}

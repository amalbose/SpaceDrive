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
	if (std::strcmp(key, "a") || std::strcmp(key, "A")) {
		keyCode = KEY_KEY_A;
	} else if (std::strcmp(key, "b") || std::strcmp(key, "B")) {
		keyCode = KEY_KEY_B;
	} else if (std::strcmp(key, "c") || std::strcmp(key, "C")) {
		keyCode = KEY_KEY_C;
	} else if (std::strcmp(key, "d") || std::strcmp(key, "D")) {
		keyCode = KEY_KEY_D;
	} else if (std::strcmp(key, "e") || std::strcmp(key, "E")) {
		keyCode = KEY_KEY_E;
	} else if (std::strcmp(key, "f") || std::strcmp(key, "F")) {
		keyCode = KEY_KEY_F;
	} else if (std::strcmp(key, "g") || std::strcmp(key, "G")) {
		keyCode = KEY_KEY_G;
	} else if (std::strcmp(key, "h") || std::strcmp(key, "H")) {
		keyCode = KEY_KEY_H;
	} else if (std::strcmp(key, "i") || std::strcmp(key, "I")) {
		keyCode = KEY_KEY_I;
	} else if (std::strcmp(key, "j") || std::strcmp(key, "J")) {
		keyCode = KEY_KEY_J;
	} else if (std::strcmp(key, "k") || std::strcmp(key, "K")) {
		keyCode = KEY_KEY_K;
	} else if (std::strcmp(key, "l") || std::strcmp(key, "L")) {
		keyCode = KEY_KEY_L;
	} else if (std::strcmp(key, "m") || std::strcmp(key, "M")) {
		keyCode = KEY_KEY_M;
	} else if (std::strcmp(key, "n") || std::strcmp(key, "N")) {
		keyCode = KEY_KEY_N;
	} else if (std::strcmp(key, "o") || std::strcmp(key, "O")) {
		keyCode = KEY_KEY_O;
	} else if (std::strcmp(key, "p") || std::strcmp(key, "P")) {
		keyCode = KEY_KEY_P;
	} else if (std::strcmp(key, "q") || std::strcmp(key, "Q")) {
		keyCode = KEY_KEY_Q;
	} else if (std::strcmp(key, "r") || std::strcmp(key, "R")) {
		keyCode = KEY_KEY_R;
	} else if (std::strcmp(key, "s") || std::strcmp(key, "S")) {
		keyCode = KEY_KEY_S;
	} else if (std::strcmp(key, "t") || std::strcmp(key, "T")) {
		keyCode = KEY_KEY_T;
	} else if (std::strcmp(key, "u") || std::strcmp(key, "U")) {
		keyCode = KEY_KEY_U;
	} else if (std::strcmp(key, "v") || std::strcmp(key, "V")) {
		keyCode = KEY_KEY_V;
	} else if (std::strcmp(key, "w") || std::strcmp(key, "W")) {
		keyCode = KEY_KEY_W;
	} else if (std::strcmp(key, "x") || std::strcmp(key, "X")) {
		keyCode = KEY_KEY_X;
	} else if (std::strcmp(key, "y") || std::strcmp(key, "Y")) {
		keyCode = KEY_KEY_Y;
	} else if (std::strcmp(key, "z") || std::strcmp(key, "Z")) {
		keyCode = KEY_KEY_Z;
	} else if (std::strcmp(key, "0")) {
		keyCode = KEY_KEY_0;
	} else if (std::strcmp(key, "1")) {
		keyCode = KEY_KEY_1;
	} else if (std::strcmp(key, "2")) {
		keyCode = KEY_KEY_2;
	} else if (std::strcmp(key, "3")) {
		keyCode = KEY_KEY_3;
	} else if (std::strcmp(key, "4")) {
		keyCode = KEY_KEY_4;
	} else if (std::strcmp(key, "5")) {
		keyCode = KEY_KEY_5;
	} else if (std::strcmp(key, "6")) {
		keyCode = KEY_KEY_6;
	} else if (std::strcmp(key, "7")) {
		keyCode = KEY_KEY_7;
	} else if (std::strcmp(key, "8")) {
		keyCode = KEY_KEY_8;
	} else if (std::strcmp(key, "9")) {
		keyCode = KEY_KEY_9;
	} else if (std::strcmp(key, "left") || std::strcmp(key, "LEFT")) {
		keyCode = KEY_LEFT;
	} else if (std::strcmp(key, "right") || std::strcmp(key, "RIGHT")) {
		keyCode = KEY_RIGHT;
	} else if (std::strcmp(key, "up") || std::strcmp(key, "UP")) {
		keyCode = KEY_UP;
	} else if (std::strcmp(key, "down") || std::strcmp(key, "DOWN")) {
		keyCode = KEY_DOWN;
	} else if (std::strcmp(key, "space") || std::strcmp(key, "SPACE")) {
		keyCode = KEY_SPACE;
	} else if (std::strcmp(key, "shift") || std::strcmp(key, "SHIFT")) {
		keyCode = KEY_SHIFT;
	} else if (std::strcmp(key, "ctrl") || std::strcmp(key, "CTRL")) {
		keyCode = KEY_CONTROL;
	} else if (std::strcmp(key, "tab") || std::strcmp(key, "TAB")) {
		keyCode = KEY_TAB;
	} else if (std::strcmp(key, "alt") || std::strcmp(key, "ALT")) {
		keyCode = KEY_MENU;
	} else if (std::strcmp(key, "enter") || std::strcmp(key, "ENTER")) {
		keyCode = KEY_RETURN;
	} else if (std::strcmp(key, "esc") || std::strcmp(key, "ESC")) {
		keyCode = KEY_ESCAPE;
	}
	return keyCode;
}

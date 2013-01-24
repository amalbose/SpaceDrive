/*************************************************************************************
 *   Created on: Jan 13, 2013
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

#include "irrcontroller.h"


int IrrlichtController::init(E_DRIVER_TYPE deviceType, const core::dimension2d<u32>& windowSize, u32 bits,
		bool fullscreen, bool stencilbuffer, bool vsync, IEventReceiver* receiver) {

	irrDevice = createDevice(deviceType, windowSize, bits, fullscreen, stencilbuffer, vsync, receiver);

	if (irrDevice == NULL) {
		Logger(ERROR) << "Setting up Irrlicht Device failed.";
		return 1;
	}
	irrDevice->setWindowCaption(GAME_NAME);
	irrDevice->getCursorControl()->setVisible(false);

	// Save off global pointers
	irrDriver = irrDevice->getVideoDriver();
	irrScene = irrDevice->getSceneManager();
	irrGUI = irrDevice->getGUIEnvironment();
	irrFile = irrDevice->getFileSystem();
	irrTimer = irrDevice->getTimer();

	return 0;
}

void IrrlichtController::close() {
	irrDevice->drop();
}

bool IrrlichtController::beginSceneRender(SColor clearColorValue) {
	return irrDriver->beginScene(true, true, clearColorValue);
}

bool IrrlichtController::beginSceneRender() {
	if (clearColor == NULL) {
		Logger(WARN) << "Clear color not set.";
		return false;
	} else {
		return beginSceneRender(clearColor);
	}
}

void IrrlichtController::endSceneRender() {
	irrDriver->endScene();
}


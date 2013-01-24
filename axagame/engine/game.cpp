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

#include "game.h"

int GameClass::init(int argc, char **argv) {

	isWindowActive = true;
	isRunning = true;
	//Initialize Config
	if (Config::Instance().initConfig()) {
		Logger(ERROR) << "Initialization of config file failed.";
		return 1;
	}
	Config::Instance().readConfig();

	event = new Event();
	//Setting up IrrlichDevice
	if (Controller::Instance().init(Config::Instance().getDriverType(),
			(core::dimension2d<u32>(Config::Instance().getScreenWidth(), Config::Instance().getScreenHeight())),
			Config::Instance().getBits(), Config::Instance().getFullscreen(), Config::Instance().getStencil(),
			Config::Instance().getVsync(), event)) {
		Logger(ERROR) << "Failed to initialize Controller.";
		return 1;
	}

	//Initialize state manager
	stateManager = new StateManager();
	stateManager->setCurrentState(STATE_PLAY);

	nextTick = irrTimer->getTime();
	return 0;
}

void GameClass::update() {
	loops = 0;
	irrDevice->run();

	while (irrTimer->getTime() > nextTick && loops < MAX_FRAMESKIP) {
		//update();
		stateManager->getCurrentState()->update();
		stateManager->getCurrentState()->updateRender();
		nextTick += SKIP_TICKS;
		loops++;
	}

	interpolation = float(irrTimer->getTime() + SKIP_TICKS - nextTick) / float(SKIP_TICKS);
	//display_game( interpolation );
	stateManager->getCurrentState()->render(interpolation);
	Controller::Instance().beginSceneRender(SColor(255, 0, 0, 0));
	irrScene->drawAll();
	Controller::Instance().endSceneRender();
}

void GameClass::close() {
	irrDevice->drop();
}

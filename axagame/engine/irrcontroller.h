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

#ifndef IRRCONTROLLER_H_
#define IRRCONTROLLER_H_

#include "imports.h"
#include "game.h"
#include "globals.h"
#include "defaults.h"
#include "singleton.h"
#include "constants.h"
#include "../utils/logger.h"

class IrrlichtController {

public:
	int init(E_DRIVER_TYPE deviceType, const core::dimension2d<u32>& windowSize, u32 bits, bool fullscreen,
			bool stencilbuffer, bool vsync, IEventReceiver* receiver);

	void close();
	void setClearColor(SColor color) { clearColor = color;}
	bool beginSceneRender();
	bool beginSceneRender(SColor clearColorValue);
	void endSceneRender();

private:
	SColor clearColor;
	bool showCursor;
};


typedef Singleton<IrrlichtController> Controller;

#endif /* IRRCONTROLLER_H_ */

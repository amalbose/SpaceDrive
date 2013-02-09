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

/**
 * IrrlichtController class manages the creation and deletion of irrlicht driver based on specified configuration.
 */
class IrrlichtController {

public:

	/**
	 * Initializes Irrlicht driver
	 * @param deviceType the device type
	 * @param windowSize the window size
	 * @param bits bit rate
	 * @param fullscreen  whether fullscreen or not
	 * @param stencilbuffer whether to use stencilbuffer
	 * @param vsync whether to use vsync
	 * @param receiver the event receiver
	 * @return irrlicht driver
	 */
	int init(E_DRIVER_TYPE deviceType, const core::dimension2d<u32>& windowSize, u32 bits, bool fullscreen,
			bool stencilbuffer, bool vsync, IEventReceiver* receiver);

	/**
	 * Drops irrlicht driver
	 */
	void close();

	/**
	 * Sets clear color
	 * @param color color to be set
	 */
	void setClearColor(SColor color) {
		clearColor = color;
	}

	/**
	 * Begin rendering with default clear color
	 * @return
	 */
	bool beginSceneRender();

	/**
	 * Begin rendering with specified clear color.
	 * @param clearColorValue
	 * @return
	 */
	bool beginSceneRender(SColor clearColorValue);

	/**
	 * Ends scene render
	 */
	void endSceneRender();

private:
	SColor clearColor;
	bool showCursor;
};

typedef Singleton<IrrlichtController> Controller;

#endif /* IRRCONTROLLER_H_ */

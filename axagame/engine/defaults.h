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

#ifndef DEFAULTS_H_
#define DEFAULTS_H_

#include "imports.h"

// Driver Initialization
const int DRIVER_TYPE = EDT_OPENGL;
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
const int ANISOTROPIC_FILTERING = 0;
const int ANTIALIASING = 0;
const bool FULLSCREEN = false;
const bool SHADOWS = true;
const bool TRILINEAR_FILTERING = true;
const bool SHADERS = false;
const bool STENCIL_BUFFER = false;
const bool VSYNC = true;

const int FPS = 60;

#endif /* DEFAULTS_H_ */

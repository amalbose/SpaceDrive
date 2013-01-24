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

#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <irrlicht.h>

extern irr::IrrlichtDevice *irrDevice;
extern irr::video::IVideoDriver *irrDriver;
extern irr::scene::ISceneManager *irrScene;
extern irr::gui::IGUIEnvironment *irrGUI;
extern irr::io::IFileSystem *irrFile;
extern irr::ITimer *irrTimer;

#endif /* GLOBALS_H_ */

/*************************************************************************************
 *   Created on: Jan 25, 2013
 *
 *	SpaceDrive - http://axatrikx.com
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

#ifndef LEVELMAN_H_
#define LEVELMAN_H_

#include <cstring>
#include <string>
#include <sstream>
#include "../engine/imports.h"
#include "../../lib/rapidxml/rapidxml.hpp"
#include "../utils/utils.h"
#include "leveldata.h"

class LevelManager {
public:
	LevelManager(const char* xmlFile);
	void displayData();

private:
	core::array<LevelData*> levelDataVal;
	void parseLevelXML(const char* xmlFile);
};

#endif /* LEVELMAN_H_ */

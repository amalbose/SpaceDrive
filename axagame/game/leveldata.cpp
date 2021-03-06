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

#include "leveldata.h"

LevelData::LevelData() {
}

LevelData::LevelData(std::string name) :
		levelName(name) {
}

LevelData::LevelData(std::string name, core::array<Resource*> resources) :
		levelName(name), resources(resources) {
}

void LevelData::addResource(Resource* resource) {
	resources.push_back(resource);
}

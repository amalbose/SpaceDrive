/*************************************************************************************
 *   Created on: Jan 24, 2013
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

#ifndef LEVEL_H_
#define LEVEL_H_
#include "../engine/imports.h"
#include "../engine/globals.h"
#include "../utils/logger.h"
#include "../engine/constants.h"
#include "levelman.h"
#include "leveldata.h"

class Nodes {
public:
	Nodes(std::string name, IAnimatedMeshSceneNode* aniNode) :
			nodeName(name), node(aniNode) {
	}
	std::string nodeName;
	IAnimatedMeshSceneNode* node;
};

class Level {
public:
	Level(char* name);
	~Level();
	int init();
	int close();

	char* getLevelName();
	void setLevelName(char* name) {
		levelName = name;
	}

	//Events
	bool onKeyPress(int key);
	bool onKeyLift(int key);
	void onMouseMotion(float valueX, float valueY);
	bool onMousePress(int button, int valueX, int valueY);
	void onMouseLift(int button, int valueX, int valueY);
	void onMouseWheel(float direction);

private:
	char* levelName;
	LevelManager* levelMan;
	const char* stateDataFile = STATE_DATA;
	core::array<Nodes*> nodeList;
};

#endif /* LEVEL_H_ */

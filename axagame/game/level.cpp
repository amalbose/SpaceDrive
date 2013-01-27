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

#include "level.h"

Level::Level(char* name) :
		levelName(name) {
	levelMan = new LevelManager(stateDataFile);
}

int Level::init() {
	Logger(INFO) << "Initialized play state";

	LevelData* lvlData = levelMan->getLevelData(levelName);
	core::array<Resource*> lvlRes = lvlData->getResources();
	int resSize = lvlRes.size();
	for (int i = 0; i < resSize; i++) {
		IAnimatedMesh* mesh = irrScene->getMesh(lvlRes[i]->getMesh().c_str());
		IAnimatedMeshSceneNode* node = irrScene->addAnimatedMeshSceneNode(mesh);

		if (node) {
			//node->setMaterialFlag(EMF_LIGHTING, false);
			node->setMaterialTexture(0, irrDriver->getTexture(lvlRes[i]->getTexture().c_str()));
			node->setScale(vector3df(lvlRes[i]->getScale(), lvlRes[i]->getScale(), lvlRes[i]->getScale()));
			node->setPosition(vector3df(0, 0, 0));
		}
	}

	ICameraSceneNode* cam = irrScene->addCameraSceneNode(0, core::vector3df(0.0f, 0.0f, 0.0f),
			core::vector3df(0.0f, 0.0f, 0.0f), -1);
	cam->bindTargetAndRotation(true);
	cam->setPosition(vector3df(0, 10, -5));
	cam->setTarget(vector3df(0, 0, 30));
	vector3df diff = vector3df(0, 0, 0) - vector3df(0, 30, -30);
	ILightSceneNode* light = irrScene->addLightSceneNode(0, vector3df(0.0f, 200.0f, 0.0f),
			SColorf(1.0f, 1.0f, 1.0f, 1.0f), 300.0f);
	ILightSceneNode* ulight = irrScene->addLightSceneNode(0, vector3df(0.0f, -200.0f, 0.0f),
			SColorf(1.0f, 1.0f, 1.0f, 1.0f), 50.0f);
	ILightSceneNode* blight = irrScene->addLightSceneNode(0, vector3df(0.0f, -200.0f, -100.0f),
			SColorf(1.0f, 1.0f, 1.0f, 1.0f), 50.0f);
	return 1;
}
int Level::close() {
	return 1;
}

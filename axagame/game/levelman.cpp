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

#include "levelman.h"

LevelManager::LevelManager(const char* xmlFile) {
	parseLevelXML(xmlFile);
}

LevelData* LevelManager::getLevelData(std::string lvlName) {
	int size = levelDataVal.size();
	for (int i = 0; i < size; i++) {
		if (levelDataVal[i]->getLevelName().compare(lvlName) == 0) {
			return levelDataVal[i];
		}
	}
	Logger(ERROR) << "Could not find level " << lvlName << " from level list.";
	return NULL;
}

void LevelManager::parseLevelXML(const char* xmlFile) {
	std::string xmlString = Utils::getFileContents(xmlFile);
	rapidxml::xml_document<> doc;
	char* cstr = new char[xmlString.size() + 1];  // Create char buffer to store string copy
	strcpy(cstr, xmlString.c_str());  // Copy string into char buffer
	doc.parse<0>(cstr);
	delete[] cstr;
	rapidxml::xml_node<>* cur_node = doc.first_node("axagame");
	cur_node = cur_node->first_node("states")->first_node("state")->first_node("levels")->first_node("level");
	rapidxml::xml_node<>* res_node;

	while (cur_node != NULL) {
		std::string levelName = cur_node->first_node("level-name")->value();
		res_node = cur_node->first_node("resources")->first_node("resource");
		core::array<Resource*> tmpResources;
		while (res_node != NULL) {
			tmpResources.push_back(
					new Resource(res_node->first_node("mesh")->value(), res_node->first_node("node-type")->value(),
							res_node->first_node("texture")->value(), res_node->first_node("resource-name")->value(),
							atoi(res_node->first_node("scale")->value())));
			res_node = res_node->next_sibling();
		}
		levelDataVal.push_back(new LevelData(levelName, tmpResources));
		tmpResources.clear();
		cur_node = cur_node->next_sibling();
	}
}

void LevelManager::displayData() {
	//display level data
	int size = levelDataVal.size();
	for (int i = 0; i < size; i++) { // no of levels
		LevelData* one = levelDataVal[i];
		core::array<Resource*> res = one->getResources();
		int resSize = res.size();
		for (int j = 0; j < resSize; j++) {
			Resource *resOne = res[j];
			std::cout << "=================" << std::endl;
			std::cout << one->getLevelName() << std::endl;
			std::cout << "=================" << std::endl;
			std::cout << resOne->getMesh() << std::endl;
			std::cout << resOne->getName() << std::endl;
			std::cout << resOne->getNodeType() << std::endl;
			std::cout << resOne->getTexture() << std::endl;
			std::cout << resOne->getScale() << std::endl;
			std::cout << "=================" << std::endl;
		}
	}
}

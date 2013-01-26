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

#ifndef LEVELDATA_H_
#define LEVELDATA_H_

#include "../engine/imports.h"
#include <iostream>

class Resource {

public:
	Resource() {

	}
	Resource(std::string mesh, std::string nodeType, std::string texture, std::string name, int scale) :
			mesh(mesh), nodeType(nodeType), texture(texture), name(name), scale(scale) {

	}

	std::string getMesh() const {
		return mesh;
	}

	std::string getNodeType() const {
		return nodeType;
	}

	std::string getTexture() const {
		return texture;
	}

	std::string getName() {
		return name;
	}

	int getScale() const {
		return this->scale;
	}

	void setScale(int scale) {
		this->scale = scale;
	}

private:
	std::string mesh, nodeType, texture, name;
	int scale;
};

class LevelData {
public:
	LevelData();
	LevelData(std::string name);
	LevelData(std::string name, core::array<Resource*> resources);

	std::string getLevelName() { return levelName; }
	void addResource(Resource* resource);
	core::array<Resource*> getResources() {
		return this->resources;
	}

private:
	core::array<Resource*> resources;
	std::string levelName;
};

#endif /* LEVELDATA_H_ */

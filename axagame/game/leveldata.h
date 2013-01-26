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

struct LevelScale {
	int xVal, yVal, zVal;
};

class Resource {

public:
	Resource() {

	}
	Resource(std::string mesh, std::string nodeType, std::string texture, std::string name) :
			mesh(mesh), nodeType(nodeType), texture(texture), name(name) {

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

	LevelScale getScale() const {
		return this->scale;
	}

	void setScale(const LevelScale& scale) {
		this->scale = scale;
	}

	void setScale(int x, int y, int z) {
		this->scale.xVal = x;
		this->scale.yVal = y;
		this->scale.zVal = z;
	}

private:
	std::string mesh, nodeType, texture, name;
	LevelScale scale;
};

class LevelData {
public:
	LevelData();
	LevelData(std::string name);
	LevelData(core::array<Resource*> resources);
	void addResource(Resource* resource);
	core::array<Resource*> getResources() {
		return this->resources;
	}

private:
	core::array<Resource*> resources;
	std::string levelName;
};

#endif /* LEVELDATA_H_ */

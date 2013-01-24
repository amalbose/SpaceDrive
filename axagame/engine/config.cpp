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

#include "config.h"

ConfigClass::ConfigClass() :
		configFile(CONFIG_FILE) {
}

int ConfigClass::initConfig() {
	return resetConfig();
}

int ConfigClass::resetConfig() {

	//Giving default values
	driverType = (E_DRIVER_TYPE) DRIVER_TYPE;
	screenWidth = SCREEN_WIDTH;
	screenHeight = SCREEN_HEIGHT;
	fullscreen = FULLSCREEN;
	shadows = SHADOWS;
	shaders = SHADERS;
	antiAliasing = ANTIALIASING;
	anisotropicFiltering = ANISOTROPIC_FILTERING;
	trilinearFiltering = TRILINEAR_FILTERING;
	stencil = STENCIL_BUFFER;
	vsync = VSYNC;

	return 0;
}

int ConfigClass::readConfig() {
	Properties prop(configFile);

	//getting driver
	std::string tmp = prop.getValue("DRIVER_TYPE");
	if (!tmp.empty()) {
		driverType = (E_DRIVER_TYPE) getDriverType(tmp);
	}
	//screen width
	tmp = prop.getValue("SCREEN_WIDTH");
	if (!tmp.empty()) {
		screenWidth = atoi(tmp.c_str());
	}
	//screen height
	tmp = prop.getValue("SCREEN_HEIGHT");
	if (!tmp.empty()) {
		screenHeight = atoi(tmp.c_str());
	}
	//full screen
	tmp = prop.getValue("FULLSCREEN");
	if (!tmp.empty()) {
		fullscreen = getBool(tmp);
	}
	//stencil
	tmp = prop.getValue("STENCIL_BUFFER");
	if (!tmp.empty()) {
		stencil = getBool(tmp);
	}
	//vsync
	tmp = prop.getValue("VSYNC");
	if (!tmp.empty()) {
		vsync = getBool(tmp);
	}
	//bits
	tmp = prop.getValue("BITS");
	if (!tmp.empty()) {
		bits = atoi(tmp.c_str());
	}
	return 0;
}

int ConfigClass::getDriverType(std::string type) {
	int dType = 0;
	if (type.find("OPENGL") != std::string::npos) {
		dType = EDT_OPENGL;
	} else if (type.find("DIRECTX") != std::string::npos) {
		dType = EDT_DIRECT3D9;
	}
	return dType;
}

bool ConfigClass::getBool(std::string boolVal) {
	if ((boolVal.find("TRUE") != std::string::npos) || (boolVal.find("true") != std::string::npos)) {
		return true;
	} else {
		return false;
	}
}

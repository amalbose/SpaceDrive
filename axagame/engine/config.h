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
#ifndef CONFIG_H_
#define CONFIG_H_

#include "imports.h"
#include "singleton.h"
#include "defaults.h"
#include "constants.h"
#include "../utils/properties.h"
#include <string>

class ConfigClass {
public:
	ConfigClass();
	int initConfig();
	void closeConfig();
	int resetConfig();

	int readConfig();
	int writeConfig();

	E_DRIVER_TYPE getDriverType() const { return driverType; }

	int getAnisotropicFiltering() const {		return anisotropicFiltering;	}

	int getAntiAliasing() const {		return antiAliasing;	}

	int getBits() const {		return bits;	}

	char* getConfigFile() const {		return configFile;	}

	bool getFullscreen() const {		return fullscreen;	}

	int getScreenHeight() const {		return screenHeight;	}

	int getScreenWidth() const {		return screenWidth;}

	bool getStencil() const {		return stencil;	}

	bool getVsync() const {		return vsync;	}

private:
	//irrlicht driver arguments
	int screenWidth, screenHeight, anisotropicFiltering, antiAliasing, bits;
	E_DRIVER_TYPE driverType;
	bool fullscreen, shadows, trilinearFiltering, shaders, stencil, vsync;
	char * configFile;
	int getDriverType(std::string type);
	bool getBool(std::string boolVal);
};

typedef Singleton<ConfigClass> Config;

#endif /* CONFIG_H_ */

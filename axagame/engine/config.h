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

/**
 * Manages the settings for Irrlicht Driver.
 */
class ConfigClass {
public:
	/**
	 * Constructor to set configuration file.
	 */
	ConfigClass();
	/**
	 * Initializes configuration.
	 * @return 1 or 0 based on successful initialization.
	 */
	int initConfig();

	/**
	 * Closes configuration.
	 */
	void closeConfig();

	/**
	 * Resets configuration.
	 * @return 0 or 1 based on successful reset.
	 */
	int resetConfig();

	/**
	 * Reads the configuration file.
	 * @return 0 or 1 based on successful execution.
	 */
	int readConfig();

	/**
	 * Writes the current configuration to file.
	 * @return 0 or 1 based on successful execution.
	 */
	int writeConfig();

	/**
	 * Returns the type of Driver (E_DRIVER_TYPE)
	 * @return the type of Driver (E_DRIVER_TYPE)
	 */
	E_DRIVER_TYPE getDriverType() const { return driverType; }

	/**
	 * Returns anisotropicfiltering value.
	 * @return
	 */
	int getAnisotropicFiltering() const {		return anisotropicFiltering;	}

	/**
	 * Returns AntiAliasing value.
	 * @return AntiAliasing value.
	 */
	int getAntiAliasing() const {		return antiAliasing;	}

	/**
	 * Gets bit rate.
	 * @return bit rate
	 */
	int getBits() const {		return bits;	}

	/**
	 * Return the configuration file
	 * @return configuration file.
	 */
	char* getConfigFile() const {		return configFile;	}

	/**
	 * Whether fullscreen or not.
	 * @return TRUE if set to fullscreen or FALSE otherwise.
	 */
	bool getFullscreen() const {		return fullscreen;	}

	/**
	 * Gets the screen height.
	 * @return screen height
	 */
	int getScreenHeight() const {		return screenHeight;	}

	/**
	 * Gets the screen width.
	 * @return screen width
	 */
	int getScreenWidth() const {		return screenWidth;}

	/**
	 * Whether stencil set or not.
	 * @return
	 */
	bool getStencil() const {		return stencil;	}

	/**
	 * Whether vsync is set or not.
	 * @return
	 */
	bool getVsync() const {		return vsync;	}

private:
	//irrlicht driver arguments
	int screenWidth, screenHeight, anisotropicFiltering, antiAliasing, bits;
	E_DRIVER_TYPE driverType;
	bool fullscreen, shadows, trilinearFiltering, shaders, stencil, vsync;
	char * configFile;

	/**
	 * Gets the driver type based on string input
	 * @param type string value for driver type
	 * @return
	 */
	int getDriverType(std::string type);

	/**
	 * Gets boolean value from string value.
	 * @param boolVal
	 * @return
	 */
	bool getBool(std::string boolVal);
};

/**
 * Singleton class for ConfigClass.
 */
typedef Singleton<ConfigClass> Config;

#endif /* CONFIG_H_ */

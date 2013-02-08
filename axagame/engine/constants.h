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

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

/**
 * Game version number.
 */
#define GAME_VERSION  "v0.1.1"

/**
 * The name of the game.
 */
#define GAME_NAME  L"SpaceDrive"

/**
 * The log file name.
 */
#define LOG_NAME  "spacedrive.log"

/**
 * The file path for configuration property file which holds the Irrlicht device settings.
 */
#define CONFIG_FILE "data/config.prop"

/**
 * File path for states xml file for holding level resource details.
 */
#define STATE_DATA "data/states-data.xml"

/**
 * File Path for key configuration file.
 */
#define KEY_CONFIG "data/keys.config"

//states
/**
 * The PLAYSTATE refering to game playing state.
 */
#define STATE_PLAY "PLAYSTATE"

#endif /* CONSTANTS_H_ */

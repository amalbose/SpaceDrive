/*************************************************************************************
 *   Created on: Jan 27, 2013
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

#ifndef ACTION_H_
#define ACTION_H_

#include <map>
#include <iostream>
#include "../engine/imports.h"
#include "../engine/constants.h"
#include "../engine/event.h"
#include "../utils/utils.h"
#include "../utils/logger.h"

enum Actions {
	ACCELERATE, DECELERATE, FORWARD, BACKWARD, LEFT, RIGHT, BRAKE
};

/**
 * Action class manages the mapping of actions to keys.
 */
class Action {
public:
	Action();

	/**
	 * Gets the value for the key
	 * @param key
	 * @return the value for the given key
	 */
	std::string getValue(const char* key);

	/**
	 * Gets the key for the corresponding Action type
	 * @param actionType the action type.
	 * @return
	 */
	int getKey(Actions actionType);

private:
	/**
	 * Collects data from config file(KEY_CONFIG).
	 */
	void collectData();

	/**
	 * Sets the configuration from the data collected from config file (KEY_CONFIG).
	 */
	void getConfiguration();

	/**
	 * Gets the action string for given action type.
	 * @param actionType the action type
	 * @return the action in string form.
	 */
	std::string getAction(Actions actionType);

	std::ifstream* keyFile;
	char* keyConfigFile = KEY_CONFIG;
	std::map<std::string,std::string> keyList;
	std::map<Actions, irr::EKEY_CODE> keyConfig;
};

#endif /* ACTION_H_ */

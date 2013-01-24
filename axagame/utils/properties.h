/*************************************************************************************
 *   Created on: Jan 19, 2013
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

#ifndef PROPERTIES_H_
#define PROPERTIES_H_

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "logger.h"

class Properties {
public:
	Properties(char *fileName);
	std::string getValue(char* key);

private:
	Properties();
	void populateProps();
	std::map<std::string, std::string> propertyList;
	std::ifstream* propFile;
};

#endif /* PROPERTIES_H_ */

/*************************************************************************************
 *   Created on: Jan 16, 2013
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

#ifndef UTILS_H_
#define UTILS_H_

#include <fstream>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

#include "logger.h"

class Utils {
public:
	Utils();
	static std::string getCurrentTime();

	static std::string getFileContents(const char *filename);

	// trim from start
	static inline std::string &ltrim(std::string &s) {
	        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	        return s;
	}

	// trim from end
	static inline std::string &rtrim(std::string &s) {
	        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	        return s;
	}

	// trim from both ends
	static inline std::string &trim(std::string &s) {
	        return ltrim(rtrim(s));
	}
};

#endif /* UTILS_H_ */

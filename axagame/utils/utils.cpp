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

#include "utils.h"

Utils::Utils() {
	// TODO Auto-generated constructor stub

}

std::string Utils::getCurrentTime() {
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];
	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "%c", timeinfo);
	std::string finalString = buffer;
	return finalString;
}

std::string Utils::getFileContents(const char *filename) {
	std::ifstream in(filename, std::ios::in | std::ios::binary);
	if (in) {
		std::ostringstream contents;
		contents << in.rdbuf();
		in.close();
		return (contents.str());
	} else {
		Logger(ERROR) << "Could not open file " << filename;
		return "";
	}
}

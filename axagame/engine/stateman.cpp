/*************************************************************************************
 *   Created on: Jan 20, 2013
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

#include "stateman.h"

StateManager::StateManager() {
	//Adding all states
	Play* playState = new Play();
	stateList.push_back(playState);
}

StateManager::~StateManager() {
	// TODO Auto-generated destructor stub
}

void StateManager::setCurrentState(irr::core::stringc strName) {
	// Local variables.
	irr::u32 i = 0;
	bool bFound = false;
	// For each state in the list, check if names match.
	while (bFound == false && i < stateList.size()) {
		if (stateList[i]->getStateName().equals_ignore_case(strName)){
			bFound = true;
		}
		else
			i++;
	}
	// If exists, release current state.
	/*if (currentState != NULL)
		currentState->close();*/

	// If state was found, set as current and initialize.
	if (bFound == true) {
		currentState = stateList[i];
		currentState->init();
	}
}

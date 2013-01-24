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

#ifndef STATE_H_
#define STATE_H_

#include <irrlicht.h>

class State {

public:
	irr::core::stringc getStateName() { return stateName; }
	virtual int init() { return 1; }
	virtual int close() { return 1; }

	virtual ~State() { }

	virtual bool onKeyPress(int key) { return false; }
	virtual bool onKeyLift(int key) { return false; }
	virtual void onMouseMotion(float valueX, float valueY) { }
	virtual bool onMousePress(int button, int valueX, int valueY) { return false; }
	virtual void onMouseLift(int button, int valueX, int valueY) { }
//		virtual void onMouseWheel(float direction) { }

	virtual void update() { }
	virtual void updateRender() { }
	virtual void render(float interpolation) { }
	void setStateName(irr::core::stringc name) { stateName = name; }
private:
	irr::core::stringc stateName;
};



#endif /* STATE_H_ */

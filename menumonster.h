/////////////////////////////////////////////////////////////////////////////////////
//Copyright (C) 2012 Benjamin Quach
//
//This file is part of garbage monsters
//
//garbage monsters is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//////////////////////////////////////////////////////////////////////////////////////

#ifndef _MENUMONSTER_H_
#define _MENUMONSTER_H_

#pragma once

#include "SDL.h"
#include "SDL_opengl.h"
#include "CEGUI.h"

using namespace CEGUI;

//shows all the monsters and stats of them
class CMonsterMenu
{
public:
	CMonsterMenu(CEGUI::Window *parent);
	~CMonsterMenu();

	void setVisible(bool visible);
	bool getVisible();

private:
	FrameWindow *menu;
	Window *parent;
	//buttons
	Window *close;
	//only six monsters allowed
	Window *monster1;
	Window *monster2;
	Window *monster3;
	Window *monster4;
	Window *monster5;
	Window *monster6;
};

#endif
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

#ifndef _MENUGAME_H_
#define _MENUGAME_H_

#pragma once

#include "SDL.h"
#include "SDL_opengl.h"
#include "CEGUI.h"
#include "menumonster.h"

using namespace CEGUI;
//Class for the in game menu
//Opened from the world screen
//Shows important sub menus
class CGameMenu
{
public:
	//Constructor
	CGameMenu(Window *root);
	~CGameMenu();

	void setVisible(bool visible);
	bool getVisible();
	bool openMonsterMenu(const CEGUI::EventArgs&);

private:
	//member variables
	Window *root;
	FrameWindow *menu;
	Window *encyclopedia;
	Window *monsters;
	CMonsterMenu *monster_menu;
	Window *garbadges;
	Window *pack;
	Window *laptop;
	Window *poacher;
	Window *save;
};

#endif
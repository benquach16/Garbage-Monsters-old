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

#ifndef _MONSTERSTATUS_H_
#define _MONSTERSTATUS_H_

#pragma once

#include "SDL.h"
#include "CEGUI.h"
#include "monster.h"

using namespace CEGUI;

//for use in battlemanager only
//shows information such as level,exp,health
class CMonsterStatus
{
public:
	CMonsterStatus(Window *root, CMonster *monster, bool enemy);
	~CMonsterStatus();

private:
	CEGUI::Window *root;
	CEGUI::FrameWindow *main;
	CEGUI::String *name;
	CEGUI::String *health;
	CEGUI::String *level;

	CMonster *monster;
	bool enemy;

};

#endif
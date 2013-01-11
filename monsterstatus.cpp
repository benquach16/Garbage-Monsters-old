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

#include "stdafx.h"
#include "monsterstatus.h"

#define ENEMY_X 100
#define ENEMY_Y 50
#define FRIEND_X 500
#define FRIEND_Y 300

CMonsterStatus::CMonsterStatus(Window *root, CMonster *monster, bool enemy) : monster(monster) , root(root) , enemy(enemy)
{
	main = (FrameWindow*)WindowManager::getSingleton().createWindow("TaharezLook/FrameWindow");
	//enemy status is in a different spot
	if(enemy)
	{
		main->setPosition(UVector2(UDim(0,ENEMY_X),UDim(0,ENEMY_Y)));
	}
	else
	{
		main->setPosition(UVector2(UDim(0,FRIEND_X), UDim(0,FRIEND_Y)));
	}
	main->setSize(UVector2(UDim(0,300),UDim(0,150)));
	main->setDragMovingEnabled(false);
	main->setTitleBarEnabled(false);
	
	root->addChildWindow(main);
}

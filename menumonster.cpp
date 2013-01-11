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
#include "menumonster.h"

CMonsterMenu::CMonsterMenu(CEGUI::Window *parent) : parent(parent)
{
	//more CEGUI stuff
	menu = (FrameWindow*)CEGUI::WindowManager::getSingleton().createWindow("TaharezLook/FrameWindow", "monstermenu");
	menu->setPosition(UVector2(UDim(0,0), UDim(0,0)));
	menu->setSize(CEGUI::UVector2(CEGUI::UDim(0,800),CEGUI::UDim(0,600)));
	menu->setDragMovingEnabled(false);
	menu->setAlwaysOnTop(true);
	parent->addChildWindow(menu);

	monster1 = WindowManager::getSingleton().createWindow("TaharezLook/FrameWindow", "window1");
	monster1->setPosition(UVector2(UDim(0,20),UDim(0,20)));
	monster1->setSize(UVector2(UDim(0,380), UDim(0, 180)));
	menu->addChildWindow(monster1);

	

}

//self explanitory
void CMonsterMenu::setVisible(bool visible)
{
	menu->setVisible(visible);
}

bool CMonsterMenu::getVisible()
{
	return menu->isVisible();
}
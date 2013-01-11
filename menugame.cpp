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
#include "menugame.h"

CGameMenu::CGameMenu(Window *root) : root(root)
{
	//Lots of CEGUI initialization
	monster_menu = new CMonsterMenu(root);
	monster_menu->setVisible(false);

	//create base menu
	menu = (FrameWindow*)CEGUI::WindowManager::getSingleton().createWindow("TaharezLook/FrameWindow", "menu");
	menu->setPosition(UVector2(UDim(0.7,0), UDim(0,0)));
	menu->setSize(CEGUI::UVector2(CEGUI::UDim(0,300),CEGUI::UDim(0,600)));
	menu->setDragMovingEnabled(false);
	root->addChildWindow(menu);


	//encyclopedia button
	//most button sare self explanitory
	encyclopedia = CEGUI::WindowManager::getSingleton().createWindow("TaharezLook/Button","encyclopedi");  // Create Window
	encyclopedia->setPosition(CEGUI::UVector2(CEGUI::UDim(0.05,0),CEGUI::UDim(0.1,0)));
	encyclopedia->setSize(CEGUI::UVector2(CEGUI::UDim(0,200),CEGUI::UDim(0,40)));
	encyclopedia->setText("Encyclopedia");
	menu->addChildWindow(encyclopedia);

	monsters = WindowManager::getSingleton().createWindow("TaharezLook/Button", "monsters");
	monsters->setPosition(CEGUI::UVector2(CEGUI::UDim(0.05,0),CEGUI::UDim(0.2,0)));
	monsters->setSize(CEGUI::UVector2(CEGUI::UDim(0,200),CEGUI::UDim(0,40)));
	monsters->setText("Garbage Monsters");
	menu->addChildWindow(monsters);
	monsters->subscribeEvent(CEGUI::PushButton::EventClicked, Event::Subscriber(&CGameMenu::openMonsterMenu,this));

	garbadges = WindowManager::getSingleton().createWindow("TaharezLook/Button", "garbadge");
	garbadges->setPosition(CEGUI::UVector2(CEGUI::UDim(0.05,0),CEGUI::UDim(0.3,0)));
	garbadges->setSize(CEGUI::UVector2(CEGUI::UDim(0,200),CEGUI::UDim(0,40)));
	garbadges->setText("Garbadges");
	menu->addChildWindow(garbadges);

	pack = WindowManager::getSingleton().createWindow("TaharezLook/Button", "pack");
	pack->setPosition(CEGUI::UVector2(CEGUI::UDim(0.05,0),CEGUI::UDim(0.4,0)));
	pack->setSize(CEGUI::UVector2(CEGUI::UDim(0,200),CEGUI::UDim(0,40)));
	pack->setText("Backpack");
	menu->addChildWindow(pack);

	laptop = WindowManager::getSingleton().createWindow("TaharezLook/Button", "laptop");
	laptop->setPosition(CEGUI::UVector2(CEGUI::UDim(0.05,0),CEGUI::UDim(0.5,0)));
	laptop->setSize(CEGUI::UVector2(CEGUI::UDim(0,200),CEGUI::UDim(0,40)));
	laptop->setText("Laptop");
	menu->addChildWindow(laptop);

	poacher = WindowManager::getSingleton().createWindow("TaharezLook/Button", "poacher");
	poacher->setPosition(CEGUI::UVector2(CEGUI::UDim(0.05,0),CEGUI::UDim(0.6,0)));
	poacher->setSize(CEGUI::UVector2(CEGUI::UDim(0,200),CEGUI::UDim(0,40)));
	poacher->setText("Poacher");
	menu->addChildWindow(poacher);

	save = WindowManager::getSingleton().createWindow("TaharezLook/Button", "save");
	save->setPosition(CEGUI::UVector2(CEGUI::UDim(0.05,0),CEGUI::UDim(0.7,0)));
	save->setSize(CEGUI::UVector2(CEGUI::UDim(0,200),CEGUI::UDim(0,40)));
	save->setText("Save");
	menu->addChildWindow(save);

}

bool CGameMenu::openMonsterMenu(const CEGUI::EventArgs&)
{
	monster_menu->setVisible(true);
	return true;
}

void CGameMenu::setVisible(bool visible)
{
	menu->setVisible(visible);
}

bool CGameMenu::getVisible()
{
	return menu->isVisible();
}
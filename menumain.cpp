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
#include "menumain.h"

CMainMenu::CMainMenu() : selected(0)
{
	CEGUI::ImagesetManager::getSingleton().createFromImageFile("BackgroundImage", "/menu/garbagemon.tga");
	WindowManager &manager = WindowManager::getSingleton();

	background =  manager.createWindow( "TaharezLook/StaticImage",
		"background" ) ;

	background->setPosition( UVector2( cegui_reldim(0), cegui_reldim(0) ) ) ;
	background->setSize( UVector2( cegui_reldim(1), cegui_reldim(1) ) ) ;

	background->setProperty( "FrameEnabled", "false" ) ;
	background->setProperty( "BackgroundEnabled", "false" ) ;

	background->setProperty( "Image", "set:BackgroundImage image:full_image" ) ;

	System::getSingleton().setGUISheet( background ) ;
	

	fWnd = (FrameWindow*)manager.createWindow( "TaharezLook/FrameWindow", "testWindow" );
	fWnd->setPosition( UVector2( cegui_reldim(0.4f), cegui_reldim(0.5f) ) ) ;
	fWnd->setMaxSize( UVector2( cegui_reldim(1.0f), cegui_reldim(1.0f) ) ) ;
	fWnd->setSize( UVector2( cegui_reldim(0.2f), cegui_reldim( 0.2f) ) ) ;
	fWnd->setText( "" ) ;
	fWnd->setDragMovingEnabled(false);
	background->addChildWindow(fWnd);

	start = CEGUI::WindowManager::getSingleton().createWindow("TaharezLook/Button","startButton");  // Create Window
	start->setPosition(CEGUI::UVector2(CEGUI::UDim(0.15,0),CEGUI::UDim(0.2,0)));
	start->setSize(CEGUI::UVector2(CEGUI::UDim(0,100),CEGUI::UDim(0,20)));
	start->setText("Start");
	fWnd->addChildWindow(start);
	button_list.push_back(start);

	quit = CEGUI::WindowManager::getSingleton().createWindow("TaharezLook/Button", "quitButton");
	quit->setPosition(UVector2(UDim(0.15,0), UDim(0.5,0)));
	quit->setSize(CEGUI::UVector2(CEGUI::UDim(0,100),CEGUI::UDim(0,20)));
	quit->setText("Quit");
	fWnd->addChildWindow(quit);
	button_list.push_back(quit);


}

void CMainMenu::setVisible(bool visible)
{
	background->setVisible(visible);
}

bool CMainMenu::getVisible()
{
	background->isVisible();
}


Window *CMainMenu::getStartButton()
{
	return start;
}

Window *CMainMenu::getQuitButton()
{
	return quit;
}

std::vector<Window*> CMainMenu::getButtons()
{
	return button_list;
}

int CMainMenu::getSelectedButton()
{
	return selected;
}

void CMainMenu::setSelectedButton(int selected)
{
	
	if(button_list.size() <= selected)
	{
		//selected went over
		selected = 0;

	}
	this->selected = selected;
}
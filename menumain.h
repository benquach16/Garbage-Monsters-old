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

#ifndef _MENUMAIN_H_
#define _MENUMAIN_H_

#pragma once

#include "SDL.h"
#include "CEGUI.h"
#include "RendererModules/OpenGL/CEGUIOpenGLRenderer.h"

using namespace CEGUI;
//Main menu
//You can click to start or load game
class CMainMenu
{
public:
	//Constructor
	CMainMenu();
	~CMainMenu();

	//self explanitory
	void setVisible(bool visible);
	bool getVisible();

	//return funcs
	Window *getStartButton();
	Window *getQuitButton();
	std::vector<Window*> getButtons();
	int getSelectedButton();
	void setSelectedButton(int selection);

private:
	CEGUI::Window *start;
	CEGUI::Window *quit;
	CEGUI::Window *background;
	std::vector<Window*> button_list;
	int selected;
	FrameWindow* fWnd;
};

#endif
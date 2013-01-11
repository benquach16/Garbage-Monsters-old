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

#ifndef _INIT_H_
#define _INIT_H_

#include "SDL.h"
#include "SDL_opengl.h"
#include "CEGUI.h"
#include "RendererModules/OpenGL/CEGUIOpenGLRenderer.h"
#include "gl/gl.h"

#include "injecthandler.h"
#include "menumain.h"
#include "worldmanager.h"

//sadly, sdl does not use namespaces
using namespace std;
using namespace CEGUI;

class CInit
{
public:
	//constructor
	CInit();
	~CInit();

	void loop();
	//run in the world map
	void worldLoop();
	void setupCEGUI();
	//start button pressed
	bool start(const CEGUI::EventArgs&);
private:
	::SDL_Surface *screen;
	CEGUI::WindowManager *manager;
	CInjectHandler *receiver;
	CMainMenu *mainmenu;
	CWorldManager *world_manager;
	bool quit;
	bool w_quit;
	bool ingame;

	CEGUI::Window *startr;
	CEGUI::Window *quitr;

	FrameWindow* fWnd;
};

#endif
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

#ifndef _INJECTHANDLER_H_
#define _INJECTHANDLER_H_

#pragma once

#include "SDL.h"
#include "CEGUI.h"
#include "RendererModules/OpenGL/CEGUIOpenGLRenderer.h"
#include "gl/gl.h"

class CInjectHandler
{
public:
	CInjectHandler();
	~CInjectHandler();
	void onEvent(SDL_Event event);
	bool getKeyPressed(SDLKey key);
	bool getKeyReleased(SDLKey key);
	void injectMouseLButton();
	void injectMouseRButton();
	

private:
	bool l_mouse;
};

#endif
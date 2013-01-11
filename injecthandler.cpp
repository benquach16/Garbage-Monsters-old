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
#include "injecthandler.h"

CInjectHandler::CInjectHandler()
{

}

CInjectHandler::~CInjectHandler()
{

}

void CInjectHandler::injectMouseLButton()
{
	CEGUI::System::getSingleton().injectMouseButtonDown( CEGUI::LeftButton ) ;
}

void CInjectHandler::injectMouseRButton()
{

}

bool CInjectHandler::getKeyPressed(SDLKey key)
{
	Uint8 *keystate = SDL_GetKeyState(NULL);
	if(keystate[key])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CInjectHandler::getKeyReleased(SDLKey key)
{
	
}

void CInjectHandler::onEvent(SDL_Event event)
{
	::SDL_PollEvent(&event);
	switch(event.type)
	{
	case SDL_KEYUP:
		{

		}
		break;
		// Mouse section:
	
	case SDL_MOUSEMOTION:
		// We inject the mouse position directly here:
		CEGUI::System::getSingleton().injectMousePosition(
			static_cast<float>( event.motion.x ), static_cast<float>( event.motion.y ) ) ;
		break;

	case SDL_MOUSEBUTTONDOWN:
		{
			if(event.button.button == SDL_BUTTON_LEFT)
			{
				CEGUI::System::getSingleton().injectMouseButtonDown(CEGUI::LeftButton);
			}
			break;
		}

	case SDL_MOUSEBUTTONUP:
		{
			if(event.button.button == SDL_BUTTON_LEFT)
			{
				CEGUI::System::getSingleton().injectMouseButtonUp(CEGUI::LeftButton);
			}
		}
		break ;
	}
}
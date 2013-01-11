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

#ifndef _WORLDMANAGER_H_
#define _WORLDMANAGER_H_

#pragma once

#include "object.h"
#include "person.h"
#include "player.h"
#include "vector"
#include "battlemanager.h"
#include "menugame.h"
#include "injecthandler.h"
#include "SDL.h"
#include "SDL_opengl.h"
#include "CEGUI.h"
#include "glimageloader.h"
#include "image.h"
#include "stdio.h"


using namespace CEGUI;


//manages in world sequences
class CWorldManager
{
public:
	CWorldManager(SDL_Surface *screen, CInjectHandler *receiver);
	~CWorldManager();
	void loop();
	//loops through all the people
	void runPeople();
	bool getExit();
	bool getCollision(CObject *target1, CObject *target2);
	//generates a battle between two persons
	bool createBattle(CPerson *player, CPerson *enemy);
	//player control fnction
	void playerControl(SDL_Event event);
private:

	std::vector<CObject*> object_manager;
	//stores all person objects
	std::vector<CPerson*> person_manager;
	std::vector<CBattleManager*> no_battles;
	CInjectHandler *receiver;
	CPlayer *player;	//main player object
	FrameWindow *root;

	CGameMenu *game_menu;

	bool in_battle;
	bool in_menu;
	bool exit;

	::SDL_Surface *background;
	SDL_Surface *screen;
	GLuint image;
	CImage *test;


};

#endif
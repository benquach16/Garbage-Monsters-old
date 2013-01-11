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

#ifndef _BATTLEMANAGER_H_
#define _BATTLEMANAGER_H_

#pragma once

#include "image.h"
#include "monster.h"
#include "person.h"
#include "player.h"
#include "monsterstatus.h"
#include "inventorymanager.h"
#include "SDL.h"
#include "SDL_opengl.h"
#include "CEGUI.h"

using namespace CEGUI;
//main object for dealing with combat sequences

class CBattleManager
{
public:
	//Constructor
	CBattleManager(CPerson *player, CPerson *enemy, Window *root);
	~CBattleManager();

	//Main loop function, called from the primary game loop
	void run();
	//Renders the ui for combat, hiding everything in the main world
	void render();
	//constantly checks if the enemy or player still has creatures left to play
	void checkMonstersLeft();
	//not called by this object
	bool inBattle();

	//CEGUI event functions
	bool useFightButton(CEGUI::EventArgs&);
	bool useMonsterButton(EventArgs&);
	bool useEscapeButton(const EventArgs&);
	bool useItemButton(EventArgs&);
	void changeMonster();

	//deleteion code
	void drop();
private:
	//monsters currently in play
	CMonster *enemy_monster;
	CMonster *friendly_monster;

	CPerson *player;
	CPerson *enemy;
	
	//images
	CImage *bkg;
	CImage *enemy_monster_sprite;
	CImage *friendly_monster_sprite;

	//general ui stuff
	CMonsterStatus *friendly_monster_status;
	CMonsterStatus *enemy_monster_status;
	Window *root;
	CEGUI::FrameWindow *combat_wind;
	FrameWindow *combat_options;
	Window *status;
	Window *fight;
	Window *monsters;
	Window *item;
	Window *escape;
	Window *friend_status;
	Window *enemy_status;

	bool in_battle;
	bool player_turn;
	bool encounter;

	
};

#endif
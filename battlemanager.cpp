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
#include "battlemanager.h"

#define ENEMY_X 480
#define ENEMY_Y 50
#define FRIEND_X 50
#define FRIEND_Y 300

CBattleManager::CBattleManager(CPerson *player, CPerson *enemy, Window *root) : player(player), enemy(enemy), in_battle(true), 
	root(root), encounter(false), enemy_monster(0), friendly_monster(0), enemy_monster_status(0), friendly_monster_status(0)
{
	if(enemy == 0)
	{
		//no enemy poacher data
		//must be wild encounter
		encounter = true;
	}
	
	//create lots of cegui windows
	combat_wind = (FrameWindow*)CEGUI::WindowManager::getSingleton().createWindow("TaharezLook/FrameWindow", "combat");
	combat_wind->setPosition(UVector2(UDim(0,0), UDim(0.7,0)));
	combat_wind->setSize(CEGUI::UVector2(CEGUI::UDim(0,800),CEGUI::UDim(0,200)));
	combat_wind->setDragMovingEnabled(false);
	combat_wind->setCloseButtonEnabled(false);
	combat_wind->setTitleBarEnabled(false);
	combat_wind->setSizingBorderThickness(0);
	root->addChildWindow(combat_wind);

	combat_options = (FrameWindow*)CEGUI::WindowManager::getSingleton().createWindow("TaharezLook/FrameWindow", "options");
	combat_options->setPosition(UVector2(UDim(0.5,0), UDim(0,25)));
	combat_options->setSize(CEGUI::UVector2(CEGUI::UDim(0,400),CEGUI::UDim(0,200)));
	combat_options->setDragMovingEnabled(false);
	combat_options->setCloseButtonEnabled(false);
	combat_options->setTitleBarEnabled(false);
	combat_wind->addChildWindow(combat_options);

	status = CEGUI::WindowManager::getSingleton().createWindow("TaharezLook/StaticText", "status");
	status->setPosition(UVector2(UDim(0,0), UDim(0,25)));
	status->setSize(CEGUI::UVector2(CEGUI::UDim(0,400),CEGUI::UDim(0,150)));
	status->setText("Enemy Poacher wants to fight");
	combat_wind->addChildWindow(status);

	fight = CEGUI::WindowManager::getSingleton().createWindow("TaharezLook/Button", "fight");
	fight->setPosition(UVector2(UDim(0,10), UDim(0,0)));
	fight->setSize(CEGUI::UVector2(CEGUI::UDim(0,180),CEGUI::UDim(0,40)));
	fight->setText("Fight");
	combat_options->addChildWindow(fight);
	
	monsters = CEGUI::WindowManager::getSingleton().createWindow("TaharezLook/Button", "monster");
	monsters->setPosition(UVector2(UDim(0,10), UDim(0.3,0)));
	monsters->setSize(CEGUI::UVector2(CEGUI::UDim(0,180),CEGUI::UDim(0,40)));
	monsters->setText("Monsters");
	combat_options->addChildWindow(monsters);

	item = CEGUI::WindowManager::getSingleton().createWindow("TaharezLook/Button", "item");
	item->setPosition(UVector2(UDim(0.5,0), UDim(0,0)));
	item->setSize(CEGUI::UVector2(CEGUI::UDim(0,180),CEGUI::UDim(0,40)));
	item->setText("Pack");
	combat_options->addChildWindow(item);

	escape = CEGUI::WindowManager::getSingleton().createWindow("TaharezLook/Button", "esc");
	escape->setPosition(UVector2(UDim(0.5,0), UDim(0.3,0)));
	escape->setSize(CEGUI::UVector2(CEGUI::UDim(0,180),CEGUI::UDim(0,40)));
	escape->setText("Run");
	escape->subscribeEvent(CEGUI::PushButton::EventClicked,CEGUI::Event::Subscriber(&CBattleManager::useEscapeButton,this));
	combat_options->addChildWindow(escape);



	bkg = new CImage(SDL_LoadBMP("res/2d/bkg/battle.bmp"),0,0);
	checkMonstersLeft();
	//now that we've ensured that something is on the field
	//display images
	if(in_battle)
	{
		enemy_monster_sprite = new CImage(SDL_LoadBMP(enemy->getMonsters()[0]->getBattleImageFront()), ENEMY_X,ENEMY_Y);
		friendly_monster_sprite = new CImage(SDL_LoadBMP(player->getMonsters()[0]->getBattleImageFront()),FRIEND_X,FRIEND_Y);

		friendly_monster_status = new CMonsterStatus(root, player->getMonsters()[0],false);
	}
}




CBattleManager::~CBattleManager()
{
	combat_wind->setVisible(false);
}

void CBattleManager::render()
{
	bkg->render();
	enemy_monster_sprite->render();
	friendly_monster_sprite->render();
}

void CBattleManager::run()
{
	render();
	checkMonstersLeft();

	if(in_battle == true)
	{
		//start combat

		if(friendly_monster->getAttackSpd() < enemy_monster->getAttackSpd())
		{
			player_turn = false;
		}
		else
			player_turn = true;

		if(player_turn == true)
		{
			//wait for player input
		}
		else
		{
			//do ai

		}
	}
}

bool CBattleManager::useEscapeButton(const CEGUI::EventArgs&)
{
	//attempt to escape from battle
	if(encounter == true)
	{
		//roll speed to escape
		int player_roll = rand() % friendly_monster->getAttackSpd();
		int enemy_roll = rand() % enemy_monster->getAttackSpd();
		if(player_roll >= enemy_roll)
		{
			//success
		}
		else
		{
			//not success
		}
	}
	else
	{
		//tried escaping from a poacher
		//player just wasted a turn
		player_turn = false;
		status->setText("You cannot escape from a poacher battle!");
	}
	return true;
}

void CBattleManager::checkMonstersLeft()
{
	if(player->getMonsters().size() > 0)
	{
		//load first monster
		friendly_monster = player->getMonsters()[0];
		if(enemy->getMonsters().size() > 0)
		{
			enemy_monster = enemy->getMonsters()[0];
			
		}
		else
		{
			//enemy has no monsters
			//auto resolve
			in_battle = false;
		}
	}
	else
	{
		//player has no monsters
		//auto resolve
		in_battle = false;
	}
}

bool CBattleManager::inBattle()
{
	return in_battle;
}

void CBattleManager::drop()
{
	delete this;
}
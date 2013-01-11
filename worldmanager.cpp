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
#include "worldmanager.h"

CWorldManager::CWorldManager(SDL_Surface *screen, CInjectHandler *receiver) : in_battle(false), in_menu(false), exit(false),
	receiver(receiver), screen(screen)
{

	//initializer list
	//temporary crap goes here
	player = new CPlayer("Player", 400,300);
	person_manager.push_back(player);
	player->addMonster(monsters().PLASTIC_RAT);

	CPerson *man = new CPerson("Hillbilly", 40,40);
	man->addMonster(monsters().PLASTIC_RAT);
	person_manager.push_back(man);
	//generate terrain
	test = new CImage(SDL_LoadBMP("res/2d/bkg/town_log.bmp"),0,0);

	root = (FrameWindow*)WindowManager::getSingleton().createWindow("DefaultWindow", "r" );
	root->setPosition( UVector2( CEGUI::UDim(0,0), CEGUI::UDim(0,0) ) ) ;
	root->setSize( UVector2( cegui_reldim(1), cegui_reldim(1) ) ) ;
	// Disables the frame and standard background:
	//root->setProperty( "FrameEnabled", "false" ) ;
	//root->setProperty( "BackgroundEnabled", "false" );
	System::getSingleton().setGUISheet( root );
	game_menu = new CGameMenu(root);



}

//call from init.cpp
void CWorldManager::loop()
{
	
	SDL_Event event;
	::SDL_PollEvent(&event);
	receiver->onEvent(event);
	if(in_battle == false)
	{
		playerControl(event);

		test->render();
		runPeople();
	}
	else
	{
		//run battle sim
		for(int i= 0; i<no_battles.size() ; i++)
		{
			//fix this
			if(no_battles[i]->inBattle())
			{
				no_battles[i]->run();
			}
			else
			{
				//remove
				no_battles[i]->drop();
				no_battles.erase(no_battles.begin()+i);
			}
		}
	}
}

void CWorldManager::runPeople()
{
	for(unsigned int i = 0; i < person_manager.size(); i++)
	{
		person_manager[i]->run();
		for(unsigned int n = 0; n < person_manager.size(); n++)
		{
			if(person_manager[n] != person_manager[i])
			{
				//battle it out automatically
				if(getCollision(person_manager[n], person_manager[i]))
				{
					createBattle(player,person_manager[i]);
				}
			}
		}
	}
}

bool CWorldManager::getCollision(CObject *target1, CObject *target2)
{
	if(target1->getX() < target2->getX() + target2->getImageSizeX())
	{
		if(target1->getX() + target1->getImageSizeX() > target2->getX())
		{
			//intersection on the x -axis
			//now check for intersection on the y - axis
			if(target1->getY() < target2->getY() + target2->getImageSizeY())
			{
				if(target1->getY() + target1->getImageSizeY() > target2->getY())
				{
					//collides on both axis
					return true;
				}
			}
			
		}
	}
	//no intersection
	return false;
}

bool CWorldManager::createBattle(CPerson *player, CPerson *enemy)
{
	if(no_battles.size() > 0)
	{
		//battle already occuring
		//do not allow another one to be created
		return false;
	}
	else
	{
		if(in_battle == false)
		{
			CBattleManager *b = new CBattleManager(player,enemy, root);
			no_battles.push_back(b);
			in_battle = true;
			return true;
		}
		else
		{
			//well someone fucked up
			//game thinks battle is happening when there are none
			return false;
		}
	}
}

void CWorldManager::playerControl(SDL_Event event)
{
	if(receiver->getKeyPressed(::SDLK_ESCAPE))
	{
		exit = true;
	}
	if(in_menu == false)
	{
		//nest of if and else
		//to ensure that the player stays on the grid
		//no diagonal movement
		game_menu->setVisible(false);
		if(receiver->getKeyPressed(::SDLK_UP))
		{
			player->setPos(player->getX(),player->getY()-1);
		}
		else
		{
			if(receiver->getKeyPressed(::SDLK_DOWN))
			{
				player->setPos(player->getX(),player->getY()+1);
			}
			else
			{
				if(receiver->getKeyPressed(::SDLK_LEFT))
				{
					player->setPos(player->getX()-1,player->getY());
				}
				else
				{
					if(receiver->getKeyPressed(::SDLK_RIGHT))
					{
						player->setPos(player->getX()+1,player->getY());
					}
				}
			}
		}
		if(in_battle == false)
		{
			if(receiver->getKeyPressed(::SDLK_x))
			{
				in_menu = true;
			}
		}
	}
	else
	{
		game_menu->setVisible(true);
		if(receiver->getKeyPressed(::SDLK_x))
		{
			in_menu = false;
		}
	}
}

bool CWorldManager::getExit()
{
	//check if player wants to quit
	return exit;
}
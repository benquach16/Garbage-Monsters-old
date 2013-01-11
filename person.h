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

#ifndef _PERSON_H_
#define _PERSON_H_

#include "object.h"
#include "types.h"
#include "inventorymanager.h"

//person object that can have monsters
class CPerson : public CObject
{
public:
	CPerson(const char *name = "Unnamed Person", int x = 10, int y = 10, bool is_player = false);
	~CPerson();

	void run();
	bool isPlayer()
	{
		return is_player;
	}
	std::vector<CMonster*> getMonsters();

	//factory function
	//so we don't have to deal with new
	bool addMonster(monster_base *monster);

private:

	CInventoryManager *inventory;

	bool is_player;

};

#endif
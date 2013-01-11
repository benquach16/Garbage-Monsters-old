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

#ifndef _INVENTORYMANAGER_H_
#define _INVENTORYMANAGER_H_

#pragma once

#include "object.h"
#include "monster.h"
#include "vector"

//contains vectors of objects that player has
class CInventoryManager
{
public:
	CInventoryManager();
	~CInventoryManager();
	void addItem(CObject *toadd);
	bool addMonster(CMonster *toadd);

	std::vector<CObject*> getItems();
	std::vector<CMonster*> getMonsters();
private:
	std::vector<CObject*> inv;
	std::vector<CMonster*> monsters;
};

#endif
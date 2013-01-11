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
#include "inventorymanager.h"

#define MAX_SIZE 8


CInventoryManager::CInventoryManager()
{

}

void CInventoryManager::addItem(CObject *toadd)
{
	inv.push_back(toadd);
}

bool CInventoryManager::addMonster(CMonster *toadd)
{
	if(monsters.size() < MAX_SIZE)
	{
		monsters.push_back(toadd);
		return true;
	}
	else
	{
		//max party size filled - return warning
		return false;
	}
}

std::vector<CObject*> CInventoryManager::getItems()
{
	return inv;
}

std::vector<CMonster*> CInventoryManager::getMonsters()
{
	return monsters;
}

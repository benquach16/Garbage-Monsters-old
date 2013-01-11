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

#ifndef _MONSTER_H_
#define _MONSTER_H_

#pragma once

#include "object.h"
#include "types.h"

//basic monster class
//inheirts from types for different kinds of monsters
class CMonster : public CObject
{
public:
	CMonster(monster_base *base);
	void levelUp();
	int getHealth();
	int getAttack();
	int getDefense();
	int getAttackSpd();
	int getLevel();
	const char* getBattleImageFront();
	~CMonster();

private:
	int health;
	int max_health;
	int attack;
	int defense;
	int attack_spd;
	int level;
	

	monster_base *base;
	bool diseased;
	DISEASE_TYPES disease;
};

#endif
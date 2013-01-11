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
#include "monster.h"

CMonster::CMonster(monster_base *base) : CObject(base->name, 0, 0), base(base), level(1)
{
	health = base->base_health;
	max_health = base->base_health;
	attack = base->base_attack_dmg;
	defense = base->base_defense;
	attack_spd =base->base_attack_spd;
	
}

CMonster::~CMonster()
{

}

const char* CMonster::getBattleImageFront()
{
	return base->battle_image_front;
}

void CMonster::levelUp()
{
	 level++;
	 // lveling up is super unsophisticated
	 //multiply by a level multiplier
	 health = health * base->level_multiplier;
	 max_health = max_health * base->level_multiplier;
	 attack = attack * base->level_multiplier;
	 defense = defense * base->level_multiplier;
	 attack_spd = attack_spd * base->level_multiplier;
}

int CMonster::getAttackSpd()
{
	return attack_spd;
}


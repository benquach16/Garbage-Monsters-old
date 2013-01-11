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

#ifndef _TYPES_H_
#define _TYPES_H_

#include "string"

enum OBJECT_TYPES
{
	TYPE_GENERIC,
	TYPE_MONSTER,
	TYPE_HEAL,
	TYPE_CAPTURE,
};

enum DISEASE_TYPES
{
	TYPE_CANCER,
	TYPE_HIV,
	TYPE_AUTISM,
	TYPE_DYSLEXIA,
	TYPE_DIABETES,
};

enum STAT_TYPES
{
	TYPE_ATTACK_DMG,
	TYPE_DEFENSE,
	TYPE_ATTACK_SPD,
	TYPE_SPECIAL_DMG,
	TYPE_HEALTH,
};

enum MONSTER_TYPES
{
	TYPE_PLASTIC,
	TYPE_RADIOACTIVE,
	TYPE_OIL,
	TYPE_POLLUTION,
	TYPE_FABRIC,
};

class item_base
{
public:
	const char *name;
	const char *description;

	OBJECT_TYPES type;
	int cost;
};

class attack_base
{
public:
	const char *name;
	const char *description;
};

class heal_item : public item_base
{
public:
	int heal_amount;
	bool revive;
};

class monster_base : public item_base
{
public:
	int base_health;
	int base_attack_dmg;
	int base_defense;
	int base_attack_spd;
	int base_special;
	float level_multiplier;

	MONSTER_TYPES monster_type;
	const char *battle_image_front;
	const char *battle_image_back;
};


class items
{
public:

	items()
	{
	}
};

class monsters
{
public:
	monster_base *PLASTIC_RAT;
	monsters()
	{
		PLASTIC_RAT = new monster_base;
		PLASTIC_RAT->name = "Plastic Bag Rat";
		PLASTIC_RAT->description = "The Plastic Bag Rat was a result of a mutation between a plastic bag and an angry rat. It uses its plastic bag for offensive and defensive purposes.";
		PLASTIC_RAT->base_attack_dmg = 7;
		PLASTIC_RAT->base_attack_spd = 9;
		PLASTIC_RAT->base_defense = 5;
		PLASTIC_RAT->base_health = 24;
		PLASTIC_RAT->base_special = 3;
		PLASTIC_RAT->level_multiplier = 1.34;
		PLASTIC_RAT->monster_type = TYPE_PLASTIC;
		PLASTIC_RAT->battle_image_front = "res/2d/monsters/plastic_rat_f.bmp";

	}
};


#endif
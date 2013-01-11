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

#ifndef _OBJECT_H_
#define _OBJECT_H_

#pragma once

#include "image.h"

//base object class
class CObject : public CImage
{
public:
	CObject(const char *name = "Object", int x = 0, int y = 0);

	~CObject();

	void setName(const char *name);
	const char *getName();

	void setDescription(const char *description());
	const char *getDescription();

private:
	const char *_name;
	const char *_description;
};

#endif
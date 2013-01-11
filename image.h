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

#ifndef _IMAGE_H_
#define _IMAGE_H_

#pragma once

#include "SDL.h"
#include "SDL_opengl.h"
#include "CEGUI.h"

struct vector2d
{
	int x;
	int y;
};


class CImage
{
public:
	//use opengl to display an image
	CImage(SDL_Surface *surface, int x, int y);
	~CImage();
	//render the image
	//creates a 2d quad to display the texture on
	void render();
	int getX();
	int getY();
	int getImageSizeX();
	int getImageSizeY();

	void setPos(int x, int y);
	void setImage(SDL_Surface *surface);
	//for using white as a alpha channel
	void setTransparencyGenerate(bool generate);

private:
	GLuint image;
	SDL_Surface *surface;
	int x;
	int y;

	vector2d pos;

};

#endif
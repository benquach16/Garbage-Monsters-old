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

#ifndef _GLIMAGELOADER_H_
#define _GLIMAGELOADER_H_

#pragma once

#include "SDL.h"
#include "SDL_opengl.h"
#include "CEGUI.h"

//defunct code
//use CImage instead
class GLImageLoader
{
public:
	GLImageLoader()
	{
	}
	~GLImageLoader()
	{
	}
	GLuint loadImage(SDL_Surface *surface)
	{
		GLuint image = 0;
		glGenTextures(1, &image);
		glBindTexture(GL_TEXTURE_2D, image);

		int Mode = GL_RGB;

		if(surface->format->BytesPerPixel == 4) {
			Mode = GL_RGBA;
		}

		glTexImage2D(GL_TEXTURE_2D, 0, Mode, surface->w, surface->h, 0, Mode, GL_UNSIGNED_BYTE, surface->pixels);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		return image;
	}
private:

};

#endif
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
#include "image.h"

//cimage class for not having to deal with opengl
CImage::CImage(SDL_Surface *surface, int x, int y) : image(0), x(x), y(y), surface(surface)
{
	//create opengl texture from bitmap
	glGenTextures(1, &image);
	glBindTexture(GL_TEXTURE_2D, image);

	int Mode = GL_RGB;
	//assign texture mode
	if(surface->format->BytesPerPixel == 4) 
	{
		//if(surface->format->Rmask == 0x000000ff)
			Mode = GL_RGBA;
		//else
		//	Mode = GL_BGRA;
	}
	if(surface->format->BytesPerPixel == 3)
	{
		if(surface->format->Rmask == 0x000000ff)
			Mode = GL_RGB;
		else
			Mode = GL_RGB;
	}
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexImage2D(GL_TEXTURE_2D, 0, Mode, surface->w, surface->h, 0, GL_BGR, GL_UNSIGNED_BYTE, surface->pixels);
	glPixelStorei(GL_UNPACK_SWAP_BYTES, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

}

CImage::~CImage()
{
}

void CImage::setImage(SDL_Surface *surface)
{
	glGenTextures(1, &image);
	glBindTexture(GL_TEXTURE_2D, image);
	int Mode = GL_RGB;

	if(surface->format->BytesPerPixel == 4) 
	{
		Mode = GL_RGBA;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, Mode, surface->w, surface->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, surface->pixels);
	::glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void CImage::setTransparencyGenerate(bool generate)
{
	if(generate == true)
	{
		glEnable(GL_ALPHA_TEST);
	}
}

void CImage::render()
{
	//all images should be quads
	//for the sake of not being retarded


	::glEnable(GL_TEXTURE_2D);
	::glBindTexture(GL_TEXTURE_2D,image);

	::glBegin(GL_QUADS);

	glTexCoord2i( 0, 0 );
	::glColor3f(1.0f,1.0f,1.0f);	
	::glVertex2f(x, y);

	glTexCoord2i( 1, 0 ); 
	::glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(x + getImageSizeX(), y);

	glTexCoord2i( 1, 1 );
	::glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(x + getImageSizeX(), y + getImageSizeY());
	
	glTexCoord2i( 0, 1 );
	::glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(x, y + getImageSizeY());

	glEnd();
}

void CImage::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

int CImage::getX()
{
	return x;
}

int CImage::getY()
{
	return y;
}

int CImage::getImageSizeX()
{
	return surface->w;
}

int CImage::getImageSizeY()
{
	return surface->h;
}
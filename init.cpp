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
#include "init.h"

#pragma comment(lib, "SDL.lib")
#pragma comment(lib, "CEGUIBase.lib")
#pragma comment(lib, "CEGUIOpenGLRenderer.lib")
#pragma comment(lib, "CEGUIExpatParser.lib")
#pragma comment(lib, "CEGUIDevILImageCodec.lib")
#pragma comment(lib, "CEGUICoronaImageCodec.lib")
#pragma comment(lib, "CEGUISTBImageCodec.lib")
#pragma comment(lib, "CEGUISILLYImageCodec.lib")
#pragma comment(lib, "CEGUITGAImageCodec.lib")
#pragma comment(lib, "CEGUIFalagardWRBase.lib")

#define X 800
#define Y 600



const std::string & CEGUIInstallBasePath =
  "res/" ;

CInit::CInit() : quit(false), ingame(false), w_quit(false)
{
	::SDL_Init(SDL_INIT_EVERYTHING);

	screen = ::SDL_SetVideoMode(X,Y,32,SDL_OPENGL);

	if(screen == 0)
	{
		//unable to initialize
	}

	glMatrixMode( GL_PROJECTION );
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, X, Y, 0, -1, 1);
	//Initialize Modelview Matrix
	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();
	glLoadIdentity();

		//Initialize clear color
	glClearColor((128.0f / 255.0f), 1.0f, 1.0f, 1.0f);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,            8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,          8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,           8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,          8);
 
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,          16);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,            32);
 
    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,        8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,    8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,        8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,    8);
 
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);
 
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);


	CEGUI::OpenGLRenderer::bootstrapSystem();
	setupCEGUI();

	receiver = new CInjectHandler;
	SchemeManager::getSingleton().create( "TaharezLook.scheme" );

	System::getSingleton().setDefaultMouseCursor( "TaharezLook", "MouseArrow" );

	mainmenu = new CMainMenu();
	mainmenu->getStartButton()->subscribeEvent(CEGUI::PushButton::EventClicked,CEGUI::Event::Subscriber(&CInit::start,this));
	loop();
}

CInit::~CInit()
{
	::SDL_Quit();
}


bool CInit::start(const CEGUI::EventArgs&)
{
	ingame = true;
	return true;
}

void CInit::loop()
{
	//fix infinite loop
	while(quit==false)
	{

		if(ingame==true)
		{
			mainmenu->setVisible(false);
			break;
		}
		
		
		//display title
		//need to clear buffer in order to render images
		glClear( GL_COLOR_BUFFER_BIT ) ;
		CEGUI::System::getSingleton().renderGUI();
		SDL_GL_SwapBuffers();


		::SDL_Event event;
		receiver->onEvent(event);
		if(receiver->getKeyPressed(::SDLK_ESCAPE))
		{
			quit = true;
		}
		if(receiver->getKeyPressed(::SDLK_UP))
		{
			::SDL_WarpMouse(400,300);
		}
		if(receiver->getKeyPressed(::SDLK_DOWN))
		{
			//get list of buttons from cmainmenu object
			//and then create selection based on the vector stored in the class
		
		}
	}

	if(ingame == true)
	{
		worldLoop();
	}
}

void CInit::worldLoop()
{
	world_manager = new CWorldManager(screen, receiver);
	while(w_quit==false)
	{

		glClear(GL_COLOR_BUFFER_BIT);
		world_manager->loop();
		CEGUI::System::getSingleton().renderGUI();
		w_quit = world_manager->getExit();
		SDL_GL_SwapBuffers();

		

	}


}

void CInit::setupCEGUI()
{
	
	CEGUI::DefaultResourceProvider *defaultResProvider =
		 static_cast<CEGUI::DefaultResourceProvider*>
			( CEGUI::System::getSingleton().getResourceProvider() ) ;
 
	const string CEGUIInstallSharePath = CEGUIInstallBasePath;

 
	defaultResProvider->setResourceGroupDirectory( "schemes",
	  CEGUIInstallSharePath + "schemes/" ) ;
 
	defaultResProvider->setResourceGroupDirectory( "imagesets",
	  CEGUIInstallSharePath + "2d/" ) ;
 
	defaultResProvider->setResourceGroupDirectory( "fonts",
	  CEGUIInstallSharePath + "fonts/" ) ;
 
	defaultResProvider->setResourceGroupDirectory( "layouts",
	  CEGUIInstallSharePath + "layouts/" ) ;
 
	defaultResProvider->setResourceGroupDirectory( "looknfeels",
	  CEGUIInstallSharePath + "looknfeel/" ) ;
   
	defaultResProvider->setResourceGroupDirectory( "schemas",
	  CEGUIInstallSharePath + "xml_schemas/" ) ;
 
	defaultResProvider->setResourceGroupDirectory( "animations",
	  CEGUIInstallSharePath + "animations/" ) ;
 
	// Sets the default resource groups to be used:
	CEGUI::Imageset::setDefaultResourceGroup( "imagesets" ) ;
	CEGUI::Font::setDefaultResourceGroup( "fonts" ) ;
	CEGUI::Scheme::setDefaultResourceGroup( "schemes" ) ;
	CEGUI::WidgetLookManager::setDefaultResourceGroup( "looknfeels" ) ;
	CEGUI::WindowManager::setDefaultResourceGroup( "layouts" ) ;
	CEGUI::AnimationManager::setDefaultResourceGroup( "animations" ) ;
	
 
	// Set-up default group for validation schemas:
	CEGUI::XMLParser * parser = CEGUI::System::getSingleton().getXMLParser() ;
	if ( parser->isPropertyPresent( "SchemaDefaultResourceGroup" ) )
		parser->setProperty( "SchemaDefaultResourceGroup", "schemas" ) ;
		
}
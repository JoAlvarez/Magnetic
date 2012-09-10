///////////////////////////////////////////////////////////////////////////////
// File:                 game.h
//
// Original Author:      Roby Atadero (RA)
//
// Creation Date:        April 29th, 2007
//
// Last Edited:          April 29th, 2007 - Implementation
//
// Purpose:              Header for the Game class that holds the information
//                       for a game and how to control it.
///////////////////////////////////////////////////////////////////////////////

#ifndef __GAME_H__
#define __GAME_H__

#include "window.h"
#include "input.h"
#include "point.h"
#include "mathfunctions.h"
#include "resourcemgr.h"
#include "image.h"
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include "toolManager.h"

#define QUIT_SIGNAL_RECEIVED false

//Define all image identifiers here so that it is much easier to
//understand what image is being used in the game class.

class Game
{
  private:

    Window*             window;             //Window that handles all the windowing
                                            //inputs, framerate counting, etc.
    bool                gameover;           //Whether or not the game is now over

    Input*              input;
    ResourceMgr*        resourceMgr;
    ToolManager         toolManager;

    void                handleLogic();
    void                renderGame();
    void                checkInput();


    bool                firstFrame;

  public:

    Game();

    ~Game();

    void init();

    void play();

};

#endif

#include "game.h"
#include <cmath>
#include "ball.h"
#include "magnet.h"

using namespace std;

Game::Game()
{
    window = NULL;
	gameover = false;
	firstFrame = true;
	stage = new Stage();
	startMenu = new StartMenu();
	inMenu = true;
}

Game::~Game()
{
    if(window)
        delete window;
}

void Game::init()
{

    window = Window::getInstance();

    if(window)
    {
		gameover = false;
    }
    else
    {
        gameover = true;
        return;
    }

    //Initiliaze the input system.
    input = Input::getInstance();

    //Get our resourceMgr
    resourceMgr = ResourceMgr::getInstance();

    //Load Fonts.
    resourceMgr->loadFont("./data/fonts/arial.ttf", "Arial", 32);
    resourceMgr->loadFont("./data/fonts/arial.ttf", "ArialS", 18);

    resourceMgr->loadImage("./data/images/marble.png", "darktile1");
    resourceMgr->loadMusic("./data/audio/level1.wav", "level1" );

    stage->start();

	window->setCoord(0, 1024, 0, 768);
}

void Game::handleLogic()
{
    if( !startMenu->inMenu() )
    {
        if(firstFrame)
        {
            firstFrame = false;
            return;
        }

        stage->updateLevel();
    }

    else
        startMenu->checkInput();

	if(input->getKeyInput() == "esc" )
	{
		startMenu->open();
	}

}

void Game::renderGame()
{

    //Start with the full colors of RGB.
    glColor4f(1.0,1.0,1.0, 0.85);

    //resourceMgr->drawImage("darktile1", -10000, 10000, -10000, 10000, -10000 / 128.0, 10000 / 128.0, -10000 / 128.0, 10000 / 128.0);

    glColor3f(1.0,1.0,1.0);

    if( !startMenu->inMenu() )
    {
        stage->drawLevel();

        //Draw the text shawdow.
        glColor3f(0.1,0.1,0.1);
        resourceMgr->drawText("Arial", "Magnetic", window->leftCoord() + 400, window->topCoord() - 50);

        //Draw the blue text over it.
        glColor3f(0.0,0.0,1.0);
        resourceMgr->drawText("Arial", "Magnetic", window->leftCoord() + 403, window->topCoord() - 47);

        //Reset the color to full RGB when finished to be safe.
        glColor3f(1.0,1.0,1.0);

        glColor3f(0.0,1.0,0.0);
        resourceMgr->drawText("ArialS", "Goal", 750, 1100);
    }
    else
        startMenu->draw();
}

void Game::play()
{
    string windowTitle = "Magnetic";
    //Set the window and taskbar caption for the game.
	SDL_WM_SetCaption(windowTitle.c_str(), windowTitle.c_str());

    //Start playing the music.
    //resourceMgr->playMusicRepeat( "level1", INFINITY );

    //Game Loop
    while(!gameover)
	{
	    //Tell the window to record the starting time of the new frame.
        window->startFrame();

        //Clear the screen so we can begin the next frame.
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Handle all input and window events.
        //If a quit signal was received from the window, we
        //quit the program.
        if(input->handleEvents() == QUIT_SIGNAL_RECEIVED)
            gameover = true;

        //Handles all the movement, AI, calculations, etc.
        handleLogic();

        //Draws everything in the scene.
    	renderGame();

        //Swap the new buffer to output everything that was drawn to the screen.
		SDL_GL_SwapBuffers();

        //Tell the window to record the stop time of the current frame.
        window->endFrame();
		//Reset the buffered input to nothing.
		input->resetInput();
	}

    //Free the resources
	resourceMgr->stopMusic();
	resourceMgr->release();
}



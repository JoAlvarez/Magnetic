#include "game.h"
#include <cmath>

using namespace std;

Game::Game()
{
    window = NULL;
	gameover = false;
	firstFrame = true;
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
    window->setCoord(0, 1024, 0, 768);
}

void Game::handleLogic()
{
    if(firstFrame)
    {
        firstFrame = false;
        return;
    }

	if(input->isKeyDown("esc"))
	{
		gameover = true;
		return;
	}
    toolManager.update();
}

void Game::renderGame()
{
    //Draw background
    glColor3f( 0.0, 0.0, 0.0 );
    glBegin( GL_QUADS );
        glVertex2f( window->leftCoord() , window->topCoord() );
        glVertex2f( window->rightCoord(), window->topCoord() );
        glVertex2f( window->rightCoord(), window->bottomCoord() );
        glVertex2f( window->leftCoord() , window->bottomCoord() );
    glEnd();
    toolManager.draw();
}

void Game::play()
{
    string windowTitle = "Magnetic - Level Editor";
    //Set the window and taskbar caption for the game.
	SDL_WM_SetCaption(windowTitle.c_str(), windowTitle.c_str());

    //Game Loop
    while(!gameover)
	{
	    //Tell the window to record the starting time of the new frame.
        window->startFrame();

        //Clear the screen so we can begin the next frame.
        glClearColor(1.0, 1.0, 1.0, 0.0);
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



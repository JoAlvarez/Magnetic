#include "level.h"


Level::Level(string level)
{
    objects = EntityContainer::getInstance();
    window = Window::getInstance();
    resourceMgr = ResourceMgr::getInstance();
    input = Input::getInstance();

    player = NULL;
    levelFile = level;
    isOver = false;
}

void Level::update()
{
    player->checkInput();
    objects->handleAllOnAlways();
    objects->handleAllDetection();

    Entity* goal = objects->getEntity("Goal");
    if(goal->touched("playerBall"))
        isOver = true;

    objects->handleAllFlags();

    if(input->getKeyInput() == "r" || input->getMouseInput() == "Middle Down")
        loadLevel();

    camera.update();
}

void Level::draw()
{
    objects->drawAll();

    Ball* ball = (Ball*)(objects->getEntity("playerBall"));
    ball->touched("Goal");

    /*double magnitude = sqrt((ball->getXVel() * ball->getXVel()) + (ball->getYVel() * ball->getYVel()));

    //Draw the text shawdow.
    glColor3f(1.0,0.0,0.0);
    resourceMgr->drawText("Arial", magnitude, window->leftCoord() + 100, window->topCoord() - 50);
	*/
}
void Level::loadLevel()
{
    if(!player)
        player = new Player();

    objects->loadLevel(levelFile);

    Entity* ball = objects->getEntity("playerBall");
    player->setPlayerBall((Ball*)(ball));
}

bool Level::levelWon()
{
    return isOver;
}

#include "level.h"

Level::Level(int levelNum)
{
    this->levelNum = levelNum;
    objects = EntityContainer::getInstance();
    window = Window::getInstance();
    player = NULL;
}

void Level::update()
{
    player->checkInput();
    objects->handleAllOnAlways();
    objects->handleAllDetection();
    objects->handleAllFlags();

    window->setCoord(player->getBall()->getCenter().getX() - (window->rightCoord() - window->leftCoord())   / 2.0,
                     player->getBall()->getCenter().getX() + (window->rightCoord() - window->leftCoord())   / 2.0,
                     player->getBall()->getCenter().getY() - (window->topCoord()   - window->bottomCoord()) / 2.0,
                     player->getBall()->getCenter().getY() + (window->topCoord()   - window->bottomCoord() ) / 2.0);
}

void Level::draw()
{
    objects->drawAll();
}

void Level::loadLevel(string bg,string level)
{
    if(!player)
        player = new Player();
    objects->loadLevel(level);
    Entity* ball = objects->getEntity("playerBall");
    player->setPlayerBall((Ball*)(ball));
}

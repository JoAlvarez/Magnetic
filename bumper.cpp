#include "bumper.h"
#include "mathfunctions.h"
#include <cmath>

Bumper::Bumper()
    :Entity()
{
    bumpValue = 0;
    window = Window::getInstance();
    resourceMgr = ResourceMgr::getInstance();
    resourceMgr->loadImage("./data/images/ball.png", "ball");
    resourceMgr->loadSound( "./data/audio/bumperSound.wav", "bumper" );
}

Bumper::Bumper(string name, int bumpVal, int health, double radius, Substance sub, Point center)
    :Entity(BUMPER, name, health, false, center, radius, sub, CIRCLE, true, false)
{
    bumpValue = bumpVal;
    window = Window::getInstance();
    resourceMgr = ResourceMgr::getInstance();
    resourceMgr->loadImage("./data/images/ball.png", "ball");
    resourceMgr->loadSound( "./data/audio/bumperSound.wav", "bumper" );
}

Bumper::~Bumper()
{
    window->release();
}

int Bumper::getBumpValue()
{
    return bumpValue;
}

void Bumper::setBumpValue(int bumpVal)
{
    bumpValue = bumpVal;
}

void Bumper::bump(Entity* ball)
{
	Ball* b = (Ball*)(ball);
    double angle = calcAngle(ball->getCenter(), getCenter());
    double xVelocity = bumpValue / b->getMass() * (cos(angle + M_PI));
    double yVelocity = bumpValue / b->getMass() * (sin(angle + M_PI));

    ((Ball*)ball)->setXVel( -((Ball*)ball)->getXVel() + xVelocity);
    ((Ball*)ball)->setYVel( -((Ball*)ball)->getYVel() + yVelocity);

}

void Bumper::onTouch()
{
    if(bumpValue > 0)
    {
        for(int i = 0; i < touchedBy.size(); i++)
        {
            Entity* temp = getEntity( touchedBy[i] );

            if(temp->getEntityType() == BALL)
            {
                // Play sound effect
                resourceMgr->playSound( "bumper" );
                bump(temp);
            }
        }
    }

}

void Bumper::draw()
{
    glColor4f(0.0, 1.0, 0.0, 1.0);
    resourceMgr->drawImage("ball", upperLeft.getX(), upperRight.getX(), lowerRight.getY(), upperRight.getY());
    glColor4f(1,1,1,1);


}



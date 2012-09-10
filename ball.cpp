#include "ball.h"
#include <cmath>
#include "magnet.h"
#include "vector2d.h"

class Magnet;

Ball::Ball()
    :Entity()
{
    charge = NEUTRAL;
    mass = 10;
    xVel = 0.0;
    yVel = 0.0;
    effectedByMagnet = false;
    window = Window::getInstance();
    resourceMgr         = ResourceMgr::getInstance();
    resourceMgr->loadImage("./data/images/ball.png", "ball");
    resourceMgr->loadImage("./data/images/positive.png", "positive");
    resourceMgr->loadImage("./data/images/negative.png", "negative");
    resourceMgr->loadImage("./data/images/glow.png", "glow");
    resourceMgr->loadSound( "./data/audio/ballCollision.wav", "ballCollision" );
    brightness = 1;

}

Ball::Ball(string name, Polarity p, double m, int health, double radius,Substance sub, Point center)
    :Entity(BALL, name, health, false, center, radius, sub, CIRCLE, false, true )
{
    charge = p;
    mass = m;
    xVel = 0.0;
    yVel = 0.0;
    effectedByMagnet = false;
    window = Window::getInstance();
    resourceMgr         = ResourceMgr::getInstance();
    resourceMgr->loadImage("./data/images/ball.png", "ball");
    resourceMgr->loadImage("./data/images/positive.png", "positive");
    resourceMgr->loadImage("./data/images/negative.png", "negative");
    resourceMgr->loadImage("./data/images/glow.png", "glow");
    resourceMgr->loadSound( "./data/audio/ballCollision.wav", "ballCollision" );
    brightness = 1;
}

Ball::Ball(string name, Polarity p, double m, double xVel, double yVel,int health, double radius,Substance sub, Point center)
    :Entity(BALL, name, health, false, center,  radius, sub, CIRCLE, false, true )
{
    charge = p;
    mass = m;
    this->xVel = xVel;
    this->yVel = yVel;
    effectedByMagnet = false;
    window = Window::getInstance();
    resourceMgr         = ResourceMgr::getInstance();
    resourceMgr->loadImage("./data/images/glow.png", "glow");
    resourceMgr->loadSound( "./data/audio/ballCollision.wav", "ballCollision" );
    brightness = 1;
}

Ball::~Ball()
{
    window->release();
}

Polarity Ball::getCharge()
{
    return charge;
}

void Ball::setCharge(Polarity p)
{
    charge = p;
}

double Ball::getXVel()
{
    return xVel;
}

double Ball::getYVel()
{
    return yVel;
}

double Ball::getMass()
{
	return mass;
}

void Ball::setXVel(double x)
{
    xVel = x;
}

void Ball::setYVel(double y)
{
    yVel = y;
}

double Ball::getXForce()
{
    return xVel * mass;
}

double Ball::getYForce()
{
    return yVel * mass;
}

void Ball::move()
{
    this->center.move(xVel * window->timedMovement(), yVel * window->timedMovement());
    this->upperLeft.move(xVel * window->timedMovement(), yVel * window->timedMovement());
    this->lowerRight.move(xVel * window->timedMovement(), yVel * window->timedMovement());
    this->lowerLeft.move(xVel * window->timedMovement(), yVel * window->timedMovement());
    this->upperRight.move(xVel * window->timedMovement(), yVel * window->timedMovement());

}

void Ball::onAlways()
{
    move();

	if(brightness > 1)
	{
		brightness -= 5 * window->timedMovement();
		if(brightness < 1)
			brightness = 1;
	}

    //Ball friction.
    if(!effectedByMagnet)
    {
    	xVel -= xVel * 0.5 * window->timedMovement();
    	yVel -= yVel * 0.5 * window->timedMovement();
    }

    effectedByMagnet = false;
}

void Ball::onTouch()
{
    //This will need to be changed
    for(int i = 0; i < touchedBy.size(); ++i)
    {
        Entity* e = getEntity(touchedBy[i]);

        if(e->getEntityType() == MAGNET)
        {
            //If the magnet and ball have opposite polarities, set the vels of the ball to 0 so it
            //gets stuck to the magnet.
            Magnet* m = (Magnet*)(e);
            if((m->getCharge() == NEGATIVE && this->charge == POSITIVE) ||
               (m->getCharge() == POSITIVE && this->charge == NEGATIVE))
            {
                xVel = 0;
                yVel = 0;
                continue;
            }
        }
		if(e->getEntityType() == WALL || e->getEntityType() == DOOR)
        {
            //If the ball hit the corner of a wall, hence it was moved back in both directions, choose
            //which direction to reverse the balls velocity by which direction it moved the most.
            if(touchedInfo[i].xAmount != 0 && touchedInfo[i].yAmount != 0)
            {
                if(touchedInfo[i].xAmount <= touchedInfo[i].yAmount)
                    yVel = -yVel * .5;
                if(touchedInfo[i].xAmount >= touchedInfo[i].yAmount)
                    xVel = -xVel * .5;
            }

            //If it hit a wall and it was pushed back in the x direction, reverse x velocity.
            else if(touchedInfo[i].xAmount != 0)
                xVel = -xVel * .5;
            //If it hit a wall and it was pushed back in the y direction, reverse y velocity.
            else if(touchedInfo[i].yAmount != 0)
                yVel = -yVel * .5;
        }
        else if(e->getDetectableType() == CIRCLE)
        {
            if ( window->getFrameNumber() - frameTouched > 2 )
            {
                //Play sound effect
                resourceMgr->playSound( "ballCollision" );
            }

            Vector2d impact = sub(Vector2d(xVel, yVel), Vector2d(touchedInfo[i].xAmount, touchedInfo[i].yAmount));
			Vector2d relPos = sub(Vector2d(touchedInfo[i].loc2.getX(), touchedInfo[i].loc2.getY()),
								  Vector2d(touchedInfo[i].loc1.getX(), touchedInfo[i].loc1.getY()));

			//double massVal = touchedInfo[i].mass * this->mass / (touchedInfo[i].mass + this->mass);

			Vector2d impulse = normalize(relPos);

			//impulse = mult(Vector2d(2, 2), impulse);

			double impactSpeed = dotProduct(impulse, impact);
			impulse = mult(impulse, impactSpeed * 2 * touchedInfo[i].mass * this->mass / (touchedInfo[i].mass + this->mass));

			if(impactSpeed > 0)
			{
				//double newSpeed = impactSpeed * touchedInfo[i].mass * this->mass / (touchedInfo[i].mass + this->mass);
				//impulse = mult(impulse, newSpeed);
				//impulse = mult(impulse, impactSpeed);

				//xVel -= impulse.getX();
				//yVel -= impulse.getY();
				xVel -= impulse.getX() / mass;
				yVel -= impulse.getY() / mass;
			}

			// Find relative velocity of impact, and the impulse
			/*vec2 impact = Vec2Subtract( pA->vel, pB->vel );

			vec2 relativePosition = Vec2Subtract( pB->pos, pA->pos );
			vec2 impulse = Vec2Normalize( relativePosition );

			// Depenetrate sprites
			float dist = Vec2Length( relativePosition );
			vec2 midPoint = Vec2Add( pA->pos, pB->pos );
			midPoint = Vec2Multiply( midPoint, .5f );
			pA->pos = Vec2Add( midPoint, Vec2Multiply( impulse, SPRITE_DIAM / -2.f ) );
			pB->pos = Vec2Add( midPoint, Vec2Multiply( impulse, SPRITE_DIAM / 2.f ) );

			// Calculate the impact speed, relative to the impact vector
			float impactSpeed = ( Vec2DotProduct( impulse, impact ) );

			if( impactSpeed > 0.f )
			{
				impulse = Vec2Multiply( impulse, impactSpeed );

				pA->vel = Vec2Subtract( pA->vel, impulse );
				pB->vel = Vec2Add( pB->vel, impulse );
			}*/
        }

   		brightness = 2;
    }

    frameTouched = window->getFrameNumber();
}

void Ball::draw()
{
	glColor4f(0.0,0.0,0.0, 0.5);
	resourceMgr->drawImage("ball", upperLeft.getX() + 3, upperRight.getX() + 3, lowerRight.getY() - 3, upperRight.getY() - 3);

	//double colorRatio = 1 - mass / 11.0;
	//glColor4f(colorRatio, colorRatio, colorRatio, 1.0);
	//resourceMgr->drawImage("ball", upperLeft.getX(), upperRight.getX(), lowerRight.getY(), upperRight.getY());

	double glowRatio = 1 + (brightness - 1) * 0.5;

	if(charge == NEGATIVE)
	{
	    glColor4f(1.0 * brightness,0.5 * brightness,0.0,1.0);
	    resourceMgr->drawImage("glow", upperLeft.getX() - getRadius() / 1.5 * glowRatio, upperRight.getX() + getRadius() / 1.5 * glowRatio,
                                       lowerRight.getY() - getRadius() / 1.5 * glowRatio , upperRight.getY() + getRadius() / 1.5 * glowRatio);
        glColor4f(1.0 * brightness,0.75 * brightness,0.0,1.0);
        resourceMgr->drawImage("ball", upperLeft.getX(), upperRight.getX(), lowerRight.getY(), upperRight.getY());
	}

	if(charge == POSITIVE)
	{
	    glColor4f(0.0,0.2 * brightness,1.0 * brightness,1.0);
	    resourceMgr->drawImage("glow", upperLeft.getX() - getRadius() / 1.5 * glowRatio, upperRight.getX() + getRadius() / 1.5 * glowRatio,
                                       lowerRight.getY() - getRadius() / 1.5 * glowRatio , upperRight.getY() + getRadius() / 1.5 * glowRatio);
        glColor4f(0.0,0.7 * brightness,1.0 * brightness,1.0);
	    resourceMgr->drawImage("ball", upperLeft.getX(), upperRight.getX(), lowerRight.getY(), upperRight.getY());

	}

	if(charge == NEUTRAL)
	{
	    glColor4f(0.1,0.1,0.1,1.0);

	    resourceMgr->drawImage("ball", upperLeft.getX(), upperRight.getX(), lowerRight.getY(), upperRight.getY());

	}



	glColor4f(1,1,1,1);
}

void Ball::wasTouchedBy(Detectable* d, Point loc1, Point loc2, double xAmount, double yAmount)
{
    Entity* e = (Entity*)(d);

    touchedBy.push_back( e->getName());

    if(e->getEntityType() == BALL)
    {
    	Ball* b = (Ball*)(e);
    	touchedInfo.push_back(TouchedInfo(b->name, loc1, loc2, b->getXVel(), b->getYVel(), b->getMass()));
    }
    else if(e->getDetectableType() == CIRCLE)
    {
    	touchedInfo.push_back(TouchedInfo(e->getName(), loc1, loc2, 0, 0, 2 * mass));
    }
    else
    	touchedInfo.push_back(TouchedInfo(e->getName(), loc1, loc2, xAmount, yAmount));
}

void Ball::movedByMagnet()
{
	effectedByMagnet = true;
}





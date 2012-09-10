#include "magnet.h"
#include <cmath>
#define RAD_TO_DEGREES        57.29577951308


Magnet:: Magnet(string name, Polarity c, double strength, double reach, bool on, bool linear, Point center,double radius)
            :Entity(MAGNET, name, 100, false, center, radius, SOLID, CIRCLE, true, false)
{
    charge = c;
    magneticForce = strength;
    maxDistance = reach;
    this->on = on;
    linearForce = linear;
    window = Window::getInstance();
    resourceMgr->loadImage("./data/images/circle.png",   "circle");
    resourceMgr->loadImage("./data/images/ball.png",     "ball");
    resourceMgr->loadImage("./data/images/positive.png", "positive");
    resourceMgr->loadImage("./data/images/negative.png", "negative");
    brightness = 1;

}

void Magnet::onAlways()
{
    if(on)
    {
        Polarity c;
        vector<Entity*> balls = getEntitiesOfType(BALL);
        for(int i = 0; i < balls.size(); i++)
        {
            c = ((Ball*)(balls[i]))->getCharge();
            if(charge == POSITIVE)
            {
                switch(c)
                {
                    case POSITIVE :
                        push(balls[i]);
                        break;
                    case NEGATIVE :
                        pull(balls[i]);
                        break;
                }
            }
            else if(charge == NEGATIVE)
            {
                switch(c)
                {
                    case POSITIVE :
                        pull(balls[i]);
                        break;
                    case NEGATIVE :
                        push(balls[i]);
                        break;
                }
            }
        }

        if(brightness > 1)
        {
        	brightness -= 5 * window->timedMovement();
        	if(brightness < 1)
        		brightness = 1;
        }
    }
}

void Magnet::setPolarity(Polarity c)
{
    charge = c;
}

void Magnet::setStrength(double s)
{
    magneticForce = s;
}

void Magnet::setReach(double distance)
{
    maxDistance = distance;
}

void Magnet::pull(Entity* b)
{
    double distance = distBetween(center, ((Ball*)b)->getCenter());
    if(distance > maxDistance)
        return;

    double force = (magneticForce - (magneticForce * (distance - getRadius() - b->getRadius()) / maxDistance));
    double angle = calcAngle(b->getCenter(),getCenter());

    double xForce = ( force * cos(angle));
    double yForce = ( force * sin(angle));

	if(!linearForce)
	{
		int sign = 1;

		if(xForce < 0)
			sign = -1;
		xForce = xForce * xForce * sign;

		sign = 1;

		if(yForce < 0)
			sign = -1;
		yForce = yForce * yForce * sign;
	}

    ((Ball*)b)->setXVel( ((Ball*)b)->getXVel() + xForce * window->timedMovement());
    ((Ball*)b)->setYVel( ((Ball*)b)->getYVel() + yForce * window->timedMovement());
    ((Ball*)b)->movedByMagnet();
}

void Magnet::push(Entity* b)
{
    double distance = distBetween(center, ((Ball*)b)->getCenter());
    if(distance > maxDistance)
        return;

    double force = -1*(magneticForce - (magneticForce * (distance - getRadius() - b->getRadius()) / maxDistance));
    double angle = calcAngle(b->getCenter(),getCenter());

    double xForce = ( force * cos(angle));
    double yForce = ( force * sin(angle));

	if(!linearForce)
	{
		int sign = 1;

		if(xForce < 0)
			sign = -1;
		xForce = xForce * xForce * sign;

		sign = 1;

		if(yForce < 0)
			sign = -1;
		yForce = yForce * yForce * sign;
	}

    ((Ball*)b)->setXVel( ((Ball*)b)->getXVel() + xForce * window->timedMovement());
    ((Ball*)b)->setYVel( ((Ball*)b)->getYVel() + yForce * window->timedMovement());
    ((Ball*)b)->movedByMagnet();
}

Polarity Magnet::getCharge() const
{
    return charge;
}

double Magnet::getStrength() const
{
    return magneticForce;
}

double Magnet::getReach() const
{
    return maxDistance;
}

void Magnet::onTouch()
{
	for(int i = 0; i < touchedBy.size(); ++i)
    {
        Entity* e = getEntity(touchedBy[i]);

        if(e->getEntityType() == BALL)
			brightness = 2;

    }
}

void Magnet::draw()
{
	//Draw magnet's reach distance
	if(charge == NEGATIVE)
		glColor4f(1.0 * brightness, 0.5 * brightness,0.0, 0.5);
	else
		glColor4f(0.0,0.2 * brightness,1.0 * brightness, 0.5);

	double glowRatio = 1 + (brightness - 1) * 0.5;

	resourceMgr->drawImage("glow", center.getX() - getRadius() * glowRatio - maxDistance, center.getX() + getRadius() * glowRatio + maxDistance,
								   center.getY() - getRadius() * glowRatio - maxDistance, center.getY() + getRadius() * glowRatio + maxDistance);

	//Draw the magnets shadow
	glColor4f(0.0,0.0,0.0, 0.5);

	resourceMgr->drawImage("ball", upperLeft.getX() + 3, upperRight.getX() + 3, lowerRight.getY() - 3, upperRight.getY() - 3);


	//Draw the magnet
	if(charge == NEGATIVE)
		glColor4f(1.0 * brightness,0.75 * brightness,0.0, 1.0);
	else
		glColor4f(0.0, 0.75 * brightness, 1.0 * brightness, 1.0);
	resourceMgr->drawImage("ball", upperLeft.getX(), upperRight.getX(), lowerRight.getY(), upperRight.getY());

	//Draw the sign.
	glColor4f(0.9,0.9,0.9,1.0);

	if(charge == NEGATIVE)
	{
	    resourceMgr->drawImage("negative", center.getX() - getRadius() * 0.65, center.getX() + getRadius() * 0.65,
                               center.getY() - getRadius() * 0.65, center.getY() + getRadius() * 0.65);
	}

	if(charge == POSITIVE)
	{
		resourceMgr->drawImage("positive", center.getX() - getRadius() * 0.65, center.getX() + getRadius() * 0.65,
                               center.getY() - getRadius() * 0.65, center.getY() + getRadius() * 0.65);
	}

    glColor4f(1,1,1,1);

}

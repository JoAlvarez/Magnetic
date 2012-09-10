#include "door.h"

Door:: Door()
    : Entity()
{
    openSpeed   = 0.0;
    closeSpeed  = 0.0;
    window      = Window::getInstance();
    resourceMgr = ResourceMgr:: getInstance();
    opening     = false;
    resourceMgr->loadSound( "./data/audio/doorSound.wav", "door" );
}

Door:: Door( string name, Point uL, int width, int height,
            double speed, Point openLoc)
    : Entity( DOOR, name, 100, false, uL, width, height, SOLID, RECTANGLE, true, true )
{

    this->openSpeed     = speed;
    this->closeSpeed    = speed;
    this->openLoc       = openLoc;
    this->closeLoc      = uL;

    if(uL.getX() == openLoc.getX())
    {
    	if(uL.getY() > openLoc.getY())
    		dir = DOWN;
		else
			dir = UP;
    }
    else
    {
    	if(uL.getX() > openLoc.getX())
    		dir = LEFT;
		else
			dir = RIGHT;
    }

    this->dir           = dir;
    window              = Window::getInstance();
    resourceMgr = ResourceMgr:: getInstance();
    opening     = false;
    img = "./data/images/door.png";
    resourceMgr->loadImage( img, img );
    resourceMgr->loadSound( "./data/audio/doorSound.wav", "door" );
}

void Door:: open()
{
    if ( !opening )
    {
        //Play sound effect
        resourceMgr->playSound( "door" );
    }
    frameOpened = window->getFrameNumber();
	opening = true;
}

void Door:: close()
{
	opening = false;
}

void Door:: draw()
{
    if ( dir == LEFT or dir == RIGHT )
        resourceMgr->drawImage( img, upperLeft.getX(), upperRight.getX(), lowerLeft.getY(), upperRight.getY(), 0, getWidth()/ 128.0, 0, getHeight() / 32.0 );
    else
        resourceMgr->drawImage( img, upperRight.getX(), lowerLeft.getX(), upperLeft.getY(), lowerLeft.getY(), 0, getWidth() / 128.0, 0, getHeight() / 32.0 );
}

Door:: ~Door()
{
    window->release();
}

void Door:: setPos( Point uL )
{
    upperLeft.setX( uL.getX() );
    upperLeft.setY( uL.getY() );

    lowerLeft.setX( upperLeft.getX() );
    lowerLeft.setY( upperLeft.getY() - height );

    upperRight.setX( upperLeft.getX() + width );
    upperRight.setY( upperLeft.getY () );

    lowerRight.setX( upperRight.getX() );
    lowerRight.setY( lowerLeft.getY() );

    center.setX(upperLeft.getX() + width  / 2.0);
    center.setY(upperLeft.getY() - height / 2.0);
}

void Door:: onAlways()
{
    if ( opening )
    {
        // Open to the right
        if ( dir == RIGHT )
        {
            moveBy( openSpeed * window->timedMovement(), 0 );

            if ( openLoc.getX() <= upperLeft.getX() )
                setPos( openLoc );
        }

        // Open to the left
        else if ( dir == LEFT )
        {
            moveBy( -openSpeed * window->timedMovement(), 0 );

            if ( openLoc.getX() >= upperLeft.getX() )
                setPos( openLoc );
        }

        // Open upward
        else if ( dir == UP )
        {
            moveBy( 0, openSpeed * window->timedMovement() );

            if ( openLoc.getY() <= upperLeft.getY() )
                setPos( openLoc );
        }

        // Open downward
        else if ( dir == DOWN )
        {
            moveBy( 0, -openSpeed * window->timedMovement() );

            if ( openLoc.getY() >= upperLeft.getY() )
                setPos( openLoc );
        }
    }

    else
    {
        // Open to the right
        if ( dir == RIGHT )
        {
            moveBy( -openSpeed * window->timedMovement(), 0 );

            if ( closeLoc.getX() >= upperLeft.getX() )
                setPos( closeLoc );
        }

        // Open to the left
        else if ( dir == LEFT )
        {
            moveBy( openSpeed * window->timedMovement(), 0 );

            if ( closeLoc.getX() <= upperLeft.getX() )
                setPos( closeLoc);
        }

        // Open upward
        else if ( dir == UP )
        {
            moveBy( 0, -openSpeed * window->timedMovement() );

            if ( closeLoc.getY() >= upperLeft.getY() )
                setPos( closeLoc );
        }

        // Open downward
        else if ( dir == DOWN )
        {
            moveBy( 0, openSpeed * window->timedMovement() );

            if ( closeLoc.getY() <= upperLeft.getY() )
                setPos( closeLoc );
        }
    }
}


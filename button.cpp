#include "button.h"

Button:: Button()
    :Entity( BUTTON, "", UNDESTRUCTIBLE, UNDESTRUCTIBLE, Point( 0, 0 ), Point( 0, 0 ), EMPTY, RECTANGLE, true, false )
{
    toggleOn = OFF;
    frameTouched = 0;
    window = Window::getInstance();
    dir = UP;
    setImages( "./data/images/btnUp.png", "./data/images/btnDown.png" );
    resourceMgr->loadSound( "./data/audio/buttonSound.wav", "button" );
}

Button:: Button( string name, Point uL, Point lR , Direction d)
    :Entity( BUTTON, name, UNDESTRUCTIBLE, UNDESTRUCTIBLE, uL, lR, EMPTY, RECTANGLE, true, false )
{
    toggleOn = OFF;
    frameTouched = 0;
    window = Window::getInstance();
	dir = d;
	resourceMgr->loadSound( "./data/audio/buttonSound.wav", "button" );
	setImages( "./data/images/btnUp.png", "./data/images/btnDown.png" );
}

void Button:: onTouch()
{
    if ( window->getFrameNumber() - frameTouched > 2 )
    {
        //Play sound effect
        resourceMgr->playSound( "button" );
        toggleOn = !toggleOn;

        if(toggleOn)
            Entity::onTouch();
        else
            Entity::onUnTouch();
    }

    frameTouched = window->getFrameNumber();
}

void Button:: draw()
{
    glColor3f( 0, 1, 1 );
    if ( toggleOn )
    {
        if ( dir == UP )
            resourceMgr->drawImage( imageDown, upperLeft.getX(), lowerRight.getX(),
                                    lowerLeft.getY(), upperRight.getY() );

        else if ( dir == DOWN )
            resourceMgr->drawImage( imageDown, upperLeft.getX(), lowerRight.getX(),
                                            upperLeft.getY(), lowerRight.getY() );

        else if ( dir == RIGHT )
            resourceMgr->drawImage( imageDown, upperRight, lowerRight,
                                            upperLeft, lowerLeft) ;

        else if ( dir == LEFT )
            resourceMgr->drawImage( imageDown, upperLeft, lowerLeft,
                                            upperRight, lowerRight) ;
    }
    else
    {
        if ( dir == UP )
            resourceMgr->drawImage( imageUp, upperLeft.getX(), lowerRight.getX(),
                                    lowerLeft.getY(), upperRight.getY() );

        else if ( dir == DOWN )
            resourceMgr->drawImage( imageUp, upperLeft.getX(), lowerRight.getX(),
                                            upperLeft.getY(), lowerRight.getY() );

        else if ( dir == RIGHT )
            resourceMgr->drawImage( imageUp, upperRight, lowerRight,
                                            upperLeft, lowerLeft) ;


        else if ( dir == LEFT )
           resourceMgr->drawImage( imageUp, upperLeft, lowerLeft,
                                            upperRight, lowerRight) ;
    }
}

void Button:: setToggle( bool status )
{
    toggleOn = status;
}

void Button:: setImages( string u, string d )
{
    imageUp   = u;
    imageDown = d;
    resourceMgr->loadImage( imageUp, imageUp );
    resourceMgr->loadImage( imageDown, imageDown );
}

Button:: ~Button()
{
    window->release();
}

void Button:: onAlways()
{
   //if ( toggleOn )
   //     Entity:: onTouch();

   // else
     //   Entity:: onUnTouch();
}


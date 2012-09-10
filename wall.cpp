#include "wall.h"
#include "entitycontainer.h"


Wall:: Wall()
    :Entity( WALL, "", UNDESTRUCTIBLE, UNDESTRUCTIBLE, Point( 0, 0 ), Point( 0, 0 ), SOLID, RECTANGLE, true, false )
{
    strength = UNDESTRUCTIBLE;
    minDamage = 2;
}

Wall:: Wall( string name, bool isDestructible, int wHealth, int wStrength, Point uL, Point lR )
    :Entity( WALL, name, wHealth, isDestructible, uL, lR, SOLID, RECTANGLE, true, false )
{
    strength = wStrength;
    minDamage = 2;
    resourceMgr->loadImage("./data/images/brick1.png", "brick1");
}

void Wall::onTouch()
{
    if ( destructible and health > 0 )
    {
        for ( int i = 0; i < touchedBy.size(); i++ )
        {
            Entity* current = getEntity( touchedBy[i] );

            if ( current->getEntityType() == BALL )
            {
                //=========================================
                /* Each Letter denotes the direction a ball
                   is coming from.
                                |              |
                            A   |      B       |   C
                                |              |
                        --------|--------------|--------
                                |              |
                                |              |
                            D   |     WALL     |   E
                                |              |
                                |              |
                                |              |
                        --------|--------------|--------
                                |              |
                            F   |      G       |   H
                                |              |
                */
                //=========================================

                // Direction A
                if ( current->getCenter().getX() < upperLeft.getX() and
                     current->getCenter().getY() > upperLeft.getY() )
                {
                    health -= abs(((int)(((Ball*)current)->getYForce() + ((Ball*)current)->getXForce() ) / strength));
                }

                // Drection B
                else if ( current->getCenter().getX() > upperLeft.getX()  and
                          current->getCenter().getX() < lowerRight.getX() and
                          current->getCenter().getY() > upperLeft.getY() )
                {
                    health -= abs( ((int)((Ball*)current)->getYForce() / strength));
                }

                // Direction C
                else if ( current->getCenter().getX() > lowerRight.getX() and
                          current->getCenter().getY() > upperLeft.getY() )
                {
                    health -= abs(((int) (((Ball*)current)->getYForce() + ((Ball*)current)->getXForce() ) / strength));
                }

                // Direction D
                else if ( current->getCenter().getX() < upperLeft.getX() and
                          current->getCenter().getY() < upperLeft.getY() and
                          current->getCenter().getY() > lowerRight.getY() )
                {
                    health -= abs(((int)((Ball*)current)->getXForce() / strength));
                }

                // Direction E
                else if ( current->getCenter().getX() > lowerRight.getX() and
                          current->getCenter().getY() < upperLeft.getY()  and
                          current->getCenter().getY() > lowerRight.getY() )
                {
                    health -= abs(((int)((Ball*)current)->getXForce() / strength));
                }

                // Direction F
                else if ( current->getCenter().getX() < upperLeft.getX() and
                          current->getCenter().getY() < lowerRight.getY() )
                {
                    health -= abs(((int)(((Ball*)current)->getYForce() + ((Ball*)current)->getXForce() ) / strength));
                }

                // Direction G
                else if ( current->getCenter().getX() > upperLeft.getX()  and
                          current->getCenter().getX() < lowerRight.getX() and
                          current->getCenter().getX() < lowerRight.getY() )
                {
                    health -= abs(((int)((Ball*)current)->getYForce() / strength));
                }

                // Direction H
                else if ( current->getCenter().getX() > lowerRight.getX() and
                          current->getCenter().getY() < lowerLeft.getY() )
                {
                    health -= abs(((int)(((Ball*)current)->getYForce() + ((Ball*)current)->getXForce() ) / strength));
                }
            }
        }

    	if(health <= 0)
    	{
    		//entityContainer->removeEntity(name);
    	}
    }
}

int Wall:: getHealth()
{
    return health;
}

int Wall:: getStrength()
{
    return strength;
}

void Wall:: setStrength( int newStrength )
{
    strength = newStrength;
}

void Wall:: draw( string im )
{
    if ( health > 0 )
    {
        glColor4f(0.8,0.8,0.8,1.0);
        resourceMgr->drawImage( im, upperLeft.getX(), upperRight.getX() - 6, lowerLeft.getY(), upperRight.getY() - 6,
                                    0, getWidth() / 32.0, 0, getHeight() / 32.0 );

        //Top part.
        glColor4f(1.0,1.0,1.0,1.0);
        resourceMgr->drawImage( im, Point(upperLeft.getX() + 12, upperLeft.getY() + 6), Point(upperRight.getX() + 6, upperRight.getY() + 6),
                                Point(upperLeft.getX(), upperLeft.getY() - 6), Point(upperRight.getX() - 6, upperRight.getY() - 6),
                                Point(0, 12 / 32.0), Point(getWidth() / 32.0, 12 / 32.0), Point(0,0), Point(getWidth() / 32.0, 0));

        //Right part.
        glColor4f(0.5,0.5,0.5,1.0);
        resourceMgr->drawImage( im, Point(upperRight.getX() - 6, upperRight.getY() - 6), Point(upperRight.getX() + 6, upperRight.getY() + 6),
                                Point(lowerRight.getX() - 6, lowerRight.getY()), Point(lowerRight.getX() + 6, lowerRight.getY() + 12),
                                Point(0, getHeight() / 32.0), Point(12 / 32.0, getHeight() / 32.0), Point(0,0), Point(12 / 32.0, 0));

        glColor4f( 1, 1, 1, 1 );
    }
}

void Wall:: draw()
{
    draw( "brick1" );
}

void Wall:: setImage( string im )
{
    image = im;
}


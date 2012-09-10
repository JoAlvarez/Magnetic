#include "grid.h"
#include <GL/gl.h>
#include <math.h>

#define DEFAULT_GRID_SIZE       20
#define DEFAULT_GRID_RGB        0.25, 0.25, 0.25
#define DEFAULT_INTERCEPT_RGB   0.0, 0.45, 0.55

Grid* Grid::gridInstance = NULL;
int Grid::gridReferenceCount = 0;

Grid::Grid()
    :window( Window::getInstance() ), gridSize( DEFAULT_GRID_SIZE )
{
}

Grid::~Grid()
{
    window->release();
}

Grid* Grid::getInstance()
{
    if( !gridInstance )
        gridInstance = new Grid();

    gridReferenceCount++;
    return gridInstance;
}

void Grid::release()
{
    if( --gridReferenceCount <= 0 &&  gridInstance )
        delete gridInstance;

    if( gridReferenceCount < 0 )
        gridReferenceCount = 0;
}

Point Grid::getNearestIntersection( Point from )
{
    //Find the nearest x coordinate of the intersection to the point specified;
    double gridMidPoint     = gridSize / 2.0;
    double x                = from.getX();
    double yGridIntercept   = floor( ( abs( x ) + gridMidPoint ) / gridSize  );
    double nearestX         = yGridIntercept * gridSize;
    if( x < 0 )
        nearestX *= -1;

    //Find the nearest y coordinate of the intersection to the point specified;
    double y                = from.getY();
    double xGridIntercept   = floor( ( abs( y ) + gridMidPoint ) / gridSize  );
    double nearestY         = xGridIntercept * gridSize;
    if( y < 0 )
        nearestY *= -1;

    return Point( nearestX, nearestY );
}

void Grid::draw()
{
    glBegin( GL_LINES );
        glColor3f( DEFAULT_GRID_RGB );

        //Draw vertical lines
        for( int x = window->leftCoord(); x <= window->rightCoord(); ++x )
        {
            if( !( x % gridSize ) )
            {
                glVertex2f( x, window->topCoord() );
                glVertex2f( x, window->bottomCoord() );
            }
        }

        //Draw horizontal lines
        for( int y = window->bottomCoord(); y <= window->topCoord(); ++y )
        {
            if( !( y % gridSize ) )
            {
                glVertex2f( window->leftCoord(), y );
                glVertex2f( window->rightCoord(), y );
            }
        }

        //Color the intercepts
        glColor3f( DEFAULT_INTERCEPT_RGB );
        if( window->leftCoord() <= 0 && window->rightCoord() >= 0 )
        {
            glVertex2f( 0, window->topCoord() );
            glVertex2f( 0, window->bottomCoord() );
        }

        if( window->bottomCoord() <= 0 && window->topCoord() >= 0 )
        {
            glVertex2f( window->leftCoord(), 0 );
            glVertex2f( window->rightCoord(), 0 );
        }
    glEnd();
}

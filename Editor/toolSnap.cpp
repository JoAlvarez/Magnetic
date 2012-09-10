#include "toolSnap.h"
#include <GL/gl.h>
#include <math.h>

#define SNAP_INDICATOR_RADIUS   5.0
#define SNAP_INDICATOR_COLOR    1.0, 1.0, 1.0, 0.8

ToolSnap* ToolSnap::toolSnapInstance = NULL;
int ToolSnap::toolSnapReferenceCount = 0;

ToolSnap::ToolSnap()
    :snapping( true ), window( Window::getInstance() ), input( Input::getInstance() ), grid( Grid::getInstance() )
{
}

ToolSnap::~ToolSnap()
{
    window->release();
    input->release();
    grid->release();
}

ToolSnap* ToolSnap::getInstance()
{
    if( !toolSnapInstance )
        toolSnapInstance = new ToolSnap();

    toolSnapReferenceCount++;
    return toolSnapInstance;
}

void ToolSnap::release()
{
    if( --toolSnapReferenceCount <= 0 &&  toolSnapInstance )
        delete toolSnapInstance;

    if( toolSnapReferenceCount < 0 )
        toolSnapReferenceCount = 0;
}

void ToolSnap::snap()
{
    snapping = true;
}

void ToolSnap::unSnap()
{
    snapping = false;
}

bool ToolSnap::isSnapping()
{
    return snapping;
}

Point ToolSnap::getMouseLoc()
{
    if( snapping )
        return grid->getNearestIntersection( input->getMouseLoc() );
    else
        return input->getMouseLoc();
}

void ToolSnap::draw()
{
    //Assume the the indicator should be drawn snapped
    Point center = grid->getNearestIntersection( input->getMouseLoc() );

    //If its not snapped draw circle ad the exact cursor location
    if( !snapping )
        center = input->getMouseLoc();

    //Enable alpha
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f( SNAP_INDICATOR_COLOR );

        //Draw circle
        glBegin(GL_TRIANGLE_FAN);
            for(int i = 0; i <= 360; ++i)
                glVertex2f(cos(i * 3.14 / 180.0) * SNAP_INDICATOR_RADIUS + center.getX(), sin(i * 3.14 / 180.0) * SNAP_INDICATOR_RADIUS + center.getY());
        glEnd();

    glDisable( GL_BLEND );
}

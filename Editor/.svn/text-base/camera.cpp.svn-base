#include "camera.h"
#include <iostream>
using namespace std;

Camera* Camera::cameraInstance = NULL;
int Camera::cameraReferenceCount = 0;

void Camera::setCoords()
{
    double frameWidth   = window->getWidth();
    double frameHeight  = window->getHeight();

    //Expand away from the focus so that the focus is considered the center
    //of the camera
    double left     = focus.getX() - (  scale * frameWidth / 2.0 );
    double right    = focus.getX() + (  scale * frameWidth / 2.0 );
    double bottom   = focus.getY() - (  scale * frameHeight / 2.0 );
    double top      = focus.getY() + (  scale * frameHeight / 2.0 );
    window->setCoord( left, right, bottom, top );
}

Camera* Camera::getInstance()
{
    if( !cameraInstance )
        cameraInstance = new Camera();

    cameraReferenceCount++;
    return cameraInstance;
}

void Camera::release()
{
    if( --cameraReferenceCount <= 0 &&  cameraInstance )
        delete cameraInstance;

    if( cameraReferenceCount < 0 )
        cameraReferenceCount = 0;
}

Camera::Camera()
    :input( Input::getInstance() ),
     window( Window::getInstance() ),
     focus( ( window->leftCoord() + window->rightCoord() ) / 2.0, ( window->bottomCoord() + window->topCoord() ) / 2.0 ),
     scale( 1.0 ),
     scaleSpeed( 10.0 ),
     enabled( false )
{
}

Camera::~Camera()
{
    window->release();
    input->release();
}

void Camera::update()
{
    if( !enabled )
        return;

    //Pan the camera
    if( input->leftMouseDown() )
        focus.move( input->getMouseXRel() * -1, input->getMouseYRel() * -1 );

    //Zoom out
    if( input->getMouseInput() == "Wheel Down" )
        scale += scaleSpeed / 100.0;

    //Zoom in
    if( input->getMouseInput() == "Wheel Up" )
        scale -= scaleSpeed / 100.0;
    setCoords();
}

void Camera::enable()
{
    enabled = true;
}

void Camera::disable()
{
    enabled = false;
}

bool Camera::isEnabled()
{
    return enabled;
}

#include "clickablebutton.h"


ClickableButton::ClickableButton( string title, Point uL, int fontSize, int padding )
{
    resourceMgr =   ResourceMgr::getInstance();
    input       =   Input::getInstance();
    window      =   Window::getInstance();
    this->fontSize  = fontSize;
    this->padding   = padding;
    resourceMgr->loadFont( "./data/fonts/arial.ttf", "linkFont", fontSize );
    this->title =   title;
    this->uL    =   uL;
    hover       =   true;
}

bool ClickableButton::isClicked()
{
    double leftx       =   uL.getX()   + window->leftCoord();
    double rightx      =   leftx       + ( title.length() * fontSize );
    double uppery      =   uL.getY()   + window->bottomCoord();
    double lowery      =   uppery      - ( fontSize + padding );
    if (
         input->getMouseXloc()  >= leftx   &&
         input->getMouseXloc()  <= rightx  &&
         input->getMouseYloc()  >= lowery  &&
         input->getMouseYloc()  <= uppery  &&
         input->getMouseInput() == "Left Up"
       )
        return true;
    else
        return false;
}

bool ClickableButton::isMouseOver()
{
    double leftx       =   uL.getX()   + window->leftCoord();
    double rightx      =   leftx       + ( title.length() * fontSize );
    double uppery      =   uL.getY()   + window->bottomCoord();
    double lowery      =   uppery      - ( fontSize + padding );
    if (
         input->getMouseXloc() >= leftx   &&
         input->getMouseXloc() <= rightx  &&
         input->getMouseYloc() >= lowery  &&
         input->getMouseYloc() <= uppery
       )
        return true;
    else
        return false;
}

void ClickableButton::draw()
{
    double leftx       =   uL.getX()   + window->leftCoord();
    double rightx      =   leftx       + ( title.length() * fontSize );
    double uppery      =   uL.getY()   + window->bottomCoord();
    double lowery      =   uppery      - ( fontSize + padding );
    if( isMouseOver() && hover == true )
        glColor3f( 0.35, 0.42, 1 );
    else
        glColor3f( 1.0, 1.0, 1.0 );

    resourceMgr->drawText( "linkFont",
                            title,
                            leftx,
                            lowery );

    glColor3f( 1.0, 1.0, 1.0 );

}

void ClickableButton::enableHover( bool enable )
{
    hover = enable;
}

ClickableButton::~ClickableButton()
{
    input->release();
    window->release();
}

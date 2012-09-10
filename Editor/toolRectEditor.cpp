#include "toolRectEditor.h"
#include <GL/gl.h>
#include <iostream>
using namespace std;

ToolRectEditor*  ToolRectEditor::toolRectEditorInstance = NULL;
int              ToolRectEditor::toolRectEditorReferenceCount = 0;


void ToolRectEditor::drawRect( Rect& rectangle )
{
    glColor3f( 1.0, 1.0, 1.0 );
    glBegin( GL_LINE_LOOP );
        glVertex2f( rectangle.ul.getX(), rectangle.ul.getY() );
        glVertex2f( rectangle.lr.getX(), rectangle.ul.getY() );
        glVertex2f( rectangle.lr.getX(), rectangle.lr.getY() );
        glVertex2f( rectangle.ul.getX(), rectangle.lr.getY() );
    glEnd();
}

Rect ToolRectEditor::createRec()
{
    Point ul;
    Point lr;
    Rect temp;

    //Expanding down and to the left
    if( !expandingRight && !expandingUp )
    {
        ul = Point( expandingTo.getX(), expandingFrom.getY() );
        lr = Point( expandingFrom.getX(), expandingTo.getY() );
    }

    //Expanding down and to the right
    else if( expandingRight && !expandingUp )
    {
        ul = expandingFrom;
        lr = expandingTo;
    }

    //Expanding up and to the left
    else if( !expandingRight && expandingUp )
    {
        ul = expandingTo;
        lr = expandingFrom;
    }

    //Expanding up and to the right
    else if( expandingRight && expandingUp )
    {
        ul = Point( expandingFrom.getX(), expandingTo.getY() );
        lr = Point( expandingTo.getX(), expandingFrom.getY() );
    }
    temp.ul = ul;
    temp.lr = lr;
    return temp;
}

void ToolRectEditor::setExpandingDirection()
{
    expandingRight = true;
    expandingUp = true;

    if( expandingFrom.getX() > expandingTo.getX() )
        expandingRight = false;

    if( expandingFrom.getY() > expandingTo.getY() )
        expandingUp = false;

}

ToolRectEditor::ToolRectEditor()
    : expandingFrom( 0, 0 ),
      expandingTo( 0, 0 ),
      expandingRight( false ),
      expandingUp( false ),
      editing( false ),
      snapTool( ToolSnap::getInstance() ),
      input( Input::getInstance() )
{
}

ToolRectEditor::~ToolRectEditor()
{
        snapTool->release();
        input->release();
}

ToolRectEditor* ToolRectEditor::getInstance()
{
    if( !toolRectEditorInstance )
        toolRectEditorInstance = new ToolRectEditor();

    toolRectEditorReferenceCount++;
    return toolRectEditorInstance;
}

void ToolRectEditor::release()
{
    if( --toolRectEditorReferenceCount <= 0 &&  toolRectEditorInstance )
        delete toolRectEditorInstance;

    if( toolRectEditorReferenceCount < 0 )
        toolRectEditorReferenceCount = 0;
}

void ToolRectEditor::edit( Point anchor )
{
    //Only allow for one edit to occur at a time
    if( editing )
        return;

    editing = true;
    expandingTo = expandingFrom = anchor;
}

void ToolRectEditor::cancel()
{
    editing = false;
    expandingTo = expandingFrom;
}

void ToolRectEditor::draw()
{
    if( !editing )
        return;

    Rect temp = createRec();
    drawRect( temp );
}

void ToolRectEditor::update()
{
    //Check if editing has completed
    if( !input->leftMouseDown() && editing )
        editing = false;

    //Check if use canceled the edit with right mouse click
    if( input->rightMouseDown() )
        cancel();

    //If were not editing don't move the expandingTo point
    if( !editing )
        return;

    //We are always expanding towards the mouse
    expandingTo = snapTool->getMouseLoc();
    setExpandingDirection();

}

bool ToolRectEditor::finishedEditing()
{
    return !editing;
}

Rect ToolRectEditor::getEditedRect()
{
    return createRec();
}

#include "toolWallEditor.h"
#include <GL/gl.h>
#include <sstream>
#include <iostream>

using namespace std;

#define NON_SELECTED_COLOR 0.0, 0.3, 1.0

void ToolWallEditor::draw( Rect& rectangle )
{
    glColor3f( NON_SELECTED_COLOR );
    glBegin( GL_LINE_LOOP );
        glVertex2f( rectangle.ul.getX(), rectangle.ul.getY() );
        glVertex2f( rectangle.lr.getX(), rectangle.ul.getY() );
        glVertex2f( rectangle.lr.getX(), rectangle.lr.getY() );
        glVertex2f( rectangle.ul.getX(), rectangle.lr.getY() );
    glEnd();
}
//%name:		destructible:	health:		strength:	ul_x:		ul_y:		lr_x:		lr_y:
//    string  name;
//    bool    isDestructible;
//    int     health;
//    int     strength;
//    Rect    dimensions;
void ToolWallEditor::saveWall( Wall& wall )
{
    string temp;
    stringstream stream;
    vector< string > tempVec;

    //Name
    tempVec.push_back( wall.name );

    //Destructible
    tempVec.push_back( fileWriter->boolToString( wall.isDestructible ) );

    //Health
    tempVec.push_back( fileWriter->intToString( wall.health ) );

    //Strength
    tempVec.push_back( fileWriter->intToString( wall.strength ) );

    //UL_X
    tempVec.push_back( fileWriter->doubleToString( wall.dimensions.ul.getX() ) );

    //UL_Y
    tempVec.push_back( fileWriter->doubleToString( wall.dimensions.ul.getY() ) );

    //LR_X
    tempVec.push_back( fileWriter->doubleToString( wall.dimensions.lr.getX() ) );

    //LR_Y
    tempVec.push_back( fileWriter->doubleToString( wall.dimensions.lr.getY() ) );

    fileWriter->addLine( tempVec );

}

ToolWallEditor::ToolWallEditor()
    :walls( 0 ),
     wallsMade( 0 ),
     toolIsActive( false ),
     editingWall( false ),
     rectEditor( ToolRectEditor::getInstance() ),
     snapTool( ToolSnap::getInstance() ),
     input( Input::getInstance() ),
     fileWriter( ToolFileWriter::getInstance() )
{
}

ToolWallEditor::~ToolWallEditor()
{
    rectEditor->release();
    snapTool->release();
    input->release();
    fileWriter->release();
}

void ToolWallEditor::update()
{
    if( !toolIsActive )
        return;

    if( input->leftMouseDown() && !editingWall )
    {
        editingWall = true;
        rectEditor->edit( snapTool->getMouseLoc() );
    }

    if( editingWall && rectEditor->finishedEditing() )
    {
        editingWall = false;

        //If the wall has no area don't save it
        if( rectEditor->getEditedRect().getArea() <= 0 )
            return;

        Wall temp;

        temp.name = "wall";
        temp.name += fileWriter->intToString( wallsMade );

        temp.dimensions = rectEditor->getEditedRect();
        walls.push_back( temp );
        ++wallsMade;
    }
}

void ToolWallEditor::enable()
{
    toolIsActive = true;
}

void ToolWallEditor::disable()
{
    toolIsActive = false;
    rectEditor->cancel();
}

void ToolWallEditor::draw()
{
    for( int i = 0; i < walls.size(); ++i )
        draw( walls[ i ].dimensions );
}

void ToolWallEditor::save()
{
    vector< string > temp;
    //Declare wall parsing
    temp.push_back( "#WALL" );
    fileWriter->addLine( temp );
    temp.clear();

    //Show wall file format
    temp.push_back( "%name:" );
    temp.push_back( "destructible:" );
    temp.push_back( "health:" );
    temp.push_back( "strength:" );
    temp.push_back( "ul_x:" );
    temp.push_back( "ul_y:" );
    temp.push_back( "lr_x:" );
    temp.push_back( "lr_y:" );
    fileWriter->addLine( temp );
    temp.clear();

    //Create seperator
    temp.push_back( "%________________________________________________________________________________________________________________________" );
    fileWriter->addLine( temp );

    //Save all walls
    for( int i = 0; i < walls.size(); ++i )
        saveWall( walls[ i ] );

}

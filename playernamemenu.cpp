#include "playernamemenu.h"
#include <fstream>
using namespace std;

PlayerNameMenu::PlayerNameMenu()
{
    resourceMgr =   ResourceMgr::getInstance();
    input       =   Input::getInstance();
    window      =   Window::getInstance();
    isOpen      =   false;
    initStart   =   false;
    gatherInput =   false;
    numInput    =   0;
    clickNum    =   0;
    finished    =   false;
    player      =   "Enter player name";
    inFieldHighlighted = false;
    resourceMgr->loadImage( "./data/images/playernamemenu.png", "namemenu" );
    resourceMgr->loadImage( "./data/images/infield.png", "inputfield" );
    resourceMgr->loadFont( "./data/fonts/arial.ttf", "font", 14 );
    buttons.push_back( ClickableButton( "OK", Point( 345, 310 ), 19, 4 ) );
    buttons.push_back( ClickableButton( "CANCEL", Point( 605, 310 ), 19, 4 ) );
}

void PlayerNameMenu::checkInput()
{
    if( buttons[0].isClicked() )
    {
        if( player.length() == 0 )
        {
            player = "Enter player name!";
            clickNum = 0;
            numInput = 0;
        }
        else
        {
            if( isNewName( player ) )
                finished = true;
            else
            {
                player = "Profile already exists.";
                clickNum = 0;
                numInput = 0;
            }
        }

        if( finished && numInput > 0 )
        {
            if( isOpen == true )
                isOpen = false;
            createNewProfile( player );
            initStart = true;
            saveName();
        }
    }

    if( buttons[1].isClicked() )
    {
        if( isOpen == true )
            isOpen = false;
    }


    if( input->getMouseXloc() >= 360 && input->getMouseXloc() <= 682
        && input->getMouseYloc() >= 373 && input->getMouseYloc() <= 400 )
    {

        if( inFieldHighlighted == false )
            inFieldHighlighted = true;

        if( input->getMouseInput() == "Left Down" )
        {
            if( gatherInput == false )
                gatherInput = true;
            if( clickNum == 0 )
                player = "";
            ++clickNum;
        }
    }
    else
    {
        if( inFieldHighlighted == true )
            inFieldHighlighted = false;

        if( input->getMouseInput() == "Left Down" )
        {
            if( gatherInput == true )
                gatherInput = false;
        }
    }

    if( gatherInput == true )
    {
        string temp = input->getKeyInput();
        if( player.length() < 23 )
        {
            if( temp.length() == 1 )
            {
                player += temp;
                ++numInput;
            }
            if( temp == "space" )
            {
                player += " ";
                ++numInput;
            }
        }
        if( temp == "backspace" )
        {
            if( numInput != 0 )
            {
                player.erase( player.end() - 1 );
                --numInput;
            }
        }
        if( temp == "enter" )
        {
            if( player.length() == 0 )
            {
                player = "Enter player name!";
                clickNum = 0;
                numInput = 0;
            }
            else
            {
                if( isNewName( player ) )
                    finished = true;
                else
                {
                    player = "Profile already exists.";
                    clickNum = 0;
                    numInput = 0;
                }
            }

            if( finished && numInput > 0 )
            {
                createNewProfile( player );
                if( isOpen == true )
                    isOpen = false;
                initStart = true;
                saveName();
            }
        }
    }
}

void PlayerNameMenu::saveName()
{
    vector< string > tempInfo;
    ifstream playerFile;
    string tempPlayer;
    playerFile.open( "./data/player.txt" );
    if( playerFile.is_open() )
    {
        while( !playerFile.eof() )
        {
            playerFile >> tempPlayer;
            tempInfo.push_back( tempPlayer );
        }
    }
    playerFile.close();

    ofstream file;
    if( tempInfo.size() != 0 )
    {
        file.open( "./data/player.txt" );
        for( int i = 0; i <= tempInfo.size() - 1; ++i )
        {
            if( tempInfo[ i ] != "" )
                file << tempInfo[ i ] << endl;
        }

        file << player;
    }
    file.close();
}

void PlayerNameMenu::draw()
{
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glEnable( GL_BLEND );
    glColor4f( 0.0, 0.0, 0.0, .65 );
    glBegin( GL_QUADS );
        glVertex2f( window->leftCoord(),
                    window->topCoord() );
        glVertex2f( window->rightCoord(),
                    window->topCoord() );
        glVertex2f( window->rightCoord(),
                    window->bottomCoord() );
        glVertex2f( window->leftCoord(),
                    window->bottomCoord() );
    glEnd();
    glDisable( GL_BLEND );
    glColor3f( 1, 1, 1 );

    resourceMgr->drawImageOverlay( "namemenu",
                                    .31,
                                    .71,
                                    .35,
                                    .65);
    if( inFieldHighlighted == true || gatherInput == true )
        glColor3f( 0.5, 0.7, .9 );

    resourceMgr->drawImageOverlay( "inputfield",
                                    .31,
                                    .71,
                                    .48,
                                    .53 );
    glColor3f( 1, 1, 1 );

    resourceMgr->drawText( "font", player, 374, 381 );

    for( int i = 0; i <= buttons.size() - 1; ++i )
        buttons[i].draw();
}

void PlayerNameMenu::createNewProfile( string name )
{
    ofstream newProfile;
    string profileName = "./data/profiles/" + name + ".txt";
    newProfile.open( profileName.c_str() );
    string junk = "";
    newProfile << junk;
}

void PlayerNameMenu::open()
{
    isOpen = true;
}

bool PlayerNameMenu::isNewName( string desiredName )
{
    ifstream playerFile;
    string tempPlayer;
    playerFile.open( "./data/player.txt" );
    if( playerFile.is_open() )
    {
        while( !playerFile.eof() )
        {
           playerFile >> tempPlayer;
           if( tempPlayer == desiredName )
           {
                playerFile.close();
                return false;
           }
        }
    }
    playerFile.close();
    return true;
}

bool PlayerNameMenu::inMenu()
{
    return isOpen;
}

bool PlayerNameMenu::isStart()
{
    return initStart;
}

PlayerNameMenu::~PlayerNameMenu()
{
    input->release();
    window->release();
}

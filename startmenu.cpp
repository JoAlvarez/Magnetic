#include "startmenu.h"
#include <iostream>
StartMenu::StartMenu()
{
    resourceMgr =   ResourceMgr::getInstance();
    input       =   Input::getInstance();
    window      =   Window::getInstance();
    isOpen      =   true;
    nameMenu    =   new PlayerNameMenu();
    resourceMgr->loadImage( "./data/images/startmenu.png", "startMenu" );
    resourceMgr->loadFont( "./data/fonts/arial.ttf", "profileFont", 12 );
    buttons.push_back( ClickableButton( "NEW GAME", Point( 450, 450 ), 19, 4 ) );
    buttons.push_back( ClickableButton( "LOAD GAME", Point( 447, 400 ), 19, 4 ) );
    buttons.push_back( ClickableButton( "OPTIONS", Point( 465, 350 ), 19, 4 ) );
    buttons.push_back( ClickableButton( "QUIT", Point( 490, 300 ), 19, 4 ) );
}

void StartMenu::checkInput()
{
    if( nameMenu->isStart() )
    {
        if( isOpen == true )
            isOpen = false;
    }
    else
    {
        for( int i = 0; i <= buttons.size() - 1; ++i )
            buttons[i].enableHover( true );
    }

    if( !nameMenu->inMenu() && isOpen == true )
    {
        if( buttons[0].isClicked() )
        {
            nameMenu->open();
            for( int i = 0; i <= buttons.size() - 1; ++i )
                buttons[i].enableHover( false );
        }
        if( buttons[1].isClicked() )
        {
            if( isOpen == true )
                isOpen = false;
        }
        if( buttons[2].isClicked() )
        {
            if( isOpen == true )
                isOpen = false;
        }
        if( buttons[3].isClicked() )
            exit( 0 );
    }
    else
        nameMenu->checkInput();
}

void StartMenu::draw()
{
    resourceMgr->drawImage( "startMenu",
                            window->leftCoord(),
                            window->rightCoord(),
                            window->bottomCoord(),
                            window->topCoord() );

    for( int i = 0; i <= buttons.size() - 1; ++i )
    {
        if( !nameMenu->inMenu() )
            buttons[i].draw();
    }

    if( nameMenu->inMenu() )
        nameMenu->draw();

    glColor3f( 1, 1, 1 );
    resourceMgr->drawTextOverlay( "profileFont", "profile: ", .8, .017 );
}

bool StartMenu::inMenu()
{
    return isOpen;
}

void StartMenu::open()
{
    if( isOpen == false )
        isOpen = true;
}

StartMenu::~StartMenu()
{
    input->release();
    window->release();
}



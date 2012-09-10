#include "menu.h"

const vector< char* >& Menu::tokenize( char links[] )
{
    vector< char* > tempVec;
    //Tokenize cstring for each seperate link in the cstring.
    char* temp = strtok( links, " ," );

    for( int i = 0; temp != NULL; ++i )
    {
        tempVec.push_back( temp );
        temp = strtok (NULL, " ,");
    }

    return tempVec;
}

Menu::Menu()
{
    padding     =   0;
    numLinks    =   0;
    resourceMgr =   ResourceMgr::getInstance();
    input       =   Input::getInstance();
    window      =   Window::getInstance();
}

Menu::Menu( Point upperLeft, char linkTitle[], int padding )
{
    linkTitles      =   tokenize( linkTitle );
    numLinks        =   linkTitles.size();
    this->padding   =   padding;
    this->upperLeft =   upperLeft;
    input           =   Input::getInstance();
    window          =   Window::getInstance();
    resourceMgr     =   ResourceMgr::getInstance();
}

void Menu::checkInput()
{

}

void Menu::draw()
{

}

Menu::~Menu()
{
    input->release();
    window->release();
}

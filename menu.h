#ifndef  __MENU_H__
#define  __MENU_H__

#include "point.h"
#include "input.h"
#include "clickablebutton.h"
#include "resourcemgr.h"

#define  M_FONT_HEIGHT 12
#define  M_FONT_WIDTH  4

class Menu
{
    private:
        char                        linkTitle[];
        Point                       upperLeft;
        int                         padding;
        Input*                      input;
        Window*                     window;
        ResourceMgr*                resourceMgr;
        vector< char* >             linkTitles;
        vector< ClickableButton >   buttons;
        int                         numLinks;
        const vector< char* >&      tokenize( char links[] );

    public:
        Menu();
        Menu( Point upperLeft, char linkTitles[], int padding );
        virtual void checkInput();
        virtual void draw();
        virtual ~Menu();
};

#endif

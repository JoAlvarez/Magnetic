#ifndef __START_MENU_H__
#define __START_MENU_H__

#include "input.h"
#include "clickablebutton.h"
#include "resourcemgr.h"
#include "playernamemenu.h"

class StartMenu
{
    private:
        Input*                      input;
        Window*                     window;
        PlayerNameMenu*             nameMenu;
        ResourceMgr*                resourceMgr;
        bool                        isOpen;
        vector< ClickableButton >   buttons;

    public:
        StartMenu();
        void draw();
        void checkInput();
        bool inMenu();
        void open();
        ~StartMenu();
};

#endif


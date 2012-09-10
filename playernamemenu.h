#ifndef __PLAYER_NAME_MENU__
#define _PLAYER_NAME_MENU__

#include "input.h"
#include "clickablebutton.h"
#include "resourcemgr.h"

class PlayerNameMenu
{

    private:
        Input*                      input;
        Window*                     window;
        ResourceMgr*                resourceMgr;
        bool                        isOpen;
        vector< ClickableButton >   buttons;
        bool                        initStart;
        bool                        inFieldHighlighted;
        bool                        gatherInput;
        string                      player;
        int                         numInput;
        int                         clickNum;
        bool                        finished;

    public:
        PlayerNameMenu();
        void checkInput();
        void draw();
        void open();
        bool inMenu();
        bool isStart();
        void saveName();
        void createNewProfile( string name );
        bool isNewName( string desiredName );
        ~PlayerNameMenu();
};

#endif

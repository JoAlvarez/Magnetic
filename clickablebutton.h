#ifndef  __CLICKABLE_BUTTON_H__
#define  __CLICKABLE_BUTTON_H__

#include "point.h"
#include "input.h"
#include "resourcemgr.h"

class ClickableButton
{
    private:
        string          title;
        Point           uL;
        Input*          input;
        Window*          window;
        ResourceMgr*    resourceMgr;
        double          leftx;
        double          rightx;
        double          uppery;
        double          lowery;
        int             fontSize;
        int             padding;
        bool            hover;

    public:
        ClickableButton( string title, Point uL, int fontSize, int padding );
        void draw();
        bool isClicked();
        bool isMouseOver();
        void enableHover( bool hover );
        ~ClickableButton();
};

#endif

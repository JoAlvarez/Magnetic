#ifndef __TOOL_SNAP_H__
#define __TOOL_SNAP_H__

#include "point.h"
#include "window.h"
#include "input.h"
#include "grid.h"

class ToolSnap
{
    private:
        bool                    snapping;
        Window*                 window;
        Input*                  input;
        Grid*                   grid;
        static ToolSnap*        toolSnapInstance;
        static int              toolSnapReferenceCount;

    public:
                                ToolSnap();
                                ~ToolSnap();
        static                  ToolSnap* getInstance();
        void                    release();
        void                    snap();
        void                    unSnap();
        bool                    isSnapping();
        Point                   getMouseLoc();
        void                    draw();
};

#endif

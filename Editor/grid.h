#ifndef __GRID_H__
#define __GRID_H__

#include "window.h"
#include "point.h"

class Grid
{
    private:
        Window*                 window;
        int                     gridSize;

        static Grid*            gridInstance;
        static int              gridReferenceCount;

    public:
        Grid();
        ~Grid();
        static Grid*            getInstance();
        void                    release();
        Point                   getNearestIntersection( Point from );
        void                    draw();
};

#endif

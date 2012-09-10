#ifndef __RECT_H__
#define __RECT_H__
#include "point.h"

struct Rect
{
    Point ul;
    Point lr;
    double getArea()
    {
        double width    = lr.getX() - ul.getX();
        double height   = ul.getY() - lr.getY();
        return width * height;
    }
};

#endif

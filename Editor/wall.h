#ifndef __WALL_H__
#define __WALL_H__

#include "point.h"
#include "rect.h"
#include <string>

using namespace std;

struct Wall
{
    string  name;
    bool    isDestructible;
    int     health;
    int     strength;
    Rect    dimensions;
    bool    selected;
};
#endif


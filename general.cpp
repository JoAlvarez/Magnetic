#include "general.h"

General::General()
    :Entity()
{
    hasImage = false;
}

General::General(string name, Point upperLeft, double height, double width, string image)
    :Entity(GENERAL, name, 100, false, upperLeft, width, height, EMPTY, RECTANGLE, true, false)
{
    if(image == "N/A")
        hasImage = false;
    else
    {
        hasImage = true;
        resourceMgr->loadImage(image, name);
    }
}

void General::draw()
{
    if(hasImage)
        resourceMgr->drawImage(name, upperLeft, upperRight, lowerLeft,lowerRight);
}

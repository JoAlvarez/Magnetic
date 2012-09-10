#ifndef __GENERAL_H__
#define __GENERAL_H__

#include "entity.h"

class General
    :public Entity
{
    private:
        bool hasImage;
    public:
        General();
        General(string name, Point upperLeft, double height, double width, string image);
        void draw();
};

#endif

#ifndef __BUMPER_H__
#define __BUMPER_H__
#include "entity.h"
#include "window.h"
#include "point.h"
#include "resourcemgr.h"
#include "ball.h"

class Bumper : public Entity
{
    private:
        int bumpValue;
        double radius;

        Window * window;

		ResourceMgr* resourceMgr;

    public:
        Bumper();
        Bumper(string name, int bumpVal, int health, double radius, Substance sub, Point center);

        ~Bumper();

        int getBumpValue();
        void setBumpValue(int bumpVal);
        void bump(Entity* ball);

        void onTouch();
        void draw();

};






#endif

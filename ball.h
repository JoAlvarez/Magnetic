#ifndef __BALL_H__
#define __BALL_H__
#include "entity.h"
#include "window.h"
#include "point.h"
#include "resourcemgr.h"



//Defines a Polarity datatype that can be 3 values, POSITIVE, NEGATIVE, or NEUTRAL.
enum Polarity
{
    POSITIVE = 1,
    NEGATIVE = -1,
    NEUTRAL = 0
};


class Ball : public Entity
{
    private:

        Polarity charge;

        double mass;
        double xVel;
        double yVel;
        double radius;

        double brightness;

        bool effectedByMagnet;

        Window * window;

		ResourceMgr* resourceMgr;

    public:

        Ball();
        Ball(string name, Polarity p, double m, int health, double radius, Substance sub, Point center);
        Ball(string name, Polarity p, double m, double xVel, double yVel, int health, double radius, Substance substance, Point center);

        ~Ball();

        Polarity getCharge();

        void setCharge(Polarity p);
        double getXVel();
        double getYVel();
        double getMass();
        void setXVel(double x);
        void setYVel(double y);
        double getXForce();
        double getYForce();
        void move();
        void movedByMagnet();

        void onAlways();
        void onTouch();

        void draw();

        void wasTouchedBy(Detectable* d, Point loc1, Point loc2, double xAmount, double yAmount);

        unsigned long long frameTouched;
};

#endif

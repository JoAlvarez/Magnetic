#ifndef __MAGNET_H__
#define __MAGNET_H__

#include "mathfunctions.h"
#include "ball.h"

class Magnet
        :public Entity
{
    private:

        Polarity charge;

        double magneticForce;
        double maxDistance;

        Window* window;

        bool on;

    public:
        Magnet(string name, Polarity c, double strength, double reach, bool on, Point center,double radius);

        void onAlways();
        void setPolarity(Polarity c);
        void setStrength(double s);
        void setReach(double distance);
        void pull(Entity* b);
        void push(Entity* b);

        Polarity getCharge() const;

        double getStrength() const;
        double getReach() const;

        void draw();


};
#endif

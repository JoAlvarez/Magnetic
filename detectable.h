#ifndef __DETECTABLE_H__
#define __DETECTABLE_H__

#include "point.h"

enum DetectableType
{
    RECTANGLE, CIRCLE
};

enum Substance
{
    EMPTY, RUBBER, SOLID
};

enum Direction
{
    UP, DOWN, LEFT, RIGHT
};

class Detectable
{

    protected:

        Point           upperLeft;
        Point           upperRight;
        Point           lowerRight;
        Point           lowerLeft;
        Point           center;

        double          width;
        double          height;

        bool            fixed;
        bool            moves;

        Substance       substance;

        DetectableType  dType;

        void circleOnRectDetection(Detectable* circle, Detectable* rect);
        void rectOnRectDetection(Detectable* rect1, Detectable* rect2);
        void circleOnCircleDetection(Detectable* circle1, Detectable* circle2);

        void circleOnRectResponce(Detectable* circle, Detectable* rect, double dx, double dy);
        void circleOnCircleResponce(Detectable* c1, Detectable* c2, double distance, double angle);

    public:

        Detectable();
        Detectable(Point upperLeft, Point lowerRight, Substance substance, DetectableType type, bool fixed, bool moves);
        Detectable(Point upperLeft, double width, double height, Substance substance, DetectableType type, bool fixed, bool moves);
        Detectable(Point center, double radius, Substance substance, DetectableType type, bool fixed, bool moves);

        double getWidth();
        double getHeight();
        double getRadius();

        DetectableType getDetectableType();
        Substance      getSubstance();

        Point getCenter();
        Point getUpperLeft();
        Point getLowerRight();

        void handleDetection(Detectable* d2);

        void moveBy(double dx, double dy);

        virtual void wasTouchedBy(Detectable* d, Point loc1, Point loc2, double xAmount, double yAmount);
        //virtual void wasTouchedBy(Detectable* d) = 0;

};

#endif

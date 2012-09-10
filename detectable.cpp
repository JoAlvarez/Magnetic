#include "detectable.h"
#include "mathfunctions.h"
#include <cmath>

Detectable::Detectable()
{
    upperLeft = Point(0,0);
    upperRight = Point(0,0);
    lowerRight = Point(0,0);
    lowerLeft = Point(0,0);
    center = Point(0,0);
    width = 0;
    height = 0;
    dType = RECTANGLE;
    substance = EMPTY;
    fixed = true;
    moves = false;
}

Detectable::Detectable(Point upperLeft, Point lowerRight, Substance substance, DetectableType type, bool fixed, bool moves)
{
    this->upperLeft = upperLeft;
    this->lowerRight = lowerRight;
    this->substance = substance;
    this->dType = type;
    this->fixed = fixed;
    this->moves = moves;

    width = lowerRight.getX() - upperLeft.getX();
    height = upperLeft.getY() - lowerRight.getY();

    upperRight = Point(lowerRight.getX(), upperLeft.getY());
    lowerLeft = Point(upperLeft.getX(), lowerRight.getY());

    center = Point(upperLeft.getX() + width / 2.0, upperLeft.getY() - height / 2.0);
}

Detectable::Detectable(Point upperLeft, double width, double height, Substance substance, DetectableType type, bool fixed, bool moves)
{
    this->upperLeft = upperLeft;
    this->width = width;
    this->height = height;
    this->dType = type;
    this->substance = substance;
    this->fixed = fixed;
    this->moves = moves;

    lowerRight = Point(upperLeft.getX() + width, upperLeft.getY() - height);
    upperRight = Point(lowerRight.getX(), upperLeft.getY());
    lowerLeft = Point(upperLeft.getX(), lowerRight.getY());

    center = Point(upperLeft.getX() + width / 2.0, upperLeft.getY() - height / 2.0);
}

Detectable::Detectable(Point center, double radius, Substance substance, DetectableType type, bool fixed, bool moves)
{
    this->center = center;
    this->dType = type;
    this->substance = substance;
    this->fixed = fixed;
    this->moves = moves;

    width = radius * 2.0;
    height = radius * 2.0;

    upperLeft = Point(center.getX() - radius, center.getY() + radius);
    lowerRight = Point(center.getX() + radius, center.getY() - radius);
    upperRight = Point(lowerRight.getX(), upperLeft.getY());
    lowerLeft = Point(upperLeft.getX(), lowerRight.getY());
}

double Detectable::getWidth()
{
    return width;
}

double Detectable::getHeight()
{
    return height;
}

double Detectable::getRadius()
{
    return width / 2.0;
}

DetectableType Detectable::getDetectableType()
{
    return dType;
}

Substance Detectable::getSubstance()
{
    return substance;
}

Point Detectable::getCenter()
{
    return center;
}

Point Detectable::getUpperLeft()
{
    return upperLeft;
}

Point Detectable::getLowerRight()
{
    return lowerRight;
}

void Detectable::circleOnCircleResponce(Detectable* c1, Detectable* c2, double distance, double angle)
{
    //Signify that the two circles were touched by each other so they can handle their special functions.
    c1->wasTouchedBy(c2, c1->center, c2->center, 0,0);
    c2->wasTouchedBy(c1, c2->center, c1->center, 0,0);

    //If either the two circles has no substance, then we move neither object.
    if(c1->substance == EMPTY || c2->substance == EMPTY)
        return;

    if(!c1->fixed && c2->fixed)
    {
        c1->moveBy(-cos(angle) * distance, -sin(angle) * distance);
    }
    else if(!c1->fixed && !c2->fixed)
    {
        c1->moveBy(-cos(angle) * distance / 2.0, -sin(angle) * distance / 2.0);
        c2->moveBy(cos(angle) * distance / 2.0, sin(angle) * distance / 2.0);
    }
    else if(c1->fixed && !c2->fixed)
    {
        c2->moveBy(cos(angle) * distance, sin(angle) * distance);
    }
    else
    {
        //c1->moveBy(-cos(angle) * distance / 2.0, -sin(angle) * distance / 2.0);
        //c2->moveBy(cos(angle) * distance / 2.0, sin(angle) * distance / 2.0);
    }
}

void Detectable::circleOnRectResponce(Detectable* circle, Detectable* rect, double xMovement, double yMovement)
{
    //Signify that the circle was touched by the rect and the rect was touched by the circle.
    circle->wasTouchedBy(rect, circle->center, rect->center, xMovement, yMovement);
    rect->wasTouchedBy(circle, rect->center, circle->center, -xMovement, -yMovement);

    //If either the circle or rectangle has no substance, then we move neither object.
    if(circle->substance == EMPTY || rect->substance == EMPTY)
        return;

    //If the circle is moveable but the rect isnt, move the circle.
    if(!circle->fixed && rect->fixed)
    {
        circle->moveBy(xMovement, yMovement);
    }
    //If the circle and rect are both moveable, move them both in opposite directions.
    else if(!circle->fixed && !rect->fixed)
    {
        circle->moveBy(xMovement / 2.0,  yMovement / 2.0);
        rect->moveBy( -xMovement / 2.0, -yMovement / 2.0);
    }
    //If the circle is not movable but the rect is, move the rect.
    else if(circle->fixed && !rect->fixed)
    {
        rect->moveBy(-xMovement, -yMovement);
    }
    //If the circle and rect are not movable, just move them apart in opposite directions.
    else
    {
        circle->moveBy(xMovement / 2.0,  yMovement / 2.0);
        rect->moveBy(-xMovement / 2.0,  -yMovement / 2.0);
    }


}

void Detectable::circleOnRectDetection(Detectable* circle, Detectable* rect)
{
    //Initial high level check. Get the distance between the two centers.
    double distanceBetweenCenters = distBetween(circle->center, rect->center);

    //If the distance between the two centers is bigger than the circles radius plus the
    //bigger between the rect's width and height, then there was no collision. Stop here.
    if(distanceBetweenCenters > circle->getRadius() + max(rect->width, rect->height))
        return;

    //Now that we have done a broad check and the two objects were close enough,
    //let's get more precise to see if there really was a collision.

    bool isAbove =   circle->center.getY() > rect->upperLeft.getY();
    bool isBelow =   circle->center.getY() < rect->lowerRight.getY();
    bool isToLeft =  circle->center.getX() < rect->upperLeft.getX();
    bool isToRight = circle->center.getX() > rect->lowerRight.getX();

    //If the circle is above and within the X values of the rectangle.
    if(isAbove && !isToLeft && !isToRight)
    {
        //Check the Y distance between the center of the Rect and center of the Circle.
        double distance = distBetween(Point(0, circle->center.getY()), Point(0, rect->center.getY()));

        //Get the length of the circle's radius plus half the rects height.
        double radiusPlusHeight = circle->getRadius() + rect->height / 2.0;

        if(distance < radiusPlusHeight)
        {
            //There was a collision.
            circleOnRectResponce(circle, rect, 0, radiusPlusHeight - distance);
        }

        //There was no collision.
        return;
    }
    //If the circle is below and within the X values of the rectangle.
    else if(isBelow && !isToLeft && !isToRight)
    {
        //Check the Y distance between the center of the Rect and center of the Circle.
        double distance = distBetween(Point(0, circle->center.getY()), Point(0, rect->center.getY()));

        //Get the length of the circle's radius plus half the rects height.
        double radiusPlusHeight = circle->getRadius() + rect->height / 2.0;

        if(distance < radiusPlusHeight)
        {
            //There was a collision.
            circleOnRectResponce(circle, rect, 0, -(radiusPlusHeight - distance));
        }

        //There was no collision.
        return;
    }
    //If the circle is to the left and within the Y values of the rectangle.
    else if(isToLeft && !isAbove && !isBelow)
    {
        //Check the X distance between the center of the Rect and center of the Circle.
        double distance = distBetween(Point(circle->center.getX(), 0), Point(rect->center.getX(), 0));

        //Get the length of the circle's radius plus half the rects width.
        double radiusPlusWidth = circle->getRadius() + rect->width / 2.0;

        if(distance < radiusPlusWidth)
        {
            //There was a collision.
            circleOnRectResponce(circle, rect, -(radiusPlusWidth - distance), 0);
        }

        //There was no collision.
        return;
    }
    //If the circle is to the right and within the Y values of the rectangle.
    else if(isToRight && !isAbove && !isBelow)
    {
        //Check the X distance between the center of the Rect and center of the Circle.
        double distance = distBetween(Point(circle->center.getX(), 0), Point(rect->center.getX(), 0));

        //Get the length of the circle's radius plus half the rects width.
        double radiusPlusWidth = circle->getRadius() + rect->width / 2.0;

        if(distance < radiusPlusWidth)
        {
            //There was a collision.
            circleOnRectResponce(circle, rect, radiusPlusWidth - distance, 0);
        }

        //There was no collision.
        return;
    }
    //If the circle is above and to the left of the rectangle.
    else if(isAbove && isToLeft)
    {
        //Check the distance the center of the circle is to the upperLeft corner of the rect.
        double distance = distBetween(circle->center, rect->upperLeft);

        if(circle->getRadius() > distance)
        {
            //There was a collision
            double angle = calcAngle(rect->upperLeft, circle->center);
            circleOnRectResponce(circle, rect, (circle->getRadius() - distance) * cos(angle), (circle->getRadius() - distance) * sin(angle));
        }

        //There was no collision.
        return;
    }
    //If the circle is above and to the right of the rectangle.
    else if(isAbove && isToRight)
    {
        //Check the distance the center of the circle is to the upperRight corner of the rect.
        double distance = distBetween(circle->center, rect->upperRight);

        if(circle->getRadius() > distance)
        {
            //There was a collision
            double angle = calcAngle(rect->upperLeft, circle->center);
            circleOnRectResponce(circle, rect, (circle->getRadius() - distance) * cos(angle), (circle->getRadius() - distance) * sin(angle));
        }

        //There was no collision.
        return;
    }
    //If the circle is below and to the left of the rectangle.
    else if(isBelow && isToLeft)
    {
        //Check the distance the center of the circle is to the lowerLeft corner of the rect.
        double distance = distBetween(circle->center, rect->lowerLeft);

        if(circle->getRadius() > distance)
        {
            //There was a collision
            double angle = calcAngle(rect->upperLeft, circle->center);
            circleOnRectResponce(circle, rect, (circle->getRadius() - distance) * cos(angle), (circle->getRadius() - distance) * sin(angle));
        }

        //There was no collision.
        return;
    }
    //If the circle is below and to the right of the rectangle.
    else if(isBelow && isToRight)
    {
        //Check the distance the center of the circle is to the lowerRight corner of the rect.
        double distance = distBetween(circle->center, rect->lowerRight);

        if(circle->getRadius() > distance)
        {
            //There was a collision
            double angle = calcAngle(rect->upperLeft, circle->center);
            circleOnRectResponce(circle, rect, (circle->getRadius() - distance) * cos(angle), (circle->getRadius() - distance) * sin(angle));
        }

        //There was no collision.
        return;
    }
    //The center of the circle is within the rectangle.
    else
    {
        //See if the circle's center is above and if is to the right of the rect's center.
        bool aboveCenter = circle->center.getY() > rect->center.getY();
        bool rightOfCenter = circle->center.getX() > rect->center.getX();

        //If the circle is above and to the right of the rect's center.
        if(aboveCenter && rightOfCenter)
        {
            //Check to see how far the circle is in the rect in x and y direction.
            double xDistance = rect->upperRight.getX() - circle->center.getX();
            double yDistance = rect->upperRight.getY() - circle->center.getY();

            if(xDistance > yDistance)
            {
                circleOnRectResponce(circle, rect, 0, yDistance + circle->getRadius());
            }
            else
            {
                circleOnRectResponce(circle, rect, xDistance + circle->getRadius(), 0);
            }
        }
        //If the circle is above and to the left of the rect's center.
        else if(aboveCenter && !rightOfCenter)
        {
            //Check to see how far the circle is in the rect in x and y direction.
            double xDistance = circle->center.getX() - rect->upperLeft.getX();
            double yDistance = rect->upperLeft.getY() - circle->center.getY();

            if(xDistance > yDistance)
            {
                circleOnRectResponce(circle, rect, 0, yDistance + circle->getRadius());
            }
            else
            {
                circleOnRectResponce(circle, rect, -(xDistance + circle->getRadius()), 0);
            }
        }
        //If the circle is below and to the right of the rect's center.
        else if(!aboveCenter && rightOfCenter)
        {
            //Check to see how far the circle is in the rect in x and y direction.
            double xDistance = rect->lowerRight.getX() - circle->center.getX();
            double yDistance = circle->center.getY() - lowerRight.getY();

            if(xDistance > yDistance)
            {
                circleOnRectResponce(circle, rect, 0, -(yDistance + circle->getRadius()));
            }
            else
            {
                circleOnRectResponce(circle, rect, xDistance + circle->getRadius(), 0);
            }
        }
        //If the circle is below and to the left of the rect's center.
        else
        {
            //Check to see how far the circle is in the rect in x and y direction.
            double xDistance = circle->center.getX() - rect->lowerLeft.getX();
            double yDistance = circle->center.getY() - lowerLeft.getY();

            if(xDistance > yDistance)
            {
                circleOnRectResponce(circle, rect, 0, -(yDistance + circle->getRadius()));
            }
            else
            {
                circleOnRectResponce(circle, rect, -(xDistance + circle->getRadius()), 0);
            }
        }
    }
}

void Detectable::rectOnRectDetection(Detectable* r1, Detectable* r2)
{

}

void Detectable::circleOnCircleDetection(Detectable* c1, Detectable* c2)
{
    double distance = distBetween(c1->center, c2->center);

    //If the distance between the two circles is within the two radiuss added together,
    //then the two circles collided.
    if(distance <= c1->getRadius() + c2->getRadius())
    {
        circleOnCircleResponce(c1, c2, c1->getRadius() + c2->getRadius() - distance, calcAngle(c1->center, c2->center));
    }
}


void Detectable::handleDetection(Detectable* d2)
{
    Detectable* d1 = this;

    //If both objects are rectangles, then do the rectOnRectDetection
    if(d1->dType == RECTANGLE && d2->dType == RECTANGLE)
    {
        rectOnRectDetection(d1, d2);
    }
    //If the first object is a circle and the other a rectangle, then do circleonRectDetection
    else if(d1->dType == CIRCLE && d2->dType == RECTANGLE)
    {
        circleOnRectDetection(d1, d2);
    }
    //If the first is a rectangle and the other a circle, do circleOnRectDetection.
    else if(d1->dType == RECTANGLE && d2->dType == CIRCLE)
    {
        circleOnRectDetection(d2, d1);
    }
    //If both objects are circles, do circle on circle detection.
    else
    {
        circleOnCircleDetection(d1, d2);
    }

}


void Detectable::moveBy(double dx, double dy)
{
    upperLeft.move(dx, dy);
    upperRight.move(dx, dy);
    lowerLeft.move(dx, dy);
    lowerRight.move(dx, dy);
    center.move(dx, dy);
}

void Detectable::wasTouchedBy(Detectable* d, Point loc1, Point loc2, double xAmount, double yAmount)
{

}

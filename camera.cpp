#include "camera.h"
#include <iostream>
#include "mathfunctions.h"
#include <cmath>

using namespace std;

Camera::Camera()
{
    input = Input::getInstance();
    window = Window::getInstance();
    objects = EntityContainer::getInstance();
    speed = 10.0;
    atGoal = false;
    atBall = true;
}

Camera::~Camera()
{
    window->release();
    input->release();
}

void Camera::centerOnFocus()
{
    window->setCoord(focus.getX() - (window->rightCoord() - window->leftCoord())   / 2.0,
                     focus.getX() + (window->rightCoord() - window->leftCoord())   / 2.0,
                     focus.getY() - (window->topCoord()   - window->bottomCoord()) / 2.0,
                     focus.getY() + (window->topCoord()   - window->bottomCoord()) / 2.0);
}

void Camera::update()
{
    Entity* ball = objects->getEntity("playerBall");
    Entity* goal = objects->getEntity("Goal");

    if(input->isKeyDown("space"))
    {
        atBall = false;
        if(!atGoal)
        {
            double angle = calcAngle(focus, goal->getCenter());
            focus.move(cos(angle) * speed, sin(angle) * speed);
            double newAngle = calcAngle(focus, goal->getCenter());
            double angleDiff = newAngle - angle;

            if(angleDiff > M_PI_4 or angleDiff < -M_PI_4)
            {
                atGoal = true;
                focus = goal->getCenter();
            }
        }
    }
    else
    {
        atGoal = false;
        if(!atBall)
        {

            double angle = calcAngle(focus, ball->getCenter());
            focus.move(cos(angle) * speed, sin(angle) * speed);
            double nextAngle = calcAngle(focus, ball->getCenter());
            double diff = nextAngle - angle;

            if(diff > M_PI_4 or diff < -M_PI_4)
            {
                atBall = true;
                focus = ball->getCenter();
            }
        }
        else
        {
            focus = ball->getCenter();
            centerOnFocus();
        }
    }

    centerOnFocus();


}

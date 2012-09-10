#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "entity.h"
#include "entitycontainer.h"
#include "player.h"
#include "point.h"
#include "input.h"
#include "window.h"

class Camera
{
    private:
        Input * input;
        Window * window;
        Point focus;
        EntityContainer * objects;
        void centerOnFocus();
        double speed;
        bool atGoal;
        bool atBall;

    public:
        Camera();
        ~Camera();
        void update();


};


#endif

#ifndef __CAMERA_H__
#define __CAMERA_H__
#include "point.h"
#include "input.h"
#include "window.h"

class Camera
{
    private:
        Input*                  input;
        Window*                 window;
        Point                   focus;
        double                  scale;
        double                  scaleSpeed;
        bool                    enabled;

        static Camera*          cameraInstance;
        static int              cameraReferenceCount;

        void                    setCoords();

    public:
                                Camera();
                                ~Camera();
        static Camera*          getInstance();
        void                    enable();
        void                    disable();
        bool                    isEnabled();
        void                    release();
        void                    update();
};
#endif

#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "entitycontainer.h"
#include "player.h"
#include "input.h"
#include <cmath>
#include "door.h"
#include "camera.h"

struct BackGroungInfo
{
     string backGroundImage;
     double width;
     double height;

    BackGroungInfo(string path, double w,double h)
    {
        backGroundImage = path;
        width = w;
        height = h;
    }
};

class Level
{
    private:
        EntityContainer* objects;
        Player* player;
        Input* input;
        Window* window;
        ResourceMgr* resourceMgr;
        vector <BackGroungInfo> bg;
        Camera camera;

        string levelFile;
        string bkFile;

        bool isOver;

    public:
        Level (string level);
        void loadLevel();
        void update();
        void draw();
        bool levelWon();
};
#endif

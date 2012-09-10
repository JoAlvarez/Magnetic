#ifndef __STAGE_H__
#define __STAGE_H__

#include "level.h"
#include <fstream>
class Stage
{
    private:
        int currentLevel;
        vector<Level*> levels;
        ResourceMgr* resourceMgr;
        void loadLevels(string path);

    public:
        Stage();
        void start();
        void drawLevel();
        void updateLevel();
        void levelChange();

};
#endif

#ifndef __TOOL_MANAGER_H__
#define __TOOL_MANAGER_H__

#include "grid.h"
#include "camera.h"
#include "toolSnap.h"
#include "toolRectEditor.h"
#include "toolWallEditor.h"
#include "toolFileWriter.h"
#include "input.h"

class ToolManager
{
    private:
        Grid*               grid;
        ToolSnap*           toolSnap;
        ToolRectEditor*     toolRectEditor;
        Camera*             camera;
        ToolFileWriter*     toolFileWriter;
        Input*              input;
        ToolWallEditor      toolWallEditor;

        void manageInput();
        void save();
        string getSaveFile();

    public:
        ToolManager();
        ~ToolManager();
        void update();
        void draw();
};

#endif

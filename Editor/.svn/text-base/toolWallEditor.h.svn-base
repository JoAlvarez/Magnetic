#ifndef __TOOL_WALL_EDITOR_H__
#define __TOOL_WALL_EDITOR_H__

#include "wall.h"
#include "toolRectEditor.h"
#include "toolSnap.h"
#include "input.h"
#include "toolFileWriter.h"
#include <vector>
using namespace std;

class ToolWallEditor
{
    private:
        vector< Wall >      walls;
        int                 wallsMade;
        bool                toolIsActive;
        bool                editingWall;
        ToolRectEditor*     rectEditor;
        ToolSnap*           snapTool;
        Input*              input;
        ToolFileWriter*     fileWriter;

        void                draw( Rect& rectangle );
        void                saveWall( Wall& wall );

    public:
                            ToolWallEditor();
                            ~ToolWallEditor();
        void                update();
        void                enable();
        void                disable();
        void                draw();
        void                save();
};
#endif

#ifndef __TOOL_RECT_EDITOR_H__
#define __TOOL_RECT_EDITOR_H__

#include "point.h"
#include "toolSnap.h"
#include "rect.h"
#include "input.h"
class ToolRectEditor
{
    private:
        Point                   expandingFrom;
        Point                   expandingTo;
        bool                    expandingRight;
        bool                    expandingUp;
        bool                    editing;

        ToolSnap*               snapTool;
        Input*                  input;

        static ToolRectEditor*  toolRectEditorInstance;
        static int              toolRectEditorReferenceCount;

        void                    drawRect( Rect& rectangle );
        Rect                    createRec();
        void                    setExpandingDirection();

    public:
                                ToolRectEditor();
                                ~ToolRectEditor();
        static ToolRectEditor*  getInstance();
        void                    release();
        void                    edit( Point anchor );
        void                    cancel();
        void                    update();
        void                    draw();
        bool                    finishedEditing();
        Rect                    getEditedRect();
};

#endif

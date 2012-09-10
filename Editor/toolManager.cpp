#include "toolManager.h"
#include <windows.h>
#include <Commdlg.h>
#include <iostream>

using namespace std;

void ToolManager::manageInput()
{
    if( input->isKeyDown( "lctrl" ) && input->isKeyDown( "c" ) )
        camera->enable();
    else
        camera->disable();

    if( input->isKeyDown( "lctrl" ) && input->isKeyDown( "w" ) )
        toolWallEditor.enable();
    else
        toolWallEditor.disable();

    if( input->isKeyDown( "lctrl" ) && input->isKeyDown( "s" ) )
        save();
}

void ToolManager::save()
{
    string saveFileName = getSaveFile();

    //Return if a file was notu l selected
    if( saveFileName == "" )
        return;

    //Have all tools write to the fileWriter
    toolWallEditor.save();

    //Set save file name
    toolFileWriter->setWriteFile( saveFileName );

    //Write file
    toolFileWriter->write();
}

string ToolManager::getSaveFile()
{
    OPENFILENAME ofn;       // common dialog box structure
    char szFile[260];       // buffer for file name
    HWND hwnd;              // owner window
    HANDLE hf;              // file handle

    // Initialize OPENFILENAME
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    // Set lpstrFile[0] to '\0' so that GetOpenFileName does not
    // use the contents of szFile to initialize itself.
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    // Display the Open dialog box.

    GetSaveFileName(&ofn);

    return string( ofn.lpstrFile );
}

ToolManager::ToolManager()
    :grid( Grid::getInstance() ),
     toolSnap( ToolSnap::getInstance() ),
     toolRectEditor( ToolRectEditor::getInstance() ),
     camera( Camera::getInstance() ),
     toolFileWriter( ToolFileWriter::getInstance()),
     input( Input::getInstance() ),
     toolWallEditor()
{
}

ToolManager::~ToolManager()
{
    grid->release();
    toolSnap->release();
    toolRectEditor->release();
    camera->release();
    toolFileWriter->release();
}

void ToolManager::update()
{
    manageInput();
    toolRectEditor->update();
    camera->update();
    toolWallEditor.update();
}

void ToolManager::draw()
{
    grid->draw();
    toolSnap->draw();
    toolRectEditor->draw();
    toolWallEditor.draw();
}

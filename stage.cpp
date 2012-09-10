#include "stage.h"

Stage::Stage()
{
    currentLevel = 0;
    loadLevels("./data/levels/levelNames.txt");
    resourceMgr = ResourceMgr::getInstance();
}

void Stage::start()
{
    levels[currentLevel]->loadLevel();
}

void Stage::drawLevel()
{
    levels[currentLevel]->draw();
}

void Stage::updateLevel()
{
    levels[currentLevel]->update();
    if(levels[currentLevel]->levelWon())
        levelChange();
}
void Stage::levelChange()
{
    currentLevel++;
    if(currentLevel < levels.size())
    {
        glColor3f(1.0,1.0,0.0);
        resourceMgr->drawText("ArialS", "switch", 750, 1100);
        levels[currentLevel]->loadLevel();
        levels[currentLevel]->draw();
    }
}
void Stage::loadLevels(string path)
{
    ifstream file(path.c_str());

    int numbLines = 0;
    string line;
    string folder = "./data/levels/";

    if(file.is_open())
    {
        while(!file.eof())
        {
            getline(file,line);
            if(numbLines % 2 > 0)
                levels.push_back(new Level(folder+line));
            numbLines++;
        }
    }
}

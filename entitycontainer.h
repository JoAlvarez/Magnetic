#ifndef __ENTITY_CONTAINER_H__
#define __ENTITY_CONTAINER_H__

#include "entity.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

class EntityContainer
{
    private:
        static EntityContainer* ecInstance;
        static int              ecReferenceCount;
        map<string, Entity*>    entitiesMap;
        vector< vector<Entity*> > entitiesVec;
        vector< Entity* >         entitiesVecOneD;

        ////////////////////////////////////////////////////
        //LOADING
        ////////////////////////////////////////////////////
        //Load each line of the file specified into a single
        //element of the specified vector.
        //@param: Name of the file/file path
        //@param: vector to store the lines of the file
        //@return: void
        void loadFileIntoVector( const string& fileName, vector<string>& lineStorage );

        //This will parse a single specified line, and will change the curEntityType if
        //the line specifies to do so.
        //@param: A single line
        //@param: the current entity type that should be being loaded.
        void parseLineForEntity( const string& line, EntityType& curEntityType, bool& endOfEntities );

        //This will parse a single specified line, looking for stim response lines
        void parseLineForSR( const string& line, bool& parsingSR );

        //Load a ball entity into the container given  a line of arguments.
        //@param: line containing Ball arguments
        //@return: void
        void parseBall( const string& line );

        //Load a button entity into the container given  a line of arguments.
        //@param: line containing Button arguments
        //@return: void
        void parseButton( const string& line );

        //Load a magnet entity into the container given  a line of arguments.
        //@param: line containing Magnet arguments
        //@return: void
        void parseMagnet( const string& line );

        //Load a wall entity into the container given  a line of arguments.
        //@param: line containing Wall arguments
        //@return: void
        void parseWall( const string& line );

        //Load a bumper entity into the container given  a line of arguments.
        //@param: line containing Bumper arguments
        //@return: void
        void parseBumper( const string& line );

        //Load a door entity into the container given  a line of arguments.
        //@param: line containing Door arguments
        //@return: void
        void parseDoor( const string& line );

        //Load a general entity into the container given  a line of arguments.
        //@param: line containing General arguments
        //@return: void
        void parseGeneral( const string& line );

        //Load stimulus/response into a specified entity
        //@param: Line containing SR arguments
        //@return: void
        void parseStimulusResponse( const string& line );

        //LOADING.helpers
        //Find all the arguments in a line of text and load each argument into
        //a specified vector.
        //@param: the line to parse for arguments.
        //@param: vector to load arguments into.
        //@return: void
        void findArguments( const string& line, vector<string>& arguments );

        //Return a single word from the string starting at the index spcified.
        //The word will return after the first space or tab is found.
        //@param: the line to create the word from.
        //@param: the index of the first character of the word. EX. line = the cat
        //        index = 4 will return the word cat.
        //@return: the newly formed word.
        string lineSegmentToWord( const string& line, int fromIndex );

        //Converts a string to double
        //@param: string to convert.
        //@return: the converted double
        double stringToDouble( const string& word );

        //Converts a string to int
        //@param: string to convert.
        //@return: the converted integer
        int stringToInt( const string& word );

        ////////////////////////////////////////////////////
        //UNLOADING
        ////////////////////////////////////////////////////
        //Destroy the instance of the container
        //@return: void
        void destroy();

        //Delete all entities fromt he container
        //@return: void
        void freeEntities();

        //Clear the Map and Vector of all elements.
        //@return: void
        void clearMapVec();


    public:

        ////////////////////////////////////////////////////
        //CONSTRUCTORS/DESTRUCTORS
        ////////////////////////////////////////////////////
        EntityContainer();
        ~EntityContainer();

        //Returns instance of the EntityContainer
        //return: pointer to the container
        static EntityContainer* getInstance();

        //Releases your instance of the EntityContainer
        //return: void
        void release();

        ////////////////////////////////////////////////////
        //ACCESSORS
        ////////////////////////////////////////////////////
        //Looks for an entity inside the container given a name
        //@param: name of the entity you're searching for
        //@return: returns a pointer to the entity if it was found
        //         otherwise returns NULL.
        Entity* getEntity( const string& name );

        //Looks for all entites of a specific type. And returns a
        //a vector of all entities matching that type. IE:
        //you tell it to look for BALL, it will return a vector of
        //all the balls.
        //@param: name of the type of entities you would like to
        //        have returned.
        //@return: returns a vector of all entities of the spcified
        //         type empty vector if it wasn't found.
        const vector< Entity* >& getEntitiesOfType( EntityType eType ) const;

        //Returns all entites as a vector
        //@return: If there are entitties in the container they'll be returned as a vector.
        //         If therere are none the fucntion will return an empty vector.
        const vector< Entity* >& getAllEntities() const;

        //Call ->draw() on all the entities in the container.
        //@return: void
        void drawAll();

        ////////////////////////////////////////////////////
        //MUTATORS
        ////////////////////////////////////////////////////
        //Load all the entities in the file specified.
        //@param: file name of the file we want to load.
        //@return: void
        void loadLevel( const string& fileName );

        //Remove entity from the container given a name.
        //@param: name of entity to be removed.
        //@return: void
        void removeEntity( const string& name );

        //Insert an entity into the container.
        //@param: entity pointer to insert.
        //@return: void
        void insertEntity( Entity* entity );

        //Insert a stimulus/response into an already stored entity
        //@param: name of the entity to insert into
        //@param: the StimeResp to insert into the entity
        void insertStimResp( const string& name, const StimResp& stimResp );

        //Call ->handleFlags() on all the entities in the container
        //return: void
        void handleAllFlags();

        //Call ->onAlways() on all the entities in the container.
        //return: void
        void handleAllOnAlways();

        //Call ->handleDetection( .. ) on all the entities upon all
        //the entities.
        //return: void
        void handleAllDetection();
};

#endif

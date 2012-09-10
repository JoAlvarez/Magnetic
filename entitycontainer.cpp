#include "entitycontainer.h"
#include "ball.h"
#include "button.h"
#include "magnet.h"
#include "wall.h"
#include "bumper.h"
#include "door.h"
#include "general.h"
#include <iostream>
#include <fstream>
#include <sstream>
#define FILE_NUM_ARGUMENTS_BALL     10
#define FILE_NUM_ARGUMENTS_BUTTON   6
#define FILE_NUM_ARGUMENTS_MAGNET   9
#define FILE_NUM_ARGUMENTS_WALL     8
#define FILE_NUM_ARGUMENTS_SR       4
#define FILE_NUM_ARGUMENTS_BUMPER   7
#define FILE_NUM_ARGUMENTS_DOOR     8
#define FILE_NUM_ARGUMENTS_GENERAL  6

EntityContainer* EntityContainer::ecInstance = NULL;
int EntityContainer::ecReferenceCount = 0;

void EntityContainer::insertEntity( Entity* entity )
{
    string name = entity->getName();
    entitiesMap[ name ] = entity;
    int index = entity->getEntityType();
    entitiesVec[ index ].push_back( entity );
    entitiesVecOneD.push_back( entity );
}

void EntityContainer::insertStimResp( const string& name, const StimResp& stimResp )
{
    Entity* entityFoundAt = getEntity( name );
    if( !entityFoundAt )
        return;
    entityFoundAt->insertStimResp( stimResp );
}

void EntityContainer::freeEntities()
{
    for( int i = 0; i < entitiesVec.size(); ++i )
    {
        for( int j = 0; j < entitiesVec[i].size(); ++j )
            delete entitiesVec[i][j];
    }
}

void EntityContainer::clearMapVec()
{
    freeEntities();
    entitiesMap.clear();
    for(int i = 0; i < entitiesVec.size(); ++i)
    	entitiesVec[i].clear();
    entitiesVecOneD.clear();
}

EntityContainer::EntityContainer()
{
    vector<Entity*> v;
    for( int i = 0; i < ENTITY_TYPE_NUM; ++i )
        entitiesVec.push_back(v);
}

EntityContainer::~EntityContainer()
{
    clearMapVec();
}

EntityContainer* EntityContainer::getInstance()
{
    if( !ecInstance )
        ecInstance = new EntityContainer();

    ecReferenceCount++;
    return ecInstance;
}

void EntityContainer::destroy()
{
    if( ecInstance )
        delete ecInstance;
}

void EntityContainer::release()
{
    if( --ecReferenceCount <= 0 )
        destroy();
    if( ecReferenceCount < 0 )
        ecReferenceCount = 0;
}

void EntityContainer::removeEntity( const string& name )
{
    Entity* e = getEntity( name );

    //If the entity was not found return
    if( !e ) return;

    //Store data from entity to erase the pointer from
    // the 2d vec then delete the pointer
    EntityType t = e->getEntityType();
    delete e;

    //Erase from the map
    entitiesMap.erase( entitiesMap.find(name) );

    //Find the element in the 2d vec then delete
    for( int i = 0; i < entitiesVec[ t ].size(); ++i )
    {
        if( entitiesVec[ t ][ i ] == e )
        {
            entitiesVec[ t ].erase( entitiesVec[ t ].begin() + i );
            return;
        }
    }

    //Find the element in the 1d vec then delete
    for( int i = 0; i < entitiesVecOneD.size(); ++i )
    {
        if( entitiesVecOneD[ i ] == e )
        {
            entitiesVecOneD.erase( entitiesVecOneD.begin() + i );
            return;
        }
    }
}

void EntityContainer::drawAll()
{
    for( int i = 0; i < entitiesVecOneD.size(); ++ i )
        entitiesVecOneD[i]->draw();
}

void EntityContainer::loadLevel( const string& fileName )
{
	clearMapVec();
    vector<string> lines;
    loadFileIntoVector( fileName, lines );

    //Parse all entities in file
    bool endOfEntities = false;
    EntityType curLoadingType;
    for( int i = 0; i < lines.size() and !endOfEntities; ++i )
        parseLineForEntity( lines[ i ], curLoadingType, endOfEntities );

    //Parse all SRs in file
    bool parsingSRs = false;
    for( int i = 0; i < lines.size(); ++i )
        parseLineForSR( lines[ i ], parsingSRs );
}

Entity* EntityContainer::getEntity( const string& name )
{
    if( entitiesMap.find( name ) != entitiesMap.end() )
        return entitiesMap[ name ];
    return NULL;
}

const vector< Entity* >& EntityContainer::getEntitiesOfType( EntityType eType ) const
{
    if( eType < entitiesVec.size() )
        return entitiesVec[ eType ];

    //If the type does not exist yet return an empty vector.
    return entitiesVecOneD;
}

const vector< Entity* >& EntityContainer::getAllEntities() const
{
    return entitiesVecOneD;
}

void EntityContainer::loadFileIntoVector( const string& fileName, vector<string>& lineStorage )
{
    string line;
    ifstream inputFile ( fileName.c_str() );

    //Push each line of the file into a single element of a vector
    if ( inputFile.is_open() )
    {
        while ( !inputFile.eof() )
        {
            getline ( inputFile, line );
            lineStorage.push_back( line );
        }
        inputFile.close();
    }
}

string EntityContainer::lineSegmentToWord( const string& line, int fromIndex )
{
    string temp = "";

    //Concantanate until we reach a space or tab or the end of the string.
    for( int i = fromIndex;( i < line.size() ) and ( line[i] != ' ' ) and ( line[i] != '\t' ); ++i )
        temp = temp + line[i];
    return temp;
}

double EntityContainer::stringToDouble( const string& word )
{
    stringstream tempBuffer;
    double  tempNum;
    tempBuffer << word;
    tempBuffer >> tempNum;
    return tempNum;
}

int EntityContainer::stringToInt( const string& word )
{
    stringstream tempBuffer;
    int  tempNum;
    tempBuffer << word;
    tempBuffer >> tempNum;
    return tempNum;
}

void EntityContainer::parseLineForEntity( const string& line, EntityType& curEntityType, bool& endOfEntities )
{
    //If line is blank end parse
    if( line == " " or line == "" )
        return;

    //If line is comment end parse
    if( line[0] == '%' )
        return;

    //Define the entity type we should currently be parsing
    if( line[0] == '#' )
    {
        string entityType = lineSegmentToWord( line, 1 );
        if( entityType == "BALL" )
            curEntityType = BALL;

        else if( entityType == "BUTTON" )
            curEntityType = BUTTON;

        else if( entityType == "MAGNET" )
            curEntityType = MAGNET;

        else if ( entityType == "WALL" )
            curEntityType = WALL;
        else if ( entityType == "BUMPER" )
            curEntityType = BUMPER;
        else if ( entityType == "DOOR" )
            curEntityType = DOOR;
        else if ( entityType == "GENERAL" )
            curEntityType = GENERAL;
        else
        {
            endOfEntities = true;
            return;
        }
    }
    else
    {
        //Handle type parsing
        switch( curEntityType )
        {
            case BALL:
                parseBall( line );
            break;
            case BUTTON:
                parseButton( line );
            break;
            case MAGNET:
                parseMagnet( line );
            break;
            case WALL:
                parseWall( line );
            break;
            case BUMPER:
                parseBumper( line );
            break;
            case DOOR:
                parseDoor( line );
            break;
            case GENERAL:
                parseGeneral( line );
            break;
        }
    }
}

void EntityContainer::parseLineForSR( const string& line, bool& parsingSR )
{
    //If line is blank end parse
    if( line == " " or line == "" )
        return;

    //If line is comment end parse
    if( line[0] == '%' )
        return;

    if( line[0] == '#' )
    {
        //Check if we've made it to the stimulus response portion
        // of the file.
        string preParseTag = lineSegmentToWord( line, 1 );
        if( preParseTag == "STIMULUSRESPONSE" )
            parsingSR = true;
        else
            parsingSR = false;
    }
    else
        if( parsingSR )
            parseStimulusResponse( line );
}

void EntityContainer::parseBall( const string& line )
{
    vector<string> arguments( FILE_NUM_ARGUMENTS_BALL );
    findArguments( line, arguments );
    Entity* tempE = new Ball( arguments[0],
                              (Polarity)stringToInt( arguments[1] ),
                              stringToDouble( arguments[2] ),
                              stringToDouble( arguments[3] ),
                              stringToDouble( arguments[4] ),
                              stringToInt( arguments[5] ),
                              stringToDouble( arguments[6] ),
                              (Substance)stringToInt( arguments[7] ),
                              Point( stringToDouble( arguments[8] ), stringToDouble( arguments[9] ) )
                            );
    insertEntity( tempE );
}

void EntityContainer::parseButton( const string& line )
{
    vector<string> arguments( FILE_NUM_ARGUMENTS_BUTTON );
    findArguments( line, arguments );
    Entity* tempE = new Button( arguments[0],
                                Point( stringToDouble( arguments[1] ), stringToDouble( arguments[2] ) ),
                                Point( stringToDouble( arguments[3] ), stringToDouble( arguments[4] ) ),
                                (Direction)stringToInt( arguments[5] )
                              );
    insertEntity( tempE );
}

void EntityContainer::parseMagnet( const string& line )
{
    vector<string> arguments( FILE_NUM_ARGUMENTS_MAGNET );
    findArguments( line, arguments );
    Entity* tempE = new Magnet( arguments[0],
                                (Polarity)stringToInt( arguments[1] ),
                                stringToDouble( arguments[2] ),
                                stringToDouble( arguments[3] ),
                                stringToInt( arguments[4] ),
                                stringToInt( arguments[5] ),
                                Point( stringToDouble( arguments[6] ), stringToDouble( arguments[7] ) ),
                                stringToDouble( arguments[8] )
                              );
    insertEntity( tempE );
}

void EntityContainer::parseWall( const string& line )
{
    vector<string> arguments( FILE_NUM_ARGUMENTS_WALL );
    findArguments( line, arguments );
    Entity* tempE = new Wall( arguments[0],
                              stringToInt( arguments[1] ),
                              stringToInt( arguments[2] ),
                              stringToInt( arguments[3] ),
                              Point( stringToDouble( arguments[4] ), stringToDouble( arguments[5] ) ),
                              Point( stringToDouble( arguments[6] ), stringToDouble( arguments[7] ) )
                            );
    insertEntity( tempE );
}

void EntityContainer::parseBumper( const string& line )
{
    vector<string> arguments( FILE_NUM_ARGUMENTS_BUMPER );
    findArguments( line, arguments );
    Entity* tempE = new Bumper( arguments[0],
                                stringToInt( arguments[1] ),
                                stringToInt( arguments[2] ),
                                stringToDouble( arguments[3] ),
                                (Substance)stringToInt( arguments[4] ),
                                Point( stringToDouble( arguments[5] ), stringToDouble( arguments[6] ) ) );
    insertEntity( tempE );
}

void EntityContainer::parseDoor( const string& line )
{
    vector<string> arguments( FILE_NUM_ARGUMENTS_DOOR );
    findArguments( line, arguments );
    Entity* tempE = new Door(   arguments[0],
                                Point( stringToDouble( arguments[1] ), stringToDouble( arguments[2] ) ),
                                stringToInt( arguments[3] ),
                                stringToInt( arguments[4] ),
                                stringToDouble( arguments[5] ),
                                Point( stringToDouble( arguments[6] ), stringToDouble( arguments[7] ) ) );
    insertEntity( tempE );
}

void EntityContainer::parseGeneral( const string& line )
{
    vector<string> arguments( FILE_NUM_ARGUMENTS_GENERAL );
    findArguments( line, arguments );
    Entity* tempE = new General( arguments[0],
                                 Point( stringToDouble( arguments[1] ), stringToDouble( arguments[2] ) ),
                                 stringToDouble( arguments[3] ),
                                 stringToDouble( arguments[4] ),
                                 arguments[5] );
    insertEntity( tempE );
}

void EntityContainer::parseStimulusResponse( const string& line )
{
    vector<string> arguments( FILE_NUM_ARGUMENTS_SR );
    findArguments( line, arguments );

    //Create the SR object to pass into the insertion function
    StimResp tempSR( (Stimulus)stringToInt( arguments[ 1 ] ),
                    arguments[ 2 ],
                    (Response)stringToInt( arguments[ 3 ] ) );
    insertStimResp( arguments[ 0 ], tempSR );
}

void EntityContainer::findArguments( const string& line, vector<string>& arguments )
{
    //Load line into the buffer
    stringstream lineBuffer( line );

    //Copy each word from the buffer into an element of the vector
    for( int i = 0; i < arguments.size(); ++i )
        lineBuffer >> arguments[ i ];
}

void EntityContainer::handleAllFlags()
{
    for( int i = 0; i < entitiesVecOneD.size(); ++ i )
            entitiesVecOneD[i]->handleFlags();
}

void EntityContainer::handleAllOnAlways()
{
    for( int i = 0; i < entitiesVecOneD.size(); ++ i )
        entitiesVecOneD[i]->onAlways();
}

void EntityContainer::handleAllDetection()
{
    for(int i = 0; i < entitiesVecOneD.size(); i++)
        for(int j = i +1; j < entitiesVecOneD.size();j++)
            entitiesVecOneD[i]->handleDetection(entitiesVecOneD[j]);
}

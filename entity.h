#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "detectable.h"
#include "resourcemgr.h"
#include <string>
#include <vector>

//Keeps track of number of entity types we have
// mostly useful for the entity container but
// easier to edit here since this is where they're
// added.
#define ENTITY_TYPE_NUM 5

using namespace std;

class EntityContainer;

enum EntityType
{
    BALL = 0,
    BUTTON = 1,
    DOOR = 2,
    MAGNET = 3,
    WALL = 4,
    BUMPER = 5,
    GENERAL = 6
};
enum Stimulus
{
    ONTOUCH = 0,
    ONUNTOUCH = 1
};
enum Response
{
    OPEN = 0,
    CLOSE = 1
};

class StimResp
{
    public:
        Stimulus stimulus;
        string targetName;
        Response response;

        StimResp( Stimulus stim, const string& targetName, Response resp )
            :stimulus( stim ), targetName( targetName ), response( resp )
        {}
};

struct TouchedInfo
{
    string name;
    Point loc1, loc2;
    double xAmount;
    double yAmount;
    double mass;

    TouchedInfo(string n, double x, double y)
    {
        name = n;
        xAmount = x;
        yAmount = y;
    }
    TouchedInfo(string n, Point p1, Point p2, double x, double y)
    {
		name = n;
		loc1 = p1;
		loc2 = p2;
        xAmount = x;
        yAmount = y;
    }
    TouchedInfo(string n, Point p1, Point p2, double x, double y, double m)
    {
		name = n;
		loc1 = p1;
		loc2 = p2;
        xAmount = x;
        yAmount = y;
    	mass = m;
    }
};

class Entity
    :public Detectable
{
    protected:
        EntityContainer* entityContainer;

    protected:
        EntityType eType;
        int health;
        bool destructible;
        string name;
        ResourceMgr* resourceMgr;
        vector<string> touchedBy;
        vector<struct TouchedInfo> touchedInfo;
        vector<string> unTouchedBy;
        vector<StimResp> StimulusResponseList;

    public:
        Entity();
        Entity( EntityType type, string name, int health, bool destructible, Point upperLeft, Point lowerRight, Substance substance, DetectableType type, bool fixed, bool moves  );
        Entity( EntityType type, string name, int health, bool destructible, Point upperLeft, double width, double height, Substance substance, DetectableType type, bool fixed, bool moves );
        Entity( EntityType type, string name, int health, bool destructible, Point center, double radius, Substance substance, DetectableType type, bool fixed, bool moves );

        string getName();
        virtual ~Entity();
        void insertStimResp( Stimulus stim, const string& targetName, Response resp );

        //STIMULUS FUNCTIONS
        //Will be called in handle flags functions.
        virtual void onTouch();
        virtual void onUnTouch();

        //Response
        virtual void open();
        virtual void close();

        //Misc
        virtual void onAlways();
        virtual void onFrameEnd();
        void touch( const string& name );
        void handleFlags();

        void callFunction( const string& entityName, Response funcName );
        void callFunction( const vector<StimResp>& srList, Stimulus stim );
        virtual void draw();

        virtual void wasTouchedBy(Detectable* d, Point loc1, Point loc2, double xAmount, double yAmount);

        void printSR();

        bool touched(const string name) const;

        //Organize later
        EntityType getEntityType();
        Entity* getEntity( const string& entityName );
        const vector< Entity* >& getEntitiesOfType( EntityType eType ) const;
        const vector< Entity* >& getAllEntities() const;
        void insertStimResp( const StimResp & stimResp );

        //////////////////////////////////////////////////////////
        /////////DESCRIBE YOUR FUNCTIONS HERE ILL PROTOTYPE AND
        /////////DEFINE THEM LATER JEW BASTARDS
        //////////////////////////////////////////////////////////
        /*
        */
};

#endif

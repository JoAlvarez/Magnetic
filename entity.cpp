#include "entity.h"
#include "entitycontainer.h"
#include <math.h>
#include <iostream>

Entity::Entity()
    :Detectable()
{
    resourceMgr = ResourceMgr::getInstance();
    entityContainer = EntityContainer::getInstance();
}

Entity::Entity( EntityType eType, string name, int health, bool destructible, Point upperLeft, Point lowerRight,
                Substance substance, DetectableType dType, bool fixed, bool moves  )
    :Detectable( upperLeft, lowerRight, substance, dType, fixed, moves )
{
    this->eType         = eType;
    this->name          = name;
    this->health        = health;
    this->destructible  = destructible;
    resourceMgr         = ResourceMgr::getInstance();
    entityContainer = EntityContainer::getInstance();
}

Entity::Entity( EntityType eType, string name, int health, bool destructible, Point upperLeft, double width, double height,
                Substance substance, DetectableType dType, bool fixed, bool moves )
    :Detectable( upperLeft, width, height, substance, dType, fixed, moves )
{
    this->eType         = eType;
    this->name          = name;
    this->health        = health;
    this->destructible  = destructible;
    resourceMgr         = ResourceMgr::getInstance();
    entityContainer = EntityContainer::getInstance();
}

Entity::Entity( EntityType eType, string name, int health, bool destructible, Point center, double radius,
                Substance substance, DetectableType dType, bool fixed, bool moves )
    :Detectable( center, radius, substance, dType, fixed, moves )
{
    this->eType         = eType;
    this->name          = name;
    this->health        = health;
    this->destructible  = destructible;
    resourceMgr         = ResourceMgr::getInstance();
    entityContainer = EntityContainer::getInstance();
}

Entity::~Entity()
{
    resourceMgr->release();
    entityContainer->release();
}

string Entity::getName()
{
    return name;
}

void Entity::insertStimResp( Stimulus stim, const string& targetName, Response resp )
{
    StimulusResponseList.push_back( StimResp( stim, targetName, resp ) );
}

void Entity::handleFlags()
{
    if( !touchedBy.empty() )
        this->onTouch();

    if( !unTouchedBy.empty() )
        onUnTouch();

    touchedBy.erase(touchedBy.begin(), touchedBy.end());
    touchedInfo.erase(touchedInfo.begin(), touchedInfo.end());
    unTouchedBy.erase(unTouchedBy.begin(), unTouchedBy.end());
}

Entity* Entity::getEntity( const string& entityName )
{

    return entityContainer->getEntity( entityName );
}

const vector< Entity* >& Entity::getAllEntities() const
{
    return entityContainer->getAllEntities();
}

void Entity::touch( const string& name )
{
    touchedBy.push_back( name );
}

bool Entity::touched(const string name) const
{
	for(int i = 0; i < touchedBy.size(); ++i)
		if(touchedBy[i] == name)
			return true;
	return false;
}

void Entity::callFunction( const string& entityName, Response funcName )
{
    //Find the pointer to the target node
    Entity* targetEntity = getEntity( entityName );

    //If the entity wasnt found end function
    if( !targetEntity )
        return;

    //Call the specified function on the entity already found
    Response function = funcName;
    switch( function )
    {
        case OPEN:
            targetEntity->open();
        break;

        case CLOSE:
            targetEntity->close();
        break;
    }
}

void Entity::callFunction( const vector<StimResp>& srList, Stimulus stim )
{
    //Traverse the vector looking for all instances that
    //have the specified stimulus.
    //Ex: Looks for all StimResp instances with a stimulus
    //    of onTouch. If stim == onTouch
    for( int i = 0; i < srList.size(); ++i )
    {
        StimResp srInstance = srList[ i ];
        //If the an instance has a matching stimulus call the
        //response on the proper node.
        if( srInstance.stimulus == stim )
            callFunction( srInstance.targetName, srInstance.response );
    }
}

EntityType Entity::getEntityType()
{
    return eType;
}

const vector< Entity* >& Entity::getEntitiesOfType( EntityType eType ) const
{
    return entityContainer->getEntitiesOfType( eType );//entitiesVec;
}

void Entity::draw()
{

    if( dType == RECTANGLE )
    {
        glColor3f(0.0,0.0,0.0);
        glBegin( GL_QUADS );
            glVertex2f( upperLeft.getX()    , upperLeft.getY() );
            glVertex2f( upperRight.getX()   , upperRight.getY() );
            glVertex2f( lowerRight.getX()   , lowerRight.getY() );
            glVertex2f( lowerLeft.getX()    , lowerLeft.getY() );
        glEnd();
    }
    else
    {
        if(eType == BALL)
            glColor3f(0.8, 0.8, 0.8);
        if(eType == MAGNET)
            glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_TRIANGLE_FAN);
            for(int i = 0; i <= 360; ++i)
                glVertex2f(cos(i * 3.14 / 180.0) * getRadius() + center.getX(), sin(i * 3.14 / 180.0) * getRadius() + center.getY());
        glEnd();
    }

}

void Entity::wasTouchedBy(Detectable* d, Point loc1, Point loc2, double xAmount, double yAmount)
{
    Entity* e = (Entity*)(d);

    touchedBy.push_back( e->name );

    touchedInfo.push_back(TouchedInfo(e->name, loc1, loc2, xAmount, yAmount));
}

void Entity::insertStimResp( const StimResp & stimResp )
{
    StimulusResponseList.push_back( stimResp );
}

//ALL UNDEFINED FUNCTIONS INHERITED/DEFINED BY CHILDREN
void Entity::onTouch()
{
    callFunction( StimulusResponseList, ONTOUCH );
}

void Entity::onUnTouch()
{
	callFunction( StimulusResponseList, ONUNTOUCH );
}

void Entity::onAlways()
{

}

void Entity::onFrameEnd()
{
}

void Entity::open()
{
}

void Entity::close()
{
}

void Entity::printSR()
{
    for( int i = 0; i < StimulusResponseList.size(); ++i )
        cout << StimulusResponseList[i].stimulus << " " << StimulusResponseList[i].targetName << " " << StimulusResponseList[i].response << endl;
}

#ifndef  __DOOR_H__
#define  __DOOR_H__

#include "point.h"
#include "entity.h"

class Door : public Entity
{
    public:

        Door();                                 // Default Constructor

        Door( string, Point,
              int, int, double, Point);         // Constructor with parameters.

        ~Door();                                // Deconstructor

        virtual void onAlways();                 // Opens or closes the door depending on opening bool

        void        open();                     // Opens the door.

        void        close();                    // Closes the door.

        void        draw();                     // Renders the door in the window

        void        setPos( Point );            // Sets the position of the door.

    private:

        double      openSpeed;
        double      closeSpeed;
        Point       openLoc;
        Point       closeLoc;
        Direction   dir;
        bool        opening;

        string      img;
        int         frameOpened;

        ResourceMgr* resourceMgr;
        Window*     window;


};

#endif __DOOR_H__

#ifndef _WALL_H_
#define _WALL_H_

#include "entity.h"
#include "ball.h"

// Strength Levels
#define EPIC            10
#define HEAVY_DUTY      9
#define REINFORCED      8
#define STRONG          7
#define TOUGH           6
#define DURABLE         5
#define DULL            4
#define WEAK            3
#define FLIMSY          2
#define FRAGILE         1
#define UNDESTRUCTIBLE  0

class Wall
    :public Entity
{
    public:

        Wall();                                 // Default Constructor.

        Wall( string name, bool, int, int, Point, Point );   // Constructor with adjustable properties.

        virtual void onTouch();                 // When the wall is touched, if it's damagable
                                                // reduce health.

        int getHealth();                        // Returns the health of the Wall.

        int getStrength();                      // Returns the strength of the Wall.

        void setStrength( int );                // Sets the strength of the Wall.

        void draw( string image );      // Draws the the image within the wall.

        void draw();                    // Draws the wall.

        void setImage( string );                // Set the image alias.

    private:

        int strength;                           // Holds the stregnth of the wall.

        int minDamage;                          // Return minimum amount of damage that must
                                                // be reached in order to reduce health

        string image;                           // Holds the image alias.
};

#endif _WALL_H_

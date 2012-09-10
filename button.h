#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "entity.h"

#define UNDESTRUCTIBLE 0
#define ON  1
#define OFF 0

class Button
    :public Entity
{
    public:

        Button();                               // Default constructor.

        ~Button();                              // Destructor.

        Button( Point, Point );                 // Constructor with location.

        Button( string name, Point, Point, Direction dir );    // Constructor with location.

        void onTouch();                         // Toggles the button on or off.

        void setToggle( bool );                 // Set the status of the button.

        void draw();                            // Draws the button.

        void onAlways();                        //

        void setImages( string, string );       // Sets the image file aliases.

    private:

        bool toggleOn;                          // Holds the status of the button.

        Direction dir;							// Direction the button is facing.

        string imageUp, imageDown;              // Hold the image aliases.

        unsigned long long frameTouched;        // Holds the frame the button was last touched on

        Window* window;                         // Window Object
};

#endif _BUTTON_H_

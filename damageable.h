#ifndef _DAMAGEABLE_H_
#define _DAMAGEABLE_H_

class Damageable
{
    public:

        Damageable();                               // Deafault constructor.

        Damageable( bool, bool, bool, bool );       // Constructor with set from.

        void setFrom( bool, bool, bool, bool );     // Set the locations the objects is
                                                    // damageable from.

    private:

        bool fromLeft, fromRight;                   // Hold wheter or not the object is
        bool fromTop, fromBottom;                   // damageable from each side.
};

#endif _DAMAGEABLE_H_

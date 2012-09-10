#include "damageable.h"

// Default object is damageable
// from all sides.
Damageable:: Damageable()
    :fromLeft( true ), fromRight( true ),
     fromTop( true ) , fromBottom( true )
{
}

Damageable:: Damageable( bool left, bool right, bool top, bool bottom )
{
    fromLeft   = left;
    fromRight  = right;
    fromTop    = top;
    fromBottom = bottom;
}

void Damageable:: setFrom( bool left, bool right, bool top, bool bottom )
{
    fromLeft   = left;
    fromRight  = right;
    fromTop    = top;
    fromBottom = bottom;
}

#ifndef _MISSILE_HH_
#define _MISSILE_HH_
#include "Object.hh"

class Missile : public Object
{
private:
    Missile(float z, float a, float x1, float y1);


public:
    Missile()
    {

    }
};

#endif // _MISSILE_HH_

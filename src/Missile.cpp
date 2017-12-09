#include "Object.hh"
#include "Missile.hh"
#include <cmath>
#include <ctgmath>

using namespace std;

Missile::Missile(float speed,  Position posBegin, Position posEnd, const string& key)
    : Object(posBegin,key)
{
    _speed = speed;
    _posEnd = posEnd;

}


void Missile::move(int ms)
{
    Position pos = getPos();
    double angle = atan2(_posEnd.y - pos.y, _posEnd.x - pos.x);

    pos.x += _speed * ms * cos(angle);
    pos.y += _speed * ms * sin(angle);
    Missile.setPos(pos);
}






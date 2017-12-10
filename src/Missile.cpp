#include "Object.hh"
#include "Missile.hh"
#include <cmath>

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
    if (this->getKey() == "MISSILE_ALLY" && pos.y <= _posEnd.y)
      pos = _posEnd;
    else if (this->getKey() == "MISSILE_FOE" && pos.y >= _posEnd.y)
      pos = _posEnd;
    this->setPos(pos);
}

bool	Missile::isEnded() const
{
  return (this->getPos().y == _posEnd.y);
}

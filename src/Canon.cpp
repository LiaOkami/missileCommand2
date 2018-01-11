#include "Canon.hh"

using namespace std;

Canon::Canon(const Position &posCan)
  : Object(posCan, "CANON")
{

}

Missile	Canon::shoot(const Position& target)
{
  return (Missile(12, this->getPos(), target, "MISSILE_ALLY"));
}

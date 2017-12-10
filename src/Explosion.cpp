#include "Explosion.hh"

Explosion::Explosion(const Position &pos) :
  Object(pos, std::string("EXPLOSION"))
{
  _ray = 0;
}

void	Explosion::update(float time)
{
  _ray += time * _SPEED;
  if (_ray > _MAX_RAY)
    _ray = _MAX_RAY;
}

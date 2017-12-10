/** \file Explosion.hh
 *  \brief Classe Explosion
 */

#pragma once

#include "MissileCommand.hh"
#include "Object.hh"

/** Doxygen todo */
class Explosion : public Object
{
private:
  static constexpr float	_MAX_RAY = 30;
  static constexpr float	_SPEED = 30;
  float	_ray;

public:
  Explosion(const Position &pos);

  void	update(float time);
};

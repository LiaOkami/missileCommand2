#ifndef _MISSILE_HH_
# define _MISSILE_HH_

# include "Object.hh"

class Missile : public Object
{
private:
  float		_speed;
  Position	_posEnd;
  double	_angle;

public:

  Missile(float speed, Position posBegin, Position posEnd, const string& key);
  void	move(int ms);
  bool	isEnded() const;
  double	getAngle() const;
};

#endif // _MISSILE_HH_

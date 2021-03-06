#include "Object.hh"

using namespace std;

Object::Object(const Position &pos, const string &key)
{
    _key = key;
    _pos = pos;
}

void Object::setPos(const Position &pos)
{
    _pos = pos;
}

void Object::setKey(const string &key)
{
    _key = key;
}

const Position& Object::getPos() const
{
    return _pos;
}

void Object::draw(SFMLHandler& handler) const
{
    handler.draw(_key, _pos);
}

const string&	Object::getKey() const
{
  return _key;
}

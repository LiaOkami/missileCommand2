#include "Object.hh"

using namespace std;

Object::Object(float x, float y, const std::string &key)
{
    _key = key;
    _pos.x = x;
    _pos.y = y;
}

void Object::draw(SFMLHandler& handler) const
{
    handler.draw(_key, _pos);
}


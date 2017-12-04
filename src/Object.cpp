#include "Object.hh"

using namespace std;

Object::Object(const Position &pos, const string &key)
{
    _key = key;
    _pos = pos;
}

void Object::draw(SFMLHandler& handler) const
{
    handler.draw(_key, _pos);
}


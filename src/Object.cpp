#include <SFML/Graphics.hpp>
#include "Object.hh"

#include <iostream>
#include <vector>


using namespace std;

Object :: Object(float x, float y, const std::string &key){
_key = key;
_pos.x = x;
_pos.y = y;

}

void draw(const SFMLHandler& handler) const{
handler.draw(_key, _pos);


  }


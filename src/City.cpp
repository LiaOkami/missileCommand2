#include "Object.hh"
#include "City.hh"


using namespace std;

City::City(Position posCity, const string& key)
    : Object(posCity, key)
    {
        Position posCity = this->getPos();

        _posCity = posCity;

    }

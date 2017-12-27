#include "Object.hh"
#include "Canon.hh"


using namespace std;

Canon::Canon(Position posCan, const string& key)
    : Object(posCan, key)
    {
        Position posCan = this->getPos();

        _posCan = posCan;

    }

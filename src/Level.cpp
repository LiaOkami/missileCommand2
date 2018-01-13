#include "Level.hh"

Level::Level()
{

}

void Level::defLevel(unsigned int numLevel, unsigned int &nbMissileAlly, unsigned int &nbMissileFoe)
{
    nbMissileAlly=21-numLevel;
    nbMissileFoe=9+numLevel;
}

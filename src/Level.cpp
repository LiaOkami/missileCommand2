#include "Level.hh"

Level::Level()
{

}

void Level::defLevel(int numLevel, int &nbMissileAlly, int &nbMissileFoe)
{
    nbMissileAlly=21-numLevel;
    nbMissileFoe=9+numLevel;
}

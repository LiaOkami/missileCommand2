#include "Level.hh"
#include "MissileCommand.hh"

Level::Level()
{

}

void defLevel(unsigned int numLevel, unsigned int &nbMissileAlly, unsigned int &nbMissileFoe)
{
    nbMissileAlly=21-numLevel;
    nbMissileFoe=9+numLevel;
}

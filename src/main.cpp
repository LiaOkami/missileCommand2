#include <cstdlib>
#include "MissileCommand.hh"

int     main()
{
    MissileCommand        game;

    srand(time(NULL));
    game.launch();
    return (0);
}

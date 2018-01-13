#include <cstdlib>
#include "MissileCommand.hh"
#include "Menu.hh"

int     main()
{
    MissileCommand      game;
    //Menu		menu(&(game.getWindow()), &game);

    game.launch();
    srand(time(NULL));
    return (0);
}

/**
 * \file MissileCommand.hh
 * \brief Classe MissileCommand
 * \author Pierrick Garcia
 *
 * Classe contenant tout le jeu MissileCommand
 */

#ifndef _MISSILECOMMAND_HH_
# define _MISSILECOMMAND_HH_

class MissileCommand
{
public:
  MissileCommand();

  /**
   * \fn void launch()
   * \brief Lance le jeu
   *
   * Appelé au début du programme.
   * L'intégralité du jeu est exécutée dans cette méthode.
   */
  void	launch();
};

#endif

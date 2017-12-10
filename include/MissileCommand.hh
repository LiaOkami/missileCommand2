/** \file MissileCommand.hh
 *  \brief Classe MissileCommand
 */

#ifndef _MISSILECOMMAND_HH_
# define _MISSILECOMMAND_HH_

# include "SFMLHandler.hh"

/** \brief Classe contenant tout le jeu Missile Command
 *  \author Pierrick Garcia
 */
class MissileCommand
{
private:
  SFMLHandler	_window;

public:
  /** \brief Constructeur par défaut
   */
  MissileCommand();

  /** \brief Lance le jeu
   *
   * Appelé au début du programme.
   * L'intégralité du jeu est exécutée dans cette méthode.
   */
  void	launch();

  void	update();

  void	draw();
};

#endif

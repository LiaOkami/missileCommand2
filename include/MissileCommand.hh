/** \file MissileCommand.hh
 *  \brief Classe MissileCommand
 */

#ifndef _MISSILECOMMAND_HH_
# define _MISSILECOMMAND_HH_

# include <stdint.h>

/** \brief Structure représentant la Position d'un Object
 *  \author Pierrick Garcia
 */
struct Position
{
  uint16_t	_x;
  uint16_t	_y;
};

/** \brief Classe contenant tout le jeu Missile Command
 *  \author Pierrick Garcia
 */
class MissileCommand
{
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
};

#endif

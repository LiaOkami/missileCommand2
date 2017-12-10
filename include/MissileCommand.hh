/** \file MissileCommand.hh
 *  \brief Classe MissileCommand
 */

#ifndef _MISSILECOMMAND_HH_
# define _MISSILECOMMAND_HH_

# include "Missile.hh"
# include "SFMLHandler.hh"

/** \brief Classe contenant tout le jeu Missile Command
 *  \author Pierrick Garcia
 */
class MissileCommand
{
private:
  SFMLHandler	_window;
  Position		_canonPosition;
  std::vector<Missile>	_tabMissFoe;
  std::vector<Missile>	_tabMissAlly;
  sf::Clock		_chrono;
  sf::Clock		_apparition;
  sf::Time		_dureeMax;
  sf::Time		_dureeApparition;

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

private:
  void	_pollEvents();
  void	_update();
  void	_checkCollision(const Object &missile);
  void	_draw();
};

#endif

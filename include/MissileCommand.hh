/** \file MissileCommand.hh
 *  \brief Classe MissileCommand
 */

#ifndef _MISSILECOMMAND_HH_
# define _MISSILECOMMAND_HH_

# include "Missile.hh"
# include "Canon.hh"
# include "City.hh"
# include "Explosion.hh"
# include "SFMLHandler.hh"
# include "Level.hh"

static const int	WINDOW_WIDTH = 1200;
static const int	WINDOW_HEIGHT = 900;

/** \brief Classe contenant tout le jeu Missile Command
 *  \author Pierrick Garcia
 */
class MissileCommand
{
private:
  SFMLHandler	_window;
  std::vector<Explosion>	_explosions;
  std::vector<Canon>	_canons;
  std::vector<City>	_cities;
  std::vector<Missile>	_tabMissFoe;
  std::vector<Missile>	_tabMissAlly;
  sf::Clock		_chrono;
  sf::Clock		_apparition;
  sf::Time		_dureeMax;
  sf::Time		_dureeApparition;
  unsigned int		score;
  unsigned int  nbMissileAlly;
  unsigned int  nbMissileFoe;
  unsigned int  numLevel;


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
  SFMLHandler &	getWindow();

private:
  void	_pollEvents();
  void	_update();
  void	_checkCollision(const Object &object, std::vector<City> &objects);
  void	_checkCollision(const Object &object, std::vector<Missile> &objects);
  void	_draw();
};

#endif

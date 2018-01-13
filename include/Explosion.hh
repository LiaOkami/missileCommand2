/** \file Explosion.hh
 *  \brief Classe Explosion
 */

#pragma once

#include "Object.hh"

/** Doxygen todo */
class Explosion : public Object
{
private:
  static constexpr float	_MAX_RAY = 30;
  static constexpr float	_SPEED = 1;
  float	_ray;

public:

    /** \brief méthode de génération d'une explosion
     *
     *  \param const Position &pos : prends en paramètres une Position
     *
     *  Méthode gérant toutes les explosions
     */
  Explosion(const Position &pos);

    /** \brief fonction d'update de l'explosion en fonction du temps en ms
     *
     *  \param float time: référentiel de temps pour gérer l'affichage de l'explosion
     *
     *  Fonction calculant le déplacement du missile à chaque frame
     */
  void	update(float time);

  bool	isEnded() const;

  float	getRay() const;
};

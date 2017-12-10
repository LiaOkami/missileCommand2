#ifndef _MISSILE_HH_
# define _MISSILE_HH_

# include "Object.hh"

class Missile : public Object
{
private:
  float		_speed;
  Position	_posEnd;
  double	_angle;

public:

    /** \brief Constructeur par défaut
     *
     *  \param float speed          :Vitesse du missile
     *  \param Position posBegin    :Position de départ
     *  \param Position posEnd      :Position de fin
     *  \param const string& key    :chaine, clé d'une sprite d'un Object
     *
     *  Construction du missile ayant pour attributs une vitesse, une position de début, une destination, et une key
     */
  Missile(float speed, Position posBegin, Position posEnd, const string& key);

    /** \brief fonction de déplacement du missile
     *
     *  \param int ms : durée de la frame
     *
     *  Fonction calculant le déplacement du missile à chaque frame
     */
  void	move(int ms);

    /** \brief vérifie que le missile est arrivée au terme de sa course
     *
     *  \return booléen; retourne vrai quand l'ordonnée du missile a atteint son ordonnée de position finale, reçue en paramètres initiaux
     */
  bool	isEnded() const;
  double	getAngle() const;
};

#endif // _MISSILE_HH_

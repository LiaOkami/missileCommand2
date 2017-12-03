#include "Object.hh"
#include "Missile.hh"
#include <iostream>
#include <cmath>
#include <ctgmath>

using namespace std;

Missile::Missile(float z hypothenuse, float a &vitesse, float x1 posX1, float y1 posy1 ){

_hypothenuse = hypothenuse;
_vitesse = vitesse;
_posx1 = posX1; // position au tour t+1
_posy1 = posy1; // position au tour t+1

// _hypothenuse == _vitesse * un cycle, _vitesse passée en paramètre
double angle;
// angle de la trajectoire connu
float deplAbciss; //deplacement en abcisse
float deplOrdonn; // deplacement en ordonnée

deplAbciss = cos(angle)*_hypothenuse;
_posx1 = _pos.x + deplAbciss;

deplOrdonn = sqrt(pow(_hypothenuse, 2)-pow(deplAbciss,2));
_posy1= _pos.y+deplOrdonn;


}


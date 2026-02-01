#include "Forme.h"

// Fonction contructeur forme par défaut
Forme::Forme() : centre(Point()) {}

// Fonction constructeur forme
Forme::Forme(Point const &centre) : centre(centre) {}

// Fonction pour récupérer le point d'une forme
Point Forme::getCentre() const
{
  return this->centre;
}

// Fonction de surcharge qui incrémente le point passé en paramètre
void Forme::operator+=(Point const &p)
{
  this->centre += p;
}

// Fonction pour afficher les coordonnées du centre du point
std::ostream &operator<<(std::ostream &s, Forme const &f)
{
  s << "centre : " << f.getCentre();
  return s;
}

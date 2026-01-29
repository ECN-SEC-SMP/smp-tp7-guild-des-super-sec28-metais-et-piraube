#include "Rectangle.h"

double Rectangle::perimetre() const
{
  return 2 * (this->largeur + this->longueur);
}

double Rectangle::surface() const
{
  return this->largeur * this->longueur;
}

double Rectangle::getLargeur() const
{
  return this->largeur;
}

double Rectangle::getLongueur() const
{
  return this->longueur;
}

std::ostream &operator<<(std::ostream &s, Rectangle const &r)
{
  s << "Rectangle : " << "centre : " << r.getCentre() << ", largeur : " << r.getLargeur() << ", longueur : " << r.getLongueur() << ", perimetre : " << r.perimetre() << ", surface : " << r.surface();
  return s;
}

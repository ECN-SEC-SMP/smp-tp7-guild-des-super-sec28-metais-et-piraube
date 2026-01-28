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
  s << "Rectangle : " << "centre : " << r.getCentre() << ", Largeur : " << r.getLargeur() << ", Longueur : " << r.getLongueur() << ", Perimetre : " << r.perimetre() << ", Surface : " << r.surface();
  return s;
}

#include "Cercle.h"

Cercle::Cercle() : Forme(), rayon(1.0) {}
Cercle::Cercle(Point const &centre, double rayon) : Forme(centre), rayon(rayon) {}

double Cercle::getRayon() const
{
  return this->rayon;
}

double Cercle::perimetre() const
{
  return M_PI * 2 * this->rayon;
}

double Cercle::surface() const
{
  return M_PI * this->rayon * this->rayon;
}

std::ostream &operator<<(std::ostream &s, Cercle const &c)
{
  s << "Cercle : centre = " << c.getCentre() << ",rayon = " << c.getRayon() << ",perimetre = " << c.perimetre() << ", surface = " << c.surface();
  return s;
}
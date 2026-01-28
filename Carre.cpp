#include "Carre.h"

Carre::Carre() : Rectangle(Point(), 1.0, 1.0), cote(1.0) {}
Carre::Carre(Point const &centre, double cote) : Rectangle(Point(centre), cote, cote), cote(cote) {}

double Carre::getCote() const
{
  return this->cote;
}

double Carre::perimetre() const
{
  return 4 * this->cote;
}

double Carre::surface() const
{
  return this->cote * this->cote;
}

std::ostream &operator<<(std::ostream &s, Carre const &c)
{
  s << "Carre : " << "centre : " << c.getCentre() << ", cote : " << c.getCote() << ", perimetre : " << c.perimetre() << ", surface : " << c.surface();
  return s;
}

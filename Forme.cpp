#include "Forme.h"

Forme::Forme() : centre(Point()) {}

Forme::Forme(Point const &centre) : centre(centre) {}

Point Forme::getCentre() const
{
  return this->centre;
}

void Forme::operator+=(Point const &p)
{
  this->centre += p;
}

std::ostream &operator<<(std::ostream &s, Forme const &f)
{
  s << "centre : " << f.getCentre();
  return s;
}

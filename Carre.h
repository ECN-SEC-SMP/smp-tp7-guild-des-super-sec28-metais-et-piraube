#pragma once

#include "Forme.h"
#include "Rectangle.h"
#include "Point.h"

// Classe carré qui hérite de rectangle
class Carre : public Rectangle
{
private:
  double cote;

public:
  Carre();
  Carre(Point const &centre, double cote);

  double getCote() const;

  double perimetre() const override;
  double surface() const override;
};

std::ostream &operator<<(std::ostream &s, Carre const &c);
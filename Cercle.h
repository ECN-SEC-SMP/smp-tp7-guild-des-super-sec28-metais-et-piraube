#pragma once

#include "Forme.h"
#include "Point.h"

#include <cmath> // Pour M_PI

// Fonction de cercle qui hérite de forme
class Cercle : public Forme
{
private:
  double rayon;

public:
  Cercle();
  Cercle(Point const &centre, double rayon);

  double getRayon() const;

  double perimetre() const override;
  double surface() const override;
};

std::ostream &operator<<(std::ostream &s, Cercle const &c);
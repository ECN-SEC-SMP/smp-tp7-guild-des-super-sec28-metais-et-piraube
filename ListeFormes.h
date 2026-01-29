#pragma once

#include "Point.h"
#include "Forme.h"
#include "Cercle.h"
#include "Rectangle.h"
#include "Carre.h"

#include <vector>
#include <limits>

class boiteEnglobante
{
private:
  double xMin;
  double xMax;
  double yMin;
  double yMax;

public:
  boiteEnglobante();
  boiteEnglobante(std::vector<Forme *> const &formes);

  void calculer(std::vector<Forme *> const &formes);

  double getXMin() const;
  double getXMax() const;
  double getYMin() const;
  double getYMax() const;

  double getSurface() const;

  Point getCoinInferieurGauche() const;
  Point getCoinSuperieurDroit() const;
};

std::ostream &operator<<(std::ostream &s, boiteEnglobante const &b);
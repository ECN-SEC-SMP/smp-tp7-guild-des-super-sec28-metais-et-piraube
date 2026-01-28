#pragma once

#include "Point.h"

class Forme
{
private:
  Point centre;

public:
  Forme();
  Forme(Point const &centre);

  virtual ~Forme() {}

  Point getCentre() const;

  virtual double perimetre() const = 0;
  virtual double surface() const = 0;

  void operator+=(Point const &f);
};

std::ostream &operator<<(std::ostream &s, Forme const &f);
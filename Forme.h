#pragma once

#include "Point.h"

// Classe forme
class Forme
{
private:
  Point centre;

public:
  // Fonction constructeur
  Forme();
  Forme(Point const &centre);

  virtual ~Forme() {}

  // Fonction pour récupérer le point d'une forme
  Point getCentre() const;

  // Fonction du périmètre et de la surface pour les classes enfants
  virtual double perimetre() const = 0;
  virtual double surface() const = 0;

  // Fonction de surcharge pour incrémenter le point
  void operator+=(Point const &f);
};

std::ostream &operator<<(std::ostream &s, Forme const &f);
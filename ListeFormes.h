#pragma once

#include "Point.h"
#include "Forme.h"
#include "Cercle.h"
#include "Rectangle.h"
#include "Carre.h"

#include <vector>
#include <limits>

// Classe boit englobante
class boiteEnglobante
{
private:
  double xMin;
  double xMax;
  double yMin;
  double yMax;

public:
  // Définitions des constructeurs
  boiteEnglobante();
  boiteEnglobante(std::vector<Forme *> const &formes);

  // Fonction pour calculer et mettre les attributs de boite englobante
  void calculer(std::vector<Forme *> const &formes);

  // Fonction pour récupérer les attributs de boite englobante
  double getXMin() const;
  double getXMax() const;
  double getYMin() const;
  double getYMax() const;

  // Fonction pour calculer la surface
  double getSurface() const;

  // Fonction pour récupérer les coordonnées des coins inférieurs gauches et supérieurs droits
  Point getCoinInferieurGauche() const;
  Point getCoinSuperieurDroit() const;
};

// Fonction d'affichage de boite englobante pour montrer les informations
std::ostream &operator<<(std::ostream &s, boiteEnglobante const &b);
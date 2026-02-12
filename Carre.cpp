#include "Carre.h"

// Instance de carré par défaut
Carre::Carre() : Rectangle(Point(), 1.0, 1.0), cote(1.0) {}

// Constructeur de l'objet carré
Carre::Carre(Point const &centre, double cote) : Rectangle(Point(centre), cote, cote), cote(cote) {}

// Fonction pour récupérer le côté du carré
double Carre::getCote() const
{
  return this->cote;
}

// Fonction pour récupérer le périmètre du carré
double Carre::perimetre() const
{
  return 4 * this->cote;
}

// Fonction pour récupérer la surface du carré
double Carre::surface() const
{
  return this->cote * this->cote;
}

// Surcharge pour afficher les informations du carré
std::ostream &operator<<(std::ostream &s, Carre const &c)
{
  s << "Carre : " << "centre : " << c.getCentre() << ", cote : " << c.getCote() << ", perimetre : " << c.perimetre() << ", surface : " << c.surface();
  return s;
}

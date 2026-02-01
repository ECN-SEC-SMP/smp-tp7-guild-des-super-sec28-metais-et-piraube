#include "Cercle.h"

// Instance de cercle par défaut
Cercle::Cercle() : Forme(), rayon(1.0) {}

// Constructeur de l'objet cercle
Cercle::Cercle(Point const &centre, double rayon) : Forme(centre), rayon(rayon) {}

// Fonction pour récupérer le rayon
double Cercle::getRayon() const
{
  return this->rayon;
}

// Fonction pour calculer et récupérer le rayon
double Cercle::perimetre() const
{
  return M_PI * 2 * this->rayon;
}

// Fonction pour calculer et récupérer la surface
double Cercle::surface() const
{
  return M_PI * this->rayon * this->rayon;
}

// Fonction pour afficher les informations du cercle
std::ostream &operator<<(std::ostream &s, Cercle const &c)
{
  s << "Cercle : centre = " << c.getCentre() << ", rayon = " << c.getRayon() << ", perimetre = " << c.perimetre() << ", surface = " << c.surface();
  return s;
}
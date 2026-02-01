#include "Rectangle.h"

// Fonction pour récupérer le périmètre d'un rectangle
double Rectangle::perimetre() const
{
  return 2 * (this->largeur + this->longueur);
}

// Fonction pour récupérer la surface d'un rectangle
double Rectangle::surface() const
{
  return this->largeur * this->longueur;
}

// Fonction pour récupérer la largeur du rectangle
double Rectangle::getLargeur() const
{
  return this->largeur;
}

// Fonction pour récupérer la longueur du rectangle
double Rectangle::getLongueur() const
{
  return this->longueur;
}

// Fonction pour afficher les informations du rectangle
std::ostream &operator<<(std::ostream &s, Rectangle const &r)
{
  s << "Rectangle : " << "centre : " << r.getCentre() << ", largeur : " << r.getLargeur() << ", longueur : " << r.getLongueur() << ", perimetre : " << r.perimetre() << ", surface : " << r.surface();
  return s;
}

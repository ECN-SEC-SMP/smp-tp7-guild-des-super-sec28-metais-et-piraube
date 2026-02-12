#include "ListeFormes.h"

// Constructeur par défaut de boite englobante
boiteEnglobante::boiteEnglobante() : xMin(std::numeric_limits<double>::max()), xMax(std::numeric_limits<double>::lowest()), yMin(std::numeric_limits<double>::max()), yMax(std::numeric_limits<double>::lowest()) {}

// Constructeur de boite englobante en passant un vecteur de forme
boiteEnglobante::boiteEnglobante(std::vector<Forme *> const &formes)
{
  calculer(formes);
}

// Fonction qui permet de retourner un vecteur de forme du plus petit au plus grand
void boiteEnglobante::calculer(std::vector<Forme *> const &formes)
{
  // On récupère les coordonnées x et y min et max
  this->xMin = std::numeric_limits<double>::max();
  this->xMax = std::numeric_limits<double>::lowest();
  this->yMin = std::numeric_limits<double>::max();
  this->yMax = std::numeric_limits<double>::lowest();

  // On parcours les formes dans le vecteur passé en paramètre
  for (Forme *f : formes)
  {
    Point centre = f->getCentre();

    // vérifier le type de forme pour calculer ses limites
    if (Cercle *c = dynamic_cast<Cercle *>(f)) // retourne null_ptr si ce n'est pas un Cercle
    {
      // On récupère le rayon et les coordonnées x et y
      double rayon = c->getRayon();
      double x = centre.getX();
      double y = centre.getY();

      // On détermine les plus petites et grandes valeurs de x et y
      if (x - rayon < this->xMin)
        this->xMin = x - rayon;
      if (x + rayon > this->xMax)
        this->xMax = x + rayon;
      if (y - rayon < this->yMin)
        this->yMin = y - rayon;
      if (y + rayon > this->yMax)
        this->yMax = y + rayon;
    }
    else if (Rectangle *r = dynamic_cast<Rectangle *>(f)) // retourne (aussi) vrai si c'est un carré car classe fille de Rectangle
    {
      // On récupère la largeur, longueur et les coordonnées x et y
      double largeur = r->getLargeur();
      double hauteur = r->getLongueur();
      double x = centre.getX();
      double y = centre.getY();

      // On détermine les plus petites et grandes valeurs de x et y
      if (x - largeur / 2 < this->xMin)
        this->xMin = x - largeur / 2;
      if (x + largeur / 2 > this->xMax)
        this->xMax = x + largeur / 2;
      if (y - hauteur / 2 < this->yMin)
        this->yMin = y - hauteur / 2;
      if (y + hauteur / 2 > this->yMax)
        this->yMax = y + hauteur / 2;
    }
  }
}

// Fonction qui retourne la plus petite valeur de x
double boiteEnglobante::getXMin() const
{
  return this->xMin;
}

// Fonction qui retourne la plus grande valeur de x
double boiteEnglobante::getXMax() const
{
  return this->xMax;
}

// Fonction qui retourne la plus petite valeur de y
double boiteEnglobante::getYMin() const
{
  return this->yMin;
}

// Fonction qui retourne la plus grande valeur de y
double boiteEnglobante::getYMax() const
{
  return this->yMax;
}

// Fonction qui retourne la surface
double boiteEnglobante::getSurface() const
{
  return (this->xMax - this->xMin) * (this->yMax - this->yMin);
}

// Fonction qui retourne les plus petites coordonées x et y
Point boiteEnglobante::getCoinInferieurGauche() const
{
  return Point(this->xMin, this->yMin);
}

// Fonction qui retourne les plus grandes coordonées x et y
Point boiteEnglobante::getCoinSuperieurDroit() const
{
  return Point(this->xMax, this->yMax);
}

// Fonction qui affiche les informations sur la boite englobante
std::ostream &operator<<(std::ostream &s, boiteEnglobante const &b)
{
  s << "Boite englobante : coin inferieur gauche = " << b.getCoinInferieurGauche() << ", coin superieur droit = " << b.getCoinSuperieurDroit() << ", surface = " << b.getSurface();
  return s;
}
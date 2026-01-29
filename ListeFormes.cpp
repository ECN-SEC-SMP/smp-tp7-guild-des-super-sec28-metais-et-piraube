#include "ListeFormes.h"

boiteEnglobante::boiteEnglobante() : xMin(std::numeric_limits<double>::max()), xMax(std::numeric_limits<double>::lowest()), yMin(std::numeric_limits<double>::max()), yMax(std::numeric_limits<double>::lowest()) {}

boiteEnglobante::boiteEnglobante(std::vector<Forme *> const &formes)
{
  calculer(formes);
}

void boiteEnglobante::calculer(std::vector<Forme *> const &formes)
{
  this->xMin = std::numeric_limits<double>::max();
  this->xMax = std::numeric_limits<double>::lowest();
  this->yMin = std::numeric_limits<double>::max();
  this->yMax = std::numeric_limits<double>::lowest();

  for (Forme *f : formes)
  {
    Point centre = f->getCentre();

    // vérifier le type de forme pour calculer ses limites
    if (Cercle *c = dynamic_cast<Cercle *>(f)) // retourne null_ptr si ce n'est pas un Cercle
    {
      double rayon = c->getRayon();
      double x = centre.getX();
      double y = centre.getY();

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
      double largeur = r->getLargeur();
      double hauteur = r->getLongueur();
      double x = centre.getX();
      double y = centre.getY();

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

double boiteEnglobante::getXMin() const
{
  return this->xMin;
}

double boiteEnglobante::getXMax() const
{
  return this->xMax;
}

double boiteEnglobante::getYMin() const
{
  return this->yMin;
}

double boiteEnglobante::getYMax() const
{
  return this->yMax;
}

double boiteEnglobante::getSurface() const
{
  return (this->xMax - this->xMin) * (this->yMax - this->yMin);
}

Point boiteEnglobante::getCoinInferieurGauche() const
{
  return Point(this->xMin, this->yMin);
}

Point boiteEnglobante::getCoinSuperieurDroit() const
{
  return Point(this->xMax, this->yMax);
}

std::ostream &operator<<(std::ostream &s, boiteEnglobante const &b)
{
  s << "Boite englobante : coin inferieur gauche = " << b.getCoinInferieurGauche() << ", coin superieur droit = " << b.getCoinSuperieurDroit() << ", surface = " << b.getSurface();
  return s;
}
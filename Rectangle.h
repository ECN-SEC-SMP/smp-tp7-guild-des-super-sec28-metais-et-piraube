#pragma once

#include "Forme.h"

class Rectangle : public Forme
{
private:
    double largeur;
    double longueur;

public:
    Rectangle() : Forme(), largeur(1.0), longueur(1.0) {}
    Rectangle(Point const &centre, double _largeur, double _longueur) : Forme(centre), largeur(_largeur), longueur(_longueur) {}

    double perimetre() const override;
    double surface() const override;

    double getLargeur() const;
    double getLongueur() const;
};
std::ostream &operator<<(std::ostream &s, Rectangle const &r);
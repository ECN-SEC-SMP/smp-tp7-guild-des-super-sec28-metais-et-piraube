#pragma once

#include "Forme.h"

// Classe rectangle qui hérite de la classe Forme
class Rectangle : public Forme
{
private:
    double largeur;
    double longueur;

public:
    // Constructeurs de rectangle
    Rectangle() : Forme(), largeur(1.0), longueur(1.0) {}
    Rectangle(Point const &centre, double _largeur, double _longueur) : Forme(centre), largeur(_largeur), longueur(_longueur) {}

    // Fonction pour récupérer le périmètre et la surface du rectangle qui sont réécrite
    double perimetre() const override;
    double surface() const override;

    // Fonction pour récupérer la largeur et la longueur du rectangle
    double getLargeur() const;
    double getLongueur() const;
};

// Fonction pour afficher les informations du rectangle
std::ostream &operator<<(std::ostream &s, Rectangle const &r);
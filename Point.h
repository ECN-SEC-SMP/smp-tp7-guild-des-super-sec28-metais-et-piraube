#pragma once

#include <iostream>

// Classe point
class Point
{
private:
  double x;
  double y;

public:
  // Constructeurs de point
  Point();
  Point(double x, double y);
  Point(Point const &p);

  // Fonctions de translation
  void translater(double dx, double dy);
  void translater(Point p);

  // Fonctions pour récupérer les coordonnées X et Y
  double getX() const;
  double getY() const;

  // Fonctions pour set les coordonnées X et Y
  void setX(double x);
  void setY(double y);

  // Fonction pour translater un point avec l'opérateur +=
  void operator+=(Point const &p);
};

// Fonction d'affichage des informations d'un point
std::ostream &operator<<(std::ostream &s, Point const &p);
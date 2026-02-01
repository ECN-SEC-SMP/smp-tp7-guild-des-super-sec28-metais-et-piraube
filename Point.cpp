//
// Created by pirau on 28/01/2026.
//

#include "Point.h"

// Construteur par défaut de point
Point::Point() : x(0), y(0) {}

// Constructeur de point
Point::Point(double x, double y) : x(x), y(y) {}

// Constructeur de point depuis un point
Point::Point(Point const &p) : x(p.getX()), y(p.getY()) {}

// Fonction pour translater les coordonnées d'un point depuis des coordonnées
void Point::translater(double x, double y)
{
  this->x += x;
  this->y += y;
}

// Fonction pour translater les coordonnées d'un point depuis un point
void Point::translater(Point p)
{
  this->x += p.getX();
  this->y += p.getY();
}

// Fonction pour récupérer les coordonnées X d'un point
double Point::getX() const
{
  return this->x;
}

// Fonction pour récupérer les coordonnées Y d'un point
double Point::getY() const
{
  return this->y;
}

// Fonction pour set les coordonnées X d'un point
void Point::setX(double x)
{
  this->x = x;
}

// Fonction pour set les coordonnées Y d'un point
void Point::setY(double y)
{
  this->y = y;
}

// Fonction pour afficher les informations d'un point
std::ostream &operator<<(std::ostream &s, Point const &p)
{
  s << "x = " << p.getX() << ", y = " << p.getY();
  return s;
}

// Fonction de surcharge pour translater un point avec un autre point
void Point::operator+=(Point const &p)
{
  this->x += p.getX();
  this->y += p.getY();
}

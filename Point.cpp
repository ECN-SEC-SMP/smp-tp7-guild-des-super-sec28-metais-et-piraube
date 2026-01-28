//
// Created by pirau on 28/01/2026.
//

#include "Point.h"

Point::Point() : x(0), y(0) {}

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point(Point const &p) : x(p.getX()), y(p.getY()) {}

void Point::translater(double x, double y)
{
  this->x += x;
  this->y += y;
}

void Point::translater(Point p)
{
  this->x += p.getX();
  this->y += p.getY();
}

double Point::getX() const
{
  return this->x;
}

double Point::getY() const
{
  return this->y;
}

void Point::setX(double x)
{
  this->x = x;
}

void Point::setY(double y)
{
  this->y = y;
}

std::ostream &operator<<(std::ostream &s, Point const &p)
{
  s << "x = " << p.getX() << ", y = " << p.getY();
  return s;
}

void Point::operator+=(Point const &p)
{
  this->x += p.getX();
  this->y += p.getY();
}

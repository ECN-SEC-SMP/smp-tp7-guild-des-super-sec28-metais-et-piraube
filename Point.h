#pragma once

#include <iostream>

class Point
{
private:
  double x;
  double y;

public:
  Point();
  Point(double x, double y);
  Point(Point const &p);

  void translater(double dx, double dy);
  void translater(Point p);

  double getX() const;
  double getY() const;

  void setX(double x);
  void setY(double y);

  std::ostream affichePoint() const;
  void operator+=(Point const &p);
};

std::ostream &operator<<(std::ostream &s, Point const &p);
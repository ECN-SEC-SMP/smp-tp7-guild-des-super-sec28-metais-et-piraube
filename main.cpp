#include "Point.h"
#include "Forme.h"
#include "Cercle.h"
#include "Rectangle.h"
#include "Carre.h"

#include <iostream>

int main(int argc, char **argv)
{
  Point p1(2.0, 3.0);
  Point p2(4.0, 5.0);
  p1 += p2;
  std::cout << "Point 1 : " << p1 << std::endl;
  Forme *r1 = new Rectangle(p1, 54, 34);
  std::cout << *static_cast<Rectangle *>(r1) << std::endl;

  Forme *c1 = new Cercle(Point(5.0, 6.0), 10.0);
  std::cout << *static_cast<Cercle *>(c1) << std::endl;

  Forme *carre1 = new Carre(Point(1.0, 1.0), 5.0);
  std::cout << *static_cast<Carre *>(carre1) << std::endl;

  delete r1;
  delete c1;
  delete carre1;

  return 0;
}
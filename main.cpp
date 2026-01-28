#include "Point.h"
#include "Forme.h"

#include <iostream>

int main(int argc, char **argv)
{
  Point p1(2.0, 3.0);
  Point p2(4.0, 5.0);
  p1 += p2;
  std::cout << "Point 1 : " << p1 << std::endl;

  return 0;
}
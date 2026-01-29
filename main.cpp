#include "Point.h"
#include "Forme.h"
#include "Cercle.h"
#include "Rectangle.h"
#include "Carre.h"
#include "ListeFormes.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// fonction pour générer des formes aléatoires
void ajouterFormesAleatoires(std::vector<Forme *> &formes, int nombre)
{
  for (int i = 0; i < nombre; i++)
  {
    // position aléatoire entre -50 et 50
    double x = (rand() % 100) - 50;
    double y = (rand() % 100) - 50;
    Point centre(x, y);

    // type de forme aléatoire (0=Cercle, 1=Rectangle, 2=Carré)
    int type = rand() % 3;

    if (type == 0)
    {
      // cercle avec rayon entre 5 et 20
      double rayon = 5 + (rand() % 16);
      formes.push_back(new Cercle(centre, rayon));
    }
    else if (type == 1)
    {
      // rectangle avec dimensions entre 10 et 40
      double largeur = 10 + (rand() % 31);
      double hauteur = 10 + (rand() % 31);
      formes.push_back(new Rectangle(centre, largeur, hauteur));
    }
    else
    {
      // carré avec côté entre 5 et 25
      double cote = 5 + (rand() % 21);
      formes.push_back(new Carre(centre, cote));
    }
  }
}

int main(int argc, char **argv)
{
  srand(time(NULL));

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

  std::vector<Forme *> formes;
  formes.push_back(r1);
  formes.push_back(c1);
  formes.push_back(carre1);

  double surfaceTotale = 0;

  for (Forme *f : formes)
  {
    surfaceTotale += f->surface();
  }

  std::cout << "Surface totale des formes : " << surfaceTotale << std::endl;

  ajouterFormesAleatoires(formes, 20);
  boiteEnglobante *boite = new boiteEnglobante(formes);
  std::cout << (*boite) << std::endl;

  // TODO : créer tous les destrcuteurs et bien viéder la mémoire
  for (Forme *f : formes)
  {
    delete f;
  }
  delete boite;

  return 0;
}
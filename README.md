# Compte Rendu TP7 - Programmation Orientée Objet
**École Centrale de Nantes - SMP**

---

## 1. Création d'une classe Point

### Implémentation
Classe représentant un point 2D avec coordonnées x et y privées.

```cpp
class Point {
private:
  double x, y;
public:
  Point();                          // Constructeur par défaut
  Point(double x, double y);        // Constructeur paramétré
  Point(Point const &p);            // Constructeur de copie
  
  void translater(double dx, double dy);
  void translater(Point p);
  
  double getX() const;
  void setX(double x);
  // idem pour Y
};
```

### Concepts POO

**Encapsulation** : Les attributs sont privés, on y accède uniquement via getters/setters. Ça protège les données et permet de contrôler comment elles sont modifiées.

**Constructeur de copie** : Prend `Point const &p` (référence constante). Le `const` garantit qu'on ne modifiera pas le point original, et la référence évite de copier inutilement l'objet en mémoire.

**Méthode const** : `double getX() const` indique que cette méthode ne modifie pas l'objet. Essentiel pour pouvoir appeler la méthode sur des objets constants.

```cpp
Point p1(2.0, 3.0);
Point p2(p1);           // Constructeur de copie
p1.translater(1.0, 2.0);
```

---

## 2. Surcharge d'opérateurs

### Opérateur << (externe à la classe)

```cpp
std::ostream &operator<<(std::ostream &s, Point const &p) {
  s << "x = " << p.getX() << ", y = " << p.getY();
  return s;
}
```

**Pourquoi externe ?** L'opérateur `<<` prend en premier paramètre un `ostream`, pas un `Point`. Si c'était une méthode membre, on devrait écrire `point << cout` au lieu de `cout << point`. En étant externe, la syntaxe reste naturelle.

### Opérateur += (membre de la classe)

```cpp
void Point::operator+=(Point const &p) {
  this->x += p.getX();
  this->y += p.getY();
}
```

**Pourquoi membre ?** L'opérateur `+=` modifie l'objet de gauche (`p1 += p2` modifie `p1`). En tant que méthode membre, on a directement accès à `this` qui représente l'objet à modifier.

**Usage :**
```cpp
Point p1(2.0, 3.0);
Point p2(4.0, 5.0);
p1 += p2;  // p1 devient (6.0, 8.0)
std::cout << p1 << std::endl;
```

---

## 3. Formes géométriques abstraites

### Classe abstraite Forme

```cpp
class Forme {
private:
  Point centre;
public:
  Forme(Point const &centre);
  virtual ~Forme() {}
  
  Point getCentre() const;
  
  virtual double perimetre() const = 0;  // Méthode pure
  virtual double surface() const = 0;    // Méthode pure
  
  void operator+=(Point const &p);
};
```

### Concepts POO

**Classe abstraite** : Les méthodes `perimetre()` et `surface()` sont **virtuelles pures** (`= 0`). Ça force les classes dérivées à implémenter ces méthodes. On ne peut pas créer d'objet `Forme` directement car le concept de "forme" est abstrait - seules les formes concrètes (cercle, carré...) ont un sens.

```cpp
Forme* f = new Forme(Point(0,0));  // ❌ ERREUR - classe abstraite
Forme* f = new Cercle(Point(0,0), 5.0);  // ✅ OK
```

**Destructeur virtuel** : `virtual ~Forme()` est crucial pour le polymorphisme. Sans ça, quand on fait `delete forme;` sur un pointeur `Forme*` qui pointe vers un `Cercle`, seul le destructeur de `Forme` serait appelé, créant une fuite mémoire.

```cpp
Forme* f = new Cercle(Point(0,0), 5.0);
delete f;  // Sans virtual ~Forme(), le destructeur de Cercle ne serait pas appelé
```

---

## 4. Formes géométriques concrètes

### Cercle, Rectangle, Carré

```cpp
class Cercle : public Forme {
private:
  double rayon;
public:
  Cercle(Point const &centre, double rayon);
  double perimetre() const override;  // Implémente la méthode pure
  double surface() const override;
};

class Rectangle : public Forme {
private:
  double largeur, longueur;
public:
  Rectangle(Point const &centre, double l, double L);
  double perimetre() const override;
  double surface() const override;
};

class Carre : public Rectangle {
private:
  double cote;
public:
  Carre(Point const &centre, double cote);
  double perimetre() const override { return 4 * cote; }
  double surface() const override { return cote * cote; }
};
```

### Concepts POO

**Héritage** : `Cercle` hérite de `Forme`, `Carré` hérite de `Rectangle`. Permet de réutiliser le code (le centre est géré par `Forme`) et de créer une hiérarchie logique.

**Override** : Le mot-clé `override` indique qu'on redéfinit une méthode virtuelle. C'est optionnel mais recommandé car le compilateur vérifie qu'on redéfinit bien une méthode existante (évite les typos).

**Polymorphisme** : On peut stocker différentes formes dans un même conteneur et appeler leurs méthodes sans connaître leur type exact :

```cpp
std::vector<Forme*> formes;
formes.push_back(new Cercle(Point(0,0), 5.0));
formes.push_back(new Rectangle(Point(1,1), 10, 20));
formes.push_back(new Carre(Point(2,2), 7.0));

double surfaceTotale = 0;
for (Forme* f : formes) {
  surfaceTotale += f->surface();  // Appel polymorphe - la bonne méthode est appelée
}
```

---

## 5. Boîte englobante et liste de formes

### Dynamic cast pour identifier le type

```cpp
void boiteEnglobante::calculer(std::vector<Forme*> const &formes) {
  for (Forme* f : formes) {
    Point centre = f->getCentre();
    
    if (Cercle* c = dynamic_cast<Cercle*>(f)) {
      // f est un Cercle
      double rayon = c->getRayon();
      // Calcul des limites : centre ± rayon
      if (centre.getX() - rayon < this->xMin) this->xMin = centre.getX() - rayon;
      // ...
    }
    else if (Rectangle* r = dynamic_cast<Rectangle*>(f)) {
      // f est un Rectangle ou un Carré (car Carré hérite de Rectangle)
      double largeur = r->getLargeur();
      double hauteur = r->getLongueur();
      // Calcul des limites : centre ± largeur/2 et hauteur/2
      // ...
    }
  }
}
```

### Concepts POO

**Dynamic_cast** : Permet de vérifier et convertir un pointeur de classe mère vers une classe fille à l'exécution. Renvoie `nullptr` si la conversion est impossible.

**Pourquoi dynamic_cast ici ?** On a un `Forme*` mais on a besoin d'accéder à des méthodes spécifiques comme `getRayon()` (Cercle) ou `getLargeur()` (Rectangle) qui n'existent pas dans `Forme`. Le `dynamic_cast` nous permet de savoir si c'est un Cercle ou un Rectangle et d'accéder aux bonnes méthodes.

**Alternative sans dynamic_cast** : On aurait pu ajouter des méthodes virtuelles `getXMin()`, `getXMax()`, etc. dans `Forme`, mais ça alourdit l'interface. Le `dynamic_cast` est justifié ici car le calcul de la boîte englobante dépend vraiment de la géométrie spécifique de chaque forme.

```cpp
// Exemple complet
std::vector<Forme*> formes;
formes.push_back(new Cercle(Point(0,0), 10));
formes.push_back(new Rectangle(Point(20,20), 15, 25));

boiteEnglobante boite(formes);
std::cout << boite << std::endl;
// Affiche le rectangle minimal contenant toutes les formes
```

---

## Concepts POO - Résumé

1. **Encapsulation** : Attributs privés, accès contrôlé via getters/setters
2. **Héritage** : Réutilisation de code (Cercle hérite de Forme, Carré de Rectangle)
3. **Polymorphisme** : Un `Forme*` peut pointer vers n'importe quelle forme concrète
4. **Abstraction** : `Forme` est abstraite (méthodes pures), seules les formes concrètes existent
5. **Surcharge d'opérateurs** : `<<` externe pour syntaxe naturelle, `+=` membre pour modification
6. **RTTI (dynamic_cast)** : Identification du type réel à l'exécution
7. **Const correctness** : `const &` pour références, méthodes `const` pour garanties
8. **Destructeur virtuel** : Destruction correcte des objets polymorphes
#include "nuage.hpp"

unsigned int Nuage::size() { return (unsigned int) points.size();}
void Nuage::ajouter(Point & p) { points.push_back(&p); }
Nuage::const_iterator Nuage::begin() { return points.begin();}
Nuage::const_iterator Nuage::end() { return points.end();}

Cartesien barycentre(Nuage & n) {
   double x = 0.0, y = 0.0;

   Nuage::const_iterator it;

   for(it = n.begin(); it != n.end(); ++it) {
      Cartesien tmp;

      (*it)->convertir(tmp);
      x += tmp.getX();
      y += tmp.getY();
   }

   return Cartesien(x/n.size(), y/n.size());
}
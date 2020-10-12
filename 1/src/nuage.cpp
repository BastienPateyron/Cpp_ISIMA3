#include "nuage.hpp"

unsigned int Nuage::size() { return (unsigned int) points.size();}
void Nuage::ajouter(Point & p) { points.push_back(&p); }
Nuage::const_iterator Nuage::begin() { return points.begin();}
Nuage::const_iterator Nuage::end() { return points.end();}
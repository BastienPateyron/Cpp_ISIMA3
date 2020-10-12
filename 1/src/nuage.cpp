#include "nuage.hpp"

unsigned int Nuage::size() { return (unsigned int) points.size();}
void Nuage::ajouter(Point & p) { points.push_back(&p); }
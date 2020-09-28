#include "cartesien.hpp"

Cartesien::Cartesien() : Cartesien(0.0, 0.0) {}
Cartesien::Cartesien(double x, double y) : x(x), y(y) {}

void Cartesien::getX() const { return this-> x; }
void Cartesien::getY() const { return this-> y; }

#endif
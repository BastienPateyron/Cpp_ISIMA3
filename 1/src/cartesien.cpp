#include "cartesien.hpp"

// Constructeurs
Cartesien::Cartesien() : Cartesien(0.0, 0.0) {}
Cartesien::Cartesien(double x, double y) : x(x), y(y) {}

// Constantes
double Cartesien::getX() const { return this->x; }
double Cartesien::getY() const { return this->y; }
void Cartesien::afficher(std::stringstream & flux) const {
   flux << "(x=" << x << ";y=" << y << ")";
}

// Effet de bord
void Cartesien::setX(double X) { this->x = X;}
void Cartesien::setY(double Y) { this->y = Y;}


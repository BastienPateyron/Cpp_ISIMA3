#include "cartesien.hpp"

// Constructeurs
Cartesien::Cartesien() : Cartesien(0.0, 0.0) {}
Cartesien::Cartesien(double x, double y) : x(x), y(y) {}
Cartesien::Cartesien(Polaire const & p) { p.convertir(*this); }

// Constantes
double Cartesien::getX() const { return this->x; }
double Cartesien::getY() const { return this->y; }
std::ostream & Cartesien::afficher(std::ostream & flux) const {
   return flux << "(x=" << x << ";y=" << y << ")";
}
void Cartesien::convertir(Polaire & p) const {
   p.setAngle(atan2(y, x) * 180 / M_PI);
   p.setDistance(hypot(x, y));
}
void Cartesien::convertir(Cartesien & c) const { c = *this; }

// Effet de bord
void Cartesien::setX(double X) { this->x = X;}
void Cartesien::setY(double Y) { this->y = Y;}



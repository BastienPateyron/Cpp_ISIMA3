#include "polaire.hpp"

// int Forme::nbFormes = 0; // Initialisation unique de la variable de classe

Polaire::Polaire() : Polaire(0.0, 0.0) {}
Polaire::Polaire(double a, double d) : a(a), d(d) {}
Polaire::Polaire(Cartesien const & c) { c.convertir(*this); }

// Methodes const
double Polaire::getAngle()    const { return this->a; }
double Polaire::getDistance() const { return this->d; }
std::ostream & Polaire::afficher(std::ostream & flux) const {   
      return flux << "(a=" << a << ";d=" << d << ")";
}

void Polaire::convertir(Polaire & p) const { p = *this; }
void Polaire::convertir(Cartesien & c) const {
      c.setX(d * cos(a * M_PI / 180));
      c.setY(d * sin(a * M_PI / 180));
}

// Methodes avec effet de bord
void Polaire::setAngle(double a)    { this->a = a; }
void Polaire::setDistance(double d) { this->d = d; }

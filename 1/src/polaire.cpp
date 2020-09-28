#include "polaire.hpp"

// int Forme::nbFormes = 0; // Initialisation unique de la variable de classe

// Forme::Forme() : Forme(0, 0) {}

Polaire::Polaire() : Polaire(0.0, 0.0) {}
Polaire::Polaire(double a, double d) : a(a), d(d) {}

// Forme::Forme(double w, double h, Point p) : couleur(COULEURS::BLEU),
//                                             id(Forme::nbFormes++),
//                                             point(p),
//                                             w(w),
//                                             h(h)
// {
// }

// TODO
// std::string Polaire::afficher() const
// {
//    return std::to_string(point.getX()) + " " +
//           std::to_string(point.getY()) + " " +
//           std::to_string(getLargeur()) + " " +
//           std::to_string(getHauteur());
// }

// Methodes statiques / de classe
// int Forme::getId() const { return id; }
// int Forme::prochainId() { return nbFormes; }

// Methodes const
double Polaire::getAngle()    const { return this->a; }
double Polaire::getDistance() const { return this->d; }
void   Polaire::afficher(std::ostream & flux) const {   
      flux << "(a=" << a << ";d=" << d << ")";
}

// COULEURS Forme::getCouleur() const { return couleur; }
// double Forme::getLargeur() const { return w; }
// double Forme::getHauteur() const { return h; }

// Methodes avec effet de bord
void Polaire::setAngle(double a)    { this->a = a; }
void Polaire::setDistance(double d) { this->d = d; }

// Point &Forme::getPoint() { return point; } // TODO: Réussir à retourner la référence du point
// void Forme::setCouleur(COULEURS c) { couleur = c; }
// void Forme::setX(double x) { point.setX(x); }
// void Forme::setY(double y) { point.setY(y); }
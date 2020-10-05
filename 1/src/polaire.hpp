#ifndef __CPP1__POLAIRE_HPP__
#define __CPP1__POLAIRE_HPP__

#include <iostream>
#include <sstream>
#include "point.hpp"
#include "cartesien.hpp"

class Polaire : public Point {
   // Attributs //
   private:
      double a;   // Angle
      double d;   // Distance

   public:

   
   // Methodes //
   public:
      Polaire();
      Polaire(double a, double d);
      Polaire(Cartesien const & c);

      // Methodes const
      double getAngle() const;
      double getDistance() const;
      std::ostream & afficher(std::ostream & flux) const; // TODO: passer en std::stringstream
      void convertir(Cartesien & c) const;
      void convertir(Polaire & p) const;

      // Methodes a effet de bord
      void setAngle(double a);
      void setDistance(double d);
      
      // Elements statiques
   private:
      // static int nbFormes;

   public:
      // static int prochainId();
};

#endif
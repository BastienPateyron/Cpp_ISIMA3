#ifndef __CPP1__CARTESIEN_HPP__
#define __CPP1__CARTESIEN_HPP__

#include <sstream>
#include "point.hpp"
#include "polaire.hpp"

class Cartesien : public Point 
{
   private:
      double x;
      double y;

   public:
      Cartesien();
      Cartesien(double x, double y);
      Cartesien(Polaire const & p);

      // Constantes
      double getX() const;
      double getY() const;
      std::ostream & afficher(std::ostream & flux) const;
      void convertir(Cartesien & c) const;
      void convertir(Polaire & p) const;

      // Effet de bord
      void setX(double X);
      void setY(double Y);

};

#endif
#ifndef __CPP1__CARTESIEN_HPP__
#define __CPP1__CARTESIEN_HPP__

#include <sstream>

class Cartesien {
   private:
      double x;
      double y;

   public:
      Cartesien();
      Cartesien(double x, double y);

      // Constantes
      double getX() const;
      double getY() const;
      void afficher(std::stringstream & flux) const;

      // Effet de bord
      void setX(double X);
      void setY(double Y);

};

#endif
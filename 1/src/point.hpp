#ifndef __CPP1__POINT_HPP__
#define __CPP1__POINT_HPP__

#include <iostream>
#include <math.h>

class Cartesien;
class Polaire;

class Point {
   // Attributs
   private:


   public:


   private:

   public:
   // Constructeurs
   Point();
   virtual ~Point();

   // Méthodes
   virtual std::ostream & afficher(std::ostream & flux) const = 0;
   virtual void convertir(Cartesien & p) const = 0;
   virtual void convertir(Polaire & p) const = 0;

};

std::ostream & operator<<(std::ostream & flux, Point const & p);

#endif


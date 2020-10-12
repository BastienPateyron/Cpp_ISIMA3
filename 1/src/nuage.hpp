#ifndef __CPP1__NUAGE_HPP__
#define __CPP1__NUAGE_HPP__

#include <iostream>
#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"
#include <vector>
#include <iterator>



class Nuage {


   private:
      std::vector<Point *> points;

   public:
      using const_iterator = std::vector<Point *>::const_iterator;

      unsigned int size();
      void ajouter(Point & p);
      const_iterator begin();
      const_iterator end();
};


Cartesien barycentre(Nuage & n);


#endif
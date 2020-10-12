#ifndef __CPP1__NUAGE_HPP__
#define __CPP1__NUAGE_HPP__

#include <iostream>
#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"
#include <vector>

class Nuage {

   private:
      std::vector<Point *> points;

   public:
      unsigned int size();
      void ajouter(Point & p);

};

#endif
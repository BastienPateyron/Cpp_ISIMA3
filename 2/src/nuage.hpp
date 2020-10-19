#ifndef __CPP1__NUAGE_HPP__
#define __CPP1__NUAGE_HPP__

#include <iostream>
#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"
#include <vector>
#include <iterator>

template<class Cartesien> class Nuage;
template<class Polaire> class Nuage;


template <typename T> class Nuage {

   private:
      // std::vector<Point *> points;
      std::vector<T> points;
   
   public:
      // using const_iterator = std::vector<Point *>::const_iterator;
      using const_iterator = typename std::vector<T>::const_iterator;

      unsigned int size() { return (unsigned int) points.size(); }
      void ajouter(const T & p) { points.push_back(p); }
      const_iterator begin() { return points.begin(); }
      const_iterator end() { return points.end(); }
      // T barycentre(Nuage<T> & n);
};





// class BarycentreCartesien {
//    public:
//       Cartesien operator()(Nuage & n);
// };

// class BarycentrePolaire {
//    public:
//       Polaire operator()(Nuage & n);
// };



#endif
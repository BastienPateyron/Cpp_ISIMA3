#ifndef __CPP1__NUAGE_HPP__
#define __CPP1__NUAGE_HPP__

#include <iostream>
#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"
#include <vector>
#include <iterator>

// template<class Cartesien> class Nuage;
// template<class Polaire> class Nuage;


template <typename T> class Nuage {

   private:
      std::vector<T> points;
   
   public:
      using const_iterator = typename std::vector<T>::const_iterator;

      unsigned int size() { return (unsigned int) points.size(); }
      void ajouter(const T & p) { points.push_back(p); }
      const_iterator begin() { return points.begin(); }
      const_iterator end() { return points.end(); }
};

template <typename T> T barycentre_v1(Nuage<T> & n) {
   double x = 0.0, y = 0.0;

   if(n.size() == 0) {
      return T(x, y);
   }
   else {
      typename Nuage<T>::const_iterator it;

      for(it = n.begin(); it != n.end(); ++it) {
         Cartesien tmp;

         (*it).convertir(tmp);
         x += tmp.getX();
         y += tmp.getY();
      }

      Cartesien c(x/n.size(), y/n.size());
      T resultat;

      return c;
   }
}

template <typename T> T barycentre_v2(Nuage<T> & n) {
   double x = 0.0, y = 0.0;

   if(n.size() == 0) {
      return T(x, y);
   }
   else {
      typename Nuage<T>::const_iterator it;

      for(it = n.begin(); it != n.end(); ++it) {
         Cartesien tmp;

         (*it).convertir(tmp);
         x += tmp.getX();
         y += tmp.getY();
         // std::cout << tmp.getX() << std::endl;
      }

      Cartesien c(x/n.size(), y/n.size());
      T resultat;

      return c;
   }
}




// class BarycentreCartesien {
//    public:
//       Cartesien operator()(Nuage & n);
// };

// class BarycentrePolaire {
//    public:
//       Polaire operator()(Nuage & n);
// };



#endif
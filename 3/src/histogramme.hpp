#ifndef __CPP3__HISTOGRAMME_HPP__
#define __CPP3__HISTOGRAMME_HPP__

#include <vector>
#include "classe.hpp"

class Histo {
   
   public:
      typedef std::vector<Classe> classes_t;

   private:
      classes_t classes;

   public:
      Histo(const double borneInf, const double borneSup, const unsigned nombre) {
         double interval = (borneSup - borneInf) / nombre;

         for(unsigned i = 0; i < nombre; i++){
            double inf = borneInf + (interval * i);
            double sup = inf + interval;
            // std::cout << inf << " - " << sup << std::endl;

            classes.push_back(Classe(inf, sup));
         }
      }

      classes_t const &  getClasses() const {return classes;}

};

#endif
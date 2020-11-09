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
      

      // TODO:
      /** 
       * Parcours la liste des valeurs de l'échantillon.
       * Pour chaque valeur, parcours la liste des "classes" de notre histogramme.
       * Si la valeur actuelle est comprise dans les bornes de la classe actuelle,
       * on augmente la quantité de cette classe puis on passe à la valeur suivante
       */
      void ajouter(Echantillon e) {

         // // TODO: Peut-être faire un foreach ?
         // Histo::classes_t::const_iterator it = getClasses().begin();
         // for(unsigned i = 0; i < e.getTaille(); ++i) {
         //    if(e.getValeur(i).getNombre() <= it->getBorneInf() 
         //       && e.getValeur(i).getNombre() <= it->getBorneSup()) {
         //          it->setQuantite(e.getValeur(i).getNombre());
         //    }
         // }
      }

};

#endif
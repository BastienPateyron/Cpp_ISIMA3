#ifndef __CPP3__HISTOGRAMME_HPP__
#define __CPP3__HISTOGRAMME_HPP__

#include <vector>
#include "classe.hpp"

class Histogramme
{

public:
   typedef std::vector<Classe> classes_t;

private:
   classes_t classes;

public:
   Histogramme(const double borneInf, const double borneSup, const unsigned nombre)
   {
      double interval = (borneSup - borneInf) / nombre;

      for (unsigned i = 0; i < nombre; i++)
      {
         double inf = borneInf + (interval * i);
         double sup = inf + interval;
         classes.push_back(Classe(inf, sup));
      }
   }

   classes_t &getClasses() { return classes; }

   /** 
    * Parcours la liste des valeurs de l'échantillon.
    * Pour chaque valeur, parcours la liste des "classes" de notre histogramme.
    * Si la valeur actuelle est comprise dans les bornes de la classe actuelle,
    * on augmente la quantité de cette classe puis on passe à la valeur suivante
    */
   void ajouter(Echantillon e)
   {
      for (unsigned i = 0; i < e.getTaille(); ++i)
      {
         for (Classe & classe  : getClasses())
         {
            if (e.getValeur(i).getNombre() >= classe.getBorneInf() &&
                e.getValeur(i).getNombre() < classe.getBorneSup())
            {
               classe.ajouter();
            }
         }
      }
   }
};

#endif
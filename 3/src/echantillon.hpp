#ifndef __CPP3__ECHANTILLON_HPP__
#define __CPP3__ECHANTILLON_HPP__

#include "valeur.hpp"
#include <vector>
#include <iostream>

class Echantillon
{

private:
   // unsigned int taille;
   std::vector<Valeur> valeurs;

public:
   // Echantillon(unsigned int taille = 0) : taille(taille) {}
   unsigned int getTaille() const { return valeurs.size(); }
   void ajouter(double v) { valeurs.push_back(v); }
  
   Valeur getMinimum()
   {
      typename std::vector<Valeur>::const_iterator it;
      Valeur v = (*(valeurs.begin()));

      // std::cout << v.getNombre() << std::endl;
      for (it = valeurs.begin(); it != valeurs.end(); it++)
      {
         // std::cout << (*it).getNombre() << std::endl;
         if ((*it).getNombre() < v.getNombre())
         {
            
            v = (*it);
         }
      }
      return v;
   }

   Valeur getMaximum()
   {
      typename std::vector<Valeur>::const_iterator it;
      Valeur v = (*(valeurs.begin()));
      
      for (it = valeurs.begin(); it != valeurs.end(); it++)
      {
         if ((*it).getNombre() > v.getNombre())
         {
            v = (*it);
         }
      }
      return v;
   }
};

#endif
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

   Valeur const & getValeur(unsigned int i) const {
      Valeur v;

      if (valeurs.size())
      {
         v = valeurs.at(i);
      }
      else
      {
         throw std::domain_error("Tableau vide");
      }

      return v;
   }


   Valeur getMinimum()
   {
      Valeur v;
      typename std::vector<Valeur>::const_iterator it;
      if (valeurs.size())
      {
         v = (*(valeurs.begin()));

         for (it = valeurs.begin(); it != valeurs.end(); it++)
         {
            if ((*it).getNombre() < v.getNombre())
            {
               v = (*it);
            }
         }
      }
      else
      {
         throw std::domain_error("Tableau vide");
      }

      return v;
   }

   Valeur getMaximum()
   {
      typename std::vector<Valeur>::const_iterator it;
      Valeur v;
      if (valeurs.size())
      {
         v = (*(valeurs.begin()));
         for (it = valeurs.begin(); it != valeurs.end(); it++)
         {
            if ((*it).getNombre() > v.getNombre())
            {
               v = (*it);
            }
         }
      }
      else
      {
         throw std::domain_error("Tableau vide");
      }
      return v;
   }
};

#endif
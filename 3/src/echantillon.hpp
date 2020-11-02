#ifndef __CPP3__ECHANTILLON_HPP__
#define __CPP3__ECHANTILLON_HPP__

#include "valeur.hpp"
#include <vector>
#include <iterator>

class Echantillon {

   private:
      // unsigned int taille;
      std::vector<Valeur> valeurs;

   public:
      // Echantillon(unsigned int taille = 0) : taille(taille) {}
      unsigned int getTaille() const {return valeurs.size();}
      void ajouter(double v) {valeurs.push_back(v);}

};

#endif
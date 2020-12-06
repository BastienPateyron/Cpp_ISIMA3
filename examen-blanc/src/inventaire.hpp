#ifndef __HPP__INVENTAIRE__
#define __HPP__INVENTAIRE__

#include "item.hpp"
#include <map>
#include <vector>


class Inventaire {

   public: enum class Categorie {
      CONSOMMABLE = 'C',
      RARE        = 'R',
      ARME        = 'A',
      NORMAL      = 'N',
   };

   public: using list_t = std::vector<Item *>;

   // Attributs
   private: std::map<Inventaire::Categorie, list_t> items;

   // Methodes constantes
   public: int getTaille() const {return items.size();}
   public: list_t const & getItemsParCategorie(Categorie categorie) {return items[categorie];}

   // Methodes non constantes
   // public: void ajouter(Item * i) {ajouter(i, Inventaire::Categorie::NORMAL);}
   public: void ajouter(Item * i, Categorie categorie);
};

// Definitions
void Inventaire::ajouter(Item * i, Categorie categorie = Categorie::NORMAL) {
   auto it = std::find_if(
      items[categorie].begin(),
      items[categorie].end(),
      [i](Item * current) {return i->getNom() < current->getNom();}
   );

   items[categorie].insert(it, i);
}

#endif
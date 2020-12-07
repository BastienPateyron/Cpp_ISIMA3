#ifndef __HPP__INVENTAIRE__
#define __HPP__INVENTAIRE__

#include "item.hpp"
#include <map>
#include <set>
#include <vector>

class TrieurAlphabetique {
   public: bool operator () (Item * a, Item * b) {return a->getNom() < b->getNom();}
};

class TrieurPrix {
   public: bool operator () (Item * a, Item * b) {return a->getPrix() < b->getPrix();}
};
 
template <class Trieur = TrieurAlphabetique>
class Inventaire {

   public: enum class Categorie {
      CONSOMMABLE = 'C',
      RARE        = 'R',
      ARME        = 'A',
      NORMAL      = 'N',
   };

   public: using list_t = std::set<Item *, Trieur>;

   // Attributs
   private: std::map<Inventaire::Categorie, list_t> items;

   // Methodes constantes
   public: int getTaille() const {return items.size();}
   public: list_t const & getItemsParCategorie(Categorie categorie) {return items[categorie];}

   // Methodes non constantes
   // public: void ajouter(Item * i) {ajouter(i, Inventaire::Categorie::NORMAL);}
   public: void ajouter(Item * i, Categorie categorie = Categorie::NORMAL);
};

// Definitions
template <typename Trieur>
void Inventaire<Trieur>::ajouter(Item * i, Categorie categorie) {
   items[categorie].insert(i);

   // // A utiliser si on prend avec un vector
   // auto it = std::find_if(
   //    items[categorie].begin(),
   //    items[categorie].end(),
   //    [i](Item * current) {return i->getNom() < current->getNom();}
   // );

   // items[categorie].insert(it, i);
}

#endif
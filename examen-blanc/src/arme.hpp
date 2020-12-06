#ifndef __HPP__ARME__
#define __HPP__ARME__

#include <iostream>
#include "item.hpp"
#include "enchantement.hpp"

class Arme : public Item {

   // Attributs
   private: int durabilite;
   private: Enchantement * enchantement;
   
   // Constructeurs
   public: Arme(std::string nom, int prix, int durabilite) : Item(nom.c_str(), prix), durabilite(durabilite), enchantement(nullptr) {}
   public: Arme(Arme const & arme) : 
      Item(arme.getNom().c_str(), arme.getPrix()),
      durabilite(arme.getDurabilite()),
      enchantement(new Enchantement(arme.getEnchantement()->getPuissance())) {}


   // Methodes constantes
   public: std::string     getNom()          const {return Item::getNom() + " [" + std::to_string(durabilite) + "]";}
   public: Enchantement *  getEnchantement() const {return enchantement;}
   public: int             getDurabilite()   const {return durabilite;}

   // Methodes non constantes
   public: void utiliser() {(durabilite) ? --durabilite : throw DestroyedItemException();}
   public: void enchanter(Enchantement * e) {enchantement = e;} 

   // Exceptions
   class DestroyedItemException : public std::exception {
      const char * what() const throw() {return "This item is destroyed";}
   };
};

#endif
#ifndef __HPP__ITEM__
#define __HPP__ITEM__

class Item {

   // Attributs
   private: std::string nom;
   private: bool        vendable;
   private: int         prix;
   
   // Constructeurs
   public:  Item(char const * nom) : nom(nom), vendable(false), prix(0) {}
   public:  Item(char const * nom, int prix) : nom(nom), vendable(false), prix(prix) {}

   // Methodes constantes
   public:  std::string getNom() const {return  std::string(nom);}
   public:  bool estVendable()   const {return prix > 0;}
   public:  int getPrix()        const {return prix;}

   // Methodes non constantes
};

#endif
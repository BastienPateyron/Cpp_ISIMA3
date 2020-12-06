#ifndef __HPP__ENCHANTEMENT__
#define __HPP__ENCHANTEMENT__
class Enchantement
{
   // Attributs
   private: float puissance;
   
   // Constructeurs
   public: Enchantement(float puissance) : puissance(puissance) {}

   // Methodes constantes
   public: float getPuissance() const {return puissance;}

   // Methodes non constantes

};

#endif
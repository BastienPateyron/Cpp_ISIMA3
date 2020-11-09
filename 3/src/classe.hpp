#ifndef __CPP3__CLASSE_HPP__
#define __CPP3__CLASSE_HPP__

class Classe {
   private:
      double borneInf;
      double borneSup;
      unsigned quantite;

   public:
      Classe(const double a, const double b) : borneInf(a), borneSup(b), quantite(0){}
      double getBorneInf() const {return borneInf;}
      double getBorneSup() const {return borneSup;}
      unsigned getQuantite() const {return quantite;}

      void setBorneInf(const double val) {borneInf = val;}
      void setBorneSup(const double val) {borneSup = val;}
      void setQuantite(const unsigned val) {quantite = val;}
      void ajouter() {quantite++;}

};

#endif

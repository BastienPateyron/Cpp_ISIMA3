#ifndef __CPP3__VALEUR_HPP__
#define __CPP3__VALEUR_HPP__

class Valeur {
   private:
      double a;

   public:
      Valeur(double a = 0) : a(a) {}
      double getNombre() const {return a;}
      void setNombre(double a) { this->a = a;}

};

#endif
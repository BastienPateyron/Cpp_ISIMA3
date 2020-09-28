#ifndef __CPP1__POLAIRE_HPP__
#define __CPP1__POLAIRE_HPP__

// #include "point.hpp"
#include <iostream>

class Polaire // : public Point
{
   // Attributs //
   private:
      double a;   // Angle
      double d;   // Distance

   public:

   
   // Methodes //
   public:
      Polaire();
      Polaire(double a, double d);
      // Forme();
      // Forme(double w, double h);
      // Forme(Point p, COULEURS c);
      // Forme(double w, double h, Point p);
      // Forme(double w, double h, double x, double y);
      
      
      // virtual ~Forme();

      // Methodes const
      double                 getAngle()      const;
      double                 getDistance()   const;
      void                   afficher(std::ostream & flux) const; // TODO: passer en std::stringstream
      // COULEURS            getCouleur() const;
      // double              getLargeur() const;
      // double              getHauteur() const;
      // virtual std::string toString()   const;

      // Methodes a effet de bord
      void setAngle(double a);
      void setDistance(double d);

      // Point & getPoint() ;
      // void    setCouleur(COULEURS c);
      // void    setX(double x);
      // void    setY(double y);
      
   // Elements statiques
   private:
      // static int nbFormes;

   public:
      // static int prochainId();
};

#endif
#ifndef __CPP1__CARTESIEN_HPP__
#define __CPP1__CARTESIEN_HPP__

class Cartesien {
   private:
      double x;
      double y;

   public:
      Cartesien();
      Cartesien(double x, double y);

      void getX() const;
      void getY() const;

};

#endif
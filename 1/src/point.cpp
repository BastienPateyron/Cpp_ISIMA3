#include "point.hpp"

Point::Point() {}
Point::~Point() {}

std::ostream & operator<<(std::ostream & flux, Point const & p) {
   return p.afficher(flux);
}
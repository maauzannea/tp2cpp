#include "point.hpp"

void Point::afficher(std::stringstream & ss) const {}

void Point::convertir(Cartesien& c) const {}

void Point::convertir(Polaire& p) const {}

void operator<<(std::stringstream & ss, const Point& p) {
	p.afficher(ss);
}

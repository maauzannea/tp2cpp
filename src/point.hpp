#pragma once
#include <sstream>

const double PI = 3.14159265359;

class Cartesien;
class Polaire;

class Point {
	public:
		virtual void afficher(std::stringstream&) const;
		virtual void convertir(Cartesien&) const;
		virtual void convertir(Polaire&) const;
};

void operator<<(std::stringstream&, const Point&);

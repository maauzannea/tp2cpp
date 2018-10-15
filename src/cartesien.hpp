#pragma once

#include "point.hpp"

class Cartesien : public Point {
	private:
		double x;
		double y;
	public:
		Cartesien();
		Cartesien(double,double);
		Cartesien(const Polaire&);
		~Cartesien();
		double getX() const;
		double getY() const;
		void setX(double);
		void setY(double);
		virtual void afficher(std::stringstream&) const;
		virtual void convertir(Cartesien&) const;
		virtual void convertir(Polaire&) const;
};

void operator<<(std::stringstream&, const Cartesien&);

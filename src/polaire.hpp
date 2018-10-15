#pragma once

#include "point.hpp"

class Polaire : public Point {
	private:
		double angle;
		double distance;
		
	public:
		Polaire();
		Polaire(double, double);
		Polaire(const Cartesien&);
		~Polaire();
		double getAngle() const;
		double getDistance() const;
		void setAngle(double);
		void setDistance(double);
		virtual void afficher(std::stringstream&) const;
		virtual void convertir(Cartesien&) const;
		virtual void convertir(Polaire&) const;
};

void operator<<(std::stringstream&, const Polaire&);

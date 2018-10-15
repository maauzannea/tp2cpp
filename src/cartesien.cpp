#include "cartesien.hpp"
#include "polaire.hpp"
#include <iostream>
#include <cmath>

Cartesien::Cartesien() : x(0.0), y(0.0) {}

Cartesien::Cartesien(double pX, double pY) : x(pX), y(pY) {}

Cartesien::Cartesien(const Polaire &p) {
	x = p.getDistance() * cos(PI * p.getAngle() / 180.0);
	y = p.getDistance() * sin(PI * p.getAngle() / 180.0);
}

Cartesien::~Cartesien() {}

double Cartesien::getX() const {
	return x;
}

double Cartesien::getY() const {
	return y;
}

void Cartesien::setX(double pX) {
	x = pX;
}

void Cartesien::setY(double pY) {
	y = pY;
}

void Cartesien::afficher(std::stringstream &ss) const {
	ss << "(x=" << x << ";y=" << y << ")";
}

void Cartesien::convertir(Cartesien &c) const {
	c.setX(x);
	c.setY(y);
}

void Cartesien::convertir(Polaire &p) const { 
	double dist = sqrt(pow(x,2) + pow(y,2));
	double angle = 180.0 * acos(x/dist) / PI;
	p.setDistance(dist);
	p.setAngle(angle);
}

void operator<<(std::stringstream &ss, const Cartesien &p) {
	p.afficher(ss);
}

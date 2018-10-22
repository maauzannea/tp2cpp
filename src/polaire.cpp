#include "polaire.hpp"
#include "cartesien.hpp"
#include <iostream>
#include <cmath>

Polaire::Polaire() : angle(0.0), distance(0.0) {}

Polaire::Polaire(double pAngle, double pDistance) : angle(pAngle), distance(pDistance) {}

Polaire::Polaire(const Cartesien &c) {
	if ((distance = sqrt(pow(c.getX(),2) + pow(c.getY(),2))) != 0) {
		angle = 180.0 * acos(c.getX()/distance) / PI;
	} else {
		angle = 0.0;
	}
}

Polaire::~Polaire() {}

double Polaire::getAngle() const {
	return angle;
}

double Polaire::getDistance() const {
	return distance;
}

void Polaire::setAngle(double pAngle) {
	angle = pAngle;
}

void Polaire::setDistance(double pDistance) {
	distance = pDistance;
}

void Polaire::afficher(std::stringstream &ss) const {
	ss << "(a=" << angle << ";d=" << distance << ")";
}

void Polaire::convertir(Cartesien &c) const {
	c.setX(distance * cos(PI * angle / 180.0));
	c.setY(distance * sin(PI * angle / 180.0));
}

void Polaire::convertir(Polaire &p) const {
	p.setAngle(angle);
	p.setDistance(distance);
}

void operator<<(std::stringstream &ss, const Polaire& p) {
	p.afficher(ss);
}

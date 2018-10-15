#pragma once

#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"
#include <vector>

template <typename T> class Nuage {
	private:
		std::vector<T> vectPoints;
	public:
		Nuage();
		~Nuage();
		void ajouter(T);
		size_t size() const;
		typedef typename std::vector<T>::const_iterator const_iterator;
		const_iterator begin() const;
		const_iterator end() const;
};

template <typename T>
Nuage<T>::Nuage() {}

template <typename T>
Nuage<T>::~Nuage() {}

template <typename T>
void Nuage<T>::ajouter(T p) {
	vectPoints.push_back(p);
}

template <typename T>
size_t Nuage<T>::size() const {
	return vectPoints.size();
}

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::begin() const {
	return vectPoints.begin();
}

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::end() const {
	return vectPoints.end();
}

template <typename T>
T barycentre_v1(Nuage<T> &n) {
	T bary;
	Cartesien buf;
	double xSum = 0.0;
	double ySum = 0.0;
	typename Nuage<T>::const_iterator it = n.begin();
	while(it != n.end()) {
		(*it).convertir(buf);
		xSum += buf.getX();
		ySum += buf.getY();
		++it;
	}
	if (n.size() != 0) {
		buf.setX(xSum/n.size());
		buf.setY(ySum/n.size());
	} else {
		buf.setX(0.0);
		buf.setY(0.0);
	}
	buf.convertir(bary);
	return bary;
}

template <>
Polaire barycentre_v1<Polaire>(Nuage<Polaire> &n) {
	Polaire bary;
	double xSum = 0.0;
	double ySum = 0.0;
	typename Nuage<Polaire>::const_iterator it = n.begin();
	while(it != n.end()) {
		xSum += (*it).getAngle();
		ySum += (*it).getDistance();
		++it;
	}
	if (n.size() != 0) {
		bary.setAngle(xSum/n.size());
		bary.setDistance(ySum/n.size());
	} else {
		bary.setAngle(0.0);
		bary.setDistance(0.0);
	}
	return bary;
}

template <typename T, typename C>
T barycentre_v2(C &n) {
	T bary;
	Cartesien buf;
	double xSum = 0.0;
	double ySum = 0.0;
	typename C::const_iterator it = n.begin();
	while(it != n.end()) {
		(*it).convertir(buf);
		xSum += buf.getX();
		ySum += buf.getY();
		++it;
	}
	if (n.size() != 0) {
		buf.setX(xSum/n.size());
		buf.setY(ySum/n.size());
	} else {
		buf.setX(0.0);
		buf.setY(0.0);
	}
	buf.convertir(bary);
	return bary;
}

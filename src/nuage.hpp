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

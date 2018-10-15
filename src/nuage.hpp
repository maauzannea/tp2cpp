#pragma once

#include "point.hpp"
#include <vector>

template <typename T> class Nuage {
	private:
		std::vector<T*> vectPoints;
	public:
		Nuage();
		~Nuage();
		void ajouter(T&);
		size_t size() const;
		typedef std::vector<T*>::const_iterator const_iterator;
		const_iterator begin() const;
		const_iterator end() const;
};

template <typename T>
Nuage::Nuage() {}

template <typename T>
Nuage::~Nuage() {}

template <typename T>
void Nuage::ajouter(T &p) {
	
}

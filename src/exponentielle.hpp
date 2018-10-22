#pragma once

#include "puissance.hpp"
#include "factorielle.hpp"

template <int N> class Exponentielle {
	public:
		static double valeur(const double x) {
			return (Puissance<N>::valeur(x)/Factorielle<N>::valeur) 
				 + Exponentielle<N-1>::valeur(x);
		}
};

template <> class Exponentielle<0> {
	public:
		static double valeur(const double x) {
			return 1.0;
		}
};


#pragma once

#include "puissance.hpp"
#include "factorielle.hpp"

template <int N> class Cosinus {
	public:
		static double valeur(const double x) {
			return (Puissance<N>::valeur(-1.0)*Puissance<2*N>::valeur(x)/Factorielle<2*N>::valeur)
				  + Cosinus<N-1>::valeur(x);
		}
};

template <> class Cosinus<0> {
	public:
		static double valeur(const double x) {
			return 1.0;
		}
};

template <int N> class Sinus {
	public:
		static double valeur(const double x) {
			return (Puissance<N>::valeur(-1.0)*Puissance<2*N+1>::valeur(x)/Factorielle<2*N+1>::valeur)
				  + Sinus<N-1>::valeur(x);
		}
};

template <> class Sinus<0> {
	public:
		static double valeur(const double x) {
			return x;
		}
};

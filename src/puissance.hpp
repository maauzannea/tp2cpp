#pragma once

template <int N> class Puissance {
	public:
		static const double valeur(const double p) {
			return p * Puissance<N-1>::valeur(p);
		}
};

template <> class Puissance<0> {
	public:
		static const double valeur(const double p) {
			return 1.0;
		}
};

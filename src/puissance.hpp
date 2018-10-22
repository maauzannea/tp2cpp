#pragma once

template <int N> class Puissance {
	public:
		static const int valeur(const int p) {
			return p * Puissance<N-1>::valeur(p);
		}
};

template <> class Puissance<0> {
	public:
		static const int valeur(const int p) {
			return 1;
		}
};

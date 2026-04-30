/* controllo se un vettore è ordinato o no */

#pragma once
#include <vector>

template<typename T>
bool is_sorted(const std::vector<T>& vec)
{
	/* se vec lungo 1 o vuoto è già ordinato */
	if (vec.size()<=1) {
		return true;
	}
	
	/* se ogni componente successiva è minore di quella precedente allora non è ordinato */
	for(size_t i=1; i<vec.size(); i+=1) {
		if (vec[i]<vec[i-1]) {
			return false;
		}
	}
	return true;
}
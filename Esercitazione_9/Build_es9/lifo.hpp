#pragma once
#include <list>

class lifo {
private:
	std::list<int> data;
public:
	/* Costruttore di default */
	lifo()=default;
	
	/* Metodo put() (push): inserisco un elemento nel contenitore */
	void put(int x) {
		data.push_back(x);
	}
	
	/* Metodo get() (pop): rimuovo un elemento dal contenitore */
	int get() {
		int value=data.back();
		data.pop_back();
		return value;
	}
	
	/* Metodo empty(): determino se il contenitore è vuoto */
	bool empty() const {
		return data.empty();
	}
};
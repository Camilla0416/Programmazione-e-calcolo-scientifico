#pragma once
#include <list>

class fifo {
private:
	std::list<int> data;
public:
	/* Costruttore di default */
	fifo()=default;
	
	/* Metodo put() (Enqueue): inserisco un elemento nel contenitore */
	void put(int x) {
		data.push_back(x);
	}
	
	/* Metodo get() (Dequeue): rimuovo un elemento dal contenitore */
	int get() {
		int value=data.front();
		data.pop_front();
		return value;
	}
	
	/* Metodo empty(): determino se il contenitore è vuoto */
	bool empty() const {
		return data.empty();
	}
};
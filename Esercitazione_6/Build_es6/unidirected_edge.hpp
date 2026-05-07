#pragma once
#include <algorithm>
#include <iostream>

/* Arco non diretto tra 2 nodi */
class unidirected_edge {
private:
	int m_from;
	int m_to;
public:
	/* Costruttore user-defined */
	unidirected_edge(int a, int b) {
		/* from <= to */
		if (a<b) {
			m_from=a;
			m_to=b;
		} else {
			m_from=b;
			m_to=a;
		}
	}
	
	int from() const{ return m_from; }
	int to() const{ return m_to; }

	/* Operatore < per ordinare gli archi */
	bool operator<(const unidirected_edge& other) const {
		if (m_from<other.m_from) {
			return true;
		}
		if (m_from>other.m_from) {
			return false;
		}
		return m_to<other.m_to;
	}

	/* Operatore == */
	bool operator==(const unidirected_edge& other) const {
		if (m_from!=other.m_from) {
			return false;
		}
		if (m_to!=other.m_to) {
			return false;
		}
		return true;
	}
};

/* Operatore <<: implementazione dell'output */
inline std::ostream& operator<<(std::ostream& os, const unidirected_edge& e) {
	return os << "(" << e.from() << "," << e.to() << ")";
}
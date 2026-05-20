#pragma once
#include fstream /* per metodo write_dot() */
#include <set> /* no duplicati, ordine mantenuto (edge_number()), ricerca efficiente */
#include <unordered_map>
#include "unidirected_edge.hpp"

class unidirected_graph {
private:
	std::set<unidirected_edge> edges; /* archi: (1,2),(2,3)... */
	std::set<int> nodes; /* nodi: 1,2,3... */
	std::unordered_map<int,std::set<int>> adj; /* associazione nodi-vicini: adj[1]={2,3} (1->{2,3}),adj[2]={1} (2->{1})... */
public:
	/* Costruttore di default */
	unidirected_graph()=default;
	
	/* Costruttore di copia */
	unidirected_graph(const unidirected_graph& other)=default;
	
	/* metodo neighbours(): restituisco i vicini di un nodo */
	std::set<int> neighbours(int node) const {
		std::set<int> neighs; /* insieme dei vicini */
		for (const auto& e:edges) { /* controllo un arco alla volta */
			/* se nodo cercato è from() allora il vicino è to() */
			if (e.from()==node) {
				neighs.insert(e.to());
			}
			/* grafo non diretto */
			if (e.to()==node) {
				neighs.insert(e.from());
			}
		}
		return neighs;
	}
	
	/* metodo add_edge(): aggiungo un arco al grafo */
	void add_edge(int a,int b) {
		unidirected_edge e(a,b);
		if (edges.find(e)==edges.end()) { 
			edges.insert(e); /* se non trovo l'arco lo inserisco */
			adj[a].insert(b);
			adj[b].insert(a);
			nodes.insert(a);
			nodes.insert(b);
		}
	}
	
	/* metodo add_node() non implementato perché nodi creati automaticamente quando aggiungo archi */
	
	/* metodo all_edges(): restituisco tutti gli archi */
	std::set<unidirected_edge> all_edges() const {
		return edges;
	}

	/* metodo all_nodes(): restituisco tutti i nodi */
	std::set<int> all_nodes() const {
		return nodes;
	}
	
	/* metodo edge_number(): restituisco il numero dell'arco nel grafo */
	int edge_number(const unidirected_edge& edge) const {
		int i=0;
		for (auto e:edges) {
			if (e==edge)
				return i;
			i=i+1;
		}
		return -1; /* arco assente */
	}
	
	/* metodo edge_at(): dato un numero d'arco restituisco il corrispondente oggetto arco nel grafo --> opposto di edge_number() */
	unidirected_edge edge_at(int index) const {
		int i=0;
		for (auto e:edges) {
			if (i==index)
				return e;
			i=i+1;
		}
		return unidirected_edge(-1,-1); /* indice assente */
	}

    /* Differenza tra grafi=archi presenti nel primo e non presenti nel secondo */
    unidirected_graph operator-(const unidirected_graph& other) const {
        unidirected_graph difference;
        for (auto e:edges) {
			bool found=false;
			for(auto other_edge:other.edges) {
				if (e==other_edge) {
					found=true;
				}
			}
            if (!found) {
				difference.add_edge(e.from(),e.to()); /* se non trovo l'arco lo aggiungo */
            }
        }
        return difference;
    }
};

/* per disegnare il grafo */
void write_dot(const unidirected_graph& g, const std::string& filename)
{
    std::ofstream file(filename);
    file << "graph G {\n";
    for (auto e:g.all_edges()) {
        file << "    " << e.from() << " -- " << e.to() << ";\n";
	}
    file << "}\n";
}
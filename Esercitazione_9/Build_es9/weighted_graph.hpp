#pragma once
#include <set>
#include <unordered_map>

class weighted_graph {
private:
    std::set<int> nodes; /* nodi: 1,2,3... */
    std::unordered_map<int,std::set<std::pair<int,double>>> adj; /* associazione nodi-vicini: adj[1]={(2,4.0),(3,1.0)} (1->{2 peso 4.0; 3 peso 1.0})... */
public:
	/* Costruttore di default */
    weighted_graph()=default;
	
	/* metodo neighbours(): restituisco i vicini di un nodo */
    std::set<std::pair<int,double>>
    neighbours(int node) const {
        auto it=adj.find(node);
        if (it==adj.end()) {
            return {};
        }
        return (*it).second;
    }
	
	/* metodo add_edge(): aggiungo un arco pesato al grafo */
    void add_edge(int a,int b,double w) {
        adj[a].insert({b,w});
        adj[b].insert({a,w});
        nodes.insert(a);
        nodes.insert(b);
    }
	
	/* metodo all_nodes(): restituisco tutti i nodi */
    std::set<int> all_nodes() const {
        return nodes;
    }
};
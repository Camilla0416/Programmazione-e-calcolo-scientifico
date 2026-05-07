#include <iostream>
#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"

int main() {
    unidirected_graph G;
    G.add_edge(1,2);
    G.add_edge(2,3);
    G.add_edge(3,4);
    G.add_edge(1,3);

    std::cout << "Archi: ";
    for (const auto& e:G.all_edges()) {
        std::cout << e << " ";
    }
	std::cout << "\n";
	
    std::cout << "Nodi: ";
    for (int n:G.all_nodes()) {
        std::cout << n << " ";
    }
	std::cout << "\n";

    std::cout << "Vicini di 2: ";
    for (int n:G.neighbours(2)) {
        std::cout << n << " ";
    }
	std::cout << "\n";

    std::cout << "Indice arco (1,3): ";
    std::cout << G.edge_number(unidirected_edge(1,3)) << " ";
	std::cout << "\n";

    std::cout << "Arco in posizione 1: ";
    std::cout << G.edge_at(1) << " ";
	std::cout << "\n";

    /* Test differenza grafi */
    unidirected_graph G2;
    G2.add_edge(1,2);
    unidirected_graph difference=G-G2;
    std::cout << "Differenza G-G2: ";
    for (const auto& e:difference.all_edges()) {
        std::cout << e << " ";
    }
	std::cout << "\n";
	
	/* Test costruttore di copia */
	unidirected_graph copy_graph(G);
    std::cout << "Copia di G: ";
    for (auto e:copy_graph.all_edges()) {
        std::cout << e << " ";
    }
	std::cout << "\n";
	
    return 0;
}
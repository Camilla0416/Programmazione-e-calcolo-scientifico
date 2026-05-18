#pragma once
#include <set>
#include "unidirected_graph.hpp"

template<typename Container>
unidirected_graph graph_visit(const unidirected_graph& graph, int source, Container& container)
{
	unidirected_graph tree;
	/* nodi già processati */
	std::set<int> reached;
    /* nodi già inseriti */
    std::set<int> discovered;
	container.put(source);
	discovered.insert(source);
	while(!container.empty()) {
		int u=container.get();
		/* già visitato? */
		if (reached.find(u)!=reached.end()) {
            continue;
        }
        reached.insert(u);
		auto neighs=graph.neighbours(u);
		for(int w:neighs) {
            /* MAI scoperto? */
            if (discovered.find(w)==discovered.end()) {
                discovered.insert(w);
                tree.add_edge(u,w);
                container.put(w);
            }
        }
    }
    return tree;
}
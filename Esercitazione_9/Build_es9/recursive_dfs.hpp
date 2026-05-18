#pragma once
#include <set>
#include "unidirected_graph.hpp"

void recursive_dfs_visit(const unidirected_graph& graph, int current, std::set<int>& reached, unidirected_graph& tree) {
	/* reached[current]=true */
    reached.insert(current);
    /* foreach(w in LA[current]) */
    auto neighs=graph.neighbours(current);
    for (int w:neighs) {
        /* non visitato? */
        if (reached.find(w)==reached.end()) {
            /* arco dell'albero DFS */
            tree.add_edge(current,w);
            /* chiamata ricorsiva */
            recursive_dfs_visit(graph, w, reached, tree);
        }
    }
}

/* funzione principale */
unidirected_graph recursive_dfs(const unidirected_graph& graph, int source) {
    unidirected_graph tree;
    std::set<int> reached;
    recursive_dfs_visit(graph, source, reached, tree);
    return tree;
}
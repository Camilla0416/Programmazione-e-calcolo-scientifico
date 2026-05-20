#pragma once
#include <set>
#include <unordered_map>
#include <limits> /* per +inf */
#include "unidirected_graph.hpp"

/* risultato finale */
struct dijkstra_result {
    std::unordered_map<int,int> dist; /* distanza */
	std::unordered_map<int,int> pred; /* predecessori */
};

dijkstra_result dijkstra(const unidirected_graph& graph, int source) {
    dijkstra_result result;
    /* Inizializzo i nodi */
    for (int node:graph.all_nodes()) {
        result.dist[node]=std::numeric_limits<int>::max(); /* dist[i]=+inf */
		result.pred[node]=-1; /* pred[i]=-1 */
    }
    result.dist[source]=0; /* sorgente */
	result.pred[source]=source;
	/* set ordinato: (distanza,nodo) */
	std::set<std::pair<int,int>> pq;
	pq.insert({0,source}); /* PQ.Enqueue() */
    while (!pq.empty()) {
        /* PQ.Dequeue() */
		auto current=*pq.begin(); /* nodo con distanza minima */
		pq.erase(pq.begin());
		int dist_u=current.first;
        int u=current.second;
		for (int v:graph.neighbours(u)) {
            int new_dist=result.dist[u]+1;
            if (new_dist<result.dist[v]) {
				/* se il nodo è gia nella coda, rimuovo la vecchua dist */
				if (result.dist[v] != std::numeric_limits<int>::max()) {
					pq.erase({result.dist[v],v}); /* Decreasekey */
				}
				result.dist[v]=new_dist;
				result.pred[v]=u;
				/* DecreaseKey: reinserisco il nodo con nuova priorità */
				pq.insert({new_dist,v});
            }
        }
    }
    return result;
}
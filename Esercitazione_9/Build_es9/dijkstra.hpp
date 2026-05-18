#pragma once
#include <queue>
#include <limits> /* per inf */
#include "weighted_graph.hpp"

/* nodo della priority queue */
struct pq_node { /* (nodo, distanza_corrente) */
    int node;
    double distance;
	/* voglio distanza minima */
    bool operator<(const pq_node& other) const {
        return distance>other.distance;
    }
};

/* risultato finale */
struct dijkstra_result {
    std::unordered_map<int,int> pred; /* predecessori */
    std::unordered_map<int,double> dist; /* distanze minime */
};

dijkstra_result dijkstra(const weighted_graph& graph, int source) {
    dijkstra_result result;
    /* Inizializzo i nodi */
    for (int node:graph.all_nodes()) {
        result.pred[node]=-1; /* pred[i]=-1 (non conosco ancora) */
        result.dist[node]=std::numeric_limits<double>::infinity(); /* dist[i]=inf (non conosco ancora) */
    }
    result.dist[source]=0; /* sorgente */
    std::priority_queue<pq_node> pq; /* min priority queue */
    pq.push({source,0}); /* PQ.Enqueue() */
    while (!pq.empty()) {
        pq_node current=pq.top(); /* PQ.Dequeue() --> min nodo */
        pq.pop(); /* PQ.Dequeue() */
        int u=current.node;
        double d=current.distance;
        if (d>result.dist[u]) { /* sostituisce DecreaseKey */
            continue;
        }
        /* espoloro i vicini: foreach(v in Adj[u]) */
        auto neighs=graph.neighbours(u);
        for (auto neigh:neighs) {
            int v=neigh.first; /* vicino */
            double weight=neigh.second; /* peso arco */
            if (result.dist[v]>result.dist[u]+weight) {
				result.dist[v]=result.dist[u]+weight;
                result.pred[v]=u;
                /* DecreaseKey: reinserisco il nodo con nuova priorità */
                pq.push({v,result.dist[v]});
            }
        }
    }
    return result;
}
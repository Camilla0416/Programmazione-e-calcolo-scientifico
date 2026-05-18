#include "unidirected_graph.hpp"
#include "fifo.hpp"
#include "lifo.hpp"
#include "graph_visit.hpp"

int main()
{
	unidirected_graph G;
	G.add_edge(1,2);
	G.add_edge(1,3);
	G.add_edge(1,4);
	G.add_edge(1,6);
	G.add_edge(2,4);
	G.add_edge(2,5);
	G.add_edge(2,7);
	G.add_edge(3,6);
    G.add_edge(4,6);
	G.add_edge(4,7);
	G.add_edge(5,7);
	G.add_edge(6,7);
	G.add_edge(6,8);
	G.add_edge(7,9);
	G.add_edge(8,9);
	
	/* Visita in profondità di G: DFS */
	lifo s;
	auto dfsG=graph_visit(G,1,s); /* risultato in dfsG */
	
	/* Visita in ampiezza di G: BFS */
	fifo q;
	auto bfsG=graph_visit(G,1,q); /* risultato in bfsG */
    
    G.write_dot("graph.dot"); /* grafico originale */
    bfsG.write_dot("bfs.dot"); /* grafico bfs */
    dfsG.write_dot("dfs.dot"); /* grafico dfs */
}
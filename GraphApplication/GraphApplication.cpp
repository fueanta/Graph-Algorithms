#include <iostream>

#include "Graph.h"
#include "BFS.h"
#include "DFS.h"
#include "MST.h"

using namespace std;

void bfs_demonstration();
void dfs_demonstration();
void prims_demonstration();
void kurskals_demonstration();

int main(void)
{
	bfs_demonstration();
	dfs_demonstration();
	prims_demonstration();
    kurskals_demonstration();

	getchar();
	return 0;
}

void bfs_demonstration()
{
	Graph g(9, Nature::DIR);
	g.add_edge('a', 'b');
	g.add_edge('a', 'd');
	g.add_edge('b', 'c');
	g.add_edge('d', 'b');
	g.add_edge('b', 'e');
	g.add_edge('e', 'c');
	g.add_edge('d', 'e');
	g.add_edge('f', 'd');
	g.add_edge('g', 'f');
	g.add_edge('e', 'g');
	g.add_edge('e', 'i');
	g.add_edge('f', 'h');
	g.add_edge('h', 'g');
	g.add_edge('g', 'i');
	g.add_edge('i', 'h');

	g.display_graph();

	BFS bfs_obj(&g, 'a');

	bfs_obj.print_bfs_queue(Representation::CHAR);

	// bfs_obj.print_bfs_queue(INT);

	cout << "\nCost of a to h: " << bfs_obj.get_cost('a', 'h') << endl;
	cout << "\nPath from a to h: ";
	bfs_obj.print_path('a', 'h', Representation::CHAR);
	cout << "\nPath from a to i: ";
	bfs_obj.print_path('a', 'i', Representation::CHAR);

	cout << "\nRemoving edges e->i and g->i....\n";

	g.remove_edge('e', 'i');
	g.remove_edge('g', 'i');

	bfs_obj.modify_details(&g, 'a');

	g.display_graph();

	bfs_obj.print_bfs_queue(Representation::CHAR);

	cout << "\nCost of a to h: " << bfs_obj.get_cost('a', 'h') << endl;
	cout << "\nPath from a to h: ";
	bfs_obj.print_path('a', 'h', Representation::CHAR);
	cout << "\nPath from a to i: ";
	bfs_obj.print_path('a', 'i', Representation::CHAR);
}

void dfs_demonstration()
{
	Graph g(8, Nature::DIR);
	g.add_edge(1, 2);
	g.add_edge(1, 7);
	g.add_edge(2, 8);
	g.add_edge(2, 3);
	g.add_edge(2, 4);
	g.add_edge(3, 4);
	g.add_edge(3, 5);
	g.add_edge(4, 6);

	g.display_graph();

	DFS obj(&g);
	obj.print_dfs_outcomes();
	obj.print_topological_order();
}

void prims_demonstration()
{
	cout << "\nSpanning Tree : Prims''\n";

	Graph g(8, Nature::UN_DIR);
	g.add_edge(1, 5, 2);
	g.add_edge(1, 2, 4);
	g.add_edge(1, 4, 10);
	g.add_edge(2, 4, 8);
	g.add_edge(2, 3, 18);
	g.add_edge(3, 4, 11);
	g.add_edge(4, 5, 5);
	g.add_edge(4, 7, 11);
	g.add_edge(6, 7, 1);
	g.add_edge(6, 8, 2);
	g.add_edge(4, 8, 9);

	MST mst_obj(&g);
	mst_obj.do_prims();
	mst_obj.print_mst();

	Graph g2(5, Nature::UN_DIR);

	g2.add_edge('a', 'b', 7);
	g2.add_edge('a', 'c', 4);
	g2.add_edge('a', 'd', 1);
	g2.add_edge('c', 'd', 3);
	g2.add_edge('b', 'd', 8);
	g2.add_edge('b', 'e', 6);
	g2.add_edge('d', 'e', 6);

	mst_obj.modify_graph(&g2);
	mst_obj.do_prims();
	mst_obj.print_mst();
}

void kurskals_demonstration()
{
	cout << "\nSpanning Tree : Kruskals'\n";

	Graph g(8, Nature::UN_DIR);
	g.add_edge(1, 5, 2);
	g.add_edge(1, 2, 4);
	g.add_edge(1, 4, 10);
	g.add_edge(2, 4, 8);
	g.add_edge(2, 3, 18);
	g.add_edge(3, 4, 11);
	g.add_edge(4, 5, 5);
	g.add_edge(4, 7, 11);
	g.add_edge(6, 7, 1);
	g.add_edge(6, 8, 2);
	g.add_edge(4, 8, 9);

	MST mst_obj(&g);
	mst_obj.do_kruskals();
	mst_obj.print_mst();

	Graph g2(5, Nature::UN_DIR);

	g2.add_edge('a', 'b', 7);
	g2.add_edge('a', 'c', 4);
	g2.add_edge('a', 'd', 1);
	g2.add_edge('c', 'd', 3);
	g2.add_edge('b', 'd', 8);
	g2.add_edge('b', 'e', 6);
	g2.add_edge('d', 'e', 6);

	mst_obj.modify_graph(&g2);
	mst_obj.do_kruskals();
	mst_obj.print_mst();
}
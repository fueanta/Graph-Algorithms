#pragma once

#include "Graph.h"

struct Edge  // edge for prims
{
	int node_1;
	int node_2;
	int _cost;
};

struct Edge_CMP  // returns edge with lowest cost
{
	bool operator()(const Edge* left, const Edge* right) const
	{
		return left->_cost > right->_cost;
	}
};

class MST
{
	Graph* _main_graph;
	Graph* _spanning_tree;

	State* _states; // required only for prims

	int _edge_count;
	int _minimum_cost;

	void init();
public:
	MST(Graph*);
	~MST();

	void modify_graph(Graph*);
	void do_prims();
	void do_kruskals();
	void print_mst();
};
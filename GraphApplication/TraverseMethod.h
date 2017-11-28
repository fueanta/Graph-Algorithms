#pragma once

#include "Graph.h"

struct Topo_Node // node for topological order
{
	int _node;
	int _ending_time;
};

struct node_cmp // compares topo_nodes
{
	bool operator()(const Topo_Node* a, const Topo_Node* b) const
	{
		return a->_ending_time < b->_ending_time;
	}
};

class TraverseMethod
{
protected:
	Graph* _graph; // both

	int* _parents; // both
	State* _states; // both

	int _global_time = 0; // dfs-exclusive
	int* _starting_times; // dfs-exclusive
	int* _ending_times; // dfs-exclusive

	int _source; // bfs-exclusive
	int* _levels; // bfs-exclusive
public:
	TraverseMethod();
	~TraverseMethod();
};
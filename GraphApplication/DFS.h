#pragma once

#include "TraverseMethod.h"

class DFS : public TraverseMethod
{
	std::priority_queue<Topo_Node*, std::vector<Topo_Node*>, node_cmp>* topological_list;

	void set_graph(Graph*);

	void init();

	void do_dfs();
	void dfs_visit(int);
public:
	DFS(Graph*);
	~DFS();
	void modify_graph(Graph*);
	void print_dfs_outcomes();
	void print_topological_order();
};
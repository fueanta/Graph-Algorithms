#pragma once

#include "TraverseMethod.h"

class BFS : public TraverseMethod
{
	std::vector<int>* bfs_queue;

	void set_graph(Graph*);
	void set_source(int);
	void set_source(char);

	void init();
	void do_bfs();

	void find_path_int(int, int);
	void find_path_char(int, int);
public:
	BFS(Graph*, char);
	BFS(Graph*, int);
	~BFS();

	void modify_details(Graph*, int);
	void modify_details(Graph*, char);

	void print_bfs_queue(Representation);
	int get_cost(int, int);
	int get_cost(char, char);
	void print_path(int, int, Representation);
	void print_path(char, char, Representation);
};
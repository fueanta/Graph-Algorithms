#pragma once

#include <iostream>
#include <queue>
#include <vector>

#include "Disjoint_Set.h"

enum Nature { DIR = 1, UN_DIR = 0 };
enum State { UNDISCOVERED = 0, DISCOVERED = 1, PROCESSED = 2 };
enum Representation { INT = -1, CHAR = 1 };

class Graph
{
	int _vertex_count = 0;
	int **_adjacency_matrix;
	Nature _type;

	void matrix_init();
public:
	// Graph();
	Graph(int, Nature);
	~Graph();

	int get_vertex_count();
	Nature get_nature();

	void add_edge(int, int, int);
	bool has_edge_graph(int, int);
	int get_cost_graph(int, int);

	void add_edge(int, int);
	void remove_edge(int, int);
	bool has_edge(int, int);
	int get_cost(int, int);

	void add_edge(char, char);
	void add_edge(char, char, int);
	void remove_edge(char, char);
	bool has_edge(char, char);
	int get_cost(char, char);

	void display_graph();
};
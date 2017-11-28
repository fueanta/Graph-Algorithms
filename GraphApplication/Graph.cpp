#include "Graph.h"

void Graph::matrix_init()
{
	this->_adjacency_matrix = new int*[_vertex_count];
	for (int i = 0; i < _vertex_count; ++i)
	{
		_adjacency_matrix[i] = new int[_vertex_count] { 0 };
	}
}

bool Graph::has_edge_graph(int i, int j)
{
	if (i > -1 && i < _vertex_count && j > -1 && j < _vertex_count)
	{
		return (_adjacency_matrix[i][j] != 0);
	}
	else
	{
		std::cout << "\nOut of bound..!\n";
		return false;
	}
}

int Graph::get_cost_graph(int i, int j)
{
	return this->_adjacency_matrix[i][j];
}

/*
Graph::Graph()
{
}
*/

Graph::Graph(int n, Nature type)
{
	_vertex_count = n;
	this->_type = type;
	matrix_init();
}

Graph::~Graph()
{
	for (int i = 0; i < _vertex_count; ++i)
	{
		delete[] _adjacency_matrix[i];
	}
	delete[] _adjacency_matrix;

	std::cout << "\nGraph object has been deleted..!\n\n";
}

int Graph::get_vertex_count()
{
	return _vertex_count;
}

Nature Graph::get_nature()
{
	return this->_type;
}

void Graph::add_edge(int i, int j)
{
	this->add_edge(i, j, 1);
}

void Graph::add_edge(int i, int j, int cost)
{
	--i, --j;
	if (i > -1 && i < _vertex_count && j > -1 && j < _vertex_count)
	{
		_adjacency_matrix[i][j] = cost;
		if (this->_type == Nature::UN_DIR)
		{
			_adjacency_matrix[j][i] = cost;
		}
	}
	else
	{
		std::cout << "\nOut of bound..!\n";
	}
}

void Graph::remove_edge(int i, int j)
{
	this->add_edge(i, j, 0);
}

bool Graph::has_edge(int i, int j)
{
	return has_edge_graph(--i, --j);
}

int Graph::get_cost(int i, int j)
{
	--i, --j;
	if (i > -1 && i < _vertex_count && j > -1 && j < _vertex_count)
	{
		return this->_adjacency_matrix[i][j];
	}
	else
	{
		std::cout << "\nOut of bound..!\n";
		return 0;
	}
}

void Graph::add_edge(char i, char j)
{
	this->add_edge((int)i - 96, (int)j - 96, 1);
}

void Graph::add_edge(char i, char j, int cost)
{
	this->add_edge((int)i - 96, (int)j - 96, cost);
}

void Graph::remove_edge(char i, char j)
{
	this->add_edge((int)i - 96, (int)j - 96, 0);
}

bool Graph::has_edge(char i, char j)
{
	return this->has_edge((int)i - 96, (int)j - 96);
}

int Graph::get_cost(char i, char j)
{
	return this->get_cost(int(i) - 96, int(j) - 96);
}

void Graph::display_graph()
{
	std::cout << "\nDisplaying Adjacency Matrix:\n----------------------------\n    ";

	for (int i = 0; i < _vertex_count; ++i)
	{
		std::cout << (i + 1) << " ";
	}
	std::cout << std::endl << "   ";

	for (int i = 0; i < _vertex_count; ++i)
	{
		std::cout << "--";
	}
	std::cout << std::endl;

	for (int i = 0; i < _vertex_count; ++i)
	{
		std::cout << (i + 1) << " | ";
		for (int j = 0; j < _vertex_count; ++j)
		{
			std::cout << _adjacency_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
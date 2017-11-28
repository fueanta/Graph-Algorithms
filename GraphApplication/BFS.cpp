#include "BFS.h"

void BFS::init()
{
	_source = -1;

	delete[] _parents;
	delete[] _levels;
	delete[] _states;
	delete bfs_queue;

	_parents = new int[_graph->get_vertex_count()];
	for (int i = 0; i < _graph->get_vertex_count(); ++i)
	{
		_parents[i] = -1;
	}

	_levels = new int[_graph->get_vertex_count()]{ 0 };

	_states = new State[_graph->get_vertex_count()]
	{ State::UNDISCOVERED };

	bfs_queue = new std::vector<int>();
}

void BFS::do_bfs()
{
	if (_source > -1)
	{
		std::queue<int> local_queue;
		this->_states[_source] = State::DISCOVERED;
		this->_levels[_source] = 0;
		this->_parents[_source] = 0;

		local_queue.push(_source);
		int node = 0;

		while (!local_queue.empty())
		{
			node = local_queue.front();
			local_queue.pop();

			for (int i = 0; i < this->_graph->get_vertex_count(); ++i)
			{
				if ((this->_graph->has_edge_graph(node, i)) &&
					(_states[i] == State::UNDISCOVERED))
				{
					this->_states[i] = State::DISCOVERED;
					this->_levels[i] = this->_levels[node] + 1;
					this->_parents[i] = node;

					local_queue.push(i);
				}
			}
			this->_states[node] = State::PROCESSED;
			this->bfs_queue->push_back(node + 1);
		}
	}
	else
	{
		std::cout << "\nInvalid Source!\n";
	}
}

void BFS::find_path_int(int source, int destination)
{
	if (source == destination)
		std::cout << (source + 1) << " ";
	else if (_parents[destination] == -1)
		std::cout << "No Path here :(";
	else
	{
		BFS::find_path_int(source, _parents[destination]);
		std::cout << (destination + 1) << " ";
	}
}

void BFS::find_path_char(int source, int destination)
{
	if (source == destination)
		std::cout << char(source + 97) << " ";
	else if (_parents[destination] == -1)
		std::cout << "No Path here :(";
	else
	{
		BFS::find_path_char(source, _parents[destination]);
		std::cout << char(destination + 97) << " ";
	}
}

BFS::BFS(Graph* graph, char source)
{
	this->_graph = graph;
	this->set_source(source);
}

BFS::BFS(Graph* graph, int source)
{
	this->_graph = graph;
	this->set_source(source);
}

BFS::~BFS()
{
	delete[] _parents;
	delete[] _levels;
	delete[] _states;
	delete bfs_queue;

	std::cout << "\nBFS object has been deleted..!\n";
}

void BFS::set_graph(Graph* graph)
{
	this->_graph = graph;
	this->init();
}

void BFS::set_source(int source)
{
	this->init();
	this->_source = source - 1;
	this->do_bfs();
}

void BFS::set_source(char source)
{
	this->set_source(int(source - 96));
}

void BFS::modify_details(Graph* graph, int source)
{
	this->_graph = graph;
	this->set_source(source);
}

void BFS::modify_details(Graph* graph, char source)
{
	this->_graph = graph;
	this->set_source(source);
}

int BFS::get_cost(int source, int destination)
{
	if (source > -1 && source < _graph->get_vertex_count() &&
		destination > -1 && destination < _graph->get_vertex_count())
	{
		return _levels[destination - 1];
	}
	else
	{
		std::cout << "\nOut of bound!\n";
	}
}

int BFS::get_cost(char a, char b)
{
	return this->get_cost((int)a - 96, (int)b - 96);
}

void BFS::print_bfs_queue(Representation type)
{
	std::cout << "\nBFS Queue is: ";
	if (type == Representation::CHAR)
	{
		for (int i = 0; i < this->bfs_queue->size(); ++i)
		{
			std::cout << char(bfs_queue->at(i) + 96) << " ";

		}
	}
	else if (type == Representation::INT)
	{
		for (int i = 0; i < this->bfs_queue->size(); ++i)
		{
			std::cout << bfs_queue->at(i) << " ";

		}
	}
	std::cout << std::endl;
}

void BFS::print_path(int source, int destination, Representation type)
{
	--source, --destination;
	if (source > -1 && source < _graph->get_vertex_count() &&
		destination > -1 && destination < _graph->get_vertex_count())
	{
		if (type == Representation::CHAR)
		{
			this->find_path_char(source, destination);
		}
		else if (type == Representation::INT)
		{
			this->find_path_int(source, destination);
		}
	}
	else
	{
		std::cout << "\nOut of bound!\n";
	}
	std::cout << std::endl;
}

void BFS::print_path(char i, char j, Representation type)
{
	this->print_path((int(i) - 96), (int(j) - 96), type);
}
#include "DFS.h"

void DFS::set_graph(Graph* graph)
{
	this->_graph = graph;
	this->init();
	this->do_dfs();
}

void DFS::init()
{
	this->_global_time = 0;

	delete[] this->_parents;
	delete[] this->_starting_times;
	delete[] this->_ending_times;
	delete[] this->_states;
	delete this->topological_list;

	this->_parents = new int[this->_graph->get_vertex_count()];
	for (int i = 0; i < _graph->get_vertex_count(); ++i)
	{
		this->_parents[i] = -1;
	}

	this->_starting_times = new int[this->_graph->get_vertex_count()]{ 0 };
	this->_ending_times = new int[this->_graph->get_vertex_count()]{ 0 };

	this->_states = new State[this->_graph->get_vertex_count()]
	{ State::UNDISCOVERED };

	this->topological_list = new std::priority_queue<Topo_Node*,
		std::vector<Topo_Node*>, node_cmp>();
}

void DFS::do_dfs()
{
	for (int i = 0; i < this->_graph->get_vertex_count(); ++i)
	{
		if (this->_states[i] == State::UNDISCOVERED)
			this->dfs_visit(i);
	}
}

void DFS::dfs_visit(int node)
{
	Topo_Node* t_node = new Topo_Node(); t_node->_node = node + 1;

	this->_states[node] = State::DISCOVERED;
	this->_starting_times[node] = ++_global_time;

	for (int i = 0; i < this->_graph->get_vertex_count(); ++i)
	{
		if (this->_graph->has_edge_graph(node, i) &&
			this->_states[i] == State::UNDISCOVERED)
		{
			this->_parents[i] = node;
			this->dfs_visit(i);
		}
	}

	this->_states[node] = State::PROCESSED;

	t_node->_ending_time = this->_ending_times[node] = ++_global_time;
	this->topological_list->push(t_node);
}

DFS::DFS(Graph* graph)
{
	this->set_graph(graph);
}

DFS::~DFS()
{
	delete[] this->_parents;
	delete[] this->_starting_times;
	delete[] this->_ending_times;
	delete[] this->_states;
	delete this->topological_list;

	std::cout << "\nDFS object has been deleted..!\n";
}

void DFS::modify_graph(Graph* graph)
{
	this->set_graph(graph);
}

void DFS::print_dfs_outcomes()
{
	for (int i = 0; i < this->_graph->get_vertex_count(); ++i)
	{
		std::cout << "\n[ Node " << (i + 1) << ": Parent-> "
			<< (this->_parents[i] + 1) << ", Start Time: "
			<< this->_starting_times[i] << ", End Time: "
			<< this->_ending_times[i] << " ]" << std::endl;
	}
}

void DFS::print_topological_order()
{
	std::cout << "\nTopological Order: ";
	while (!this->topological_list->empty())
	{
		std::cout << this->topological_list->top()->_node << " ";
		this->topological_list->pop();
	}
	std::cout << std::endl;
}
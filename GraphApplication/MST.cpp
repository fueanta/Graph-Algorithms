#include "MST.h"

void MST::init()
{
	delete this->_spanning_tree;
	delete[] this->_states;

	this->_spanning_tree = new Graph(this->_main_graph->get_vertex_count(),
		this->_main_graph->get_nature());

	this->_states = new State[this->_main_graph->get_vertex_count()]
	{ State::UNDISCOVERED };

	this->_edge_count = 0;
	this->_minimum_cost = 0;
}

MST::MST(Graph* _graph)
{
	this->_main_graph = _graph;
}

MST::~MST()
{
	std::cout << "\nMST object has been deleted.\n";
	// delete this->_main_graph;
	delete this->_spanning_tree;
	delete[] this->_states;
}

void MST::modify_graph(Graph* _graph)
{
	this->_main_graph = _graph;
}

void MST::do_prims()
{
	init();

	std::priority_queue<Edge*, std::vector<Edge*>, Edge_CMP>* Q_edges
		= new std::priority_queue<Edge*, std::vector<Edge*>, Edge_CMP>();

	// taking the first node arbitrarily...
	int node = 0;
	this->_states[node] = State::DISCOVERED;
	for (int i = 1; i < this->_main_graph->get_vertex_count(); ++i)
	{
		if (this->_main_graph->has_edge_graph(node, i))
		{
			Edge* e = new Edge();
			e->node_1 = node;
			e->node_2 = i;
			e->_cost = this->_main_graph->get_cost_graph(node, i);
			Q_edges->push(e);
		}
	}
	this->_states[node] = State::PROCESSED;

	
	while (this->_edge_count != this->_main_graph->get_vertex_count() - 1)
	{
		Edge* e = Q_edges->top();
		Q_edges->pop();

		if (_states[e->node_2] == State::UNDISCOVERED)
		{
			this->_states[e->node_2] = State::DISCOVERED;

			for (int i = 0; i < this->_main_graph->get_vertex_count(); ++i)
			{
				if (this->_main_graph->has_edge_graph(e->node_2, i))
				{
					Edge* _e = new Edge();
					_e->node_1 = e->node_2;
					_e->node_2 = i;
					_e->_cost = this->_main_graph->get_cost_graph(e->node_2, i);
					Q_edges->push(_e);
				}
			}

			this->_spanning_tree->add_edge(e->node_1 + 1, e->node_2 + 1, e->_cost);
			this->_minimum_cost += e->_cost;
			this->_states[e->node_2] = State::PROCESSED;
			this->_edge_count++;
		}
	}
}

void MST::do_kruskals()
{
	init();

	std::priority_queue<Edge*, std::vector<Edge*>, Edge_CMP>* Q_edges
		= new std::priority_queue<Edge*, std::vector<Edge*>, Edge_CMP>();

	Disjoint_Set* D_nodes
		= new Disjoint_Set(this->_main_graph->get_vertex_count());

	for (int i = 0; i < this->_main_graph->get_vertex_count(); i++)
	{
		for (int j = i + 1; j < this->_main_graph->get_vertex_count(); j++)
		{
			if (this->_main_graph->has_edge_graph(i, j))
			{
				Edge* e = new Edge();
				e->node_1 = i;
				e->node_2 = j;
				e->_cost = this ->_main_graph->get_cost_graph(i, j);
				Q_edges->push(e);
			}
		}
	}

	while (_edge_count != this->_main_graph->get_vertex_count() - 1)
	{
		Edge* e = Q_edges->top();
		Q_edges->pop();

		if (!D_nodes->Is_In_Same_Set(e->node_1, e->node_2))
		{
			D_nodes->Union(e->node_1, e->node_2);
			this->_spanning_tree->add_edge(e->node_1 + 1, e->node_2 + 1, e->_cost);
			this->_minimum_cost += e->_cost;
			this->_edge_count++;
		}
	}
}

void MST::print_mst()
{
	std::cout << "\nMST:\n";
	this->_spanning_tree->display_graph();
	std::cout << "\nCost: " << this->_minimum_cost << "\n";
}
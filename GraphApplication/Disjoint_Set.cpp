#include "Disjoint_Set.h"

void Disjoint_Set::makeset(int node)
{
	this->_parent[node] = node;
}

void Disjoint_Set::init_disjoint_sets(int count)
{
	for (int i = 0; i < count; ++i)
	{
		this->makeset(i);
	}
}

Disjoint_Set::Disjoint_Set(int count)
{
	this->_parent = new int[count];
	this->init_disjoint_sets(count);
}

Disjoint_Set::~Disjoint_Set()
{
	delete[] this->_parent;
}

void Disjoint_Set::Union(int node_1, int node_2)
{
	int representative_1 = Find_Representative(node_1);
	int representative_2 = Find_Representative(node_2);

	if (representative_1 != representative_2)
		_parent[representative_2] = representative_1;
}

int Disjoint_Set::Find_Representative(int node)
{
	if (_parent[node] == node)
		return node;
	_parent[node] = Find_Representative(_parent[node]); // path compression
	return _parent[node];
}

bool Disjoint_Set::Is_In_Same_Set(int node_1, int node_2)
{
	int representative_1 = Find_Representative(node_1);
	int representative_2 = Find_Representative(node_2);

	return (representative_1 == representative_2);
}

void Disjoint_Set::Union(char node_1, char node_2)
{
	this->Union((int)node_1 - 97, (int)node_2 - 97);
}

int Disjoint_Set::Find_Representative(char node)
{
	return this->Find_Representative((int) node - 97);
}

bool Disjoint_Set::Is_In_Same_Set(char node_1, char node_2)
{
	return this->Is_In_Same_Set((int)node_1 - 97, (int)node_2 - 97);
}

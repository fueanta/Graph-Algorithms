#pragma once
class Disjoint_Set
{
	int* _parent;

	void makeset(int);
	void init_disjoint_sets(int);
public:
	Disjoint_Set(int);
	~Disjoint_Set();

	void Union(int, int);
	int Find_Representative(int);
	bool Is_In_Same_Set(int, int);

	void Union(char, char);
	int Find_Representative(char);
	bool Is_In_Same_Set(char, char);
};
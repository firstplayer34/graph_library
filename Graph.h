#pragma once
#include <vector>
#include <math.h>
class Graph
{
public:
	Graph(int** matrix, int size);
	Graph(std::vector<std::vector<int>>&list);

	~Graph();

	void PrintMatrix();
	void PrintList();

	int Size() { return this->size; }

	//Returns data as a matrix
	int** MatrixOfAdjacency() { return this->matrixOfAdjacency; }

	//Returns data as a vector
	std::vector<std::vector<int>> ListOfAdjacency() { return this->listOfAdjacency; }



private:
	int** matrixOfAdjacency;
	std::vector<std::vector<int>>listOfAdjacency;
	int size = 0;
};


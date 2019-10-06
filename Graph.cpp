#include "Graph.h"
#include <iostream>
#pragma warning(disable:4018)
Graph::Graph(int** matrix, int size)
{
	this->size = size;
	this->matrixOfAdjacency = new int* [size];
	for (int i = 0; i < this->size; i++) {
		this->matrixOfAdjacency[i] = new int[size];
		for (int j = 0; j < this->size; j++) {
			this->matrixOfAdjacency[i][j] = matrix[i][j];
		}
	}
	for (int i = 0; i < this->size; i++) {
		std::vector<int>temp;
		for (int j = 0; j < this -> size; j++) {
			if (this->matrixOfAdjacency[i][j] == 1)
				temp.push_back(j);
		}
		this->listOfAdjacency.push_back(temp);
	}
}

//In list must be ALL vertexes even if they are useless
Graph::Graph(std::vector<std::vector<int>> &list)
{
	this->size = list.size();
	this->matrixOfAdjacency = new int* [size];
	for (int i = 0; i < this->size; i++) {
		this->matrixOfAdjacency[i] = new int[size];
		for (int j = 0; j < this->size; j++) {
			this->matrixOfAdjacency[i][j] = 0;
		}
	}
	this->listOfAdjacency = list;
	for (int i = 0; i < this-> listOfAdjacency.size(); i++) {
		for (int j = 0; j < this->listOfAdjacency[i].size();i++) {
			int k = list[i][j];
			printf("%i ", k);
			this->matrixOfAdjacency[i][k] = true;
			this->matrixOfAdjacency[k][i] = true;
		}
		printf("\n");
	}
}

Graph::~Graph()
{
	for (int i = 0; i < this->size; i++) {
		delete this->matrixOfAdjacency[i];
	}
	delete this->matrixOfAdjacency;
	this->size = 0;
}

void Graph::PrintMatrix()
{
	for (size_t i = 0; i < this->size; i++) {
		for (size_t j = 0; j < this->size; j++) {
			printf("%i ",this->matrixOfAdjacency[i][j]);
		}
		printf("\n");
	}
}

void Graph::PrintList()
{
	for (size_t i = 0; i < this->listOfAdjacency.size(); i++) {
		printf("%i:", i);
		for (size_t j = 0; j < this->listOfAdjacency[i].size(); j++)
			printf(" %i", this->listOfAdjacency[i][j]);
		printf("\n");
	}
}

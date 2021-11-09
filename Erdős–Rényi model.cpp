// Erdős–Rényi model.cpp
//created by ErfanHephaestus on GitHub

#include <iostream>
#include<cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

typedef unsigned short int ushort;	//defining new name for type
const ushort N = 100;	// Number of nodes in the network
const float P = 0.25;	// probability
void erdosRenyi(ushort** const adjmat);	//This function creates Erdős–Rényi graph

int main()
{
	srand(time(0));	//seeding random number generator

	//creating 2D array on the heap
    ushort** adjacencyMatrix = NULL;
    adjacencyMatrix = new ushort*[N];
    for (int i = 0; i < N; ++i)
        adjacencyMatrix[i] = new ushort[N];

	//calling function to create Erdős–Rényi graph
	erdosRenyi(adjacencyMatrix);

	//freeing allocated memory
	for (int i = 0; i < N; ++i) {
		delete[] adjacencyMatrix[i];
	}
	delete[] adjacencyMatrix;
}
//function definitin
void erdosRenyi(ushort** const adjmat)
{
	//set all array elements to zero
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			adjmat[i][j] = 0;
			adjmat[j][i] = 0;
		}
	}

	// creating graph base on probablity
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			double r = ((double)rand() / (RAND_MAX));
			if (r < P)
			{
				adjmat[i][j] = 1;
				adjmat[j][i] = 1;

			}
		}
	}
	ofstream adjacency("adjacencymatrix.txt", ios::out | ios::trunc);	//creating file to store result in text file
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			adjacency << adjmat[i][j] << "   ";
			
		}
		adjacency << endl;
	}
	adjacency.close();
}

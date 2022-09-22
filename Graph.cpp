#include "Graph.h"
#include <stdexcept>

void Graph::setVertexCount(int count)
{
	vertexCount = count;
	matrix.resize(count);
	for (int i = 0; i < count; i++) {
		matrix[i].resize(count, 0);
	}
}

void Graph::addEdge(unsigned v1, unsigned v2)
{
	if (v1 >= vertexCount || v2 >= vertexCount) {
		throw out_of_range("ERROR: Vertex number out of range");
	}
	matrix[v1][v2] = 1;
	matrix[v2][v1] = 1;
}

void Graph::findShortestPaths()
{
	// paths initialization
	paths.resize(vertexCount);
	for (int i = 0; i < vertexCount; i++) {
		paths[i].resize(vertexCount, INT_MAX);
	}
	for (size_t i = 0; i < vertexCount; i++)
		for (size_t j = 0; j < vertexCount; j++) {
			if (i == j) {
				paths[i][j] = 0;
			} else if (matrix[i][j]) {
				paths[i][j] = matrix[i][j];
			}
			
		}
	// Floyd algorythm
	for (size_t k = 0; k < vertexCount; k++)
		for (size_t i = 0; i < vertexCount; i++)
			for (size_t j = 0; j < vertexCount; j++) {
				if (paths[i][k] != INT_MAX && paths[k][j] != INT_MAX && paths[i][k] + paths[k][j] < paths[i][j]) {
					paths[i][j] = paths[i][k] + paths[k][j];
				}
			}
	return;
}

int Graph::countPathsShorterThan(int maxLength)
{
	int answer = 0;
	for (size_t i = 0; i < vertexCount; i++)
		for (size_t j = i + 1; j < vertexCount; j++) { //pairs with j < i were already counted, j == i is not a pair
			if (paths[i][j] <= maxLength) {
				answer++;
			}
		}
	return answer;
}

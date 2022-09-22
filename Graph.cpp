#include "Graph.h"

void Graph::setVertexCount(int count)
{
	vertexCount = count;
	matrix.resize(count);
	for (int i = 0; i < count; i++) {
		matrix[i].resize(count);
	}
}

void Graph::addEdge(int v1, int v2)
{
}

void Graph::findShortestPaths()
{
}

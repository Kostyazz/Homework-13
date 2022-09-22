#pragma once
#include <vector>
#include <string>

using namespace std;
class Graph {
public:
    Graph() {};
    void setVertexCount(int count);
    void addEdge(int v1, int v2);
    void findShortestPaths();

private:
    int vertexCount = 0;
    vector< vector<int> > matrix; // adjacency matrix
    vector< vector<int> > paths; // shortest paths calculated by Floyd algorythm
};

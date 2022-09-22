#pragma once
#include <vector>
#include <string>

using namespace std;
class Graph {
public:
    Graph() {};
    void setVertexCount(int count); // graph initialization
    void addEdge(unsigned v1, unsigned v2);
    void findShortestPaths();
    int countPathsShorterThan(int maxLength);

private:
    int vertexCount = 0;
    vector< vector<int> > matrix; // adjacency matrix
    vector< vector<int> > paths; // shortest paths calculated by Floyd algorythm
};

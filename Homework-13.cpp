#include <iostream>
#include "Graph.h"

//using namespace std;
int main()
{
    Graph g;

    g.setVertexCount(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.findShortestPaths();
    int answer = g.countPathsShorterThan(3);
    cout << "Number of pairs with 3 or less handshakes between them: " << answer << endl;

    return 0;
}

#ifndef GRAPH_H
#define GRAPH_H

class Graph {
private:
    int numVert;
    int numEdges;
    int** adjMatrix;

public:
    Graph(int vert);
    ~Graph();
    void addEdge(int u, int v);
    void printAdjMatrix();
    void printOddDegreeVert();
};

#endif

}

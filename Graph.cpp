#include "Graph.h"
#include <isostream>

Graph::Graph(int vert) {
    numVert = vert;
    numEdges = 0;

    adjMatrix = new int*[numVert];
    for (int i = 0; i < numVert; i++) {
        adjMatrix[i] = new int[numVert];
        for (int j = 0; j < numVert; j++) {
            adjMatrix[i][j] = 0;
    }
    }
}
Graph::~Graph() {
    for (int i = 0; i < numVert; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

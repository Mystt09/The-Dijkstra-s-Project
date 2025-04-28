#include "Graph.h"
#include <iostream>

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

void Graph::addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
    numEdges++;
}

void Graph::printAdjMatrix() {
    for (int i = 0; i < numVert; i++) {
        for (int j = 0; j < numVert; j++) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::printOddDegreeVert() {
    for (int i = 0; i < numVert; i++) {
        int degree = 0;
        for (int j = 0; j < numVert; j++) {
            degree += adjMatrix[i][j];
        }
        if (degree % 2 != 0) {
            std::cout << "Vertex " << i << " has an odd degree." << std::endl;
        }
    }
}

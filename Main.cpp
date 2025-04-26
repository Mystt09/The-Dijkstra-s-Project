#include "Edge.h"
#include "Vertex.h"
#include "Queue.cpp"
#include <iostream>
#include <string>
using namespace std;

int main(){

    // start of the initial pipeline that loads the test case file stream from std::cin

    int numOfVertices;
    int numOfEdges;

    if(!std::cin.eof()){
        std::cin >> numOfVertices;
        std::cin >> numOfEdges;
    }
    else{
        std::cout<<"Input not found!"<<std::endl;
        return NULL;
    }

    while(!std::cin.eof()){
        int startVertice;
        int endVertice;
        std::cin >> startVertice;
        std::cin >> endVertice;
        Edge* newEdge = new Edge(startVertice, endVertice); // this can be used to populate the adjacency matrix 
        // Here is where you load up the Graph object


    }

    // And here is where you start working on the three tasks

    //  ********** printing the odd vertices ********************8
    // will get the info from the graph object, to count the number of 1s in each row
    // then print the vertices with an odd amount of 1s
    // for test purposes i will hard code the marix from the instrucions 

    // Hard coded matrix for testing 

    const int MAX_V = 8;
    int matrix[MAX_V][MAX_V] = {

        {0, 1, 0, 1, 1, 0, 0, 0},  // row 1
        {1, 0, 1, 1, 0, 0, 0, 0},  // row 2
        {0, 1, 0, 1, 1, 1, 0, 0},  // row 3
        {1, 1, 1, 0, 0, 0, 0, 0},  // row 4
        {1, 0, 1, 0, 0, 0, 0, 0},  // row 5
        {0, 0, 1, 0, 0, 0, 1, 1},  // row 6
        {0, 0, 0, 0, 0, 1, 0, 1},  // row 7
        {0, 0, 0, 0, 0, 1, 1, 0}   // row 8
    };
    

    int oddVertices[MAX_V];
    int oddCount = 0;
    


   //int oddVertices[numOfVertices]; // set the size to 0 for now 

   // int oddCount = 0; // keeps track of the vertices with odd numbers 
   
    // Make an array of vertices with the Vertex object

    Vertex vertices[MAX_V];
                      

for (int i = 0; i < MAX_V; i++){

    int count = 0; // counter that will reset after counting the number of 1s in each row 
     

    for(int j = 0; j < MAX_V; j++) {

        

        if (matrix[i][j] == 1) {

            count ++; 
        }


    }

    // after the number of 1s have been added, check if count is odd 

    vertices[i].setIndex(i + 1);
    vertices[i].setDegree(count);

   
}

 //print the oddVertices array elements

cout << "Odd Vertices: \n";
    
for (int i = 0; i < numOfVertices; i++){

    if ((vertices[i].getDegree() % 2) != 0) {

    oddVertices[oddCount] = vertices[i].getIndex();

    oddCount++;

    }

}
 
// print odd vertices array 

for (int i = 0; i < oddCount; i++){

    cout << oddVertices[i] << endl; 

}





// ***** Shortest Path ***** 

// initialize arrays 

int INF = 1000; 
//int dist[numOfVertices];
//bool visited[numOfVertices]; 
int dist[MAX_V];

for (int i = 0; i < oddCount; i++) {

    //int dist[numOfVertices];
   // bool visited[numOfVertices]; 

    int oddVertice = oddVertices[i];

   // if ((vertices[i].getDegree() % 2) != 0) { // if the vertice is odd, then add it to the oddVertice variable 

     //   oddVertice = vertices[i].getIndex();

    

    for (int j = 0; j < numOfVertices; j++) { // initialize the dist to be INF 
        dist[j] = INF;
       
    }

    //call bfs function 

    Queue shortestPath;

    shortestPath.bfs(oddVertice -1, numOfVertices, matrix, dist);

    cout << "Single source shortest path lengths from node " << oddVertices[i] << endl;


    //print the paths from node i 

    for (int k = 0; k < MAX_V; k++) {

        cout << (k + 1) << ": " <<  dist[k] << endl;

    }

//} // end closing bracket for if statement 



}






    return 0;
}

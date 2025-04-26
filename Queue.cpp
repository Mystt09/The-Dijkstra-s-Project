#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 200
#define MAX_VERTICE 8


class Queue {

int head = -1;
int tail = -1;
int arrQue[MAX_SIZE];

bool isEmpty() { return head == -1 || head > tail; } 

void enqueue(int vertex)
{
   
    // if queue is empty, set front to 0
    if (isEmpty()) 

        head = 0;

        tail++;

    arrQue[tail] = vertex;
    

}


    

int dequeue()
    {
        // Check underflow condition
       // if (isEmpty()) {
         //   cout << "Queue is empty" << endl;
         //   return -1;
       // }


        int deqVal = arrQue[head];

        head++;

        // if queue becomes empty, reset both pointers
        if (isEmpty()) 

            head = tail = -1;

    

        return deqVal;

    };

    // function for shortest path 

    // V is numOfVertices 

    public:

    void bfs(int startNode, int V, int matrix[][MAX_VERTICE], int dist[]) {

        int visited[V];
        

        // initialize all values to false 
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }


        // enqueue start node and mark it as visited
        // set distance[0] == 0 

        enqueue(startNode);

        visited[startNode] = true;
        dist[startNode] = 0;


        // while loop to check that the queue is not empty 

        while(!isEmpty()) {

            // variable for the dequeued value 

            int u = dequeue(); 

            for(int i = 0; i < V; i++){

                if(matrix[u][i] == 1 && !visited[i]) {

                    visited[i] = true;
                    dist[i] = dist[u] +1;

                    enqueue(i); 

                }

           

            }
    
        }
        

    

    }


    
 };

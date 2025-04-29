all: Main.o Edge.o Vertex.o Graph.o Queue.o
	g++ -g -Wall Main.o Edge.o Vertex.o Graph.o Queue.o -o dijkstra

Graph.o: Graph.h Graph.cpp
		g++ -g -Wall -c Graph.cpp

Queue.o: Queue.h Queue.cpp
		g++ -g -Wall -c Queue.cpp

Edge.o: Edge.h Edge.cpp
		g++ -g -Wall -c Edge.cpp

Vertex.o: Vertex.h Vertex.cpp	
		g++ -g -Wall -c Vertex.cpp

Main.o: Main.cpp
		g++ -g -Wall -c Main.cpp

clean:
	rm -rf *.o dijkstra

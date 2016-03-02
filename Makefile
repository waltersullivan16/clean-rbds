CC = g++ -ggdb -std=c++11

create_graph: create_graph.o
		$(CC) $(CCFLAGS) -o create_graph create_graph.o -pthread

create_graph.o: create_graph.cpp
		$(CC) $(CCFLAGS) -c create_graph.cpp -pthread


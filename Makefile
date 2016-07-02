CC = g++ -ggdb -std=c++11

all: create_graph create_table create_any_graph

create_graph: create_graph.o
		$(CC) $(CCFLAGS) -o create_graph create_graph.o -pthread

create_graph.o: create_graph.cpp
		$(CC) $(CCFLAGS) -c create_graph.cpp -pthread

create_table: create_table.o
		$(CC) $(CCFLAGS) -o create_table create_table.o -pthread

create_table.o: create_table.cpp
		$(CC) $(CCFLAGS) -c create_table.cpp -pthread

create_any_graph: create_any_graph.o
		$(CC) $(CCFLAGS) -o create_any_graph create_any_graph.o -pthread

create_any_graph.o: create_any_graph.cpp
		$(CC) $(CCFLAGS) -c create_any_graph.cpp -pthread

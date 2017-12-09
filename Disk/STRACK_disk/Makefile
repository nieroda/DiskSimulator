
CFLAGS=-std=c++11 -ggdb

OBJECTS=STRACKQueueNode.o STRACKQueue.o main.o

STRACK_disk.x: $(OBJECTS)
	g++ $(CFLAGS) $(OBJECTS) -o STRACK_disk.x

STRACKQueueNode.o: STRACKQueueNode.cpp STRACKQueueNode.hpp
	g++ $(CFLAGS) -c STRACKQueueNode.cpp -o STRACKQueueNode.o

STRACKQueue.o: STRACKQueue.cpp STRACKQueue.hpp STRACKQueueNode.hpp 
	g++ $(CFLAGS) -c STRACKQueue.cpp -o STRACKQueue.o

main.o: main.cpp STRACKQueue.hpp STRACKQueueNode.hpp 
	g++ $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -fr *~ $(OBJECTS) STRACK_disk.x

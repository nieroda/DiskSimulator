
CFLAGS=-std=c++11 -ggdb

OBJECTS=PICKUPQueueNode.o PICKUPQueue.o main.o

PICKUP_disk.x: $(OBJECTS)
	g++ $(CFLAGS) $(OBJECTS) -o PICKUP_disk.x

PICKUPQueueNode.o: PICKUPQueueNode.cpp PICKUPQueueNode.hpp
	g++ $(CFLAGS) -c PICKUPQueueNode.cpp -o PICKUPQueueNode.o

PICKUPQueue.o: PICKUPQueue.cpp PICKUPQueue.hpp PICKUPQueueNode.hpp 
	g++ $(CFLAGS) -c PICKUPQueue.cpp -o PICKUPQueue.o

main.o: main.cpp PICKUPQueue.hpp PICKUPQueueNode.hpp 
	g++ $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -fr *~ $(OBJECTS) PICKUP_disk.x


CFLAGS=-std=c++11 -ggdb

OBJECTS=CLOOKQueueNode.o CLOOKQueue.o main.o

CLOOK_disk.x: $(OBJECTS)
	g++ $(CFLAGS) $(OBJECTS) -o CLOOK_disk.x

CLOOKQueueNode.o: CLOOKQueueNode.cpp CLOOKQueueNode.hpp
	g++ $(CFLAGS) -c CLOOKQueueNode.cpp -o CLOOKQueueNode.o

CLOOKQueue.o: CLOOKQueue.cpp CLOOKQueue.hpp CLOOKQueueNode.hpp 
	g++ $(CFLAGS) -c CLOOKQueue.cpp -o CLOOKQueue.o

main.o: main.cpp CLOOKQueue.hpp CLOOKQueueNode.hpp 
	g++ $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -fr *~ $(OBJECTS) CLOOK_disk.x

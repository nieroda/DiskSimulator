
CFLAGS=-std=c++11 -ggdb

OBJECTS=LOOKQueueNode.o LOOKQueue.o main.o

LOOK_disk.x: $(OBJECTS)
	g++ $(CFLAGS) $(OBJECTS) -o LOOK_disk.x

LOOKQueueNode.o: LOOKQueueNode.cpp LOOKQueueNode.hpp
	g++ $(CFLAGS) -c LOOKQueueNode.cpp -o LOOKQueueNode.o

LOOKQueue.o: LOOKQueue.cpp LOOKQueue.hpp LOOKQueueNode.hpp 
	g++ $(CFLAGS) -c LOOKQueue.cpp -o LOOKQueue.o

main.o: main.cpp LOOKQueue.hpp LOOKQueueNode.hpp 
	g++ $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -fr *~ $(OBJECTS) LOOK_disk.x

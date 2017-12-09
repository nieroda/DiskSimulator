CFLAGS=-std=c++11 

OBJECTS=FCFSQueueNode.o FCFSQueue.o CLOOKQueueNode.o  CLOOKQueue.o LOOKQueueNode.o LOOKQueue.o PICKUPQueueNode.o PICKUPQueue.o STRACKQueueNode.o STRACKQueue.o main.o

main_out.x : $(OBJECTS)
	g++ $(CFLAGS) $(OBJECTS) -o main_out.x


FCFSQueueNode.o: FCFSQueueNode.cpp FCFSQueueNode.hpp
	g++ $(CFLAGS) -c FCFSQueueNode.cpp -o FCFSQueueNode.o

FCFSQueue.o: FCFSQueue.cpp FCFSQueue.hpp FCFSQueueNode.hpp
	g++ $(CFLAGS) -c FCFSQueue.cpp -o FCFSQueue.o

CLOOKQueueNode.o: CLOOKQueueNode.cpp CLOOKQueueNode.hpp
	g++ $(CFLAGS) -c CLOOKQueueNode.cpp -o CLOOKQueueNode.o

CLOOKQueue.o: CLOOKQueue.cpp CLOOKQueue.hpp CLOOKQueueNode.hpp
	g++ $(CFLAGS) -c CLOOKQueue.cpp -o CLOOKQueue.o

LOOKQueueNode.o: LOOKQueueNode.cpp LOOKQueueNode.hpp
	g++ $(CFLAGS) -c LOOKQueueNode.cpp -o LOOKQueueNode.o

LOOKQueue.o: LOOKQueue.cpp LOOKQueue.hpp LOOKQueueNode.hpp
	g++ $(CFLAGS) -c LOOKQueue.cpp -o LOOKQueue.o

PICKUPQueueNode.o: PICKUPQueueNode.cpp PICKUPQueueNode.hpp
	g++ $(CFLAGS) -c PICKUPQueueNode.cpp -o PICKUPQueueNode.o

PICKUPQueue.o: PICKUPQueue.cpp PICKUPQueue.hpp PICKUPQueueNode.hpp
	g++ $(CFLAGS) -c PICKUPQueue.cpp -o PICKUPQueue.o


STRACKQueueNode.o: STRACKQueueNode.cpp STRACKQueueNode.hpp
	g++ $(CFLAGS) -c STRACKQueueNode.cpp -o STRACKQueueNode.o

STRACKQueue.o: STRACKQueue.cpp STRACKQueue.hpp STRACKQueueNode.hpp
	g++ $(CFLAGS) -c STRACKQueue.cpp -o STRACKQueue.o

main.o: main.cpp CLOOKQueue.hpp CLOOKQueueNode.hpp FCFSQueueNode.hpp FCFSQueue.hpp LOOKQueueNode.hpp LOOKQueue.hpp PICKUPQueueNode.hpp PICKUPQueue.hpp STRACKQueue.hpp STRACKQueueNode.hpp
	g++ $(CFLAGS) -c main.cpp -o main.o


clean:
	rm -fr *.o *.x
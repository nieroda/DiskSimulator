
#include "Request.hpp"
#include "STRACKQueue.hpp"
#include <fstream>
#include <string>
#include <sstream>


int main() {

    STRACKQueue *queue = new STRACKQueue();
/*
    Request *r1 = new Request(196, 79, 23, 1);
    //Request *r1 = new Request(10, 5, 20);
    queue->addRequest(r1);

    Request *r2 = new Request(276, 47, 14, 2);
    //Request *r2 = new Request(15, 15, 2);
    queue->addRequest(r2);

    Request *r3 = new Request(326, 43, 10, 3);
    //Request *r3 = new Request(25, 5, 8);
    queue->addRequest(r3);

    Request *r4 = new Request(394, 21, 5, 4);
    //Request *r4 = new Request(48, 8, 8);
    queue->addRequest(r4);

    Request *r5 = new Request(412, 72, 14, 5);
    //Request *r4 = new Request(48, 8, 8);
    queue->addRequest(r5);

    Request *r6 = new Request(596, 16, 6, 6);
    //Request *r4 = new Request(48, 8, 8);
    queue->addRequest(r6);

    Request *r7 = new Request(743, 52, 21, 7);
    //Request *r4 = new Request(48, 8, 8);
    queue->addRequest(r7);

    Request *r8 = new Request(785, 89, 6, 8);
    //Request *r4 = new Request(48, 8, 8);
    queue->addRequest(r8);

    Request *r9 = new Request(886, 40, 12, 9);
    //Request *r4 = new Request(48, 8, 8);
    queue->addRequest(r9);

    Request *r10 = new Request(1153, 9, 15, 10);
    //Request *r4 = new Request(48, 8, 8);
    queue->addRequest(r10);
*/

     std::string Stringtime, Stringtrack, Stringsector;
     int time, track, sector;
     int iter = 1;
     std::string line;
     while (std::getline(std::cin, line)) {
     std::stringstream stream(line);
     stream >> Stringtime >> Stringtrack >> Stringsector;
     time = std::stoi(Stringtime);
     track = std::stoi(Stringtrack);
     sector = std::stoi(Stringsector);
     Request *r = new Request(time, track, sector, iter);
     queue->addRequest(r);
     iter++;
     }

    std::cout << "iter is " << iter << std::endl;

    queue->print();

    delete queue;


    return 0;
}

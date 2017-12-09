
#include "Request.hpp"
#include "FCFSQueue.hpp"
#include <fstream>
#include <string>
#include <sstream>

int main() {

    FCFSQueue *queue = new FCFSQueue();
    
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

    queue->print();

    delete queue;


    return 0;
}


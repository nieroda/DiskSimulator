#include "FCFSQueue.hpp"
#include "Request.hpp"
#include <iomanip>
#include <fstream>


//fcfs
void FCFSQueue::addRequest(Request *request) {
    FCFSQueueNode *rNode = new FCFSQueueNode(request);
    if( isEmpty() ) {
        head = tail = rNode;
    } else {
        tail->next(rNode);
        tail = rNode;
    }
}

Request *FCFSQueue::getRequest() {
    if( isEmpty() ) {
        std::cout << "Calling FCFSQueueNode::getRequest() on empty queue. Terminating...\n";
        exit(1);
    }
}

bool FCFSQueue::isEmpty() { 
    return head == nullptr; 
}



FCFSQueue::~FCFSQueue() {
    while( head != nullptr ) {
        FCFSQueueNode *node = head;
        head = node->next();
        delete node;
    }        
}

void FCFSQueue::print() {
    int iter = 1;
    int count = 1;
    int Ctrack = 0, Csector = 0, Dtrack = 0, Dsector = 0;
    float entr = 0, pEntr = 0;
    float serv = 0, seektime = 0, rotationaldelay = 0;
    float comp = 0, pComp = 0;
    float wait = 0, TmInSys = 0, init = 0;
    
    std::ofstream myfile;
    myfile.open ("FCFS_output");
    printHead(myfile);

    
    for ( auto cur = head; cur; cur = cur->next() ) {
        
        calculate(cur, count, iter, pComp, Ctrack, Csector, Dtrack, Dsector, entr, init, wait, serv, TmInSys, comp);
        printAll(myfile, iter, Dtrack, Dsector, entr, init, comp, wait, serv, TmInSys);
        
        pComp = comp;
        Ctrack = Dtrack;
        Csector = Dsector;
        Csector++;
        count++;
    }
    myfile.close();
}

void FCFSQueue::calculate(FCFSQueueNode* cur, int count, int& iter, float pComp, int Ctrack, int Csector, int& Dtrack, int& Dsector, float& entr, float& init, float& wait, float& serv, float& TmInSys, float& comp) {
    iter = cur->request()->index();
    Dtrack = cur->request()->track();
    Dsector = cur->request()->sector();
    entr = cur->request()->time()/10;
    init = (count == 1) ? entr : pComp;
    wait = init - entr;
    serv = getServ(Ctrack, Dtrack, Csector, Dsector);
    TmInSys = wait + serv;
    comp = TmInSys + entr;
}

float FCFSQueue::getServ(int Ctrack, int Dtrack, int Csector, int &Dsector) {
    
    float seektime = getTrack(Ctrack, Dtrack) * 3;
    float rotdelay = differenceSector(Csector, Dsector) * .1;
    return seektime + rotdelay + .1;
}


int FCFSQueue::getTrack(int x, int y) {
    return x > y ? x - y : y - x;
}


int FCFSQueue::differenceSector(int x, int y) {
    
    int returnV = 0;
    if (x > y) {
        while (x != 30) {
            x++;
            returnV++;
        }
        x = 0;
        returnV += (y - x);
        return returnV;
    }
    else {
        return (y - x);
    }
}

void FCFSQueue::printAll(std::ofstream  &filein,  int iter, int track, int sector, float entr, float init, float comp, float wait, float serv, float TmInSys) {
    filein << std::setw(5) << std::setprecision(2) << std::fixed << std::right << iter;
    filein << std::setw(10) << track;
    filein << std::setw(10) << sector;
    filein << std::setw(10) << entr;
    filein << std::setw(10) << init;
    filein << std::setw(10) << comp;
    filein << std::setw(10) << wait;
    filein << std::setw(10) << serv;
    filein << std::setw(10) << TmInSys << "\n";
}

void FCFSQueue::printHead(std::ofstream &filein) {
    filein << std::setw(5) << std::right << "#";
    filein << std::setw(10) << "Trac";
    filein << std::setw(10) << "Sec";
    filein << std::setw(10) << "Entr";
    filein << std::setw(10) << "Init";
    filein << std::setw(10) << "Comp";
    filein << std::setw(10) << "Wait";
    filein << std::setw(10) << "Serv";
    filein << std::setw(10) << "TmInSys" << "\n";
}



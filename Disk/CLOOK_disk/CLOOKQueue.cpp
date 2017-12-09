#include "CLOOKQueue.hpp"
#include "Request.hpp"
#include <iomanip>
#include <fstream>

//clook
void CLOOKQueue::addRequest(Request *request) {
    CLOOKQueueNode *rNode = new CLOOKQueueNode(request);
    if( isEmpty() ) {
        head = tail = rNode;
    } else {
        CLOOKQueueNode *temp = head;
        int first = temp->request()->track();
        int incomingtrack = request->track();

        while(temp->next() != nullptr) {
            int currenttrack = temp->request()->track();
            int next = temp->next()->request()->track();
            if (currenttrack == incomingtrack) {
                return insertEnd(temp, rNode);
            }
            

            if(incomingtrack > currenttrack && incomingtrack < next) {
                return insertEnd(temp, rNode);
            }
            
            if (next < currenttrack && currenttrack > incomingtrack && next > incomingtrack) {
                return insertEnd(temp, rNode);
            }
            
            if (currenttrack > next && incomingtrack > currenttrack && incomingtrack > next) {
                return insertEnd(temp, rNode);
            }
    

            temp = temp->next();
        
        }
        tail->next(rNode);
        tail = rNode;
        tail->next(nullptr);
    }
}

void CLOOKQueue::insertEnd(CLOOKQueueNode *temp, CLOOKQueueNode *rNode) {
    int val = rNode->request()->track();
    while (temp->next() != nullptr) {
        if (temp->next()->request()->track() == val)
            temp = temp->next();
        else {
            rNode->next(temp->next());
            temp->next(rNode);
            return;
        }
    }
    tail->next(rNode);
    tail = rNode;
    tail->next(nullptr);
}

Request *CLOOKQueue::getRequest() {
    if( isEmpty() ) {
        std::cout << "Calling CLOOKQueueNode::getRequest() on empty queue. Terminating...\n";
        exit(1);
    }
}

bool CLOOKQueue::isEmpty() { 
    return head == nullptr; 
}



CLOOKQueue::~CLOOKQueue() {
    while( head != nullptr ) {
        CLOOKQueueNode *node = head;
        head = node->next();
        delete node;
    }        
}


void CLOOKQueue::print() {
    int iter = 1;
    int count = 1;
    int Ctrack = 0, Csector = 0, Dtrack = 0, Dsector = 0;
    float entr = 0, pEntr = 0;
    float serv = 0, seektime = 0, rotationaldelay = 0;
    float comp = 0, pComp = 0;
    float wait = 0, TmInSys = 0, init = 0;
    
    std::ofstream myfile;
    myfile.open("CLOOK_output");
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

void CLOOKQueue::calculate(CLOOKQueueNode* cur, int count, int& iter, float pComp, int Ctrack, int Csector, int& Dtrack, int& Dsector, float& entr, float& init, float& wait, float& serv, float& TmInSys, float& comp) {
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

float CLOOKQueue::getServ(int Ctrack, int Dtrack, int Csector, int &Dsector) {
    
    float seektime = getTrack(Ctrack, Dtrack) * 3;
    float rotdelay = differenceSector(Csector, Dsector) * .1;
    return seektime + rotdelay + .1;
}


int CLOOKQueue::getTrack(int x, int y) {
    return x > y ? x - y : y - x;
}


int CLOOKQueue::differenceSector(int x, int y) {
    
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

void CLOOKQueue::printAll(std::ofstream  &filein,  int iter, int track, int sector, float entr, float init, float comp, float wait, float serv, float TmInSys) {
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

void CLOOKQueue::printHead(std::ofstream &filein) {
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


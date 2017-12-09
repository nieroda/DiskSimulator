#include "Request.hpp"
#include "CLOOKQueue.hpp"
#include "FCFSQueue.hpp"
#include "LOOKQueue.hpp"
#include "PICKUPQueue.hpp"
#include "STRACKQueue.hpp"
#include "Disk.hpp"
#include <fstream> 
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <map>

bool diskTaskManager(int timerNow, Disk *fcfs, Disk *strack, Disk *pickup, Disk *clook, Disk *look);
void addRequestAll(Disk *fcfs, Disk *strack, Disk *pickup, Disk *clook, Disk *look, Request *req);
void dealwithrequestAll(Disk *fcfs, Disk *strack, Disk *pickup, Disk *clook, Disk *look);
void examineQueueLength(Disk *fcfs, Disk *strack, Disk *pickup, Disk *clook, Disk *look);
void printIntroSummary(std::ofstream &filein);
void printSummaryOutput(Disk *fcfs, Disk *strack, Disk *pickup, Disk *clook, Disk *look);
void printTIMER_output(std::map<int, int>fc, std::map<int, int>st, std::map<int, int>pu, std::map<int, int>cl, std::map<int, int>lo);
void updateMap(std::map<int, int>&fc, std::map<int, int>&st, std::map<int, int>&pu, std::map<int, int>&cl, std::map<int, int>&lo, int requesttime, Disk *fcfs, Disk *strack, Disk *pickup, Disk *clook, Disk *look);




int main() {
    
    Disk *fcfs      = new Disk( new FCFSQueue(), "FCFS" );
    Disk *strack    = new Disk( new STRACKQueue(), "STRACK" );
    Disk *pickup    = new Disk( new PICKUPQueue(), "PICKUP" );
    Disk *clook     = new Disk( new CLOOKQueue(), "CLOOK"  );
    Disk *look      = new Disk( new LOOKQueue(), "LOOK"   );

    std::string Stringtime, Stringtrack, Stringsector;
    int time, track, sector;
    int iter = 1;
    std::string line;
    std::queue<Request *>RequestsQueue;
    while (std::getline(std::cin, line)) {
        std::stringstream stream(line);
        stream >> Stringtime >> Stringtrack >> Stringsector;
        time = std::stoi(Stringtime);
        track = std::stoi(Stringtrack);
        sector = std::stoi(Stringsector);
        Request *r = new Request(time, track, sector, iter);
        RequestsQueue.push(r);
        iter++;
    }
    
    std::map<int, int> fc;
    std::map<int, int> st;
    std::map<int, int> pu;
    std::map<int, int> cl;
    std::map<int, int> lo;
    bool _continue = true;
    int requesttime = 50;
    int timerNow = 0;
  
    while(1) {
 
        if (timerNow == 0) {                   //add the initial request in
            addRequestAll(fcfs, strack, pickup, clook, look, RequestsQueue.front());
            RequestsQueue.pop();
            dealwithrequestAll(fcfs, strack, pickup, clook, look);
        }

        
        if ( !RequestsQueue.empty() && timerNow > RequestsQueue.front()->time()/10 ) {  //adding requests based off the time they should come in
            addRequestAll(fcfs, strack, pickup, clook, look, RequestsQueue.front());
            RequestsQueue.pop();
            //examineQueueLength(fcfs, strack, pickup, clook, look);
        }   
        

        if (diskTaskManager(timerNow, fcfs, strack, pickup, clook, look)) {
            _continue = false;
        }
        
        
        if(timerNow % 50 == 0 && timerNow != 0) {
            updateMap(fc, st, pu, cl, lo, requesttime, fcfs, strack, pickup, clook, look);
            examineQueueLength(fcfs, strack, pickup, clook, look);
            requesttime += 50;
            
            if (!_continue) break;
        }
        
        timerNow++;
    }
    
    printTIMER_output(fc, st, pu, cl, lo);
    printSummaryOutput(fcfs, strack, pickup, clook, look);
    
    return 0;
}

void examineQueueLength(Disk *fcfs, Disk *strack, Disk *pickup, Disk *clook, Disk *look) {
    fcfs->updateQueueData();
    strack->updateQueueData();
    pickup->updateQueueData();
    clook->updateQueueData();
    look->updateQueueData();
}


void printSummaryOutput(Disk *fcfs, Disk *strack, Disk *pickup, Disk *clook, Disk *look) {
    std::ofstream myfile;
    myfile.open("SUMMARY_output");
    printIntroSummary(myfile);
    fcfs->getStringifiedAvg(myfile);
    strack->getStringifiedAvg(myfile);
    pickup->getStringifiedAvg(myfile);
    clook->getStringifiedAvg(myfile);
    look->getStringifiedAvg(myfile);
    myfile.close();
}

void updateMap(std::map<int, int>&fc, std::map<int, int>&st, std::map<int, int>&pu, std::map<int, int>&cl, std::map<int, int>&lo, int requesttime, Disk *fcfs, Disk *strack, Disk *pickup, Disk *clook, Disk *look) {
    fc[requesttime] = fcfs->queueLength();
    st[requesttime] = strack->queueLength();
    pu[requesttime] = pickup->queueLength();
    cl[requesttime] = clook->queueLength();
    lo[requesttime] = look->queueLength();
}


void dealwithrequestAll(Disk *fcfs, Disk *strack, Disk *pickup, Disk *clook, Disk *look) {
    fcfs->dealwithrequest();
    strack->dealwithrequest();
    pickup->dealwithrequest();
    clook->dealwithrequest();
    look->dealwithrequest();
}

void addRequestAll(Disk *fcfs, Disk *strack, Disk *pickup, Disk *clook, Disk *look, Request *req) {
    fcfs->addRequest( req );
    strack->addRequest( req );
    pickup->addRequest( req );
    clook->addRequest( req );
    look->addRequest( req );
}


void printIntroSummary(std::ofstream &filein) {
    filein << "Summary Report" << std::endl;
    filein << std::setw(30) << std::right << "TimeInSystem";
    filein << std::setw(30) << "WaitTime";
    filein << std::setw(30) << "ServiceTime";
    filein << std::setw(20) << "NumInQueue" << std::endl;
    filein << std::setw(10) << "";
    for (int i = 0; i < 3; i++) {
        filein << std::setw(10) << std::right << "Min";
        filein << std::setw(10) << "Max";
        filein << std::setw(10) << "Avg";
    }
    filein << std::setw(10) << "Max";
    filein << std::setw(10) << "Avg";
    filein << std::endl;
}




bool diskTaskManager(int timerNow, Disk *fcfs, Disk *strack, Disk *pickup, Disk *clook, Disk *look) {
    if( fcfs->isTotalEmpty() && strack->isTotalEmpty() && pickup->isTotalEmpty() && clook->isTotalEmpty() && look->isTotalEmpty()) { return true; }

    if ( timerNow != 0 && timerNow > fcfs->getDiskCompTime())
        fcfs->dealwithrequest();
    if ( timerNow != 0 && timerNow > strack->getDiskCompTime())
        strack->dealwithrequest();
    if ( timerNow != 0 && timerNow > pickup->getDiskCompTime())
        pickup->dealwithrequest();
    if ( timerNow != 0 && timerNow > clook->getDiskCompTime())
        clook->dealwithrequest();
    
    if ( timerNow != 0 && timerNow > look->getDiskCompTime())
        look->dealwithrequest();
    
  
    return false;
}

void printTIMER_output(std::map<int, int>fc, std::map<int, int>st, std::map<int, int>pu, std::map<int, int>cl, std::map<int, int>lo) {
    std::ofstream file;
    file.open("TIMER_output");
    auto b = st.begin();
    auto c = pu.begin();
    auto d = cl.begin();
    auto e = lo.begin();
    file << std::setw(10) << std::right << "Time";
    file << std::setw(10) << "FCFS";
    file << std::setw(10) << "Same Track";
    file << std::setw(10) << "Pickup";
    file << std::setw(10) << "C-Look";
    file << std::setw(10) << "Look" << std::endl;
    for ( auto a = fc.begin(); a != fc.end(); ++a ) {
        file << std::setw(10) << std::right << a->first;
        file << std::setw(10) << a->second;
        file << std::setw(10) << b->second;
        file << std::setw(10) << c->second;
        file << std::setw(10) << d->second;
        file << std::setw(10) << e->second << std::endl;
        ++b;
        ++c;
        ++d;
        ++e;
    }
    file.close();
}

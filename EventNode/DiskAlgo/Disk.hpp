#ifndef _disk_
#define _disk_

#include <iostream>
#include <climits>
#include <iomanip>
#include <string>



class Disk : public WaitQueue {
    
public:
    Disk( WaitQueue *queue, std::string(t) ): q(queue), CurrentTrack(0), CurrentSector(0), time(0), state(false), iterations(1), diskcomptime(0), priorDD(0)
        , entr(0), init(0), wait(0), serv(0), TmInSys(0), comp(0), pcomp(0), TISmin(INT_MAX), TISmax(0), TIStotal(0), WTmin(INT_MAX), WTmax(0), WTtotal(0),
        STmin(INT_MAX), STmax(0), STtotal(0), frst(false), type(t), MaxQueue(0), TotalQueue(0), queueCalls(0) {}
    
    virtual void addRequest(Request *request);
    virtual Request *getRequest();
    virtual bool isEmpty();
    virtual void deleteFirst();
    virtual int queueLength();
    virtual ~Disk() {}
    
    bool isTotalEmpty();

    int getTrackDifference();
    int differenceSector();
    float getDDONEtime();
    float getSERVtime();
    
    void updateTIS(float);
    void updateWT(float);
    void updateST(float);
    float getAverage(float);
    void getStringifiedAvg(std::ofstream &filein);
    
    int getCurrentTrack();
    int getCurrentSector();
    int getDestinationTrack();
    int getDestinationSector();
    float getDiskCompTime();
    int getTime();
    Request* getDiskRequest();
    bool getState();
    float getAvgQ();
    bool getandLoadRequest();
    void dealwithrequest();
    virtual void print();
    
    void updateQueueData();
private:
    int CurrentTrack, CurrentSector, DestinationTrack, DestinationSector;
    float priorDD;
    bool state;
    float time;
    int iterations;
    float diskcomptime;
    WaitQueue* q;
    Request *r;
    bool frst;
    float entr, init, wait, serv, TmInSys, comp, pcomp;
    
    float TISmin, TISmax, TIStotal;
    float WTmin, WTmax, WTtotal;
    float STmin, STmax, STtotal;
    std::string type;
    
    float MaxQueue, TotalQueue, queueCalls;
};

float Disk::getAvgQ() {
    return TotalQueue / queueCalls;
}

void Disk::updateQueueData() {
    queueCalls++;
    if(queueLength() > MaxQueue)
        MaxQueue = queueLength();
    
    TotalQueue += queueLength();
}

void Disk::getStringifiedAvg(std::ofstream &filein) {
    filein << std::setw(10) << std::right << type;
    filein << std::setw(10) << std::setprecision(2) << std::fixed << TISmin;
    filein << std::setw(10) << TISmax;
    filein << std::setw(10) << getAverage(TIStotal);
    filein << std::setw(10) << WTmin;
    filein << std::setw(10) << WTmax;
    filein << std::setw(10) << getAverage(WTtotal);
    filein << std::setw(10) << STmin;
    filein << std::setw(10) << STmax;
    filein << std::setw(10) << getAverage(STtotal);
    filein << std::setw(10) << MaxQueue;
    filein << std::setw(10) << getAvgQ();
    filein << std::endl;
}

void Disk::print() {
    q->print();
}

float Disk::getAverage(float needAvg) {
    float a = needAvg;
    return a / (iterations - 1);
}

void Disk::updateTIS(float TIS) {
    if (TISmin > TIS)
        TISmin = TIS;
    
    if (TIS > TISmax)
        TISmax = TIS;
    
    TIStotal += TIS;
}

void Disk::updateWT(float WT) {
    if (WTmin > WT)
        WTmin = WT;
    
    if (WT > WTmax)
        WTmax = WT;
    
    WTtotal += WT;
}

void Disk::updateST(float ST) {
    if(STmin > ST)
        STmin = ST;
    
    if(ST > STmax)
        STmax = ST;
    
    STtotal += ST;
}

void Disk::dealwithrequest() {
    if ( getandLoadRequest() ) {
        float done = getDDONEtime();
        diskcomptime = done;
        priorDD = done;
        pcomp = comp;
        entr = time/10;
        init = iterations == 1 ? entr : pcomp;
        wait = init - entr;
        serv = getSERVtime();
        TmInSys = wait + serv;
        comp = TmInSys + entr;
        updateTIS(TmInSys);
        updateWT(wait);
        updateST(serv);
        //updateQueueData();
        iterations++;
    }
    
}

bool Disk::getandLoadRequest() {
    if( !isEmpty() ){
        state = true;
        if (iterations == 1) {
            r = getRequest();
        }
        else {
            deleteFirst();
            if (getRequest() == nullptr) { return false; }
            r = getRequest();
        }

        CurrentTrack = DestinationTrack;
        CurrentSector = DestinationSector;
        iterations == 1 ? CurrentSector+=0 : CurrentSector+=1;
        DestinationTrack = r->track();
        DestinationSector = r->sector();
        time = r->time();
        return true;
 
    }
    else {
        r = nullptr;
        state = false;
        return false;
    }
}


void Disk::addRequest(Request *request) {
    q->addRequest(request);
}

Request* Disk::getRequest() {
    return q->getRequest();
}

bool Disk::isEmpty() {
    return q->isEmpty();
}

bool Disk::isTotalEmpty() {
    if (r == nullptr && q->isEmpty())
        return true;
    return false;
}

void Disk::deleteFirst() {
    q->deleteFirst();
}

int Disk::queueLength() {
    return q->queueLength();
}



int Disk::getCurrentTrack() {
    return CurrentTrack;
}

int Disk::getCurrentSector() {
    return CurrentSector;
}

float Disk::getDiskCompTime() {
    return comp;
}

int Disk::getTime() {
    return time;
}

Request* Disk::getDiskRequest() {
    return r;
}

bool Disk::getState() {
    return state;
}

int Disk::getDestinationTrack() {
    return DestinationTrack;
}
int Disk::getDestinationSector() {
    return DestinationSector;
}


int Disk::getTrackDifference() {
    int x = CurrentTrack;
    int y = DestinationTrack;
    return x > y ? x - y : y - x;
}

int Disk::differenceSector() {
    int x = CurrentSector;
    int y = DestinationSector;
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

float Disk::getSERVtime() {

    float seektime = getTrackDifference() * 3;
    float rotdelay = differenceSector() * .1;
    return seektime + rotdelay + .1;
}
    int CurrentTrack, CurrentSector, DestinationTrack, DestinationSector;


float Disk::getDDONEtime() {
    float seektime = getTrackDifference() * 3;
    float rotdelay = differenceSector() * .1;
    return iterations == 1 ? seektime + rotdelay + r->time()/10 + .1 : seektime + rotdelay + .1 + priorDD;
    
}

#endif

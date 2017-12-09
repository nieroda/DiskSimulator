#include<iostream>

#include "Queue.hpp"
#include "PICKUPQueueNode.hpp"

class Request;

class PICKUPQueue: public Queue {

public:
    PICKUPQueue(): head(nullptr), tail(nullptr) {}

    virtual void addRequest(Request *request);

    virtual Request *getRequest();
    virtual bool isEmpty();
    virtual void print(); 
    virtual ~PICKUPQueue();
    
    void calculate(PICKUPQueueNode*, int, int&, float, int, int, int&, int&, float&, float&, float&, float&, float&, float&);
    float getServ(int, int, int, int&);
    int getTrack(int x, int y);
    int differenceSector(int x, int y);
    void printHead(std::ofstream &filein);
    void printAll(std::ofstream &filein, int, int, int, float, float, float, float, float, float);

    void insertEnd(PICKUPQueueNode *temp, PICKUPQueueNode *toinsert);
    
private:
    PICKUPQueueNode *head, *tail;
};

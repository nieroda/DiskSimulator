#include<iostream>

#include "Queue.hpp"
#include "FCFSQueueNode.hpp"
#include <fstream>

class Request;

class FCFSQueue: public Queue {

public:
    FCFSQueue(): head(nullptr), tail(nullptr) {}

    virtual void addRequest(Request *request);

    virtual Request *getRequest();
    virtual bool isEmpty();
    virtual ~FCFSQueue();
    
    virtual void print();
    void calculate(FCFSQueueNode*, int, int&, float, int, int, int&, int&, float&, float&, float&, float&, float&, float&);
    float getServ(int, int, int, int&);
    int getTrack(int x, int y);
    int differenceSector(int x, int y);
    void printHead(std::ofstream &filein);
    void printAll(std::ofstream &filein, int, int, int, float, float, float, float, float, float);

private:
    FCFSQueueNode *head, *tail;
};

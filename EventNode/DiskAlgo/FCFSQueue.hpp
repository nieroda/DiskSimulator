#include<iostream>

#include "WaitQueue.hpp"
#include "FCFSQueueNode.hpp"
#include <fstream>

class Request;

class FCFSQueue: public WaitQueue {

public:
    FCFSQueue(): head(nullptr), tail(nullptr), length(0) {}

    virtual void addRequest(Request *request);
    virtual Request *getRequest();
    virtual bool isEmpty();
    virtual ~FCFSQueue();
    void print();
    
    virtual void deleteFirst();
    virtual int queueLength();


private:
    FCFSQueueNode *head, *tail;
    int length;
};

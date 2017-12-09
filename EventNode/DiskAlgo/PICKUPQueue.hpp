#include<iostream>

#include "WaitQueue.hpp"
#include "PICKUPQueueNode.hpp"

class Request;

class PICKUPQueue: public WaitQueue {

public:
    PICKUPQueue(): head(nullptr), tail(nullptr), length(0) {}

    virtual void addRequest(Request *request);

    virtual Request *getRequest();
    virtual bool isEmpty();
    virtual void print(); 
    virtual ~PICKUPQueue();
    
    virtual void deleteFirst();
    virtual int queueLength();
    
    void insertEnd(PICKUPQueueNode *temp, PICKUPQueueNode *toinsert);

    
private:
    PICKUPQueueNode *head, *tail;
    int length;
};

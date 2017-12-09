#include<iostream>

#include "WaitQueue.hpp"
#include "LOOKQueueNode.hpp"

class Request;

class LOOKQueue: public WaitQueue {

public:
    LOOKQueue(): head(nullptr), tail(nullptr), length(0) {}

    virtual void addRequest(Request *request);

    virtual Request *getRequest();
    virtual bool isEmpty();
    virtual void print(); 
    virtual ~LOOKQueue();

    virtual void deleteFirst();
    virtual int queueLength();
    
    void insertEnd(LOOKQueueNode *temp, LOOKQueueNode *toinsert);


private:
    LOOKQueueNode *head, *tail;
    int length;
};

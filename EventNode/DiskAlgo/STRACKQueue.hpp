#include<iostream>

#include "WaitQueue.hpp"
#include "STRACKQueueNode.hpp"

class Request;

class STRACKQueue: public WaitQueue {

public:
    STRACKQueue(): head(nullptr), tail(nullptr), length(0) {}

    virtual void addRequest(Request *request);

    virtual Request *getRequest();
    virtual bool isEmpty();
    virtual void print(); 
    virtual ~STRACKQueue();
    
    virtual void deleteFirst();
    virtual int queueLength();
    
    void insertEnd(STRACKQueueNode *temp, STRACKQueueNode *toinsert);


private:
    STRACKQueueNode *head, *tail;
    int length;
};

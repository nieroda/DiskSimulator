#include<iostream>

#include "WaitQueue.hpp"
#include "CLOOKQueueNode.hpp"
#include <fstream>

class Request;

class CLOOKQueue: public WaitQueue {

public:
    CLOOKQueue(): head(nullptr), tail(nullptr), length(0) {}

    virtual void addRequest(Request *request);

    virtual Request *getRequest();
    virtual bool isEmpty();
    virtual void print(); 
    virtual ~CLOOKQueue();
    
    virtual void deleteFirst();
    virtual int queueLength();
    
    void insertEnd(CLOOKQueueNode *temp, CLOOKQueueNode *toinsert);


private:
    CLOOKQueueNode *head, *tail;
    int length;
};

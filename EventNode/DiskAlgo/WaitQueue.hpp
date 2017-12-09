#ifndef _waitqueue_
#define _waitqueue_

class Request;

class WaitQueue {
public:
    virtual int queueLength() = 0;
    virtual void addRequest(Request *) = 0;
    virtual Request *getRequest() = 0;
    virtual bool isEmpty() = 0;
    virtual void deleteFirst() = 0;
    virtual void print() = 0;
    
};

#endif

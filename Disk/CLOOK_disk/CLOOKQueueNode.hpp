
#ifndef __CLOOKQueueNode_hpp
#define __CLOOKQueueNode_hpp

class Request;

class CLOOKQueueNode {
public:
    CLOOKQueueNode(Request *req, CLOOKQueueNode *nextPtr);
    CLOOKQueueNode(Request *req);
    CLOOKQueueNode *next();
    void next(CLOOKQueueNode *node);
    Request *request();

private:
    CLOOKQueueNode *_next;
    Request *_request;
};

#endif

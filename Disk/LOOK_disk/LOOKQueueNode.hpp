
#ifndef __LOOKQueueNode_hpp
#define __LOOKQueueNode_hpp

class Request;

class LOOKQueueNode {
public:
    LOOKQueueNode(Request *req, LOOKQueueNode *nextPtr);
    LOOKQueueNode(Request *req);
    LOOKQueueNode *next();
    void next(LOOKQueueNode *node);
    Request *request();

private:
    LOOKQueueNode *_next;
    Request *_request;
};

#endif

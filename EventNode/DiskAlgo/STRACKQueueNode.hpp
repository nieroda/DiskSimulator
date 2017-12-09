
#ifndef __STRACKQueueNode_hpp
#define __STRACKQueueNode_hpp

class Request;

class STRACKQueueNode {
public:
    STRACKQueueNode(Request *req, STRACKQueueNode *nextPtr);
    STRACKQueueNode(Request *req);
    STRACKQueueNode *next();
    void next(STRACKQueueNode *node);
    Request *request();

private:
    STRACKQueueNode *_next;
    Request *_request;
};

#endif


#ifndef __PICKUPQueueNode_hpp
#define __PICKUPQueueNode_hpp

class Request;

class PICKUPQueueNode {
public:
    PICKUPQueueNode(Request *req, PICKUPQueueNode *nextPtr);
    PICKUPQueueNode(Request *req);
    PICKUPQueueNode *next();
    void next(PICKUPQueueNode *node);
    Request *request();

private:
    PICKUPQueueNode *_next;
    Request *_request;
};

#endif

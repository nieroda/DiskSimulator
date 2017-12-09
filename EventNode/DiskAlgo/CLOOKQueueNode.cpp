
class Request;
#include "CLOOKQueueNode.hpp"

CLOOKQueueNode::CLOOKQueueNode(Request *req, CLOOKQueueNode *nextPtr): _request(req), _next(nextPtr) {}
CLOOKQueueNode::CLOOKQueueNode(Request *req): _request(req), _next(nullptr) {}
CLOOKQueueNode *CLOOKQueueNode::next() { 
    return _next; 
}

void CLOOKQueueNode::next(CLOOKQueueNode *node) { 
    _next = node; 
}

Request *CLOOKQueueNode::request() { 
    return _request; 
}

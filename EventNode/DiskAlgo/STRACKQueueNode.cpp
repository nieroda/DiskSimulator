
class Request;
#include "STRACKQueueNode.hpp"

STRACKQueueNode::STRACKQueueNode(Request *req, STRACKQueueNode *nextPtr): _request(req), _next(nextPtr) {}
STRACKQueueNode::STRACKQueueNode(Request *req): _request(req), _next(nullptr) {}
STRACKQueueNode *STRACKQueueNode::next() { 
    return _next; 
}

void STRACKQueueNode::next(STRACKQueueNode *node) { 
    _next = node; 
}

Request *STRACKQueueNode::request() { 
    return _request; 
}

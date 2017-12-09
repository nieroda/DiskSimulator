
class Request;
#include "LOOKQueueNode.hpp"

LOOKQueueNode::LOOKQueueNode(Request *req, LOOKQueueNode *nextPtr): _request(req), _next(nextPtr) {}
LOOKQueueNode::LOOKQueueNode(Request *req): _request(req), _next(nullptr) {}
LOOKQueueNode *LOOKQueueNode::next() { 
    return _next; 
}

void LOOKQueueNode::next(LOOKQueueNode *node) { 
    _next = node; 
}

Request *LOOKQueueNode::request() { 
    return _request; 
}

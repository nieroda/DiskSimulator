
class Request;
#include "PICKUPQueueNode.hpp"

PICKUPQueueNode::PICKUPQueueNode(Request *req, PICKUPQueueNode *nextPtr): _request(req), _next(nextPtr) {}
PICKUPQueueNode::PICKUPQueueNode(Request *req): _request(req), _next(nullptr) {}
PICKUPQueueNode *PICKUPQueueNode::next() { 
    return _next; 
}

void PICKUPQueueNode::next(PICKUPQueueNode *node) { 
    _next = node; 
}

Request *PICKUPQueueNode::request() { 
    return _request; 
}

#include "FCFSQueue.hpp"
#include "Request.hpp"
#include <iomanip>
#include <fstream>


//fcfs
void FCFSQueue::addRequest(Request *request) {
    length++;
    FCFSQueueNode *rNode = new FCFSQueueNode(request);
    if( isEmpty() ) {
        head = tail = rNode;
    } else {
        tail->next(rNode);
        tail = rNode;
    }
}

Request *FCFSQueue::getRequest() {


    if( isEmpty() ) {
        //std::cout << "Calling FCFSQueueNode::getRequest() on empty queue. Terminating...\n";
        //exit(1);
        return nullptr;
    }
    return head->request();
}

void FCFSQueue::deleteFirst() {
    if( isEmpty() ) { return; }
    length--;
    Request *tempRequest = head->request();
    FCFSQueueNode *toDelete = head;
    head = head->next();
    delete toDelete; //dont I have to do this to deallocate?

}

int FCFSQueue::queueLength() {
    return length;
}

bool FCFSQueue::isEmpty() { 
    return head == nullptr; 
}

void FCFSQueue::print() {
    FCFSQueueNode *temp = head;
    while(temp->next()) {
        std::cout << temp->request()->track() << std::endl;
        temp = temp->next();
    }
}

FCFSQueue::~FCFSQueue() {
    while( head != nullptr ) {
        FCFSQueueNode *node = head;
        head = node->next();
        delete node;
    }        
}


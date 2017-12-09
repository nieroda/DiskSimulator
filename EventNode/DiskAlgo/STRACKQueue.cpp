#include "STRACKQueue.hpp"
#include "Request.hpp"
#include <iomanip>
#include <fstream>

//strack
void STRACKQueue::addRequest(Request *request) {
    length++;
    STRACKQueueNode *rNode = new STRACKQueueNode(request);
    if( isEmpty() ) {
        head = tail = rNode;
    } else {
        STRACKQueueNode *temp = head;
        while(temp) {
            if (temp->request()->track() == request->track()) {
                //temp->next() == nullptr ? rNode->next(nullptr) : rNode->next(temp->next());
                //temp->next(rNode);
                //return;
                return insertEnd(temp, rNode);
            }
            temp = temp->next();
        }
        tail->next(rNode);
        tail = rNode;
        tail->next(nullptr);
    }
}

void STRACKQueue::insertEnd(STRACKQueueNode *temp, STRACKQueueNode *rNode) {
    int val = rNode->request()->track();
    while (temp->next() != nullptr) {
        if (temp->next()->request()->track() == val)
            temp = temp->next();
        else {
            rNode->next(temp->next());
            temp->next(rNode);
            return;
        }
    }
    tail->next(rNode);
    tail = rNode;
    tail->next(nullptr);
}

Request *STRACKQueue::getRequest() {
    if( isEmpty() ) {
        //std::cout << "Calling STRACKQueueNode::getRequest() on empty queue. Terminating...\n";
        return nullptr;
    }
    return head->request();
}

void STRACKQueue::deleteFirst() {
    if( isEmpty() ) { return; }
    length--;
    Request *tempRequest = head->request();
    STRACKQueueNode *toDelete = head;
    head = head->next();
    delete toDelete; //dont I have to do this to deallocate?
    
}

int STRACKQueue::queueLength() {
    return length;
}

bool STRACKQueue::isEmpty() { 
    return head == nullptr; 
}


STRACKQueue::~STRACKQueue() {
    while( head != nullptr ) {
        STRACKQueueNode *node = head;
        head = node->next();
        delete node;
    }        
}


void STRACKQueue::print() {
    for ( auto cur = head; cur; cur = cur->next() ) {
        std::cout << "Track: " << cur->request()->track() << "\t Sector: " << cur->request()->sector() << std::endl;
    }
}

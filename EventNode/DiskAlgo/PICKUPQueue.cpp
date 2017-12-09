#include "PICKUPQueue.hpp"
#include "Request.hpp"
#include <iomanip>
#include <fstream>


//pickup
void PICKUPQueue::addRequest(Request *request) {
    length++;
    PICKUPQueueNode *rNode = new PICKUPQueueNode(request);
    if( isEmpty() ) {
        head = tail = rNode;
    } else {
        PICKUPQueueNode *temp = head;
        while(temp->next() != nullptr) {
            if (temp->request()->track() == request->track()) {
                //temp->next() == nullptr ? rNode->next(nullptr) : rNode->next(temp->next());
                //temp->next(rNode);
                //return;
                return insertEnd(temp, rNode);
            }
            if (temp->request()->track() > request->track() && temp->next()->request()->track() < request->track()
                || temp->request()->track() < request->track() && temp->next()->request()->track() > request->track() ){
                //rNode->next(temp->next());
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

void PICKUPQueue::insertEnd(PICKUPQueueNode *temp, PICKUPQueueNode *rNode) {
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

Request *PICKUPQueue::getRequest() {
    if( isEmpty() ) {
        //std::cout << "Calling PICKUPQueueNode::getRequest() on empty queue. Terminating...\n";
        //exit(1);
        return nullptr;
    }
    return head->request();
}

void PICKUPQueue::deleteFirst() {
    if( isEmpty() ) { return; }
    length--;
    Request *tempRequest = head->request();
    PICKUPQueueNode *toDelete = head;
    head = head->next();
    delete toDelete; //dont I have to do this to deallocate?
    
}

int PICKUPQueue::queueLength() {
    return length;
}

bool PICKUPQueue::isEmpty() { 
    return head == nullptr; 
}



PICKUPQueue::~PICKUPQueue() {
    while( head != nullptr ) {
        PICKUPQueueNode *node = head;
        head = node->next();
        delete node;
    }        
}


void PICKUPQueue::print() {
    for ( auto cur = head; cur; cur = cur->next() ) {
        std::cout << "Track: " << cur->request()->track() << "\t Sector: " << cur->request()->sector() << std::endl;
    }
}


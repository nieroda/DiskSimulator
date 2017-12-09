#include "LOOKQueue.hpp"
#include "Request.hpp"
#include <iomanip>
#include <fstream>
//LOOK
void LOOKQueue::addRequest(Request *request) {
    length++;
    LOOKQueueNode *rNode = new LOOKQueueNode(request);
    if( isEmpty() ) {
        head = tail = rNode;
    } else {
        LOOKQueueNode *temp = head;
        int first = temp->request()->track();
        int incomingtrack = request->track();
        bool forward = true;
        while(temp->next() != nullptr) {
            int currenttrack = temp->request()->track();
            if (currenttrack == incomingtrack) {
                //temp->next() == nullptr ? rNode->next(nullptr) : rNode->next(temp->next());
                //temp->next(rNode);
                //return;
                return insertEnd(temp, rNode);
            }
            if (incomingtrack < currenttrack)
                forward = false;
            
            if (forward) {
                if( (incomingtrack >= currenttrack && incomingtrack <= temp->next()->request()->track())
                   || incomingtrack >= currenttrack && temp->next()->request()->track() < first) {
                    //rNode->next(temp->next());
                    //temp->next(rNode);
                    //return;
                    return insertEnd(temp, rNode);
                }
            }
            else {
                if (incomingtrack <= currenttrack && incomingtrack >= temp->next()->request()->track()) {
                    //rNode->next(temp->next());
                    //temp->next(rNode);
                    //return;
                    return insertEnd(temp, rNode);
                }
            }
            

            

            temp = temp->next();
        }
        tail->next(rNode);
        tail = rNode;
        tail->next(nullptr);
    }
}

void LOOKQueue::insertEnd(LOOKQueueNode *temp, LOOKQueueNode *rNode) {
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

Request *LOOKQueue::getRequest() {
    if( isEmpty() ) {
        //std::cout << "Calling LOOKQueueNode::getRequest() on empty queue. Terminating...\n";
        //exit(1);
        return nullptr;
    }
    return head->request();
}

void LOOKQueue::deleteFirst() {
    if( isEmpty() ) { return; }
    length--;
    Request *tempRequest = head->request();
    LOOKQueueNode *toDelete = head;
    head = head->next();
    delete toDelete; //dont I have to do this to deallocate?
    
}

int LOOKQueue::queueLength() {
    return length;
}


bool LOOKQueue::isEmpty() { 
    return head == nullptr; 
}

LOOKQueue::~LOOKQueue() {
    while( head != nullptr ) {
        LOOKQueueNode *node = head;
        head = node->next();
        delete node;
    }        
}


void LOOKQueue::print() {
    for ( auto cur = head; cur; cur = cur->next() ) {
        std::cout << "Track: " << cur->request()->track() << "\t Sector: " << cur->request()->sector() << std::endl;
    }
}






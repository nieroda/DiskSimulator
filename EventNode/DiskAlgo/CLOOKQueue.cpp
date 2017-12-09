#include "CLOOKQueue.hpp"
#include "Request.hpp"
#include <iomanip>
#include <fstream>

//clook
void CLOOKQueue::addRequest(Request *request) {
    length++;
    CLOOKQueueNode *rNode = new CLOOKQueueNode(request);
    if( isEmpty() ) {
        head = tail = rNode;
    } else {
        //print();
        //std::cout << "Done!" << std::endl;
        CLOOKQueueNode *temp = head;
        int first = temp->request()->track();
        int incomingtrack = request->track();

        while(temp->next() != nullptr) {
            int currenttrack = temp->request()->track();
            int next = temp->next()->request()->track();
            if (currenttrack == incomingtrack) {
                //temp->next() == nullptr ? rNode->next(nullptr) : rNode->next(temp->next());
                //temp->next(rNode);
                //return;
                return insertEnd(temp, rNode);
            }
            

            if(incomingtrack > currenttrack && incomingtrack < next) {
                //rNode->next(temp->next());
                //temp->next(rNode);
                //return;
                return insertEnd(temp, rNode);
            }
            
            if (next < currenttrack && currenttrack > incomingtrack && next > incomingtrack) {
                //rNode->next(temp->next());
                //temp->next(rNode);
                //return;
                return insertEnd(temp, rNode);
            }
            
            if (currenttrack > next && incomingtrack > currenttrack && incomingtrack > next) {
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

void CLOOKQueue::insertEnd(CLOOKQueueNode *temp, CLOOKQueueNode *rNode) {
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


Request *CLOOKQueue::getRequest() {
    if( isEmpty() ) {
        //std::cout << "Calling CLOOKQueueNode::getRequest() on empty queue. Terminating...\n";
        return nullptr;
    }
    return head->request();
}

void CLOOKQueue::deleteFirst() {
    if( isEmpty() ) { return; }
    length--;
    Request *tempRequest = head->request();
    CLOOKQueueNode *toDelete = head;
    head = head->next();
    delete toDelete; //dont I have to do this to deallocate?
    
}

int CLOOKQueue::queueLength() {
    return length;
}

bool CLOOKQueue::isEmpty() { 
    return head == nullptr; 
}



CLOOKQueue::~CLOOKQueue() {
    while( head != nullptr ) {
        CLOOKQueueNode *node = head;
        head = node->next();
        delete node;
    }        
}


void CLOOKQueue::print() {
    for ( auto cur = head; cur; cur = cur->next() ) {
        std::cout << "Track: " << cur->request()->track() << "\t Sector: " << cur->request()->sector() << std::endl;
    }
}



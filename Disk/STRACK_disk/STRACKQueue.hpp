#include<iostream>

#include "Queue.hpp"
#include "STRACKQueueNode.hpp"

class Request;

class STRACKQueue: public Queue {

public:
    STRACKQueue(): head(nullptr), tail(nullptr) {}

    virtual void addRequest(Request *request);

    virtual Request *getRequest();
    virtual bool isEmpty();
    virtual void print(); 
    virtual ~STRACKQueue();
    
    void calculate(STRACKQueueNode*, int, int&, float, int, int, int&, int&, float&, float&, float&, float&, float&, float&);
    float getServ(int, int, int, int&);
    int getTrack(int x, int y);
    int differenceSector(int x, int y);
    void printHead(std::ofstream &filein);
    void printAll(std::ofstream &filein, int, int, int, float, float, float, float, float, float);

    void insertEnd(STRACKQueueNode *temp, STRACKQueueNode *toinsert);
    
private:
    STRACKQueueNode *head, *tail;
};

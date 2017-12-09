#include<iostream>

#include "Queue.hpp"
#include "LOOKQueueNode.hpp"

class Request;

class LOOKQueue: public Queue {

public:
    LOOKQueue(): head(nullptr), tail(nullptr) {}

    virtual void addRequest(Request *request);

    virtual Request *getRequest();
    virtual bool isEmpty();
    virtual void print(); 
    virtual ~LOOKQueue();

    void calculate(LOOKQueueNode*, int, int&, float, int, int, int&, int&, float&, float&, float&, float&, float&, float&);
    float getServ(int, int, int, int&);
    int getTrack(int x, int y);
    int differenceSector(int x, int y);
    void printHead(std::ofstream &filein);
    void printAll(std::ofstream &filein, int, int, int, float, float, float, float, float, float);
    
    void insertEnd(LOOKQueueNode *temp, LOOKQueueNode *toinsert);
private:
    LOOKQueueNode *head, *tail;
};

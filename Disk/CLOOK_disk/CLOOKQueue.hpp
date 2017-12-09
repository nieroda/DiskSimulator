#include<iostream>

#include "Queue.hpp"
#include "CLOOKQueueNode.hpp"
#include <fstream>

class Request;

class CLOOKQueue: public Queue {

public:
    CLOOKQueue(): head(nullptr), tail(nullptr) {}

    virtual void addRequest(Request *request);

    virtual Request *getRequest();
    virtual bool isEmpty();
    virtual void print(); 
    virtual ~CLOOKQueue();
    
    void calculate(CLOOKQueueNode*, int, int&, float, int, int, int&, int&, float&, float&, float&, float&, float&, float&);
    float getServ(int, int, int, int&);
    int getTrack(int x, int y);
    int differenceSector(int x, int y);
    void printHead(std::ofstream &filein);
    void printAll(std::ofstream &filein, int, int, int, float, float, float, float, float, float);

    void insertEnd(CLOOKQueueNode *temp, CLOOKQueueNode *toinsert);

private:
    CLOOKQueueNode *head, *tail;
};

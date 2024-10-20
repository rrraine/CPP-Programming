#include <iostream>

class Queue {

    public:

    virtual void enqueue(int num) = 0;
    virtual int dequeue() = 0;
    virtual int front() = 0;
    virtual int rear() = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual void printQueue() = 0;

};
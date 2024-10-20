#include <iostream>

class Deque {
    public:
  
    virtual void addFirst(int num) = 0;
    virtual void addLast(int num) = 0;
    virtual int removeFirst() = 0;
    virtual int removeLast() = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual void printQueue() = 0;
};
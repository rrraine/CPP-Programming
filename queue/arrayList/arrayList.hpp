#include <iostream>

class arrayList {
    public:

    virtual void addLast(int num) = 0;
    virtual int removeFirst() = 0;
    virtual int getSize() = 0;
    virtual int get(int pos) = 0;
    virtual bool isEmpty() = 0;
    virtual void printList() = 0;
};
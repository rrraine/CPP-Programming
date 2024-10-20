#include <iostream>

class List {

    public:

    virtual void addHead(int num) = 0;
    virtual void addLast(int num) = 0;
    virtual void addNum(int num) = 0;
    virtual int removeHead() = 0;
    virtual int removeLast() = 0;
    virtual int getSize() = 0;
    virtual int get(int pos) = 0;
    virtual void printList() = 0;

    virtual bool isEmpty() = 0;

};
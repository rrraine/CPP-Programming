// heap.hpp

#include <iostream>
using namespace std;

class Heap {

    public:

    virtual void add(int value) = 0;

    // Remove and return the minimum element in the heap
    virtual int removeMin() = 0;

    // Get the minimum element without removing it
    virtual int getMin() = 0;

    // Print the elements in the heap (for debugging purposes)
    virtual void print() = 0;
};
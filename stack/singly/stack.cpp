#include <iostream>
#include "node.h"
using namespace std;

class Stack{
    node* head;
    int size;

    public:
    Stack(){
        head = nullptr;
        size = 0;
    }

    void push(int num){
        node* n = new node(num);
        n->next = head;
    }
};
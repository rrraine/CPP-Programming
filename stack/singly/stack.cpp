#include <iostream>
#include "node.h"
using namespace std;

class Stack{

    node* head;
    node* tail;
    int size;

    public:
    Stack(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void push(int num){ 
        node* n = new node(num);
        n->next = head;
        head = n;
        size++;        
    }

    void pop(){

        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return;
        }

        node* temp = head;
        head = head->next;
        cout << temp->data << " popped from stack" << endl;
        delete temp;
        size--;
    }

    void peek(){
        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Top: " << head->data << endl;
    }


    bool isEmpty(){
        return head == nullptr;
    }

    bool isFull(){
        return false;
    }
};
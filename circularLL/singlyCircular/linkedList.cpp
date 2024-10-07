#include <iostream>
#include "node.h"
using namespace std;

class Linkedlist {
    int size;
    node* head;
    node* tail;

    public:
    Linkedlist(){
        head = tail = NULL;
        size = 0;
    }

    ~Linkedlist(){
        node* curr = head;
        do {
            node* temp = curr;
            curr = curr->next;
            delete temp;
            size--;
        } while (curr != head);
        size = 0;
    }

    void add(int num){

        node* n = new node;
        n->data = num;

        if (!head){
            head = n;
            tail = n;
            n->next = head;
        } else {
            tail->next = n;
            tail = n;
            n->next = head;
        }
        size++;

    }

    void rotate(){
        tail = head;
        head = head->next;    
    }
    void print(){
        node* curr = head;

        do {
            cout << curr->data;
            if (curr != tail){
                cout << " -> ";
            } else {
                cout << endl;
                break;
            }
            curr = curr->next;
        } while (curr != head);
    }

};
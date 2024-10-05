#include <iostream>
#include <cmath>
#include "node.h"
#include "list.h"
using namespace std;

class LinkedList : public List{
    int size;
    node* head;
    node* tail;

    public:

    void addNum(int num) {
        node* n = new node;
        n->data = num;
        if (size == 0){
            head = n;
            tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
        size++;
    }
    
    void addHead(int num) {
        addNum(num);
    }

    void addTail(int num) {
        addNum(num);
    }

    void addAt(int num, int pos) {

    }

    int remove(int num) {

    }

    int removeAt(int pos) {

    }

    void removeAll(int num) {

    }

    void get(){

    }
    void flip() {

    }

    void print() {
        cout << "Size: " << size << endl;

        node* curr = head;
        for (int i = 0; i < size; i++){
            if (curr != tail){
                cout << curr->data << " -> ";
            } else {
                cout << curr-> data;
            }
            curr = curr->next;
        }
    }
    
};
#include <iostream>
#include <cmath>
#include "node.h"
#include "list.h"
using namespace std;

class LinkedList : public List{

    int size;
    node* head;
    node* tail;

    void addBetween(node* prev, node* next, int num){
        node* n = new node;
        n->data = num;
        n->next = next;
        n->prev = prev;
        prev->next = n;
        next->prev = n;
        size++;
    }

    void removeNode(node* curr){

    }

    public:

    LinkedList(){
        size = 0;
        head = NULL;
        tail = NULL;
    }

    void addNum(int num) {
        if (!head){
            node* n = new node;
            n->data = num;
            head = tail = n;
            head->prev = NULL;
            tail->next = NULL;
        } else {
            node* n = new node;
            n->data = num;
            tail->next = n;
            n->prev = tail;
            tail = n;
            n->next = NULL;
        }
        size++;
    }

    void addHead(int num) {
        if (!head){
            addNum(num);
        } else {
            node* n = new node;
            n->data = num;
            n->next = head;
            n->prev = NULL;
            head = n;
            size++;
        }
    }

    void addTail(int num) {
        addNum(num);
    }

    // use addBetween
    void addAt(int num, int pos) {
        if (!head){
            return;
        }

        if (pos == 1){
            addHead(num);
            return;
        }

        if (pos > size){
            addTail(num);
            return;
        }

        node* curr = head;

        for (int i = 1; i < pos - 1;i++){
            curr = curr->next;
        }

        addBetween(curr, curr->next, num);
    }
     
    // use removeNode & return the position
    int remove(int num) {

        node* temp = NULL;


        if (head->data == num){
            temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            return 1;
        }

        int i = 2; // counter, 2 as we have checked the head
        node* curr = head;

        while (curr != NULL){
            if (curr->data == num){
                temp = curr;
                if (curr == tail){
                    tail = curr->prev;
                    tail->next = NULL;
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }

                delete temp;
                size--;

                if (size == 0){
                    head = NULL;
                    tail = NULL;
                }
            }
            i++;
            curr = curr->next;
        }
        
    }
     
    // use removeNode 
    int removeAt(int pos) {

    }
     
    int removeAll(int num) {

    }

    // only reassign pointers
    int retain(int num) {
        
    }

    // remove all elements outside the range
    int corner(int left, int right) {

    }
     

    int get(int pos) { // compare which is faster: from head or from tail

    }
     
    void print() {
        cout << "Size: " << size << endl;

        node* curr = head;

        cout << "From head: ";
        while(curr){
            cout << curr->data;
            if (curr != tail){
                cout << " <-> ";
            } else {
                cout << endl;
            }
            curr = curr->next;
        }

        cout << "From tail: ";
        curr = tail;
        while (curr){
            cout << curr->data;
            if (curr != head){
                cout << " <-> ";
            } else {
                cout << endl;
            }
            curr = curr->prev;
         }
        return;
    }
 
};
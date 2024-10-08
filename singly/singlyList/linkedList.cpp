#include <iostream>
#include <cmath>
#include "node.h"
#include "list.h"
using namespace std;

class LinkedList : public List{
    int size;
    node* head;
    node* tail;

    void addBetween(node* curr, node* next, int num){
        node* n = new node;
        n->data = num;
        n->next = next;
        curr->next = n;
        size++;
    }
    public:

    void addNum(int num) {
        node* n = new node;
        n->data = num;
       if (size == 0){
            head = tail = n;
       } else {
            tail->next = n;
            tail = n;
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
            head = n;
            size++;
        }

    }

    void addTail(int num) {
        addNum(num);
    }

    void addAt(int num, int pos) {
        if (pos == 1){
            addHead(num);
            return;
        }

        if (pos > size){
            addTail(num);
            return;
        }

        node* curr = head;

        for (int i = 1; i < pos -1 ; i++){
            curr = curr->next;
        }

        node* n = new node;
        n->data = num;
        n->next = curr->next;
        curr->next = n;
        size++;

    }

    int remove(int num) {
        if (!head){
            return -1;
        }

        if (head->data == num){
            node* temp = head;
            head = head->next;
            delete temp;
            return 1;
        }

        int i = 2;
        node* curr = head;

        while (curr != tail){
            if (curr->next->data == num){
                node* temp = curr->next;

                if (curr->next == tail){
                    tail = curr;
                    tail->next = NULL;
                } else {
                    curr->next = curr->next->next;
                }
                delete temp;
                size--;
                if (size == 0){
                    head = NULL;
                    tail = NULL;
                }
                return i;
            }
            i++;
            curr = curr->next;
        }
        return -1;
    }

    int removeAt(int pos) {
        int elem;
        if (!head){
            return -1;
        }

        node* temp = NULL;
        node* curr = head;

        if (pos == 1){
            temp = head;
            head = head->next;
            elem = temp->data;
            delete temp;
            size--;
            return elem;
        }
        
        for (int i = 1; i < pos - 1; i++){
            curr = curr->next;
        }

        curr->next = curr->next->next;
        elem = curr->next->data;
        return elem;
        
    }

    int removeAll(int num) {
         int count = 0;
        if (!head){
            return count;
        }
       
        node* temp = NULL;
        node* curr = head;

        if (head->data == num){
            temp = head;
            head = head->next;
            delete temp;
            size--;
            count++;
        }

        if (size == 0){
            tail = NULL;
            return count;
        }

        
        while (curr != NULL && curr->next != NULL){
            if (curr->next->data == num){
                temp = curr->next;
                curr->next = curr->next->next;
                if (temp == tail){
                    tail = curr;
                    tail->next = NULL;
                } 
                delete temp;
                size--;
                count++;

                if (size == 0){
                    head = NULL;
                    tail = NULL;
                    return count;
                }
            } else {
                curr = curr->next;
            }
            
        }
        return count;
    }

    int get(int pos){
        node* curr = head;

        for (int i = 1; i < pos - 1; i++){
            curr = curr->next;
        }     
        return curr->data;
    }

    void flip() {

    }

    void print() {
        cout << "Size: " << size << endl;

        node* curr = head;
        if (size == 0){
            cout << "Empty list" << endl;
        } else {
            while (curr){
                cout << curr->data;
                if (curr != tail){
                    cout << " -> ";
                } else {
                    cout << endl;
                    break;
                }
                curr = curr->next;
            }
        }

        
    }
    
};


/*

int remEl(int num){
        node* temp = NULL;
        int elem;
        if (head->data == num){
            temp = head;            
            elem = temp->data;
            head = head->next;
            size--;
            if (size == 0){
                tail = NULL;
            }
            delete temp;
            return elem;
        }

        node* curr = head;
        while (curr != NULL){
            if (curr->next->data == num){
                temp = curr->next;
                elem = temp->data;
                if (curr->next == tail){
                    tail = curr;
                    tail->next = NULL;
                } else {
                    curr->next = curr->next->next;
                }
                size--;
                delete temp;
                if (size == 0){
                    head = NULL;
                    tail = NULL;
                }
                return elem;
            }
            curr= curr->next;
        }
        return -1;
    }
 */
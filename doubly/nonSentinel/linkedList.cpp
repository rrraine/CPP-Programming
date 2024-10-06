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

    int removeNode(node* curr){
        int elem = curr->data;
        
        if (curr->prev != NULL){
            curr->prev->next = curr->next;
        }
        
        if (curr->next != NULL) {
            curr->next->prev = curr->prev;
        }
        delete curr;
        return elem;
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
                return i;
            }
            i++;
            curr = curr->next;
        }
        return -1;
        
    }
     
    // use removeNode & return the removed element
    int removeAt(int pos) {
       
        int removedElement;
        node* temp = NULL;

        if (pos == 1){
            temp = head;
            //removedElement = temp->data;
            head = temp->next;
            if (head != NULL){
                head->prev = NULL;
            } else {
                tail = NULL;
            }

           // delete temp;
            size--;
            return removeNode(temp);
        }

        if (pos == size){
            temp = tail;
           // removedElement = temp->data;
            tail = temp->prev;
            
            if (tail != NULL){
                tail->next = NULL;
            } else {
                head = NULL;
            }

            //delete temp;
            size--;
            return removeNode(temp);
        }

        node* curr = head;

        if (pos <= size / 2){
            curr = head;
            for (int i = 1; i < pos; i++){
                curr = curr->next;
            }
        } else {
            curr = tail;
            for (int i = size; i > pos; i--){
                curr = curr->prev;
            }
        }

        size--;
        //removedElement = curr->next->data;
        return removeNode(curr);;

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

        if (size == 0){
            cout << "Empty list!" << endl;
            return;
        } 

        node* curr = NULL;

        cout << "From head: ";

        while (curr){
            cout << curr->data;

            if (curr != tail){
                cout << " <-> ";
            } else {
                cout << endl;
                break;
            }
            curr = curr->next;
        }

        curr = tail;
        cout << "From tail: ";
        while(curr){
            cout << curr->data;

            if (curr != head){
                cout << " <-> ";
            } else {
                cout << endl;
                break;
            }
            curr = curr->prev;
        }

        
        return;    
    }
 
};
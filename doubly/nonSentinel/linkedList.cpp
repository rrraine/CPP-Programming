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
        node* n = new node;
        n->data = num;

        if (!head){
            n->prev = NULL;
            head = tail = n;
        } else {
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

        if (pos == size + 1){
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
        int count = 0;
        
        node* temp = NULL;
        node* curr = head;

        if (head->data == num){
            temp = head;
            head = curr->next;
            if (head != NULL){
                head->prev = NULL;
            } else {
                tail = NULL;
            }
            delete temp;
            size--;
            count++;
            curr = head;
        }

        if (size == 0){
            tail = NULL;
            return count;
        }

        

        while (curr != NULL) {
            if (curr->data == num) {
                node* temp = curr;
                curr->prev->next = curr->next; // Link previous to next

                if (curr->next != NULL) {
                    curr->next->prev = curr->prev; // Link next back to previous
                } else {
                    tail = curr->prev; // Update tail if we're removing the last node
                }

                curr = curr->next; // Move to the next node before deleting
                delete temp;
                size--;
                count++;
            } else {
                curr = curr->next; // Move to the next node
            }
        }
        return count;
    }

    // only reassign pointers
    int retain(int num) {
        return 0;
    }


    // remove all elements between left and right elements
    int corner(int left, int right) {

        // check if Left and Right are valid
        if (left < 0 || left > size || right < 0 || right > size){
            return -1;
        }

        // check if both left and right == 0, you have to remove all elements

         int removedElements = size - (left + right);

        if (left == 0 && right == 0){
            head = NULL;
            tail = NULL;
            removedElements = size;
            size = 0;          
        }

       
        size = left + right;

        if (left == 0){
            // if left is 0, move head to start of right position
            node* currRight = tail;
            for (int i = 1; i < right; i++){
                currRight = currRight->prev;
            }
            head = currRight;

        } else if (right == 0){
            // if right is 0, move tail to the end of left position
            node* currLeft = head;
            for (int i = 1; i < left; i++){
                currLeft = currLeft->next;
            }
            tail = currLeft;
        } else {
            // if both left and right are not 0
            // after moving two currNodes to the left and right positions
            // connect them after

            node* currRight = tail;
            for (int i = 1; i < right; i++){
                currRight = currRight->prev;
            }
          

            node* currLeft = head;
            for (int i = 1; i < left; i++){
                currLeft = currLeft->next;
            }
           
            currLeft->next = currRight;

            if (currRight != NULL){
                currRight->prev = currLeft;
            } else {
                tail = currLeft;
            }

            head = (left > 0) ? head : currRight;
        }
        return removedElements;
    }
     

    int get(int pos) { // compare which is faster: from head or from tail

        int count;

        if (pos);

    }
    void print() {
            node* curr;
            if (size == 0) {
                cout << "Empty" << endl;
            } else {
                cout << "From HEAD: ";
                curr = head;
                while (true) {
                    cout << curr->data;
                    if (curr != tail) {
                        cout << " -> ";
                    } else {
                        cout << endl;
                        break;
                    }
                    curr = curr->next;
                }
                cout << "From TAIL: ";
                curr = tail;
                while (true) {
                    cout << curr->data;
                    if (curr != head) {
                        cout << " <- ";
                    } else {
                        cout << endl;
                        break;
                    }
                    curr = curr->prev;
                }
            }
        }
    
};
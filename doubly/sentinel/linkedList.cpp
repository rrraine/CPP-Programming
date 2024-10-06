 #include <iostream>
 #include "list.h"
 #include "node.h"
using namespace std;

class LinkedList : public List {

    int size;
    node* head;
    node* tail;

    void addBetween (node* curr, node* prev, int num){
        node* n = new node;
        n->data = num;
        n->next = curr;
        n->prev = prev;
        prev->next = n;
        curr->prev = n;
        size++;
    }

    int removeNode(node* curr){
        int removeElement = curr->data;
        
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        size--;
        
        return removeElement;
    }

    public:

    LinkedList(){
        head = new node;
        tail = new node;
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    ~LinkedList(){
        node* curr = head->next;
        while(curr){
            node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        size = 0;
    }

    void addNum(int num) {
        node* n = new node;
        n->data = num;

        if (size == 0){
            head->next = n;
            n->prev = head;
            n->next = tail;
            tail->prev = n; 
        } else {
            n->next = tail;
            n->prev = tail->prev;
            tail->prev->next = n;
            tail->prev = n;
        }

        size++;
    }

    void addHead(int num) {
        node* n = new node;
        n->data = num;
        n->next = head->next;
        n->prev = head;
        head->next->prev = n;
        head->next = n;
        
    }

    void addTail(int num) {
        node* n = new node;
        n->data = num;
        n->next = tail;
        n->prev = tail->prev;
        tail->prev->next = n;
        tail->prev = n;
    }

    //use addBetween
    void addAt(int num, int pos) {
        if (pos == 1){
            addHead(num);
            return;
        }

        if (pos == size + 1){
            addTail(num);
            return;
        }

        node* curr = head->next;

        for (int i = 1; i < pos; i++){
            curr = curr->next;
        }

        addBetween(curr, curr->prev, num);
    } 

    //use removeNode
    int remove(int num) {
        if (size == 0){
            return -1;
        }

        node* curr = head->next;
        int i = 1;
        while(curr !=tail){
            if (curr->data == num){
                node* temp = curr;
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete temp;
                size--;
                return i;
            }
            i++;
            curr = curr->next;
        }
        return -1;
    } 
    
    //use removeNode && return the removed Element
    int removeAt(int pos) {
        if (size == 0){
            return -1;
        }

        int elem;

        node* curr = head->next;

        for (int i = 1; i < pos; i++){
            curr = curr->next;
        }

        return removeNode(curr);

    } 
    
    
    int removeAll(int num) {
        int count = 0;

        if (size == 0){
            return count;
        }

        node* curr = head->next;

        while (curr != tail){
            if (curr->data == num){
                node* temp = curr;
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete temp;
                size--;
                count++;
            } else {
                curr = curr->next;
            }
        }
        return count;
    }

    //only reassign pointers
    int retain(int num) {
        return 0;
    } 

    //remove all elements outside the range
    int corner(int left, int right) {
        return 0;
    } 

    int get(int pos) {
        return 0;
    } 
    
    //compare which is faster: from head or from tail
    void print() {
        cout << "Size: " << size << endl;

        if (size == 0) {
            cout << "Empty" << endl;
            return;
        } else {
            node* curr = head->next; 
            cout << "From HEAD: ";

            while (curr != tail) { 
                cout << curr->data; 
                curr = curr->next; 
                if (curr != tail) { 
                    cout << " <-> ";
                }
            }
            cout << endl; 

            curr = tail->prev; 
            cout << "From TAIL: ";

            while (curr != head) { 
                cout << curr->data; 
                curr = curr->prev; 
                if (curr != head) { 
                    cout << " <-> ";
                }
            }
            cout << endl; // End line after printing from TAIL
        }
    }


};
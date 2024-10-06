#include <iostream>
#include "node.h"
using namespace std;

class LinkedList {
    int size;
    node* head;
    node* tail;
    node* senior;
    
    node* addBetween( Person*p, node* pred, node* succ){
        node* n = new node;
        n->person = p;
        n->next = succ;
        n->prev = pred;
        pred->next = n;
        succ->prev = n;
        size++;
        return n;
    }

    void removeNode(node* curr){
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        if (curr == senior){
            senior = curr->prev;
        }
        delete curr;
        size--;
    }

    int char_request(char ch){
        int i;
        if (ch == 'B'){
            i = 1;
        } else if (ch == 'M'){
            i = 2;
        } else if (ch == 'C'){
            i = 3;
        } else if (ch == 'D'){
            i = 4;
        }
        return i;
    }
    public:

    LinkedList(){
        head = new node;
        tail = new node;
        head->next = tail;
        tail->prev = head;
        senior = head;
        size = 0;
    }

    ~LinkedList(){
        node* curr = head->next;
        while(curr != tail){
            node* temp = curr;
            curr = curr->next;
        }
        size = 0;
    }
    // if sentinel, use addBetween
	void add(Person* p) {
	    node* newN = new node;
	    newN->person = p;
	    node* curr = head;
	    bool isSenior = false;
	    
	    if (p->age >= 60){
	        senior = addBetween(p, senior, senior->next);
	   } else {
	        addBetween(p, tail->prev, tail);
	   }
	}

    // see this problem as removing the requests of the first person that has needed request
    // set the request to 0
    // do not remove the whole node unless all of its requests are served
    // check if all requests are 0 (we can take the sum of the array)
    Person* serveRequest(char ch){
        node* curr = head->next;  // use this as a counter while traversing the list
        Person* p = NULL;
        if (size == 0){
            return p;
        }
        int index = char_request(ch);
        // lets create a helper function to return the index of requests: 
        // how do we know which request to serve?
        /// how do we know if this person has this request? -> check the request array
        // can we create a function  that will return the index of the request?

        while (curr != tail){
            if (curr->person->requests[index] == 1){
                curr->person->requests[index] = 0;
                p = curr->person;
                if (curr->person->requestCount() == 0){
                    removeNode(curr);
                }
                break;
            }
            curr = curr->next;
        }
        return p;
    }

    Person* fastLane(){
        Person* p = NULL;
        node* curr = head->next;

        while (curr != tail){
            if (curr->person->requestCount() == 1){
                p = curr->person;
                removeNode(curr);
            }
            curr = curr->next;
        }
        return p;
    }

    void print(){
        int count = 0;
        cout << "Size: " << size << endl;

        cout << "From first: " << endl;

        node* curr = head->next;
        while (curr != tail){
            cout << ++count << ". ";
            curr->person->print_name();
            for (int i = 0; i < 4; i++){
                cout << curr->person->requests[i] << " ";
            }
            cout << endl;
            curr = curr->next;
        }

        cout << "From last: " << endl;
        curr = tail->prev;
        while (curr != head){
            cout << --count << ". ";
             curr->person->print_name();
            for (int i = 0; i < 4; i++){
                cout << curr->person->requests[i] << " ";
            }
            cout << endl;
            curr = curr->prev;
        }
    }

};
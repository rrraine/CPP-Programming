#include "node.h"

class LinkedList {
	node* head;
	node* tail;
	int size;


    node* addBetween(Person* p, node* pred, node* succ){
        node* n = new node;
        n->person = p;
        n->prev = pred;
        n->next = succ;
        pred->next = n;
        succ->prev = n;
        size++;
        return n;
    } 

    void swapNode(node* dest, node* src){
        if (dest->next == src){
            src->prev = dest->prev;
            dest->next = src->next;
            dest->prev = src;
            src->next = dest;

            src->next->prev = src;
            src->prev->next = src;

            dest->next->prev = dest;
            dest->prev->next = dest;
            return;
        } else if (dest->prev == src){
            src->next = dest->next;
            dest->prev = src->prev;
            src->prev = dest;
            dest->next = src;

            src->next->prev = src;
            src->prev->next = src;

            dest->next->prev = dest;
            dest->prev->next = dest;
            return;
        }

        node* temp = dest->next;
        dest->next = src->next;
        src->next = temp;

        temp = src->prev;
        src->prev = dest->prev;
        dest->prev = temp;

        src->next->prev = src;  
        src->prev->next = src;

        dest->next->prev = dest;
        dest->prev->next = dest;

    }

	public:
	LinkedList() {
		head = new node;
		tail = new node;
		head->next = tail;
		tail->prev = head;
		size = 0;
	}

	// TODO add a person
	void add(Person* p) {
        node* n = new node;
        n->person = p;
        
        addBetween(p, tail->prev, tail);
        
	}

	// TODO advance
	void advance(string name, int forward) {
            // advance the person bearing the name (either first or last name) by forwards unit.
            // if the units to move exceed the
       node* curr = head -> next;
        
       while (!(curr->person->firstName == name || curr->person->lastName == name)){
            curr = curr->next;
        }

        for (int i = forward; i > 0; i--){
            if (curr->prev == head){
                break;
            }
            swapNode(curr->prev, curr);
        }
	}


	// TODO delay
	void delay(string name, int back) {
        node* curr = head -> next;
        
       while (!(curr->person->firstName == name || curr->person->lastName == name)){
            curr = curr->next;
        }
        
        node* tobeSwapped = curr;

        for (int i = back; i > 0; i--){
            if (tobeSwapped->next == tail){
                break;
            }
            tobeSwapped = tobeSwapped->next;
            swapNode(tobeSwapped, curr);
        }
	}


	// TODO trade places
	void trade(string name1, string name2) {
        node* curr = head -> next;
        
       while (!(curr->person->firstName == name1 || curr->person->lastName == name2)){
            curr = curr->next;
        }
        
        node* tobeSwapped = head->next;

        while (!(tobeSwapped->person->firstName == name1 || tobeSwapped->person->lastName == name2)){
            tobeSwapped = tobeSwapped->next;
        }

        swapNode(tobeSwapped, curr);
	}

	// TODO serve the request
	Person* fastLane() {
	    return NULL;
	}

	// TODO print
	void print() {
		cout << "Counter: " << size << endl;
        node* curr = head->next;
        int ctr = 1;
        
		cout << "From First: " << endl;
        while (curr!= tail){
            cout << ctr++ << ". ";
            curr->person->print();
            curr = curr->next;
        }
        ctr = size;
        curr = curr->prev;
		cout << "From Last: " << endl;
        while (curr!= head){
            cout << ctr-- << ". ";
            curr->person->print();
            curr= curr->prev;
        }
	}
};
#include <iostream>
#include <cmath>
using namespace std;


struct node{
    int data;
    node* next;
    node* prev;
    node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// sentinels
class LinkedList{

    node* head;
    node* tail;
    int size;

    void addBetween(node* succ, node* pred, int num){
        node* n = new node(num);
        n->next = succ;
        n->prev = pred;
        succ->prev = n;
        pred->next = n;
        size++;

    }
    void removeNode(node* curr){
        node* temp = curr;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete temp;
        size--;
    }
    public:

    LinkedList(){
        head = new node(0);
        tail = new node(0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addHead(int num){
        node* n = new node(num);
        n->next = head->next;
        n->prev = head;
        head->next->prev = n;
        head->next = n;
       
        size++;     
    }

    void addTail(int num){
        node* n = new node(num);
        n->next = tail;
        n->prev = tail->prev;
        tail->prev->next = n;
        tail->prev = n;
        size++;
    }

    void addAt(int num, int pos){
        if (pos < 1 || pos > size){
            return;
        }

        node* n = new node(num);
        if (pos <= ceil(size / 2.0)){ // from head
            node* curr = head->next;
            for (int i = 1; i < pos; i++){
                curr = curr->next;
            }
            
            addBetween(curr, curr->prev, num);
            cout << "Added. Started traversing from HEAD" << endl;
        } else { // from tail
            node* curr = tail->prev;
            for (int i = size; i > pos; i--){
                curr = curr->prev;
            }
            addBetween(curr, curr->prev, num);
            cout << "Added. Started traversing from TAIL" << endl;
        }
    }

    void removeFirst(){
        removeNode(head->next);
    }

    void removeLast(){
        removeNode(tail->prev);
    }

    void reset(){
        node* curr = head->next;

        while (curr != tail){
            node* temp = curr;
            curr = curr->next;
            delete temp;
            size--;
        }

        delete head;
        delete tail;
        size = 0;
    }
    void print(){
        if (head == NULL && tail == NULL){
            cout << "No list created." << endl;
            return;
        }
        
        cout << "Size: " << size << endl;
        if (size == 0){
            cout << "Empty list" << endl;
            return;
        }
        node* curr = head->next;
        cout << "From head: ";
        while (curr != tail){
            cout << curr->data;
            curr = curr->next;
            if (curr != tail){
                cout << " -> ";
            } else {
                cout << endl;
                break;
            }
            
        }
    }

};

int main(){

    LinkedList* list = new LinkedList();
    char op; int num, pos;

    do {
        cout << "Enter op: ";
        cin >> op;

        switch(op){
            case 'h':
                cin >> num;
                list->addHead(num);
                break;
            case 't':
                cin >> num;
                list->addTail(num);
                break;
            case '@':
                cin >> num >> pos;
                list->addAt(num, pos);
                break;
            case 'p':
                list->print();
                break;
            case 'r':
                list->reset();
                break;
            case 'H':
                list->removeFirst();
                break;
            case 'T':
                list->removeLast();
                break;
            case 'x':
                cout << "Exiting and deleting the list";
                break;
            default:
                cout << "Invalid operation" << endl;
                break;
        }
    } while (op != 'x');
    return 0;
}






/*
 linked list with sentinels 
  implement methods: addHead(int num), addTail(int num), removeHead(),removeTail()
 reset() - reset ra nimong linked list imo i deallocate tanang nodes
 int getMiddle() imo i implement na dili ka mugamit sa size 
    if even ang total nodes sa list kay i return nimo ang average sa duha ka middle, if odd kay return ra nimong middle
void addAt() doubly with sentinels 
    access from head if pos <= ceil(size/2.0) nya tail if mas duol sa tail
*/
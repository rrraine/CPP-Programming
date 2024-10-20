 #include <iostream>
 #include "list.hpp"
 #include "node.hpp"
 using namespace std;

 class LinkedList : public List {

    int size;
    Node* head;
    Node* tail;

    public:

    LinkedList(){
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void addLast(int num){
        Node* newNode = new Node(num);
        if (isEmpty()){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->next = nullptr;
            tail= newNode;
        }
        size++;

    }

    int removeHead(){
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return temp->data;
    }

    int getSize(){
        return size;
    }

    int get(int pos){
        if (pos < 0 || pos >= size){
            cout << "Invalid position" << endl;
            return -1;
        }

        Node* curr = head;

        for (int i = 0; i < pos; i++){
            curr = curr->next;
        }

        return curr->data;
    }

    void printList(){
        Node* curr = head;
        while (curr != nullptr){
            cout << curr->data << " ";
            if (curr->next != nullptr){
                cout << "-> ";
            }
            curr = curr->next;
        }
        cout << endl;
    }

    bool isEmpty(){
        return size == 0;
    }

 };
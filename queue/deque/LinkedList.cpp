#include <iostream>
#include <cmath>
#include "node.hpp"
#include "list.hpp"
using namespace std;

class LinkedList : public List {

    Node* head;
    Node* tail;
    int size;

    public:

    LinkedList(){
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addHead(int num){
        Node* newNode = new Node(num);
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
        size++;
    }

    void addLast(int num){
         Node* newNode = new Node(num);
         newNode->next = tail;
         newNode->prev = tail->prev;
         tail->prev->next = newNode;
         tail->prev = newNode;
         size++;
    }

    void addNum(int num){
        Node* newNode = new Node(num);
        if (size == 0){
            head->next = newNode;
            newNode->prev = head;
            newNode->next = tail;
            tail->prev = newNode;
        } else {
            newNode->next = tail;
            newNode->prev = tail->prev;
            tail->prev->next = newNode;
            tail->prev = newNode;
        }
        size++;

    }

    int removeHead(){
        if (isEmpty()){
            cout << "List is empty" << endl;
            return -1;
        }
        Node* temp = head->next;
        int tempData = temp->data;
        head->next = temp->next;
        temp->next->prev = head;
        delete temp;
        size--;
        return tempData;
    }

    int removeLast(){
        if (isEmpty()){
            cout << "List is empty" << endl;
            return -1;
        }
        Node* temp = tail->prev;
        int tempData = temp->data;
        tail->prev = temp->prev;
        temp->prev->next = tail;
        delete temp;
        size--;
        return tempData;
    }

    int getSize(){
        return size;
    }

    int get(int pos){
        if (pos < 0 || pos >= size){
            cout << "Invalid position" << endl;
            return -1;
        }

        if (pos <= (size + 1) / 2){
            Node* curr = head->next;
            for (int i = 1; i <= pos; i++){
                curr = curr->next;
            }   
            return curr->data;
        } else {
            Node* curr = tail->prev;
            for (int i = size; i > pos; i--){
                curr = curr->prev;
            }
            return curr->data;
        }

    }

    void printList(){
        Node* curr = head->next;
        while (curr != tail){
            cout << curr->data << " ";
            if (curr->next != tail){
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
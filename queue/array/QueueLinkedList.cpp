#include <iostream>
#include "linkedList.cpp"
#include "queue.hpp"
using namespace std;

class QueueLinkedList : public Queue{

    LinkedList list;

    public:

    QueueLinkedList() {
        list = LinkedList();
    }

    void enqueue(int num){
        list.addLast(num);
    }

    int dequeue(){
        return list.removeHead();
    }

    int front(){
        return list.get(0);
    }

    int rear(){
        return list.get(list.getSize() - 1);    
    }

    int getSize(){
        return list.getSize();
    }

    bool isEmpty(){
        return list.getSize() == 0;
    }

    void printQueue(){
        return list.printList();
    }

    //QueueLinkedList() : list() {}

};
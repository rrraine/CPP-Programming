#include <iostream>
#include "queue.hpp"
#include "ArrayList.cpp"
using namespace std;

class QueueArrayList : public Queue{

    ArrayList list;
 
    public:

    QueueArrayList() {
        list = ArrayList();
    }

    void enqueue(int num){
        list.addLast(num);
    }

    int dequeue(){
        return list.removeFirst();
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
        return list.isEmpty();
    }

    void printQueue(){
        cout << "Queue: ";
        list.printList();
    }

};
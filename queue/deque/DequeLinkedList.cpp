#include <iostream>
#include "LinkedList.cpp"
#include "deque.hpp"
using namespace std;

class QueueDeque : public Deque{

    LinkedList list;

    public:

    QueueDeque() {
        list = LinkedList();
    }

    void addFirst(int num){
        list.addHead(num);
    }

    void addLast(int num){
        list.addLast(num);
    }

    int removeFirst(){
        return list.removeHead();
    }

    int removeLast(){
        return list.removeLast();
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

};
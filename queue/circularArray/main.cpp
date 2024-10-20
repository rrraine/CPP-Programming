#include <iostream>
using namespace std;


class List {
    public:
    virtual void addLast(int num) = 0;
    virtual int removeFirst() = 0;
    virtual int getFront() = 0;
    virtual int getRear() = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual void print() = 0;
};

class Array : public List {
    int size, capacity;
    int front, rear;
    int* arr;

    public:
    Array(){
        capacity = 5;
        arr = new int[capacity];
        size = 0;
        front = 0;
        rear = 0;
    }

    void addLast(int num) {
        if (size == capacity){
            cout << "Array is full" << endl;
            return;
        }

        arr[rear] = num;
        rear = (rear + 1) % capacity;
        size++;
    }

    ~Array(){
        delete[] arr;
    }
    int removeFirst() {
        if (isEmpty()){
            cout << "Array is empty" << endl;
            return -1;
        }

        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;

    }

    int getFront() {
         if (isEmpty()){
            cout << "Array is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()){
            cout << "Array is empty" << endl;
            return -1;
        }
        return arr[(rear - 1 + capacity) % capacity];
    }

    int getSize()  {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void print() {
        if (isEmpty()){
            cout << "Array is empty" << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i < size; i++){
            cout << arr[(front + i) % capacity] << " ";
        }

        cout << endl;
    }

    /*
         arr[(front + i) % capacity]
        elements: 4 5 1 2 3

        front = 3
        Iteration 0: array[(3 + 0) % 5] → array[3] → prints 4
        
        !!
        Front always points to the next element to be removed.
        Rear points to the next position for adding a new element (not the last added).
    */

};

class Queue{
    public:
    virtual void enqueue(int num) = 0;
    virtual int dequeue() = 0;
    virtual int peak() = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual void print() = 0;

};

class QueueCircularArray : public Queue{
    Array array;

    public:

    QueueCircularArray(){
        array = Array();
    }

    ~QueueCircularArray(){
        // delete array;
    }
    void enqueue(int num){
        array.addLast(num);
    }

    int dequeue(){
        return array.removeFirst();
    }

    int peak(){
        return array.getFront();
    }

    int getSize(){
        return array.getSize();
    }

    bool isEmpty(){
        return array.isEmpty();
    }

    void print(){
        array.print();
    }

};


int main(){

    QueueCircularArray queue = QueueCircularArray();
    int num; char op;

    do {
        cout << "Enter op: ";
        cin >> op;

        switch(op){
            case 'e': 
                cout << "Enter num: ";
                cin >> num;
                queue.enqueue(num);
                break;
            case 'd':
                if (queue.isEmpty()){
                    cout << "Queue is empty" << endl;
                    break;
                }
                cout << "Removed: " << queue.dequeue() << endl;
                break;
            case 'f':
                cout << "Front: " << queue.peak() << endl;
                break;
            case 'r':
                cout << "Rear: " << queue.peak() << endl;
                break;
            case 's':
                cout << "Size: " << queue.getSize() << endl;
                break;
            case 'p':
                queue.print();
                break;
        }
    } while (op != 'x');

    return 0;  
}
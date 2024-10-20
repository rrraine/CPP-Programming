#include <iostream>
#include <cmath>
#include "arrayList.hpp"
using namespace std;


class ArrayList : public arrayList {

    int size;
    int capacity; 
    int *array;
    public:

    ArrayList(){
        capacity = 5;
        size = 0;
        array = (int*)malloc(capacity * sizeof(int));
    }

    ArrayList(int capacity){
        this->capacity = capacity;
        size = 0;
        array = (int*)malloc(capacity * sizeof(int));
    }

    ~ArrayList(){
        free(array);
    }
    void deduceCapacity(){ // something wrong with deduceCapacity
        if (size <= (capacity * 2.0/3.0)){
            capacity = ceil(capacity * 0.80);
            if (capacity < 5){
                capacity = 5;
            }

            array = (int*)realloc(array, capacity * sizeof(int));
        }
        return;
    }

    void increaseCapacity(){
        capacity = ceil(capacity * 1.5);
        array = (int*)realloc(array, capacity * sizeof(int));
    }


    void addLast(int num){
        if (size == capacity){
            increaseCapacity();
        }

        array[size++] = num;
    }

    int removeFirst(){
        int temp = array[0];
        for (int i = 0; i < size - 1; i++){
            array[i] = array[i + 1];
        }
        size--;
        // deduceCapacity();
        return temp;
    }

    int get(int pos){
        if (pos < 0 || pos > size -1){ // pwede mag-try-catch
            cout << "Invalid position" << endl;
            return -1;
        }

        return array[pos];
    }
    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == capacity;
    }
    void printList(){
        if (isEmpty()){
            cout << "List is empty" << endl;
            return;
        }

        for (int i = 0; i < size; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }

};
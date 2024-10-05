#include <iostream>
#include "list.h"
using namespace std;

class ArrayList : public List {
    
    
    int array[5];
    // int size = sizeof(array) / sizeof(arr[0]);
    int size = 0;
    
    public: 
    
    void add (int num) {
        if (size >= 5){
            cout << "Array is full" << endl;
            return;
        }
        array[size++] = num;
    }
    
    void addAt(int num, int pos) {
        if (pos > size){
            cout << "the position is out of bounds" << endl;
            return;
        }
        
        for (int i = size; i > pos -1 ; i--){
            array[i] = array[i - 1]    ;
        }
        
        array[pos - 1] = num;
        size++;
        
        
    }
    
    int removed (int num) {
        int rem = -1;
        for (int i = 0; i < size; i++){
            if (array[i] == num){
                rem = i + 1;
                for (int j = i; j < size -1 ; j++){
                    array[j] = array[j+1];
                }
                size--;
               break;
            }
        }
        return rem;
    }
    
    int removeAt(int pos) {
        int rem = array[pos - 1];
        
        for (int i = pos-1; i < size; i++){ // shift elem from right to left
            array[i] = array[i+1];
        }
        size--;
        return rem;
    }
    
    int removeAll (int num) {
        int count = 0;
        for (int i = 0; i < size; i++){
            if (array[i] == num){
              for (int j = i; j < size -1; j++){
                  array[j] = array[j+ 1];
              }
              i--;
              size -= 1;
              count++;
            }
        }
        return count;
    }
    void plus(int term) {
        for (int i = 0; i < size; i++){
            array[i] += term;
        }
    }
    
    int summation() {
        int sum = 0;
        
        for (int i = 0; i < size; i++){
            sum += array[i];
        }
        return sum;
    }
    
    int get (int pos) {
        return array[pos - 1];
    }
    
    void flip() {
        cout << "Normal: ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout<< endl;
        
        cout << "Flipped: ";
        for (int i = size - 1; i >= 0; i--) {
            cout << array[i] << " ";
        }
        cout<< endl;
    }
    void print() {
        for (int i = 0; i < size; i++){
            cout << array[i] << " ";
        }
        cout<< endl;
    }
};
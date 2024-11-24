// arraylist.cpp
#include <iostream>
#include <cstdlib>
#include <string>
#include "array.hpp"
using namespace std;

class ArrayList : public List {
    int* array;
    int size;
    int capacity;

    void dynamic_add() {
        int new_size = capacity * 1.5;
        array = (int*) realloc(array, sizeof(int) * new_size);
        capacity = new_size;
    }

    void dynamic_deduce() {
        int new_size = capacity * 0.75;
        array = (int*) realloc(array, sizeof(int) * new_size);
        capacity = new_size;
    }

public:
    ArrayList() : capacity(5), size(0) {
        array = (int*) calloc(capacity, sizeof(int));
    }

    void add(int num) {
        if (size == capacity) dynamic_add();
        array[size++] = num;
    }

    int removeLast() {
        if (size > 0) {
            int last = array[--size];
            if (size <= capacity * 0.75) dynamic_deduce();
            return last;
        }
        return -1;  // Handle empty array
    }

    int removeFirst() {
        if (size > 0) {
            int first = array[0];
            for (int i = 0; i < size - 1; ++i) {
                array[i] = array[i + 1];
            }
            --size;
            if (size <= capacity * 0.75) dynamic_deduce();
            return first;
        }
        return -1;  // Handle empty array
    }

    int remove(int num) {
        for (int i = 0; i < size; ++i) {
            if (array[i] == num) {
                for (int j = i; j < size - 1; ++j) {
                    array[j] = array[j + 1];
                }
                --size;
                if (size <= capacity * 0.75) dynamic_deduce();
                return num;
            }
        }
        return -1;  // Element not found
    }

    int& get(int pos) {
        if (pos >= 0 && pos < size) return array[pos];
        throw out_of_range("Index out of bounds");
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    ~ArrayList() {
        free(array);
    }
};
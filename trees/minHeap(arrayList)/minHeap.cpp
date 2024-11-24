// minHeap.cpp
#include <iostream>
#include "arraylist.cpp"
#include "heap.hpp"
using namespace std;

class MinHeap : public Heap {
    ArrayList list;  // Use ArrayList for storage
    int size;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (list.get(index) < list.get(parent)) {
                swap(list.get(index), list.get(parent));
                index = parent;  // Update index to the parent’s index
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int leftChild, rightChild, smallest;
        while (index < size) {
            leftChild = 2 * index + 1;
            rightChild = 2 * index + 2;
            smallest = index;

            if (leftChild < size && list.get(leftChild) < list.get(smallest)) {
                smallest = leftChild;
            }

            if (rightChild < size && list.get(rightChild) < list.get(smallest)) {
                smallest = rightChild;
            }

            if (smallest != index) {
                swap(list.get(index), list.get(smallest));
                index = smallest;  // Move index down the tree
            } else {
                break;
            }
        }
    }

    void swap(int& index1, int& index2) {
        int temp = index1;
        index1 = index2;
        index2 = temp;
    }

public:
    MinHeap() : size(0) {}

    void add(int value) {
        list.add(value);
        size++;
        heapifyUp(size - 1);  // Correctly maintain min-heap property after insertion
    }

    int removeMin() {
        if (size == 0) return -1;  // Handle empty heap
        
        int minVal = list.get(0);
        list.get(0) = list.get(size - 1);
        size--;
        list.removeLast();  // Remove the last element
        heapifyDown(0);  // Correctly maintain min-heap property after removal

        return minVal;
    }

    int getMin() {
        if (size == 0) return -1;  // Handle empty heap
        return list.get(0);
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << list.get(i) << " ";
        }
        cout << endl;
    }
};
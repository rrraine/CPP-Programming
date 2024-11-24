// main.cpp

#include <iostream>
//#include "arraylist.cpp"
#include "minHeap.cpp"  
using namespace std;

int main() {
    MinHeap* heap = new MinHeap();  // Create a new MinHeap instance
    char op;
    int input;

    do {
        try {
            cout << "Op: ";
            cin >> op;
            switch (op) {
                case 'A': // Add value to the heap
                    cin >> input;
                    heap->add(input);
                    cout << input << " added to the heap" << endl;
                    break;
                case 'R': // Remove the minimum value from the heap
                    input = heap->removeMin();
                    if (input != -1) {
                        cout << input << " removed from the heap" << endl;
                    } else {
                        cout << "Heap is empty!" << endl;
                    }
                    break;
                case 'M': // Get the minimum value without removing it
                    input = heap->getMin();
                    if (input != -1) {
                        cout << "Minimum value: " << input << endl;
                    } else {
                        cout << "Heap is empty!" << endl;
                    }
                    break;
                case 'P': // Print the heap
                    cout << "Heap contents: ";
                    heap->print();
                    break;
                case 'x': // Exit
                    cout << "Exiting" << endl;
                    break;
                default:
                    cout << "Invalid operation" << endl;
            }
        } catch (exception& e) {
            cout << e.what() << endl;
        }
    } while (op != 'x');

    delete heap;  // Clean up heap memory
    return 0;
}

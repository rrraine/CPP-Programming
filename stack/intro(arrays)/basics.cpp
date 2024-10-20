#include <iostream>
using namespace std;

class Stack{
    int size; // size of array
    int top; // top element of stack
    int* arr; // array to store elements

    public: 
    Stack(int size){
        this->size = size; 
        arr = new int[size];
        top = -1; // it means it is empty
    }

    ~Stack(){
        delete[] arr;
    }


    void push(int num){
        if (isFull()){
            cout << "Stack is full" << endl;
            return;
        }
        arr[++top] = num;
        cout << num << " pushed to stack" << endl;
    }

    void pushPrint(int num){

        if (isFull()){
            cout << "Stack is full" << endl;
            return; 
        }
    
        arr[++top] = num;
    }

    int pop(){  
        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;
        }

        return arr[top--]; // return the top element and decrement top

    }

    int topEl(){
        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;  
        }

        return arr[top];
    }

    bool isEmpty(){
        return top == -1; // if top is -1, it means it is empty
    }

    bool isFull(){
        return top == size - 1; // if top is equal to size - 1, it means it is full

    }

    void printStack(){
        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return;
        }


        cout << "Stack: ";

        for (int i = 0; i <= top; i++){
            cout << arr[i] << " ";
        }
        cout << endl;

        /* 
        // using recursion to print elements
        
        int topElement = arr[top];
        pop();

        printStack();

        cout << topElement << " ";
        pushPrint(topElement);
        */
    }

    void reverseStack(){
        if (isEmpty()){
            return;
        }

        cout << "Revrerse Stack: ";

        for (int i = top; i >= 0; i--){
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // int sum(); // use for-loop to sum
};

int main(){
    Stack stack(10);

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top: " << stack.topEl() << endl;
    stack.printStack();
    stack.reverseStack();
    return 0;
}
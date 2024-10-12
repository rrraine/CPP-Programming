#include <iostream>
#include "stack.cpp"
using namespace std;

int main(){
    Stack stack = Stack();
    int num; char op;

    do {
        cout << "Enter op: ";
        cin >> op;

        switch(op){
            case 'p':
                cin >> num;
                stack.push(num);
                break;
            case 'o':
                stack.pop();
                break;
            case 't':
                stack.peek();
                break;
            case 'x':
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid operation" << endl;
                break;
        }

    } while (op != 'x');

    return 0;
}
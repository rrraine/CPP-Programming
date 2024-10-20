#include <iostream>
#include "DequeLinkedList.cpp"
using namespace std;

int main(){

    QueueDeque queue = QueueDeque();
    int num; char op;

    do {
        cout << "Enter op: ";
        cin >> op;

        switch(op){
            case 'f': 
                cout << "Enter num: ";
                cin >> num;
                queue.addFirst(num);
                break;
            case 'l':
                cout << "Enter num: ";
                cin >> num;
                queue.addLast(num);
                break;
            case 'r':
                if (queue.isEmpty()){
                    cout << "Queue is empty" << endl;
                    break;
                }
                cout << "Removed first: " << queue.removeFirst() << endl;
                break;
            case 't':
                if (queue.isEmpty()){
                    cout << "Queue is empty" << endl;
                    break;
                }
                cout << "Removed last: " << queue.removeLast() << endl;
                break;
            case 's':
                cout << "Size: " << queue.getSize() << endl;
                break;
            case 'p':
                queue.printQueue();
                break;
            case 'x':
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid op" << endl;
        }
    } while (op != 'x');
  

    return 0;
}
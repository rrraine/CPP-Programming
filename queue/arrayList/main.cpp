#include <iostream>
#include "QueueArrayList.cpp"
using namespace std;

int main(){

    QueueArrayList queue = QueueArrayList();
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
                cout << "Dequeued: " << queue.dequeue() << endl;
                break;
            case 'f':
                cout << "Front: " << queue.front() << endl;
                break;
            case 'r':
                cout << "Rear: " << queue.rear() << endl;
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
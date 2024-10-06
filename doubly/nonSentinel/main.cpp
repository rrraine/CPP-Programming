#include <iostream>
#include "linkedList.cpp"
using namespace std; 

int main(){
    List* list = new LinkedList();
    char op;
    int num, pos, elem;

    do {
        cout << "Enter op: ";
        cin >> op;

        switch (op)
        {
        case 'a':
            cin >> num;
            list->addNum(num);
            break;
        case 'h':
            cin >> num;
            list->addHead(num);
            break;
        case 't':
            cin >> num;
            list->addTail(num);
            break;
        case '@':
            cin >> num;
            cin >> pos;
            list->addAt(num, pos);
            break;
        case 'r':
            cin >> num;
            cout << "Removed " << num << " at position " << list->remove(num) << endl;
            break;
        case 'A':
            cin >> pos;
            cout << "Remove element: " << list->removeAt(pos) << endl;
            break;
        case 'R':
            cin >> num;
            cout << "Removed items: " << list->removeAll(num) << endl;
            break;
        case 'g':
            cin >> pos;
            elem = list->get(pos);
            cout << "Element: " << elem << endl;
            break;
        case 'T':
            cin >> num;
            cout << "Removed Element/s: " << list->retain(num) << endl;
            break;
        case 'c':
            int left, right;
            cin >> left >> right;
            cout << "Removed Element/s: " << list->corner(left, right) << endl;
            break;
        case 'p':
            list->print();
            break;    
         case 'x':
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid operation!" << endl;
            break;
        }
    } while (op != 'x');
    return 0;
}
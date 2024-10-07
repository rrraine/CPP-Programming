#include <iostream>
#include "linkedList.cpp"   
using namespace std;

int main(){
    Linkedlist* list = new Linkedlist();
    char op;
    int num;

    do {
        cout << "Enter op: ";
        cin >> op;

        switch (op)
        {
        case 'a':
            cin >> num;
            list->add(num);
            break;
        case 'r':
            list->rotate();
            break;
        case 'R':
            cin >> num;
            list->remove(num);
            break;
        case 'p':
            list->print();
            break;
        case 'x':
            delete list;
            cout << "Deleting the list and exiting..." << endl;
            break;        
        default:
            break;
        }
    } while (op != 'x');
    
    return 0;
}
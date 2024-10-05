#include <iostream>
#include "linkedList.cpp"
using namespace std;

int main(){
    List* list = new LinkedList();
    char op;
    int num, pos;

    do {
        cout << "Enter op: ";
        cin >> op;

        switch (op)
        {
        case 'a':
            cin >> num;
            list->addNum(num);
            break;
        case 'p':
            list->print();
            break;    
    
        default:
            cout << "Invalid operation!" << endl;
            break;
        }
    } while (op != 'x');
    return 0;
}
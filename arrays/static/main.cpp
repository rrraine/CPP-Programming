#include <iostream>
#include "arrayList.cpp"  
using namespace std;

int main(){
    List* list = new ArrayList();
    int num, pos;
    char op;
    
    do{
        
        cout << "Enter op: ";
        cin >> op;
       // cout << endl;
        
        switch(op){
            case 'a':
                cin >> num;
                list->add(num);
                break;
            case '@':
                cin >> num;
                cin >> pos;
                list->addAt(num, pos);
                break;
            case 'r':
                cin >> num;
                cout << "Position: " << list->removed(num) << endl;
                break;
            case 'R':
                cin >> pos;
                cout << "Removed element: " << list->removeAt(pos) << endl;
                break;
            case 'A':
                cin >> num;
                cout << "Number of removed items: " << list->removeAll(num) << endl;
                break;
            case '+':
                cin >> num;
                list->plus(num);
                break;
            case 'g':
                cin >> pos;
                cout << list->get(pos) << endl;
                break;
            case 's':
                cout << "Sum: " << list->summation() << endl;
                break;
            case 'f':
                list->flip();
                break;
            case 'p':
                list->print();
                break;
            case 'x':
                cout << "Exiting..." << endl;
                break;
        }
        
    } while (op != 'x');
    
    return 0;
}
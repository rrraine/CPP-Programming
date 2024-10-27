#include <iostream>
#include "binaryTree.cpp"
using namespace std;

int main(){
    BinaryTree tree;
    char op; int num;

    do {
        cout << "Enter op: ";
        cin >> op;

        switch(op){
            case 'a':
                cout << "Enter num: ";
                cin >> num;
                tree.addRoot(num);
                break;
            case 'b':
                cout << "Enter num: ";
                cin >> num;
                tree.addLeft(tree.getRoot(), num);
                break;
            case 'c':
                cout << "Enter num: ";
                cin >> num;
                tree.addRight(tree.getRoot(), num);
                break;
            case 'p':
                tree.print(tree.getRoot());
                cout << endl;
                break;
        }

    } while (op != 'x');
    return 0;

}
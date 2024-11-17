#include <iostream>
#include "binary.hpp"
#include "node.hpp"
#include "binarySearch.cpp" // Assuming the file with BinarySearchTree is named binarysearchtree.hpp
using namespace std;

int main() {
    BinarySearchTree* tree = new BinarySearchTree();
    char op;
    int input, ind;
    node* nodes[100] = {nullptr}; // Array to store nodes for referencing

    do {
        try {
            cout << "Op: ";
            cin >> op;
            switch (op) {
                case 'Q': // Add root
                    cin >> input;
                    tree->insertNode(input);
                    cout << input << " added to the tree" << endl;
                    break;
                case 'S': // Search for a node
                    cin >> input;
                    if (tree->searchNode(input) != -1) {
                        cout << input << " found in the tree" << endl;
                    } else {
                        cout << input << " not found in the tree" << endl;
                    }
                    break;
                case 'D': // Delete a node
                    cin >> input;
                    if (tree->deleteNode(tree->getRoot(), input) != nullptr) {
                        cout << input << " deleted from the tree" << endl;
                    } else {
                        cout << input << " not found in the tree" << endl;
                    }
                    break;
                case 'p': // Print tree
                    tree->print();
                    break;
                case 'e': // Preorder traversal
                    cout << "PREORDER: ";
                    tree->preOrderTraversal(tree->getRoot());
                    cout << endl;
                    break;
                case 'i': // Inorder traversal
                    cout << "INORDER: ";
                    tree->inOrderTraversal(tree->getRoot());
                    cout << endl;
                    break;
                case 'o': // Postorder traversal
                    cout << "POSTORDER: ";
                    tree->postOrderTraversal(tree->getRoot());
                    cout << endl;
                    break;
            /* case 'b': // Breadth-first traversal
                    cout << "BREADTH-FIRST: ";
                    tree->breadthFirstTraversal();
                    cout << endl;
                    break;
                */
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

    delete tree;
    return 0;
}

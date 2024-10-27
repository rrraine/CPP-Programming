#include <iostream>
#include "binaryTree.cpp" // Include your BinaryTree class implementation
using namespace std;

// Function to help find a node by its value (for traversal)
node* findNode(node* current, int value) {
    if (current == nullptr) return nullptr;
    if (current->data == value) return current;

    node* foundNode = findNode(current->left, value);
    if (foundNode) return foundNode;

    return findNode(current->right, value);
}

int main() {
    Binary* tree = new BinaryTree(); // Create an instance of BinaryTree
    char op; 
    int num;

    do {
        cout << "Enter op: ";
        cin >> op;

        switch (op) {
            case 'a':
                cout << "Enter number for root: ";
                cin >> num;
                tree->addRoot(num);
                break;
            case 'b': {
                cout << "Enter number to add to left of root: ";
                cin >> num;
                node* root = tree->getRoot();
                if (root) {
                    tree->addLeft(root, num);
                } else {
                    cout << "Tree is empty, please add a root first." << endl;
                }
                break;
            }
            case 'c': {
                cout << "Enter number to add to right of root: ";
                cin >> num;
                node* root = tree->getRoot();
                if (root) {
                    tree->addRight(root, num);
                } else {
                    cout << "Tree is empty, please add a root first." << endl;
                }
                break;
            }
            case 'd': {
                cout << "Enter parent node value to add a descendant to: ";
                int parentValue;
                cin >> parentValue;

                cout << "Enter number to add as a descendant: ";
                cin >> num;

                node* parentNode = findNode(tree->getRoot(), parentValue);
                if (parentNode) {
                    char childOp;
                    cout << "Choose child to add to (l: left child, r: right child): ";
                    cin >> childOp;

                    if (childOp == 'l') {
                        tree->addLeft(parentNode, num);
                    } else if (childOp == 'r') {
                        tree->addRight(parentNode, num);
                    } else {
                        cout << "Invalid choice for child position." << endl;
                    }
                } else {
                    cout << "Parent node not found." << endl;
                }
                break;
            }
            case 's': {
                node* root = tree->getRoot();
                if (root) {
                    // Check for null before accessing siblings
                    if (root->left) {
                        cout << "Sibling of left child: " << tree->sibling(root->left) << endl;
                    } else {
                        cout << "Left child does not exist." << endl;
                    }
                    if (root->right) {
                        cout << "Sibling of right child: " << tree->sibling(root->right) << endl;
                    } else {
                        cout << "Right child does not exist." << endl;
                    }
                } else {
                    cout << "Tree is empty." << endl;
                }
                break;
            }
            case 'r': {
                node* root = tree->getRoot();
                if (root) {
                    cout << "Removing root." << endl;
                    tree->remove(root); // This will change the root if it has children
                } else {
                    cout << "Tree is empty." << endl;
                }
                break;
            }

            /*
            case 't': {
                // Create two new BinaryTree instances
                BinaryTree* t1 = new BinaryTree();
                BinaryTree* t2 = new BinaryTree();
                t1->addRoot(10);
                t2->addRoot(20);
                
                // Get the root of the main tree
                node* root = tree->getRoot();
                if (root) {
                    tree->attach(root, t1, t2);
                    cout << "Attached two trees as children of root." << endl;
                } else {
                    cout << "Tree is empty." << endl;
                }
                break;
            }
            */
            case 'p':
                tree->print(tree->getRoot());
                cout << endl;
                break;
            case 'S': // Unified size case
                cout << "Size of the tree: " << tree->getSize() << endl;
                break;
            case 'x':
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid operation. Please try again." << endl;
        }

    } while (op != 'x');

    // Clean up dynamically allocated memory
    delete tree; // Ensure to delete your main tree to prevent memory leaks

    return 0;
}

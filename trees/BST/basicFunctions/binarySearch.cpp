#include <iostream>
#include <queue>
#include "node.hpp"
#include "binary.hpp"
using namespace std;

class BinarySearchTree : public Binary {
    int size;
    node* root;

    node* getMinRightSubtree(node* root){
        // root = root->right;
        while (root->left != nullptr){
            root = root->left;
        }
        return root;
    }

    public:

    BinarySearchTree(){
        size = 0;
        root = nullptr;
    }

    void insertNode(int data){ 
        // if empty
        if (root == nullptr){
            root = new node(data);
            root->parent = nullptr;
        } else {
            node* curr = root;
            node* parent = nullptr;

            while (curr != nullptr){
                parent = curr;
                if (data < curr->data){
                    curr = curr->left;
                } else if (data > curr->data){
                    curr = curr->right;
                } else {
                    curr->data = data;
                    return;
                }
            }
            node* new_node = new node(data);
            new_node->parent = parent;
            if (data < parent->data){
                parent->left = new_node;
            } else {
                parent->right = new_node;
            }
        }

    }

    node* deleteNode(node* root, int data){ 
        //  base case : empty
        if (root == nullptr){
            return root;
        }
        if (data < root->data){
            root->left = deleteNode(root->left, data);
        } else if (data > root->data){
            root->right = deleteNode(root->right, data);
        } else {
            // found the node to be deleted

            // case 1: no child
            if (root->left == nullptr && root->right == nullptr){
                node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr){
                // case 2: one child (left)
                node* temp = root->left;
                delete root;
                return temp;
            } else if (root->left == nullptr){
                // case 2: one child (right)
                node* temp = root->right;
                delete root;
                return temp;
            }

            // case 3: two children
            node* temp = getMinRightSubtree(root->right);
            root->data = temp->data;
            // root->value = temp->value;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    int searchNode(int data){ 
        node* curr = root;

        while (curr != nullptr){
            if (data < curr->data){
                curr = curr->left;
            } else if (data > curr->data){
                curr = curr->right;
            } else { // data == curr->data
                return curr->data;
            }
        }
        return -1;
    }

    void inOrderTraversal(node* root){
        if (root == nullptr){
            return;
        }

        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
       

    }

    void preOrderTraversal(node* root){
        if (root == nullptr){
            return;
        }

        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
        
    }

    void postOrderTraversal(node* root){
       if (root == nullptr){
           return;
       }

       postOrderTraversal(root->left);
       postOrderTraversal(root->right);
       cout << root->data << " ";

    }

    node* getRoot(){
        return root;
    }

    /*
    void breadthOrderTraversal(node* root){
        Queue* q = new Queue();

        q->enqueue(root);
        while (!q->isEmpty()){
            node* curr = q->dequeue();
            cout << curr->data << " ";
            if (curr->left != nullptr){
                q->enqueue(curr->left);
            }
            if (curr->right != nullptr){
                q->enqueue(curr->right);
            }
        }

    }
    */

    void print() {
		cout << "Size: " << size << endl;
		if (!root) {
			cout << "EMPTY" << endl;
			return;
		}
		node* curr = root;
		print_node("", root, false);
        cout << "Status: " << check_parent(root, NULL) << endl;
	}

	void print_node(string prefix, node* n, bool isLeft) {
		cout << prefix;
        cout << (isLeft ? "+--L: " : "+--R: " );
        cout << n->data << endl;
		if (n->left) {
			print_node(prefix + "|   ", n->left, true);
		}
		if (n->right) {
			print_node(prefix + "|   ", n->right, false);
		}
	}

    bool check_parent(node* curr, node* par) {
        if (!curr) {
            return true;
        }
        if (curr->parent != par) {
            cout << "Illegal parent of " << curr->data << ": " << curr->parent << " -- must be " << par << endl;
            return false;
        }
        return check_parent(curr->left, curr) && check_parent(curr->right, curr);
    }
};




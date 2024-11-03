#include <iostream>
#include "node.hpp"
#include "binary.hpp"
using namespace std;

class BinaryTree : public Binary {
    node* root;
    int size;


    node* getMinRightSubtree(node* curr){
        curr = curr->right;
        while (curr->left != nullptr){
            curr = curr->left;
        }
        return curr;
    }
    public: 

    BinaryTree(){
        root = new node();
        size = 0;
    }

    node* insertNode (node* root, int data){
        // if empty (base case)
        // pwede ka na rin mag constructor sa struct node

        if (root == nullptr){
            node* n = new node();
            n->data = data;
            n->left = nullptr;  
            n->right = nullptr;
            root = n;
            size++;
            return n;
        }

        // recur 
        if (data < root->data){
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }

        return root;
    }

    node* deleteNode (node* root, int data){
        // empty (base case)
        if (root == nullptr){
            return root;
        }

        // search for the node to be deleted
        if (root->data > data){
            root->left = deleteNode(root->left, data); // travese the left subtree
        } else if (root->data < data){
            root->right = deleteNode(root->right, data); // traverse the right subtree
        } else {
            // found the node to be deleted
            node* temp;
            // case 1: no child
            if (root->left == nullptr && root->right == nullptr){
                temp = root;
                delete root;
                root = nullptr;
                size--;
                return temp;
            }

            // case 2: one child
            if (root->left == nullptr){
                temp = root;
                root = root->right;
                delete temp;
                size--;
                return temp;
            } else if (root->right == nullptr){
                temp = root;
                root = root->left;
                delete temp;
                size--;
                return temp;
            }

            // case 3: two children
            // use a helper function to find the minimum value in the right subtree
               // why? because the minimum value in the right subtree is the next largest value, it will become the root if the root is deleted
            node* succ = getMinRightSubtree(root);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data); // delete the successor
        }
        return root;
    }

    node* searchNode(node* root, int data){
        // empty (base case)
        if (root == nullptr){
            return nullptr;
        }

        // found the node
        if (root->data == data){
            return root;
        }

        // recur
        if (data < root->data){
            return searchNode(root->left, data);
        } else {
            return searchNode(root->right, data);
        }

        // always search left subtree if data < root->data and viceversa
    }

    int inOrderTraversal(node* root){
        if (root == nullptr){
            return 0;
        }

        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);

    }

    void preOrderTraversal(node* root){

    }

    void postOrderTraversal(node* root){

    }

    int minimum(node* root){

    }

    int maximum(node* root){

    }

    
};
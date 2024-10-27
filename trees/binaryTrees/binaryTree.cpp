#include <iostream>
#include "node.hpp"
using namespace std;


class BinaryTree{

    int size;
    node* root;

    private:

    node* addNode(node* p, int num){
        node* n = new node;
        n->data = num;
        n->parent = p;
        n->left = NULL;
        n->right = NULL;
        size++;
        return n;

    }

    public:

    BinaryTree(){
        size = 0;
        root = NULL;
    }

    node* getRoot(){
        return root;
    }

    node* addRoot(int num){
      if (!root){
        root = addNode(nullptr, num);
        return root;
      }
      return nullptr;
    }

    node* addLeft(node*p, int num){
        if (!p->left){
            p->left = addNode(p, num);
            
        }
        return p->left;
    }
    node* addRight(node*p, int num){
        if (!p->right){
            p->right = addNode(p, num);
            
        }
        return p->right;
    }

     void print(node* n){
        if (root == NULL){
            cout << "Tree is empty" << endl;
            return;
        }

        if (n->left){
            print(n->left);
        }

        cout << n->data << " ";

        if (n->right){
            print(n->right);
        }

    }

    // void print(){
    //     cout << "Size: " << size << endl;
    //     printT(root);
    // }




};
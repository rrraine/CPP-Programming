#include <iostream>
#include "node.hpp"
using namespace std;


class Tree {

    int size;
    node* root;

    public:

    Tree(){
        size = 0;
        root = nullptr;
    }


    node* createNode(int value){
        node* n = new node;
        n->data = value;
        n->left = nullptr;
        n->right = nullptr;
        return n;
    }

    void* setRoot(int value){
        if (!root){
            root = createNode(value);
        }
    }

    void addChild(node* parent, int childValue){
        if(!parent){
            cout << "Parent is null" << endl;
            return;
        }
    }

};
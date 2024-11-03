#include <iostream>
#include "node.hpp"

class Binary {

    public:

    virtual node* insertNode (node* root, int data) = 0;
    virtual node* deleteNode (node* root, int data) = 0;
    virtual node* searchNode(node* root, int data) = 0;
    virtual int inOrderTraversal(node* root) = 0;
    virtual int preOrderTraversal(node* root) = 0;
    virtual int postOrderTraversal(node* root) = 0;
    virtual int minimum(node* root) = 0;
    virtual int maximum(node* root) = 0;

};
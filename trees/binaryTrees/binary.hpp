#include <iostream>
#include "node.hpp"

class Binary {
    public:

    virtual node* left (node* p) = 0;
    virtual node* right (node* p) = 0;
    virtual node* sibling(node* p) = 0;
    virtual void addRoot(int e) = 0;
    virtual void addLeft(node* p, int e) = 0;
    virtual void addRight(node* p, int e) = 0;
    virtual int set (node* p, int e) = 0;
    virtual void remove(node* p) = 0;
    //virtual void attach(node* p, BinaryTree t1, BinaryTree t2) = 0;

    virtual int getDepth(node *p) = 0;
    virtual int getHeight(node* p) = 0;

    virtual bool isDescendant(node* root, node* target) = 0;
    virtual bool isEdge(node* p, node* q) = 0;

    virtual int getSize() = 0;
    virtual void print(node* p) = 0;
    virtual node* getRoot() = 0;

};
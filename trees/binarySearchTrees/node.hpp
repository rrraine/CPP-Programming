#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;

    int depth(){
        int leftDepth = (left != nullptr) ? left->depth() : -1;
        int rightDepth = (right != nullptr) ? right->depth() : -1;
        return max(leftDepth, rightDepth) + 1;
    }

    int height(){
        
    }
};
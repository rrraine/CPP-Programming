#include <iostream>
#pragma once
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node* parent;

    node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
    
    int height(){

        int leftHeight = (left == nullptr) ? 0 : left->height();
        int rightHeight = (right == nullptr) ? 0 : right->height();  

        return 1 + max(left->height(), right->height());
    }

    int depth(){
        if (this == nullptr){
            return 0;
        }

        return 1 + parent->depth();

        // return (parent != nullptr) ? 1 + parent->depth() : 0;
    }

    int countNodes(){
        int leftCount = (left == nullptr) ? 0 : left->countNodes();
        int rightCount = (right == nullptr) ? 0 : right->countNodes();
        return 1 + leftCount + rightCount;
    }
};



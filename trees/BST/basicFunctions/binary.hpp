#pragma once

#include <iostream>
#include "node.hpp"
using namespace std;

class Binary{

    public:

    virtual void insertNode(int data) = 0;
    virtual node* deleteNode(node* root, int data) = 0;
    virtual int searchNode(int data) = 0;
};
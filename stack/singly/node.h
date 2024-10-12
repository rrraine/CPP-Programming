#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node(int value) : data(value), next(nullptr) {}
};

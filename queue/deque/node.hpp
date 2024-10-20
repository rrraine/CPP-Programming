#include <iostream>

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr){};
    Node() : data(), next(nullptr), prev(nullptr){};
};
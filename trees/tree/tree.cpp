#include <iostream>
#include "node.hpp"
using namespace std;

class Tree {
    int size;
    node* root;

public:
    Tree() {
        size = 0;
        root = nullptr;
    }

    void insert(int data) {
        node* newNode = new node;
        newNode->data = data;
        newNode->firstChild = nullptr;
        newNode->nextSibling = nullptr;

        if (root == nullptr) {
            root = newNode;
        } else {
            node* current = root;
            while (current->nextSibling != nullptr) {
                current = current->nextSibling;
            }
            current->nextSibling = newNode;
        }
        size++;
    }

    // Function to add a child to a specified node
    void addChild(node* parent, int childData) {
        node* child = new node;
        child->data = childData;
        child->firstChild = nullptr;
        child->nextSibling = nullptr;

        if (parent->firstChild == nullptr) {
            parent->firstChild = child;
        } else {
            node* sibling = parent->firstChild;
            while (sibling->nextSibling != nullptr) {
                sibling = sibling->nextSibling;
            }
            sibling->nextSibling = child;
        }
        size++;
    }

    // Function to calculate the depth of a node
    int getDepth(node* root, node* target, int depth = 0) {
        if (root == nullptr) return -1;
        if (root == target) return depth;

        int childDepth = getDepth(root->firstChild, target, depth + 1);
        if (childDepth != -1) return childDepth;

        return getDepth(root->nextSibling, target, depth);
    }

    // Function to calculate the height of a node
    int getHeight(node* target) {
        if (target == nullptr) return -1;

        int maxChildHeight = -1;
        node* child = target->firstChild;
        while (child != nullptr) {
            maxChildHeight = max(maxChildHeight, getHeight(child));
            child = child->nextSibling;
        }

        return maxChildHeight + 1;
    }

    // Helper function to find a node by data
    node* findNode(node* root, int data) {
        if (root == nullptr) return nullptr;
        if (root->data == data) return root;

        node* found = findNode(root->firstChild, data);
        if (found != nullptr) return found;

        return findNode(root->nextSibling, data);
    }

    // Function to check if a node is a descendant of another
    bool isDescendant(node* root, node* target) {
        if (root == nullptr) return false;
        if (root == target) return true;

        return isDescendant(root->firstChild, target) || isDescendant(root->nextSibling, target);
    }

    // Function to check if two nodes are siblings
    bool areSiblings(node* root, node* node1, node* node2) {
        if (root == nullptr) return false;

        node* child = root->firstChild;
        while (child != nullptr) {
            if (child == node1 || child == node2) {
                return (child == node1) ? isDescendant(child, node2) : isDescendant(child, node1);
            }
            child = child->nextSibling;
        }

        return false;
    }

    // Public interface for finding node by data
    node* find(int data) {
        return findNode(root, data);
    }

    // Public interface for calculating depth from the root
    int getDepth(int data) {
        node* target = findNode(root, data);
        return (target != nullptr) ? getDepth(root, target) : -1;
    }

    // Public interface for calculating height of a node with given data
    int getHeight(int data) {
        node* target = findNode(root, data);
        return (target != nullptr) ? getHeight(target) : -1;
    }
};

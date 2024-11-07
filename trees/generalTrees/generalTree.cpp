#include <iostream>
#include "node.hpp"
using namespace std;



class GeneralTree {
    int size;
    node* root;
    public:

    void resizeChildren(node* n){
        n->children = (node**)realloc(n->children,  sizeof(node*) * n->num_child);
    }

    GeneralTree() {
        size = 0;
        root = nullptr;
    }

    node* createNode(int elem){
        node* n = new node();
        n->num_child = 0;
        n->elem = elem;
        n->parent = nullptr;
        n->children = (node**)malloc(0);
        size++;
        return n;
    }

    node* addChild(node* p, int elem){
        node* n = createNode(elem);
        p->num_child++;
        resizeChildren(p);
        p->children[p->num_child - 1] = n;
        n->parent = p;
        return n;
    }
    void remove(node* n){
        if (n->num_child) {
            throw logic_error (to_string(n->num_child) + " has 2 children ");
        }

        if (n->parent){
            for (int i = 0; i < n->parent->num_child; i++){
                if (n->parent->children[i] == n){
                    for (int j = i + 1; j < n->parent->num_child; j++){
                        n->parent->children[j-1] = n->parent->children[j];
                    }
                    break;
                }
            }
        } else {
            root = nullptr;
        }

        delete n;
        size--;
    }


};
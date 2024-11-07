#include <iostream>
#include <cstdlib>

struct node{
    node **children;
    int num_child;
    node* parent;
    int elem;

    int depth(){
        if (parent == nullptr) return 0;
        return parent->depth() + 1;
    }

    int height(){
        if (num_child == 0) return 0;
        int max_height = 0;
        for (int i = 0; i < num_child; i++){
            int h = children[i]->height();
            if (h > max_height){
                max_height = h;
            } 
        }
        return max_height + 1;
    }
};
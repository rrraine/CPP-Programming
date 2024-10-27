#include <iostream>
#include "node.hpp"
#include "binary.hpp"
using namespace std;


class BinaryTree : public Binary{
 
    int size;
    node* root;

    private:

    node* addNode(node* p, int num){
        node* n = new node;
        n->data = num;
        n->parent = p;
        n->left = NULL;
        n->right = NULL;
        size++;
        return n;

    }

    public:

    BinaryTree(){
        size = 0;
        root = NULL;
    }


    // Returns the position of the left child of p (or null if p has no left child).
    node* left (node* p){
        if (p->left != NULL){
            return p->left;
        }
        return NULL;
    }

    // Returns the position of the right child of p (or null if p has no right child).
    node* right (node* p){
        if (p->right != NULL){
            return p->right;
        }
        return NULL;
    }

    // Returns the position of the sibling of p (or null if p has no sibling).
    node* sibling(node* p){
        if (p->parent == NULL) return NULL;
        if (p->parent->left == p){
            return p->parent->right;
        } else {
            return p->parent->left;
        }
      return NULL;

    }

    // Creates a root for an empty tree, storing e as the element, and returns the position of that root; 
    // an error occurs if the tree is not empty
    void addRoot(int e){
        if (root != NULL){
            cout << "Tree is not empty" << endl;
            return;
        }
        root = addNode(NULL, e);
        size++;

    }

    // Creates a left child of position p, storing element e, and returns the position of the new node; 
    // an error occurs if p already has a left child.
    void addLeft(node* p, int e){
        if (p->left != NULL){
            cout << "Node already has a left child" << endl;
            return;
        }
        p->left = addNode(p, e);
        size++;
    }

    // Creates a right child of position p, storing element e, and returns the position of the new node; 
    // an error occurs if p already has a right child
    void addRight(node* p, int e){
        if (p->right != NULL){
            cout << "Node already has a right child" << endl;
            return;
        }
        p->right = addNode(p, e);
        size++;
    }

    // Replaces the element stored at position p with element e, and returns the previously stored element. 
    int set (node* p, int e){
        int prevData = p->data;
        p->data = e;
        return prevData;
    }

    // Removes the node at position p, replacing it with its child (if any), 
    // and returns the element that had been stored at p. 
    //An error occurs if p has two children.
    void remove(node* p){
        if (p->left != NULL && p->right != NULL){
            cout << "Node has two children" << endl;
            return;
        }
        node* temp = p;
        p = p->left != NULL ? p->left : p->right;

        if (temp->parent != NULL){
            if (temp->parent->left == temp){
                temp->parent->left = p;
            } else {
                temp->parent->right = p;
            }
        } else {
            root = p;
        }

        if (p != NULL){
            p->parent = temp->parent;
        }
        delete temp;
        size--;
    }

    // Attaches the internal structure of trees T1 and T2 as the respective left and right subtrees of leaf position p and resets T1 and T2 to empty trees;
    //  an error condition occurs if p is not a leaf
    /*
    void attach(node* p, BinaryTree t1, BinaryTree t2){
        if (p->left != NULL || p->right != NULL){
            cout << "Node is not a leaf" << endl;
            return;
        }
        p->left = t1.root;
        p->right = t2.root;
        if (t1.root != NULL){
            t1.root = p;
            t1.root->parent = p;
        }
        if (t2.root != NULL){
            t2.root = p;
            t1.root->parent = p;
        }

        t1.root = NULL;
        t2.root = NULL;
        //size += t1->getSize() + t2->getSize();
        
    }
    */

   // distance from the root to the node
    int getDepth(node *p){
        if (p == NULL){ // root
            return 0;
        }

        int depth = 0;
        while (p != root){
            p = p->parent;
            depth++;
        }
        return depth;
    }
    
    // distance from the node to the deepest leaf
    int getHeight(node* p){
        if (p == NULL){ // root case
            return 0;
        }

        int leftHeight = getHeight(p->left);
        int rightHeight = getHeight(p->right);

        return max(leftHeight, rightHeight) + 1;
    }
    

    bool isDescendant(node* root, node* target){
        if (root == NULL || target == NULL){
            return false;
        }
        while (target != NULL){
            if (target == root){
                return true;
            }
            target = target->parent;
        }
        return false;
    }
    
    bool isEdge(node* p, node* q){
        if (p == NULL || q == NULL){
            return false;
        }

        return (p->left == q || p->right == q || q->left == p || q->right == p);
    }
    







    // Prints the tree in inorder traversal
     void print(node* n){
        if (root == NULL){
            cout << "Tree is empty" << endl;
            return;
        }

        if (n->left){
            print(n->left);
        }

        cout << n->data << " ";

        if (n->right){
            print(n->right);
        }

    }

    // Returns the size of the tree
    int getSize(){
        return size;
    }

    node *getRoot(){
        return root;
    }
};
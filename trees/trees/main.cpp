#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode {
    string data;
    TreeNode* firstChild;
    TreeNode* nextSibling;

    TreeNode(const string& val) : data(val), firstChild(nullptr), nextSibling(nullptr) {}
};

// Function to add a child to a node
void addChild(TreeNode* parent, const string& childData) {
    TreeNode* child = new TreeNode(childData);
    if (parent->firstChild == nullptr) {
        parent->firstChild = child;
    } else {
        TreeNode* sibling = parent->firstChild;
        while (sibling->nextSibling != nullptr) {
            sibling = sibling->nextSibling;
        }
        sibling->nextSibling = child;
    }
}

// Function to find a node by data
TreeNode* findNode(TreeNode* root, const string& data) {
    if (root == nullptr) return nullptr;
    if (root->data == data) return root;

    TreeNode* found = findNode(root->firstChild, data);
    if (found != nullptr) return found;

    return findNode(root->nextSibling, data);
}

// Automated function to create the predefined tree structure
TreeNode* createTree() {
    TreeNode* root = new TreeNode("Electronics R' Us");

    addChild(root, "R&D");
    addChild(root, "Sales");
    addChild(root, "Purchasing");
    addChild(root, "Manufacturing");

    // Adding child nodes to "Sales"
    TreeNode* sales = findNode(root, "Sales");
    addChild(sales, "Domestic");
    addChild(sales, "International");

    // Adding child nodes to "International"
    TreeNode* international = findNode(root, "International");
    addChild(international, "Canada");
    addChild(international, "S. America");
    addChild(international, "Overseas");

    // Adding child nodes to "Overseas"
    TreeNode* overseas = findNode(root, "Overseas");
    addChild(overseas, "Africa");
    addChild(overseas, "Europe");
    addChild(overseas, "Asia");
    addChild(overseas, "Australia");

    return root;
}

// Function to calculate the depth of a node
int getDepth(TreeNode* root, TreeNode* node, int depth = 0) {
    if (root == nullptr) return -1;
    if (root == node) return depth;

    int childDepth = getDepth(root->firstChild, node, depth + 1);
    if (childDepth != -1) return childDepth;

    return getDepth(root->nextSibling, node, depth);
}

// Function to calculate the height of a node
int getHeight(TreeNode* node) {
    if (node == nullptr) return -1;

    int maxChildHeight = -1;
    TreeNode* child = node->firstChild;
    while (child != nullptr) {
        maxChildHeight = max(maxChildHeight, getHeight(child));
        child = child->nextSibling;
    }

    return maxChildHeight + 1;
}

int main() {
    TreeNode* root = createTree(); // Automatically creates the tree structure as in the image

    // Example to find the depth and height of specific nodes
    TreeNode* salesNode = findNode(root, "Sales");
    int salesDepth = getDepth(root, salesNode);
    int salesHeight = getHeight(salesNode);

    cout << "Depth of Sales: " << salesDepth << endl;
    cout << "Height of Sales: " << salesHeight << endl;

    // Example for another node
    TreeNode* internationalNode = findNode(root, "International");
    int internationalDepth = getDepth(root, internationalNode);
    int internationalHeight = getHeight(internationalNode);

    cout << "Depth of International: " << internationalDepth << endl;
    cout << "Height of International: " << internationalHeight << endl;

    // Clean up dynamically allocated memory (not implemented here)
    // Implement a recursive delete function to free all nodes if needed

    return 0;
}

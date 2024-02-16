#include <iostream>

// Assuming the Node structure is defined somewhere
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    Node* prevNode = nullptr; // Pointer to the previous node

    // Function to flatten the binary search tree
    void flattenBST(Node* root) {
        if (!root) return; // Base case: if root is null, return
        
        // Traverse the right subtree first
        flattenBST(root->right);

        // Set the right child of the current node to the previous node
        root->right = prevNode;

        // If previous node exists, set its left child to null
        if (prevNode) prevNode->left = nullptr;

        // Update the previous node to the current node
        prevNode = root;

        // Traverse the left subtree
        flattenBST(root->left);
    }

    // Function to flatten the binary search tree and return the head of the flattened tree
    Node* flattenBST(Node* root) {
        flattenBST(root);
        return prevNode; // Return the head of the flattened tree
    }
};

int main() {
    // Creating an instance of the Solution class
    Solution solution;

    // Creating a sample binary search tree
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    // Flattening the binary search tree
    Node* flattenedTreeHead = solution.flattenBST(root);

    // Printing the flattened tree
    std::cout << "Flattened BST:";
    while (flattenedTreeHead != nullptr) {
        std::cout << " " << flattenedTreeHead->data;
        flattenedTreeHead = flattenedTreeHead->right;
    }
    std::cout << std::endl;

    return 0;
}

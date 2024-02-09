#include <iostream>
using namespace std;

// Define the structure for a node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Define the Solution class with the methods to check the sum property
class Solution {
public:
    int findans(Node* root) {
        if (!root)
            return 0;

        if (!root->left && !root->right)
            return root->data;

        int leftans = findans(root->left);
        if (leftans == -1)
            return -1;

        int rightans = findans(root->right);
        if (rightans == -1)
            return -1;

        if (leftans + rightans != root->data)
            return -1;

        return root->data;
    }

    int isSumProperty(Node *root) {
        if (findans(root) == -1)
            return 0;
        return 1;
    }
};

int main() {
    // Creating a sample binary tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(5);
    root->left->left = new Node(2);
    root->left->right = new Node(3);
    root->right->left = new Node(2);
    root->right->right = new Node(3);

    // Create an object of the Solution class
    Solution solution;

    // Check if the binary tree satisfies the sum property
    if (solution.isSumProperty(root))
        cout << "The binary tree satisfies the sum property." << endl;
    else
        cout << "The binary tree does not satisfy the sum property." << endl;

    // Free memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

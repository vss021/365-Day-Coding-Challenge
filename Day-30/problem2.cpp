#include <bits/stdc++.h>
using namespace std;

// Assuming the definition of the Node class
class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    // Helper function to calculate the number of moves needed to distribute candy
    int solve(Node* root, int& move) {
        // Base case: If the current node is NULL, return 0
        if (root == nullptr)
            return 0;

        // Recursively calculate the sum of candies on the left and right subtrees
        int left = solve(root->left, move);
        int right = solve(root->right, move);

        // Calculate the moves required for the current node
        move += abs(left) + abs(right);

        // Return the sum of candies for the current node
        return root->key + left + right - 1;
    }

    // Main function to distribute candies starting from the root
    int distributeCandy(Node* root) {
        // Initialize the variable to store the total moves
        int move = 0;

        // Call the helper function to calculate moves and distribute candies
        solve(root, move);

        // Return the total number of moves needed to distribute candies
        return move;
    }
};

int main() {
    // Example usage of the Solution class

    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Creating an instance of the Solution class
    Solution solution;

    // Calling the distributeCandy function and printing the result
    int result = solution.distributeCandy(root);

    cout << "Total moves needed to distribute candies: " << result << endl;

    // Clean up the dynamically allocated memory
    // (You may want to implement a proper destructor in the Node class)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

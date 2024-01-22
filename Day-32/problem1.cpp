#include <vector>
#include <iostream>
class Solution {
private:
    // Vector to store all paths with the required sum
    vector<vector<int>> result;

    // Temporary vector to store the current path
    vector<int> currentPath;

    // Helper function to recursively find paths with the given sum
    void findPaths(Node* root, int &remainingSum) {
        // Base case: if the current node is null, return
        if (!root) {
            return;
        }

        // Calculate the remaining sum after subtracting the current node's value
        int remainingValue = remainingSum - (root->key);

        // Add the current node to the current path
        currentPath.push_back(root->key);

        // If the remaining sum is 0, add the current path to the result
        if (remainingValue == 0) {
            result.push_back(currentPath);
        }

        // Recursively explore the left and right subtrees
        findPaths(root->left, remainingValue);
        findPaths(root->right, remainingValue);

        // Remove the last element from the current path to backtrack
        currentPath.pop_back();
    }

public:
    // Main function to find paths with the given sum
    vector<vector<int>> printPaths(Node* root, int sum) {
        // Clear the result and current path vectors before starting
        result.clear();
        currentPath.clear();

        // Call the helper function to find paths with the given sum
        findPaths(root, sum);

        // Return the final result
        return result;
    }
};




// Assuming the definition of the Node class is available

int main() {
    // Creating a binary tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(3);
    root->left->left = new Node(3);
    root->left->right = new Node(2);
    root->right->right = new Node(1);

    // Creating an instance of the Solution class
    Solution solution;

    // Setting the target sum
    int targetSum = 8;

    // Calling the printPaths function to find paths with the given sum
    vector<vector<int>> result = solution.printPaths(root, targetSum);

    // Displaying the result
    for (const auto& path : result) {
        cout << "Path: ";
        for (int value : path) {
            cout << value << " ";
        }
        cout << endl;
    }

    // Clean up the allocated memory for the binary tree (not shown in the original code)
    // ...

    return 0;
}


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Define the structure of the tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper function to traverse the tree and find nodes at a distance 'k' from leaf nodes
    void findNodesAtKDistanceFromLeaf(Node *root, int k, vector<Node*> &path, unordered_set<Node*> &result, int level) {
        // Base case: if the node is null, return
        if (!root) return;
        
        // If it's a leaf node
        if (!root->left && !root->right) {
            // If the distance is k, add the leaf node to the result
            if (k == 0) {
                result.insert(root);
            } 
            // If the distance is greater than or equal to 0, add the node at the appropriate distance from the leaf node
            else if (level - k >= 0) {
                result.insert(path[level - k]);
            }
            return;
        }
        
        // Push the current node to the path
        path.push_back(root);
        
        // Recur for left and right subtrees
        findNodesAtKDistanceFromLeaf(root->left, k, path, result, level + 1);
        findNodesAtKDistanceFromLeaf(root->right, k, path, result, level + 1);
        
        // Pop the current node from the path
        path.pop_back();
    }

    // Function to return count of nodes at a given distance from leaf nodes
    int printKDistantfromLeaf(Node* root, int k) {
        vector<Node*> path;  // Store the path from root to current node
        unordered_set<Node*> result; // Store the nodes at distance 'k' from leaf nodes
        findNodesAtKDistanceFromLeaf(root, k, path, result, 0); // Call the helper function
        return result.size(); // Return the size of the set containing unique nodes
    }
};

// Function to build a sample binary tree
Node* buildTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    return root;
}

int main() {
    Solution sol;
    Node* root = buildTree();
    int k = 2;
    cout << "Number of nodes at distance " << k << " from leaf nodes: " << sol.printKDistantfromLeaf(root, k) << endl;
    return 0;
}

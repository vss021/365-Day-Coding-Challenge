#include <iostream>
#include <queue>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /*You are required to complete this method*/
    bool check(Node *root) {
        //Your code here
        queue<Node*> q; // Create a queue to perform level order traversal
        q.push(root); // Push the root node into the queue
        
        while (!q.empty()) { // Continue while there are nodes in the queue
            int sz = q.size(); // Get the current size of the queue (number of nodes in the current level)
            int cnt = 0; // Initialize a counter to count the number of leaf nodes in the current level
            
            while (sz--) { // Process all nodes in the current level
                Node *t = q.front(); // Get the front node from the queue
                q.pop(); // Remove the front node from the queue
                
                if (!t->left && !t->right) // If the current node is a leaf node (no left and right children)
                    cnt++; // Increment the count of leaf nodes
                
                if (t->left) // If the current node has a left child
                    q.push(t->left); // Push the left child into the queue
                
                if (t->right) // If the current node has a right child
                    q.push(t->right); // Push the right child into the queue
            }
            
            if (!q.empty() && cnt) // If there are more levels to process and there are leaf nodes in the current level
                return false; // Return false (not all leaf nodes are at the same level)
        }
        
        return true; // If all leaf nodes are at the same level, return true
    }
};

int main() {
    // Example usage of the check method
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    Solution sol;
    if (sol.check(root))
        cout << "All leaf nodes are at the same level." << endl;
    else
        cout << "Leaf nodes are not at the same level." << endl;
    
    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}

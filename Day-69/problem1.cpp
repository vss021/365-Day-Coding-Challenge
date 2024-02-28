#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* leftmost = nullptr; // Initialize leftmost node pointer
        
        while (!q.empty()) {
            int levelSize = q.size(); // Get the size of the current level
            leftmost = q.front(); // Initialize leftmost as the first node of the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return leftmost->val; // Return the value of the leftmost node at the bottom level
    }
};

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    Solution solution;
    cout << "The bottom-left value of the binary tree is: " << solution.findBottomLeftValue(root) << endl;
    
    // Clean up memory (not necessary in LeetCode, but good practice)
    delete root->left->left;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}

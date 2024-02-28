#include <iostream>
#include <utility>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    pair<int, int> calculateDiameterAndHeight(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }

        auto leftData = calculateDiameterAndHeight(root->left);
        auto rightData = calculateDiameterAndHeight(root->right);

        int currentDiameter = max(leftData.second + rightData.second, 
                                  max(leftData.first, rightData.first));
        int currentHeight = max(leftData.second, rightData.second) + 1;

        return {currentDiameter, currentHeight};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return calculateDiameterAndHeight(root).first;
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Create an instance of Solution
    Solution solution;

    // Calculate the diameter of the binary tree
    int diameter = solution.diameterOfBinaryTree(root);

    cout << "Diameter of the binary tree: " << diameter << endl;

    // Remember to free the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

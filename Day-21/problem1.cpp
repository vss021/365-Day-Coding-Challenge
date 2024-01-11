#include <iostream>
using namespace std;
// Assume you have a TreeNode class defined like this
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root)
            return 0;

        int minVal = root->val;
        int maxVal = root->val;
        updateMinMax(root, minVal, maxVal);

        return diff;
    }

private:
    int diff = 0;

    void updateMinMax(TreeNode* root, int& minVal, int& maxVal) {
        if (!root)
            return;

        diff = std::max(diff, std::max(std::abs(minVal - root->val), std::abs(maxVal - root->val)));
        minVal = std::min(minVal, root->val);
        maxVal = std::max(maxVal, root->val);

        updateMinMax(root->left, minVal, maxVal);
        updateMinMax(root->right, minVal, maxVal);
    }
};


int main() {
    // Create a sample tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // Create an instance of the Solution class
    Solution solution;

    // Call the maxAncestorDiff function and print the result
    int result = solution.maxAncestorDiff(root);
    cout << "Max Ancestor Difference: " << result << endl;

    // Clean up memory (not necessary in this simple example, but good practice)
    // You may want to implement a proper destructor in the TreeNode class
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

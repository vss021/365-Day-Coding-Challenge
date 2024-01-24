#include <iostream>
#include <stack>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        int count = 0;

        // Use a stack to perform iterative DFS
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 0});

        while (!stk.empty()) {
            auto [node, path] = stk.top();
            stk.pop();

            if (node != nullptr) {
                // Update the path using XOR to keep track of the occurrences of each digit
                path = path ^ (1 << node->val);

                if (node->left == nullptr && node->right == nullptr) {
                    // Check if the current path is pseudo-palindromic
                    if ((path & (path - 1)) == 0) {
                        ++count;
                    }
                } else {
                    // Push right and left children along with the updated path to the stack
                    stk.push({node->right, path});
                    stk.push({node->left, path});
                }
            }
        }

        return count;
    }
};


int main() {
    // Example tree creation
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(1);

    // Creating an instance of the Solution class
    Solution solution;

    // Calling the pseudoPalindromicPaths function and printing the result
    int result = solution.pseudoPalindromicPaths(root);
    std::cout << "Number of pseudo-palindromic paths: " << result << std::endl;

    // Freeing allocated memory (optional)
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

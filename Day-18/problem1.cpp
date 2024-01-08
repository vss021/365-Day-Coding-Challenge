#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int sum = 0;

    int inorder(TreeNode *root, int L, int R)
    {
        if (root)
        {
            inorder(root->left, L, R);
            if (root->val >= L && root->val <= R)
                sum += root->val;
            inorder(root->right, L, R);
        }
        return sum;
    }

    int rangeSumBST(TreeNode *root, int L, int R)
    {
        if (!root)
            return 0;
        return inorder(root, L, R);
    }
};

int main()
{
    // Example usage
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    Solution solution;
    int result = solution.rangeSumBST(root, 7, 15);

    cout << "Range Sum: " << result << endl;

    // Don't forget to free memory if dynamic allocation is used
    // delete nodes and the root appropriately

    return 0;
}

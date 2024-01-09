#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void collectLeaves(TreeNode* root, vector<int>& leaves) {
        if (!root)
            return;
        if (!root->left && !root->right)
            leaves.push_back(root->val);
        collectLeaves(root->left, leaves);
        collectLeaves(root->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;

        collectLeaves(root1, leaves1);
        collectLeaves(root2, leaves2);

        return leaves1 == leaves2;
    }
};

int main() {
    Solution solution;

    // Creating sample trees
    TreeNode* root1 = new TreeNode(3, new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4)))), new TreeNode(1, new TreeNode(9), new TreeNode(8)));
    TreeNode* root2 = new TreeNode(3, new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4)))), new TreeNode(1, new TreeNode(9), new TreeNode(8)));

    // Testing leafSimilar function
    bool result = solution.leafSimilar(root1, root2);

    // Displaying the result
    cout << "Are the trees leaf-similar? " << (result ? "Yes" : "No") << endl;

    // Freeing allocated memory
    delete root1;
    delete root2;

    return 0;
}

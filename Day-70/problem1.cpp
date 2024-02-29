#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    bool isIncreasing(vector<int> &nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] % 2 == 0 || nums[i + 1] % 2 == 0 || nums[i] >= nums[i + 1])
                return false;
        }
        return true;
    }
    
    bool isDecreasing(vector<int> &nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] % 2 != 0 || nums[i + 1] % 2 != 0 || nums[i] <= nums[i + 1])
                return false;
        }
        return true;
    }

public:
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr)
            return false;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool isValid = false;
        int level = -1;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> levelValues;
            
            level++;
            
            while (size--) {
                TreeNode* node = q.front(); 
                q.pop();
                
                levelValues.push_back(node->val);
                
                if (node->left)
                    q.push(node->left);
                
                if (node->right)
                    q.push(node->right);
            }

            if (level % 2 != 0) { // Odd level
                if (isDecreasing(levelValues))
                    isValid = true;
                else
                    return false;
            } else { // Even level
                if (isIncreasing(levelValues))
                    isValid = true;
                else
                    return false;
            }
        }
        
        return isValid;
    }
};

// Helper function to create a binary tree
TreeNode* createBinaryTree(vector<int>& nums, int index) {
    if (index >= nums.size() || nums[index] == -1)
        return nullptr;

    TreeNode* root = new TreeNode(nums[index]);
    root->left = createBinaryTree(nums, 2 * index + 1);
    root->right = createBinaryTree(nums, 2 * index + 2);

    return root;
}

// Main function to test the solution
int main() {
    Solution sol;
    vector<int> nums = {1, 10, 4, 3, -1, 7, 9, 12, 8, 6, -1, -1, 2};
    TreeNode* root = createBinaryTree(nums, 0);
    cout << "Is Even-Odd Tree: " << boolalpha << sol.isEvenOddTree(root) << endl;
    return 0;
}

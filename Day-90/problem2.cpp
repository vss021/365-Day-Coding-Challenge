#include <iostream>
#include <algorithm>

using namespace std;

// Definition for binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxLen = 0, maxSum = -1;

    int sumOfLongRootToLeafPath(Node *root) {
        f(root, 0, 0);
        return maxSum;
    }

    void f(Node *root, int len, int sum) {
        len++;
        sum += root->data;

        if (root->left == nullptr && root->right == nullptr) {
            if (len > maxLen)
                maxSum = sum, maxLen = len;
            else if (len == maxLen)
                maxSum = max(maxSum, sum);
        }

        if (root->left != nullptr)
            f(root->left, len, sum);
        if (root->right != nullptr)
            f(root->right, len, sum);
    }
};

int main() {
    // Example usage for sumOfLongRootToLeafPath function
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->right->right->right = new Node(9);

    Solution solution;
    int maxSum = solution.sumOfLongRootToLeafPath(root);

    cout << "Sum of nodes on the longest path from root to any leaf node: " << maxSum << endl;

    return 0;
}

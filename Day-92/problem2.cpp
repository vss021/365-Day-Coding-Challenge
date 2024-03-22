#include <iostream>
#include <vector>
#include <map>

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
    void solve(Node* root, map<int, vector<int>>& diagonalMap, int diagonal) {
        if (root == nullptr)
            return;

        diagonalMap[diagonal].push_back(root->data);

        solve(root->right, diagonalMap, diagonal);

        solve(root->left, diagonalMap, diagonal + 1);
    }

    vector<int> diagonalSum(Node* root) {
        vector<int> result;
        map<int, vector<int>> diagonalMap;
        int diagonal = 0;

        solve(root, diagonalMap, diagonal);

        for (auto it : diagonalMap) {
            int sum = 0;
            for (int val : it.second) {
                sum += val;
            }
            result.push_back(sum);
        }

        return result;
    }
};

int main() {
    // Example usage for diagonalSum function
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;
    vector<int> diagonalSums = solution.diagonalSum(root);

    cout << "Diagonal Sums: ";
    for (int sum : diagonalSums) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}

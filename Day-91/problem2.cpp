#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        
        if (root == nullptr) {
            return result;
        }
        
        queue<Node*> q;
        q.push(root);
        
        bool Direction = true;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp(size);
            
            for (int i = 0; i < size; i++) {
                Node* nextNode = q.front();
                q.pop();
                
                int index = Direction ? i : size - i - 1;
                temp[index] = nextNode->data;
                
                if (nextNode->left) {
                    q.push(nextNode->left);
                }
                
                if (nextNode->right) {
                    q.push(nextNode->right);
                }
            }
            
            Direction = !Direction;
            
            for (auto x : temp) {
                result.push_back(x);
            }
        }
        
        return result;
    }
};

int main() {
    // Example usage for zigZagTraversal function
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;
    vector<int> zigZag = solution.zigZagTraversal(root);

    cout << "Zig-Zag Level Order Traversal: ";
    for (int val : zigZag) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

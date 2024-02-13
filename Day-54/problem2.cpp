#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

// Define the Node struct
struct Node {
    int val;
    vector<Node*> neighbors;
    Node(int _val) : val(_val), neighbors(vector<Node*>()) {}
};

class Solution {
public:
    void DFS_Function(unordered_map<Node*, Node*>& mp, Node* node, Node*& cloneNode) {
        for (Node* currNode : node->neighbors) {
            if (mp.find(currNode) == mp.end()) {
                Node* newNode = new Node(currNode->val);
                mp[currNode] = newNode;
                cloneNode->neighbors.push_back(newNode);
                DFS_Function(mp, currNode, newNode);
            } else {
                cloneNode->neighbors.push_back(mp[currNode]);
            }
        }
    }
    
    Node* BFS_Function(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> mp;
        Node* cloneNode = new Node(node->val);
        mp[node] = cloneNode;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for (Node* neighbor : curr->neighbors) {
                if (mp.find(neighbor) == mp.end()) {
                    Node* newNeighbor = new Node(neighbor->val);
                    mp[neighbor] = newNeighbor;
                    mp[curr]->neighbors.push_back(newNeighbor);
                    q.push(neighbor);
                } else {
                    mp[curr]->neighbors.push_back(mp[neighbor]);
                }
            }
        }
        return cloneNode;
    }

    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*> mp;
        Node* cloneNode = new Node(node->val);
        mp[node] = cloneNode;
        DFS_Function(mp, node, cloneNode);
        return cloneNode;
    }
};

int main() {
    Solution solution;

    // Example usage
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node3);
    node2->neighbors.push_back(node1);
    node3->neighbors.push_back(node1);

    Node* clonedGraph = solution.BFS_Function(node1);

    // Output the cloned graph (for demonstration)
    cout << "Original Node: " << node1->val << endl;
    cout << "Cloned Node: " << clonedGraph->val << endl;

    // Clean up memory (deallocate nodes)
    // Add cleanup code as needed

    return 0;
}

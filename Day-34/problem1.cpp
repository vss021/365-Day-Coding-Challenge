#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Helper function to check if the graph contains a cycle using DFS
    bool isCyclic(unordered_map<int, vector<int>>& adjList, int currentNode, vector<int>& visited, int parent) {
        // Mark the current node as visited
        visited[currentNode] = 1;

        // Traverse neighbors of the current node
        for (auto neighbor : adjList[currentNode]) {
            if (visited[neighbor] == 0) {
                // Recursive call to check the neighbor and its descendants
                bool hasCycle = isCyclic(adjList, neighbor, visited, currentNode);
                if (hasCycle)
                    return true;
            } else if (neighbor != parent) {
                // If the neighbor is visited and not the parent, it means there is a cycle
                return true;
            }
        }
        return false;
    }

    // Function to check if the given graph is a tree
    bool isTree(int n, int m, vector<vector<int>>& adj) {
        // Create an adjacency list from the given edge list
        unordered_map<int, vector<int>> adjList;
        for (int i = 0; i < adj.size(); i++) {
            int u = adj[i][0];
            int v = adj[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // Initialize a vector to track visited nodes
        vector<int> visited(n, 0);

        // Check for cycles starting from the first node
        bool hasCycle = isCyclic(adjList, 0, visited, -1);

        // If there is a cycle, it's not a tree
        if (hasCycle)  
            return false;

        // Check if all nodes are visited
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0)
                return false;
        }

        // If there is no cycle and all nodes are visited, it's a tree
        return true;
    }
};

int main() {
    Solution solution;

    // Example usage
    int n = 5;
    int m = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};

    bool result = solution.isTree(n, m, edges);

    if (result)
        cout << "The graph is a tree." << endl;
    else
        cout << "The graph is not a tree." << endl;

    return 0;
}

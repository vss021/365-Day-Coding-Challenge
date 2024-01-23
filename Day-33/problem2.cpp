#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, int m, vector<vector<int>>& prerequisites) {
        // Create in-degree array and adjacency list
        vector<int> inDegree(n, 0);
        unordered_map<int, list<int>> adj;

        // Build adjacency list and in-degree array
        for (int i = 0; i < m; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            inDegree[u]++;
        }

        // Initialize a queue, answer vector, and check if any node has in-degree 0
        queue<int> q;
        vector<int> ans;
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                found = true;
            }
        }

        // If no node has in-degree 0, return an empty vector
        if (!found) {
            return ans;
        }

        // Perform topological sorting using BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto nbr : adj[node]) {
                inDegree[nbr]--;
                if (inDegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        // If the answer size is not equal to the number of nodes, there is a cycle
        if (ans.size() != n) {
            return {};
        }

        return ans;
    }
};


int main() {
    Solution solution;

    // Example usage with a set of prerequisites
    int n = 4;
    int m = 3;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}};

    vector<int> result = solution.findOrder(n, m, prerequisites);

    // Print the result
    if (!result.empty()) {
        cout << "Topological Order: ";
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No valid topological order (graph contains a cycle)." << endl;
    }

    return 0;
}

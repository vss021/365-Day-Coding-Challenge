#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;



class Solution {
public:
    int timer = 1; // Timer for tracking insertion time

    // Depth First Search function
    void dfs(int node, int parent, vector<int> adj[], vector<int>& vis, vector<int>& lowestTimeToReach, vector<int>& timeOfInsertion, vector<vector<int>>& bridges) {
        vis[node] = 1; // Mark the current node as visited
        lowestTimeToReach[node] = timeOfInsertion[node] = timer; // Set insertion time and lowest time to reach
        timer++; // Increment timer

        // Iterate over adjacent nodes
        for(auto adjNode : adj[node]) {
            // Skip the parent node
            if(adjNode == parent) continue;

            // If the adjacent node is not visited
            if(!vis[adjNode]) {
                // Recursive call to explore the unvisited node
                dfs(adjNode, node, adj, vis, lowestTimeToReach, timeOfInsertion, bridges);

                // Update lowestTimeToReach of the current node
                lowestTimeToReach[node] = min(lowestTimeToReach[node], lowestTimeToReach[adjNode]);

                // If there is a bridge (no back edge from adjNode to its ancestors)
                if(lowestTimeToReach[adjNode] > timeOfInsertion[node]) {
                    // Add the bridge to the result
                    bridges.push_back({min(adjNode,node),max(adjNode,node)});
                }
            } else {
                // If the adjacent node is visited, update lowestTimeToReach of the current node
                lowestTimeToReach[node] = min(lowestTimeToReach[node], timeOfInsertion[adjNode]);
            }
        }
    }

    // Function to find critical connections
    vector<vector<int>> criticalConnections(int v, vector<int> adj[]) {
        // Initialize vectors to track lowest time to reach, insertion time, and visited status
        vector<int> lowestTimeToReach(v, 0);
        vector<int> timeOfInsertion(v, 0);
        vector<int> visited(v, 0);
        
        // Vector to store critical connections (bridges)
        vector<vector<int>> bridges;

        // Start DFS from node 0 with parent -1
        dfs(0, -1, adj, visited, lowestTimeToReach, timeOfInsertion, bridges);
        
        // Sort the bridges based on the node values
        sort(bridges.begin(), bridges.end());
        
        // Return the result
        return bridges;
    }
};


int main() {
    // Example usage
    int v = 4; // Number of vertices
    vector<int> adj[v]; // Adjacency list representation of the graph

    // Adding edges to the graph
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);

    Solution sol;
    vector<vector<int>> result = sol.criticalConnections(v, adj);

    // Displaying the critical connections (bridges)
    cout << "Critical connections (bridges) in the graph are:\n";
    for (const auto &bridge : result) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}

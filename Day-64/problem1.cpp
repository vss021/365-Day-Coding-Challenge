#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    // Time Complexity: O(E + VlogV), where E is the number of edges and V is the number of vertices
    // Space Complexity: O(V + E)
    int SolveUsing_BFS(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Adjacency list representation of graph
        unordered_map<int, vector<pair<int,int>>> adjList;
        
        // Constructing the adjacency list
        for(auto flight : flights)
            adjList[flight[0]].push_back({flight[1], flight[2]});
        
        // BFS starting from src
        queue<pair<int,int>> q; // < node, dist_from_src > pair
        q.push({src, 0});
        int srcToTgtDist = INT_MAX; // result
        
        // BFS traversal
        while(!q.empty() && K-- >= 0) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto curr = q.front(); 
                q.pop();
                for(auto nbr : adjList[curr.first]) {
                    if(srcToTgtDist < curr.second + nbr.second)
                        continue;
                    q.push({nbr.first, curr.second + nbr.second});
                    
                    // Update distance from src to dst
                    if(dst == nbr.first)
                        srcToTgtDist = min(srcToTgtDist, curr.second + nbr.second);
                }
            }
        }
        return srcToTgtDist == INT_MAX ? -1 : srcToTgtDist;
    }

    // Time Complexity: O(K*E), where E is the number of edges
    // Space Complexity: O(V), where V is the number of vertices
    int bellman_Ford_Algorithm(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Distance from source to all other nodes
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        // Run only K+1 times since we want shortest distance in K hops
        for(int i = 0; i <= K; i++) {
            vector<int> tmp(dist);
            for(auto flight : flights) {
                if(dist[flight[0]] != INT_MAX) {
                    tmp[flight[1]] = min(tmp[flight[1]], dist[flight[0]] + flight[2]);
                }
            }
            dist = tmp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }

    // Main function to find the cheapest price
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Return result using BFS
        return SolveUsing_BFS(n, flights, src, dst, k);
        
        // Return result using Bellman-Ford Algorithm
        // return bellman_Ford_Algorithm(n, flights, src, dst, k);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    int n = 3, src = 0, dst = 2, k = 1;
    cout << "Cheapest price from " << src << " to " << dst << " within " << k << " stops: ";
    cout << sol.findCheapestPrice(n, flights, src, dst, k) << endl;
    return 0;
}

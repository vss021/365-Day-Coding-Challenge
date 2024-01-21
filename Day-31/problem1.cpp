#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
     * Approach:
     * The function finds the minimum vertex cover size for a given graph represented by 'edges'.
     * It uses a brute-force approach by trying all possible vertex cover configurations using a bitmask.
     * For each bitmask, it checks if it is a valid vertex cover by ensuring that each edge is covered.
     * The minimum cover size is updated whenever a valid cover is found.
     *
     * Parameters:
     * - numVertices: Number of vertices in the graph.
     * - edges: A vector of pairs representing the edges of the graph.
     *
     * Returns:
     * The minimum size of a valid vertex cover.
     */
    int findMinimumVertexCover(int numVertices, vector<pair<int, int>> &edges) {
        int minimumCoverSize = numVertices;

        for (int mask = 0; mask < (1 << numVertices); mask++) {
            bool isVertexCoverValid = true;

            for (auto &edge : edges) {
                int vertex1 = edge.first - 1;
                int vertex2 = edge.second - 1;

                if (!(mask & (1 << vertex1)) && !(mask & (1 << vertex2))) {
                    isVertexCoverValid = false;
                    break;
                }
            }

            if (isVertexCoverValid) {
                minimumCoverSize = min(minimumCoverSize, __builtin_popcount(mask));
            }
        }

        return minimumCoverSize;
    }
};


int main() {
    // Example usage
    Solution solution;

    // Example graph with 4 vertices and 3 edges
    int numVertices = 4;
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 4}};

    // Find the minimum vertex cover size
    int minCoverSize = solution.findMinimumVertexCover(numVertices, edges);

    // Display the result
    cout << "Minimum Vertex Cover Size: " << minCoverSize << endl;

    return 0;
}

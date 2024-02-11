#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(); // Number of rows
        int n = grid[0].size(); // Number of columns
        
        // Initialize dynamic programming array with dimensions m x n x n
        // dp[i][j][k] represents the maximum number of cherries picked by two robots at position (i, j) and (i, k)
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        
        // Initialize the starting position with cherries picked by both robots
        dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        
        // Initialize variable to store the maximum cherries picked
        int maxCherries = 0;
        
        // Iterate over each row
        for (int i = 1; i < m; ++i) {
            // Iterate over positions for robot A
            for (int j = 0; j < n; ++j) {
                // Iterate over positions for robot B
                for (int k = j + 1; k < n; ++k) {
                    // Explore all possible combinations of movements for both robots
                    for (int x = -1; x <= 1; ++x) {
                        for (int y = -1; y <= 1; ++y) {
                            int nj = j + x; // New position for robot A
                            int nk = k + y; // New position for robot B
                            
                            // Check if the new positions are within bounds
                            if (nj >= 0 && nj < n && nk >= 0 && nk < n) {
                                // Check if the previous state is valid
                                if (dp[i - 1][nj][nk] != -1) {
                                    // Update the maximum cherries picked for the current state
                                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][nj][nk] + grid[i][j] + (j != k ? grid[i][k] : 0));
                                }
                            }
                        }
                    }
                    // Update the maximum cherries picked overall
                    maxCherries = max(maxCherries, dp[i][j][k]);
                }
            }
        }
        
        return maxCherries;
    }
};


int main() {
    // Example usage of the cherryPickup function
    Solution solution;
    vector<vector<int>> grid = {
        {0, 1, -1},
        {1, 0, -1},
        {1, 1,  1}
    };

    int maxCherries = solution.cherryPickup(grid);
    cout << "Maximum cherries picked: " << maxCherries << endl;

    return 0;
}

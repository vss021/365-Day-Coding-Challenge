#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Helper function to recursively find the number of paths
    long long helper(vector<vector<int>> &arr, int i, int j, int k, vector<vector<vector<long long>>> &dp) {
        // Base case: out of bounds
        if (i < 0 || j < 0 || k < 0) {
            return 0;
        }
        // Base case: reached the starting cell
        if (i == 0 && j == 0) {
            // Check if the sum equals k
            if (k == arr[i][j]) {
                return 1;
            }
            return 0;
        }
        // If the result is already computed, return it
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        
        // Recursively explore paths from up and left cells
        long long up = helper(arr, i - 1, j, k - arr[i][j], dp);
        long long left = helper(arr, i, j - 1, k - arr[i][j], dp);
        
        // Store and return the result
        return dp[i][j][k] = up + left;
    }
    
    // Main function to compute the number of paths
    long long numberOfPath(int n, int k, vector<vector<int>> &arr) {
        // Initialize the DP table with -1
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(k + 1, -1)));
        // Start recursion from the bottom-right cell
        return helper(arr, n - 1, n - 1, k, dp);
    }
};

int main() {
    // Example usage
    Solution solution;
    int n = 3; // Size of the grid
    int k = 5; // Target sum
    vector<vector<int>> arr = {{1, 2, 1}, {3, 4, 1}, {1, 1, 2}}; // Grid values

    // Calculate the number of paths
    long long paths = solution.numberOfPath(n, k, arr);
    
    // Output the result
    cout << "Number of paths with sum " << k << " in the grid: " << paths << endl;

    return 0;
}

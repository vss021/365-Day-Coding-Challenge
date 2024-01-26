#include <iostream>

#include <cstring> // Required for memset

using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    // Recursive helper function to find the number of paths
    int countPaths(int i, int j, int m, int n, int mx, int dp[51][51][51]) {
        // Base case: if maximum steps are exhausted
        if (mx == 0) {
            // Check if the current position is out of bounds
            if (i >= m || i < 0 || j >= n || j < 0) {
                return 1;
            }
            return 0;
        }

        // Check if the current position is out of bounds
        if (i >= m || i < 0 || j >= n || j < 0) {
            return 1;
        }

        // If the result is already computed, return it
        if (dp[i][j][mx] != -1) {
            return dp[i][j][mx];
        }

        // Explore all four possible directions and calculate the total paths
        long long opt1 = countPaths(i, j + 1, m, n, mx - 1, dp);
        long long opt2 = countPaths(i + 1, j, m, n, mx - 1, dp);
        long long opt3 = countPaths(i - 1, j, m, n, mx - 1, dp);
        long long opt4 = countPaths(i, j - 1, m, n, mx - 1, dp);

        // Store and return the result modulo mod
        return dp[i][j][mx] = (opt1 + opt2 + opt3 + opt4) % mod;
    }

    // Function to find the number of paths
    int findPaths(int m, int n, int mx, int st, int sc) {
        // Initialize the dynamic programming array with -1
        int dp[51][51][51];
        memset(dp, -1, sizeof(dp));

        // Call the recursive helper function
        return countPaths(st, sc, m, n, mx, dp);
    }
};


int main() {
    // Example usage of the Solution class
    Solution pathFinder;

    // Example values for m, n, mx, st, and sc
    int m = 3, n = 3, mx = 2, st = 0, sc = 0;

    // Calculate the number of paths using the findPaths method
    int numPaths = pathFinder.findPaths(m, n, mx, st, sc);

    // Display the result
    cout << "Number of paths: " << numPaths << endl;

    return 0;
}

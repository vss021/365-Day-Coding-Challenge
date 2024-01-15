#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    // Recursive helper function with memoization
    int solve(int i, int total, const vector<int>& cost, vector<vector<int>>& dp) {
        if (i >= cost.size()) {
            return 0;
        }

        if (dp[i][total] != -1) {
            return dp[i][total];
        }

        int include = 0;
        if (cost[i] <= total) {
            // Include the current course and recursively calculate for the next courses
            include = 1 + solve(i + 1, total - ceil((10 * cost[i]) / 100.0), cost, dp);
        }

        // Exclude the current course and recursively calculate for the next courses
        int exclude = 0 + solve(i + 1, total, cost, dp);

        return dp[i][total] = max(include, exclude);
    }

    // Dynamic programming using a 2D table
    int solveTab(int total, const vector<int>& cost) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(total + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int currentTotal = 0; currentTotal <= total; currentTotal++) {
                int include = 0;
                if (cost[i] <= currentTotal) {
                    // Include the current course
                    include = 1 + dp[i + 1][currentTotal - ceil((10 * cost[i]) / 100.0)];
                }

                // Exclude the current course
                int exclude = 0 + dp[i + 1][currentTotal];

                dp[i][currentTotal] = max(include, exclude);
            }
        }

        return dp[0][total];
    }

    // Space-optimized dynamic programming
    int spaceOptimized(int total, const vector<int>& cost) {
        int n = cost.size();
        vector<int> curr(total + 1, 0), next(total + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int currentTotal = 0; currentTotal <= total; currentTotal++) {
                int include = 0;
                if (cost[i] <= currentTotal) {
                    // Include the current course
                    include = 1 + next[currentTotal - ceil((10 * cost[i]) / 100.0)];
                }

                // Exclude the current course
                int exclude = 0 + next[currentTotal];

                curr[currentTotal] = max(include, exclude);
            }
            next = curr;
        }

        return curr[total];
    }

    // Wrapper function to choose the method and start the calculation
    int maxCourses(int n, int total, const vector<int>& cost) {
        // Uncomment one of the following lines based on the desired method
        // return solve(0, total, cost, dp);
        // return solveTab(total, cost);
        return spaceOptimized(total, cost);
    }
};


int main() {
    // Example data
    int n = 4;
    int total = 50;
    vector<int> cost = {10, 20, 30, 40};

    // Create an instance of the Solution class
    Solution solution;

    // Call the maxCourses function with the example data
    int result = solution.maxCourses(n, total, cost);

    // Display the result
    cout << "Maximum number of courses that can be taken: " << result << endl;

    return 0;
}

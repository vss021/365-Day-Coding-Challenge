#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 2D array to store intermediate results for memoization
    int dp[31][1001] = {};

    // Function to calculate the number of ways to reach the target sum using 'd' dice with 'f' faces
    int numRollsToTarget(int d, int f, int target, int res = 0) {
        // Base cases
        if (d == 0 || target <= 0) {
            // If there are no dice remaining or the target becomes non-positive
            return d == target;
        }
        // If the result is already computed, return it
        if (dp[d][target]) {
            return dp[d][target] - 1;
        }
        // Loop through each face on the current die
        for (auto i = 1; i <= f; ++i) {
            // Recursive call for the remaining dice and updated target
            res = (res + numRollsToTarget(d - 1, f, target - i)) % 1000000007;
        }
        // Store the result in the memoization array and return it
        dp[d][target] = res + 1;
        return res;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Example parameters
    int d = 2;  // Number of dice
    int f = 6;  // Number of faces on each die
    int target = 7;  // Target sum

    // Calculate the number of ways to roll the dice and reach the target sum
    int result = solution.numRollsToTarget(d, f, target);

    // Display the result
    cout << "Number of ways to reach the target sum: " << result << std::endl;

    return 0;
}

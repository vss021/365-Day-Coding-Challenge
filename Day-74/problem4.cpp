#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // TC: O(2^n), SC: O(n)
    bool solveUsingRecursive(vector<int>& arr, int sum, int ind) {
        // Base case
        if (sum == 0)
            return true;

        if (sum < 0 || ind >= arr.size())
            return false;

        // Recursive calls
        bool include = false, exclude = false;
        if (arr[ind] <= sum) {
            include = solveUsingRecursive(arr, sum - arr[ind], ind + 1); // Increment ind here
        }
        exclude = solveUsingRecursive(arr, sum, ind + 1); // Increment ind here

        return include || exclude;
    }

    // TC: O(n*sum), SC: O(n*sum)
    bool solveUsingBottomUp(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        // Base case
        for (int i = 0; i <= n; ++i)
            dp[i][0] = true;

        // Dynamic programming
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= sum; ++j) {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][sum];
    }

    // TC: O(n), SC: O(sum)
    bool solveUsingMemoization(vector<vector<int>>& dp, vector<int>& arr, int sum, int ind) {
        // Base case
        if (sum == 0)
            return true;

        if (sum < 0 || ind >= arr.size())
            return false;

        // Memoization
        if (dp[ind][sum] != -1)
            return dp[ind][sum];

        // Recursive calls
        bool include = false, exclude = false;
        if (arr[ind] <= sum) {
            include = solveUsingMemoization(dp, arr, sum - arr[ind], ind + 1); // Increment ind here
        }
        exclude = solveUsingMemoization(dp, arr, sum, ind + 1); // Increment ind here

        return dp[ind][sum] = include || exclude;
    }

    // Wrapper function for solving subset sum
    bool isSubsetSum(vector<int>& arr, int sum) {
        // Code here
        // return solveUsingRecursive(arr, sum, 0);
        // Uncomment the above line for recursive solution
        // return solveUsingBottomUp(arr, sum);
        // Uncomment the above line for bottom-up DP solution

        // Initialize memoization array
        vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
        return solveUsingMemoization(dp, arr, sum, 0);
        // Uncomment the above line for memoization solution
    }
};

int main() {
    Solution solver;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (solver.isSubsetSum(arr, sum)) {
        cout << "Subset with the given sum exists." << endl;
    } else {
        cout << "No subset with the given sum exists." << endl;
    }

    return 0;
}

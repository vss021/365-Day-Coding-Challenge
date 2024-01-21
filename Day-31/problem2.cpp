#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Method 1: Recursive Approach
    void Recursion(vector<int>& nums, int& maxSum, int currentSum, int index, int n) {
        if (index >= n) {
            maxSum = max(maxSum, currentSum);
            return;
        }

        // Exclude the current element
        Recursion(nums, maxSum, currentSum, index + 1, n);

        // Include the current element
        Recursion(nums, maxSum, currentSum + nums[index], index + 2, n);
    } 

    // Method 2: Memoization Approach
    int memoization(vector<int>& nums, vector<int>& dp, int index, int n) {
        if (index >= n) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        // Exclude the current element
        int excluding = memoization(nums, dp, index + 1, n);

        // Include the current element
        int including = memoization(nums, dp, index + 2, n) + nums[index];

        return dp[index] = max(excluding, including);
    } 

    int rob(vector<int>& nums) {
        int maxSum = INT_MIN;
        int n = nums.size();
        vector<int> dp(n + 1, -1);

        return memoization(nums, dp, 0, n);
    }
};

int main() {
    Solution solution;

    // Example input array
    vector<int> nums = {2, 7, 9, 3, 1};

    // Method 1: Recursive Approach
    int maxSumRecursive = INT_MIN;
    solution.Recursion(nums, maxSumRecursive, 0, 0, nums.size());
    cout << "Maximum sum using Recursive Approach: " << maxSumRecursive << endl;

    // Method 2: Memoization Approach
    int maxSumMemoization = solution.rob(nums);
    cout << "Maximum sum using Memoization Approach: " << maxSumMemoization << endl;

    return 0;
}

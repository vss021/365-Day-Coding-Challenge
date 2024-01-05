#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Approach 1: Recursion + Memoization
    int findLISLengthApproach1(int currentIndex, int previousIndex, vector<int>& nums, vector<vector<int>>& memo) {
        if (currentIndex == nums.size()) return 0;

        if (memo[currentIndex][previousIndex + 1] != -1) {
            return memo[currentIndex][previousIndex + 1];
        }

        int notTake = findLISLengthApproach1(currentIndex + 1, previousIndex, nums, memo);
        int take = 0;

        if (previousIndex == -1 || nums[currentIndex] > nums[previousIndex]) {
            take = 1 + findLISLengthApproach1(currentIndex + 1, currentIndex, nums, memo);
        }

        return memo[currentIndex][previousIndex + 1] = max(notTake, take);
    }

    // Approach 2: Dynamic Programming
    int findLISLengthApproach2(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev = ind - 1; prev >= -1; prev--) {
                int notTake = dp[ind + 1][prev + 1];
                int take = 0;

                if (prev == -1 || nums[ind] > nums[prev]) {
                    take = 1 + dp[ind + 1][ind + 1];
                }

                dp[ind][prev + 1] = max(notTake, take);
            }
        }

        return dp[0][0];
    }

    // Approach 3: Dynamic Programming with Better Space Optimization
    int findLISLengthApproach3(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 1;

        for (int ind = 1; ind < n; ind++) {
            for (int prev = 0; prev < ind; prev++) {
                if (nums[ind] > nums[prev]) {
                    dp[ind] = max(dp[ind], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[ind]);
        }

        return maxi;
    }

    // Approach 4: Dynamic Programming with Binary Search
    int findLISLengthApproach4(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        int len = 1;
        temp.emplace_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (nums[i] > temp.back()) {
                temp.emplace_back(nums[i]);
                len++;
            } else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }

        return len;
    }

    // main function
    int lengthOfLIS(vector<int>& nums) {
        return findLISLengthApproach4(nums);
    }
};



int main() {
    // Example usage of the Solution class
    Solution solution;

    // Sample input
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    // Choose the approach (1, 2, 3, or 4)
    int approachNum = 4;

    // Call the lengthOfLIS method with the selected approach
    int result = solution.lengthOfLIS(nums, approachNum);

    // Output the result
    cout << "Length of Longest Increasing Subsequence: " << result << std::endl;

    return 0;
}

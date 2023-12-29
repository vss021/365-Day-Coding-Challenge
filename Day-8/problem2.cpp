#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int len = jobDifficulty.size();

        // Check if it's possible to divide the jobs into 'd' days
        if (len < d) {
            return -1;
        }

        // Check if all jobs have zero difficulty
        int sum = accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);
        if (sum == 0) {
            return 0;
        }

        // Memoization table
        vector<vector<int>> memo(d + 1, vector<int>(len, 0));

        // Call the helper function to solve the problem
        helper(jobDifficulty, d, 0, memo);

        // Return the result stored in the memo table
        return memo[d][0];
    }

private:
    void helper(vector<int>& jobDifficulty, int daysLeft, int idx, vector<vector<int>>& memo) {
        int len = jobDifficulty.size();

        // If the result is already memoized, return
        if (memo[daysLeft][idx] != 0) {
            return;
        }

        // If there is only one day left, find the maximum difficulty for the remaining jobs
        if (daysLeft == 1) {
            int num = 0;
            for (int i = idx; i < len; i++) {
                num = max(num, jobDifficulty[i]);
            }
            memo[daysLeft][idx] = num;
            return;
        }

        int maxDifficulty = jobDifficulty[idx];
        daysLeft--;
        int stop = len - idx - daysLeft + 1;

        int res = INT_MAX;

        // Iterate through possible partitions of the remaining jobs
        for (int i = 1; i < stop; i++) {
            maxDifficulty = max(maxDifficulty, jobDifficulty[idx + i - 1]);
            int other = memo[daysLeft][idx + i];

            // If the result is not memoized, call the helper function
            if (other == 0) {
                helper(jobDifficulty, daysLeft, idx + i, memo);
                other = memo[daysLeft][idx + i];
            }

            // Update the result with the minimum difficulty
            res = min(res, other + maxDifficulty);
        }

        // Memoize the result
        memo[daysLeft + 1][idx] = res;
    }
};

int main() {
    Solution solution;

    // Example Usage
    vector<int> jobDifficulty = {6, 5, 4, 3, 2, 1};
    int d = 2;

    int result = solution.minDifficulty(jobDifficulty, d);

    cout << "Result: " << result << endl;

    return 0;
}

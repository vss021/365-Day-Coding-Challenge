#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, int> dp;

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));

        for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        // Top-Down (Recursive with Memoization) Solution
        // return topDownMemo(0, jobs);

        // Bottom-Up Solution
        // return bottomUp(jobs);

        // Top-Down (Recursive) Solution
        // return topDownRecursive(0, jobs);
    }

private:
    // Top-Down (Recursive with Memoization) solution
    int topDownMemo(int cur, vector<vector<int>>& jobs) {
        if (cur == jobs.size()) {
            return 0;
        }

        if (dp.find(cur) != dp.end()) {
            return dp[cur];
        }

        int next = findNext(cur, jobs);
        int inclProf = jobs[cur][2] + (next == -1 ? 0 : topDownMemo(next, jobs));
        int exclProf = topDownMemo(cur + 1, jobs);

        dp[cur] = max(inclProf, exclProf);
        return dp[cur];
    }

    // Helper function for recursive solution
    int findNext(int cur, vector<vector<int>>& jobs) {
        for (int next = cur + 1; next < jobs.size(); next++) {
            if (jobs[next][0] >= jobs[cur][1]) {
                return next;
            }
        }
        return -1;
    }

    // Bottom-Up solution
    int bottomUp(vector<vector<int>>& jobs) {
        vector<int> dp(jobs.size(), 0);

        for (int i = jobs.size() - 1; i >= 0; i--) {
            int next = findNext(i, jobs);
            int inclProf = jobs[i][2] + (next == -1 ? 0 : dp[next]);
            int exclProf = (i + 1 < jobs.size()) ? dp[i + 1] : 0;

            dp[i] = max(inclProf, exclProf);
        }

        return dp[0];
    }

    // Top-Down (Recursive) solution
    int topDownRecursive(int cur, vector<vector<int>>& jobs) {
        if (cur == jobs.size()) {
            return 0;
        }

        int next = findNext(cur, jobs);
        int inclProf = jobs[cur][2] + (next == -1 ? 0 : topDownRecursive(next, jobs));
        int exclProf = topDownRecursive(cur + 1, jobs);

        return max(inclProf, exclProf);
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<int> startTime = {1, 2, 3, 3};
    vector<int> endTime = {3, 4, 5, 6};
    vector<int> profit = {50, 10, 40, 70};

    int maxProfit = solution.jobScheduling(startTime, endTime, profit);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}

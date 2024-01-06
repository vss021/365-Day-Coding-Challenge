#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int N;
    int memo[1000001];

private:
    // Recursive function to calculate the maximum profit
    int calculateMaxProfit(vector<vector<int>>& jobs, int index) {
        // Base case: if index is beyond the last job, return 0
        if (index >= N)
            return 0;

        // If the result for this index is already calculated, return it
        if (memo[index])
            return memo[index];

        int lo = 0, hi = N - 1, nextJobTime = N + 1;

        // Binary search to find the next job with start time greater than or equal to the current job's end time
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (jobs[mid][0] >= jobs[index][1]) {
                nextJobTime = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        // Calculate the maximum profit either by including or excluding the current job
        int includingCurrentJobProfit = jobs[index][2] + calculateMaxProfit(jobs, nextJobTime);
        int excludingCurrentJobProfit = calculateMaxProfit(jobs, index + 1);

        // Memoize the result for this index
        memo[index] = max(includingCurrentJobProfit, excludingCurrentJobProfit);

        return memo[index];
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        N = startTime.size();
        vector<vector<int>> jobs;

        // Create a vector of jobs with start time, end time, and profit
        for (int i = 0; i < N; ++i) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        // Sort the jobs based on their start times
        sort(begin(jobs), end(jobs));

        // Start the recursive calculation of maximum profit from the first job
        return calculateMaxProfit(jobs, 0);
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

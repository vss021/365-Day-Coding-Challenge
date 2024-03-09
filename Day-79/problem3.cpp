#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;
        // Case 1: No overlapping case before the merge intervals
        // Compare ending point of intervals to starting point of newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }
        // Case 2: Overlapping case and merging of intervals
        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        // Case 3: No overlapping of intervals after newinterval being merged
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};

int main() {
    Solution solution;

    // Example input intervals
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    // Time Complexity: O(n)
    //   The time complexity is O(n) because we iterate through the input intervals once to find the proper position for merging the new interval.
    //   Here, 'n' represents the number of intervals in the input vector 'intervals'.

    // Space Complexity: O(n)
    //   The space complexity is O(n) because we use additional space to store the merged intervals in the result vector.
    //   Here, 'n' represents the number of intervals in the input vector 'intervals'.

    // Insert newInterval into intervals
    vector<vector<int>> result = solution.insert(intervals, newInterval);

    // Output the result
    cout << "Merged Intervals:" << endl;
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}

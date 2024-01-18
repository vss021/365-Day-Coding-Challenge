#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Approach: Greedy Algorithm
    // 1. Create intervals representing the effective coverage of each sprinkler.
    // 2. Sort the intervals based on their starting points.
    // 3. Iterate through the sorted intervals and find the minimum number of sprinklers needed.
    int min_sprinklers(int gallery[], int n) {
        // Create a vector of pairs to store the intervals
        vector<pair<int, int>> intervals;

        // Populate intervals vector with valid intervals
        for (int i = 0; i < n; i++) {
            if (gallery[i] != -1) {
                intervals.push_back({max(0, i - gallery[i]), min(n - 1, i + gallery[i])});
            }
        }

        // Sort intervals based on the starting point
        sort(intervals.begin(), intervals.end());

        // Initialize variables for iteration
        int i = 0, cnt = 0, j = 0, size = intervals.size();

        // Iterate through intervals to find the minimum sprinklers needed
        while (i < n) {
            // If the starting point of the current interval is greater than the current position,
            // it means there is a gap, and it's not possible to cover the entire gallery
            if (intervals[j].first > i) {
                return -1;
            }

            // Update the current position based on the intervals
            int prev_i = i;
            while (j < size && intervals[j].first <= prev_i) {
                i = max(i, intervals[j].second + 1);
                j++;
            }

            // Increment the sprinkler count
            cnt++;
        }

        // Return the minimum sprinklers needed to cover the gallery
        return cnt;
    }
};

int main() {
    const int n = 6;
    int gallery[] = {2, -1, -1, 0, 1, -1};

    Solution solution;
    int result = solution.min_sprinklers(gallery, n);

    if (result == -1) {
        cout << "It's not possible to cover the entire gallery.\n";
    } else {
        cout << "Minimum sprinklers needed: " << result << "\n";
    }

    return 0;
}

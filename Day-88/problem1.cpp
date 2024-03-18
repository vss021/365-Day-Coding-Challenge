#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 0;
        sort(points.begin(), points.end());
        vector<int> tempInterval = points[0];
        for (auto it : points) {
            if (it[0] <= tempInterval[1]) {
                tempInterval[1] = min(it[1], tempInterval[1]);
            } else {
                count++;
                tempInterval = it;
            }
        }
        count++;
        return count;
    }
};

int main() {
    Solution solution;

    // Example usage for problem 1: Bursting Balloons with Minimum Arrows
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    int minArrows = solution.findMinArrowShots(points);
    cout << "Minimum number of arrows required: " << minArrows << endl;

    return 0;
}

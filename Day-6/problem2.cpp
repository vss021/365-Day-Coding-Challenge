#include <iostream>
#include <vector>

using namespace std;

/*
    Approach:
    - Use a sliding window approach to iterate through the balloons.
    - For each color segment, calculate the total cost by subtracting the maximum removal time.
    - Move to the next segment and repeat the process until all balloons are processed.
*/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // Initialize the total cost and pointers for the sliding window
        int totalCost = 0, i = 0, j = 0;
        int n = colors.size();

        // Iterate through the balloons
        while (j < n) {
            // Initialize variables for the current segment
            int currentCost = 0, maxTime = 0;

            // Extend the segment while the color is the same
            while (j < n && colors[i] == colors[j]) {
                currentCost += neededTime[j];
                maxTime = max(maxTime, neededTime[j]);
                ++j;
            }

            // Update the total cost by subtracting the maximum removal time in the segment
            totalCost += currentCost - maxTime;

            // Move to the next segment
            i = j;
        }

        return totalCost;
    }
};


int main() {
    Solution solution;

    // Example usage
    string colors = "abacabadabacaba";
    vector<int> neededTime = {3, 2, 1, 5, 2, 4, 6, 1, 2, 3, 4, 5, 6, 7};

    int result = solution.minCost(colors, neededTime);

    // Display the result
    cout << "Minimum cost: " << result << endl;

    return 0;
}
